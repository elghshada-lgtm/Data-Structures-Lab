

## Code 

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iomanip>
#include <random>

using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const string& key) const {
        const int prime = 31;
        long long hash = 0;

        for (char c : key) {
            hash = hash * prime + c;
        }

        return hash % capacity;
    }

    void rehash() {
        vector<list<pair<string, int>>> oldTable = table;

        capacity *= 2;
        table.clear();
        table.resize(capacity);

        currentSize = 0;
        collisionCount = 0;

        for (const auto& bucket : oldTable) {
            for (const auto& item : bucket) {
                insert(item.first, item.second);
            }
        }
    }

public:
    HashTable(int size = 11) {
        capacity = size;
        currentSize = 0;
        collisionCount = 0;
        table.resize(capacity);
    }

    void insert(const string& key, int value) {
        int index = hashFunction(key);

        for (auto& item : table[index]) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }

        if (!table[index].empty()) {
            collisionCount++;
        }

        table[index].push_back({key, value});
        currentSize++;

        if (loadFactor() > 0.75) {
            rehash();
        }
    }

    bool remove(const string& key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                currentSize--;
                return true;
            }
        }

        return false;
    }

    int search(const string& key) const {
        int index = hashFunction(key);

        for (const auto& item : table[index]) {
            if (item.first == key) {
                return item.second;
            }
        }

        return -1;
    }

    double loadFactor() const {
        return static_cast<double>(currentSize) / capacity;
    }

    int size() const {
        return currentSize;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    int getCollisionCount() const {
        return collisionCount;
    }

    int getCapacity() const {
        return capacity;
    }

    int maxBucketSize() const {
        int maxSize = 0;
        for (const auto& bucket : table) {
            if ((int)bucket.size() > maxSize) {
                maxSize = bucket.size();
            }
        }
        return maxSize;
    }

    double averageBucketLength() const {
        int usedBuckets = 0;
        int totalItems = 0;

        for (const auto& bucket : table) {
            if (!bucket.empty()) {
                usedBuckets++;
                totalItems += bucket.size();
            }
        }

        if (usedBuckets == 0) return 0.0;

        return static_cast<double>(totalItems) / usedBuckets;
    }
};

string generateRandomString(int length) {
    static const string letters = "abcdefghijklmnopqrstuvwxyz";
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, letters.size() - 1);

    string result = "";
    for (int i = 0; i < length; i++) {
        result += letters[dist(gen)];
    }

    return result;
}

void printStats(const string& title, const HashTable& ht) {
    cout << "\n=== " << title << " ===" << endl;
    cout << "Capacity: " << ht.getCapacity() << endl;
    cout << "Size: " << ht.size() << endl;
    cout << fixed << setprecision(2);
    cout << "Load Factor: " << ht.loadFactor() << endl;
    cout << "Collisions: " << ht.getCollisionCount() << endl;
    cout << "Max Bucket Size: " << ht.maxBucketSize() << endl;
    cout << "Average Bucket Length: " << ht.averageBucketLength() << endl;
}

int main() {
    HashTable ht;

    for (int i = 1; i <= 100; i++) {
        ht.insert("word" + to_string(i), i);
    }

    printStats("Basic Test After 100 Inserts", ht);

    cout << "\nSearch word25: " << ht.search("word25") << endl;
    cout << "Search missingWord: " << ht.search("missingWord") << endl;

    cout << "\nRemove word10: " << (ht.remove("word10") ? "Success" : "Failed") << endl;
    cout << "Remove word50: " << (ht.remove("word50") ? "Success" : "Failed") << endl;
    cout << "Remove fakeKey: " << (ht.remove("fakeKey") ? "Success" : "Failed") << endl;

    HashTable randomTable;
    for (int i = 0; i < 100; i++) {
        randomTable.insert(generateRandomString(6), i);
    }
    printStats("Experiment 1 - Random Strings", randomTable);

    HashTable sequentialTable;
    for (int i = 1; i <= 100; i++) {
        sequentialTable.insert("student" + to_string(i), i);
    }
    printStats("Experiment 2 - Sequential Keys", sequentialTable);

    HashTable prefixTable;
    for (int i = 1; i <= 100; i++) {
        string num = to_string(i);
        while (num.length() < 4) {
            num = "0" + num;
        }
        prefixTable.insert("data_" + num, i);
    }
    printStats("Experiment 3 - Same Prefix Keys", prefixTable);

    return 0;
}
```
## Part 6 – Experimental Analysis 
In the random string test, the keys were spread out pretty evenly across the table which made fewer collisions. When I tested sequential keys like "student1", "student2", and "student3", they followed a similar pattern which caused a little more clustering in some buckets. The same prefix test with keys like "data_0001", "data_0002", and "data_0003" had an even higher chance of collisions because many of the characters at the start of the strings were the same.

In summary, these tests showed that when the keys are very similar to each other, collisions happen more often. The rehashing step helps fix this by making a larger size of the table once it starts getting too full, which then spreads the keys out better again.


