# Final Project
Shada Elghariani / CISC 187 
## Task 1
To get an O(N + M) runtime, nested loops need to be avoided by using a hash set. Then the full names of all players from the first sport are inserted into the set in O(N) time. The players are then checked from the second sport against the set in O(M) time.

``` cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

struct Player {
    std::string first_name;
    std::string last_name;
    std::string team;
};

std::vector<std::string> find_common_players(const std::vector<Player>& basketball, const std::vector<Player>& football) {
    std::unordered_set<std::string> basketball_set;
    std::vector<std::string> common_players;

    // Hash all basketball players by full name: O(N)
    for (const auto& player : basketball) {
        basketball_set.insert(player.first_name + " " + player.last_name);
    }

    // Check football players against the hash set: O(M)
    for (const auto& player : football) {
        std::string full_name = player.first_name + " " + player.last_name;
        if (basketball_set.count(full_name)) {
            common_players.push_back(full_name);
        }
    }

    return common_players;
}

int main() {
    std::vector<Player> basketball_players = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    std::vector<Player> football_players = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    std::vector<std::string> result = find_common_players(basketball_players, football_players);
    
    std::cout << "Common Players: ";
    for (const auto& name : result) {
        std::cout << "[" << name << "] ";
    }
    std::cout << std::endl;
    return 0;
}
``` 

## Task 2

Since the array has distinct numbers from 0 to N with exactly one number missing, the size of the array is N. The sum of all numbers from 0 to N can be calculated in O(1) time using Gauss's summation formula: $\frac{N \times (N + 1)}{2}$. Subtracting the sum of the array elements from this sum reveals the missing number in O(N) time with O(1) space.

``` cpp
#include <iostream>
#include <vector>
#include <numeric>

int find_missing_number(const std::vector<int>& nums) {
    long long n = nums.size(); // The array is missing 1 element, so max value N equals array size.
    long long expected_sum = (n * (n + 1)) / 2;
    long long actual_sum = 0;
    
    for (int num : nums) {
        actual_sum += num;
    }
    
    return expected_sum - actual_sum;
}

int main() {
    std::vector<int> test1 = {2, 3, 0, 6, 1, 5};
    std::vector<int> test2 = {8, 2, 3, 9, 4, 7, 5, 0, 6};

    std::cout << "Missing number (Test 1): " << find_missing_number(test1) << std::endl; // Output: 4
    std::cout << "Missing number (Test 2): " << find_missing_number(test2) << std::endl; // Output: 1
    return 0;
}
```
## Task 3

To find the maximum profit in O(N) time, the function loops through the array once while keeping track of the minimum price seen up to that point. For every price it will check the difference between the current price and the minimum price, and then update the highest profit found so far.
``` cpp
#include <iostream>
#include <vector>
#include <algorithm>

int max_profit(const std::vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int min_price = prices[0];
    int max_prof = 0;
    
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else {
            max_prof = std::max(max_prof, prices[i] - min_price);
        }
    }
    
    return max_prof;
}

int main() {
    std::vector<int> stock_prices = {10, 7, 5, 8, 11, 2, 6};
    std::cout << "Maximum Profit: $" << max_profit(stock_prices) << std::endl; // Output: 6
    return 0;
}
```

## Task 4

The maximum product of the two numbers can come from either the two largest positive numbers or the two smallest negative numbers. This can be achieved by tracking the top 2 highest and bottom 2 lowest values in a single O(N) pass.

``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int max_product_of_two(const std::vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int num : nums) {
        // Track the two largest values
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }

        // Track the two smallest values
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    return std::max(max1 * max2, min1 * min2);
}

int main() {
    std::vector<int> nums = {5, -10, -6, 9, 4};
    std::cout << "Highest Product: " << max_product_of_two(nums) << std::endl; // Output: 60 (-10 * -6)
    return 0;
}
``` 

## Task 5

Because the range of inputs is very small and bounded, Counting Sort would be helpful. Starting with mapping the floating-point temperatures to integer index buckets, counting their frequencies in O(N) time, and rewriting the sorted values back into the array.

``` cpp
#include <iostream>
#include <vector>
#include <cmath>

void sort_temperatures(std::vector<double>& temps) {
    // 97.0 to 99.0 inclusive with 0.1 increments gives 21 possible buckets
    std::vector<int> counts(21, 0);

    // Populate frequency map: O(N)
    for (double t : temps) {
        int index = std::round((t - 97.0) * 10.0);
        counts[index]++;
    }

    // Reconstruct the sorted array: O(N)
    int arr_idx = 0;
    for (int i = 0; i < 21; ++i) {
        while (counts[i] > 0) {
            temps[arr_idx++] = 97.0 + (i / 10.0);
            counts[i]--;
        }
    }
}

int main() {
    std::vector<double> temps = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};
    
    sort_temperatures(temps);
    
    std::cout << "Sorted Temperatures: ";
    for (double t : temps) {
        std::cout << t << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

## Task 6
To avoid sorting, it would be easier to insert all the elements into a hash set. Then repeat through the numbers and look only for the start of a sequence. From that starting point, count how far the sequence goes. Since each number is visited at most twice, this guarantees a linear O(N) execution time.
```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int longest_consecutive_sequence(const std::vector<int>& nums) {
    std::unordered_set<int> num_set(nums.begin(), nums.end());
    int longest_streak = 0;

    for (int num : num_set) {
        // Only check sequence if 'num' is the start of a sequence
        if (!num_set.count(num - 1)) {
            int current_num = num;
            int current_streak = 1;

            while (num_set.count(current_num + 1)) {
                current_num += 1;
                current_streak += 1;
            }

            longest_streak = std::max(longest_streak, current_streak);
        }
    }

    return longest_streak;
}

int main() {
    std::vector<int> test1 = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    std::vector<int> test2 = {19, 13, 15, 12, 18, 14, 17, 11};

    std::cout << "Longest sequence len (Test 1): " << longest_consecutive_sequence(test1) << std::endl; // Output: 4
    std::cout << "Longest sequence len (Test 2): " << longest_consecutive_sequence(test2) << std::endl; // Output: 5
    return 0;
}

```
