# Stacks and Queues in Data Structure
## Task #1
 Using Figure 17 as a model, in the book Data Structures in C++, illustrate the result of each operation in the sequence PUSH(S,4), PUSH(S,1), PUSH(S,3), POP(S), PUSH(S,8), and POP(S) on an initially empty stack S stored in array S[1..6].

1. The stack S is stored in the array S[1..6] and begins empty. When the stack is empty, S.top = 0 because no elements are stored yet.
2. Starting off with PUSH(S,4), this inserts the value 4 into the stack. Since the stack was empty, the value is placed at S[1], and S.top becomes 1.
3. Next, PUSH(S,1) adds the value 1 on top of the stack. It is then stored in S[2], and S.top becomes 2. The stack now contains 4 at the bottom and 1 at the top.
4. Then PUSH(S,3) inserts 3 into the stack at S[3]. The top moves to position 3, so the stack now contains 4, 1, 3, with 3 as the top element.
5. After that, POP(S) removes the most recently inserted element from the stack. The value 3 is removed, and S.top decreases to 2, leaving the stack with 4 and 1.
6. Then, PUSH(S,8) adds the value 8 to the stack. It’s placed at S[3], and S.top becomes 3. The stack now contains 4, 1, 8, with 8 at the top. 
7. Now finally, POP(S) removes the top element again. The value 8 is removed, and S.top decreases to 2. 
8. At the end of all the operations, the stack contains two elements: 4 at the bottom and 1 at the top, with S.top = 2.

## Task #2
Using Figure 18 as a model, in the book Data Structures in C++, illustrate the result of each operation in the sequence ENQUEUE(Q,4), ENQUEUE(Q,1), ENQUEUE(Q,3), DEQUEUE(Q), ENQUEUE(Q,8), and DEQUEUE(Q) on an initially empty queue
Q stored in array Q[1..6].

1. The queue Q starts empty and is stored in the array Q[1..6]. At first, both Q.head and Q.tail point to the same position because there are no elements in the queue.
2. Starting with ENQUEUE(Q,4), this is going to insert the value 4 into the queue at the tail position. The tail then moves to the next position.
3. Then, ENQUEUE(Q,1) is going to add 1 to the queue behind 4, and the tail moves forward again. The queue now has 4, 1, where 4 is at the front (head).
4. Then ENQUEUE(Q,3) inserts 3 at the end of the queue. The queue now contains 4, 1, 3, with 4 still at the front.
5. Now with DEQUEUE(Q), this removes the element at the front of the queue. The value 4 is now removed and the head moves to the next value. The queue now contains 1 and 3.
6. Next, ENQUEUE(Q,8) adds 8 to the end of the queue. The queue becomes 1, 3, 8.
7. Finally, DEQUEUE(Q) removes the element at the front again. The value 1 is removed leaving the queue with 3 and 8, where 3 is now the front element.
8. At the end of all the operations, the queue contains 3 at the front and 8 at the end.

## Task #3
Rewrite ENQUEUE and DEQUEUE to detect underflow and overflow of a queue.

* To detect an overflow in ENQUEUE, you first have to check if the queue is full before inserting a new element. The queue is full when the next position of Q.tail would be the same as Q.head. If the queue is full, an overflow error should be reported and the element should not be inserted. If the queue is not full, the value x is inserted at position Q.tail. After inserting the element, Q.tail moves to the next position, wrapping around to position 1 if it reaches the end of the array.

* To detect underflow in DEQUEUE, you have to check whether the queue is empty before removing an element. The queue is empty when Q.head is equal to Q.tail. If the queue is empty, an underflow error should be shown because there is no element to remove. If the queue is not empty, the element at Q.head is removed and returned. After removing the element, Q.head moves to the next position, wrapping around to position 1 if it reaches the end of the array. Both operations will still run in O(1) time because they only need a few simple checks and pointer updates.

## Task #4
A stack allows insertion and deletion of elements at only end, and a queue allows insertion at one end and deletion at the other end, a deque (double-ended queue) allows insertion and deletion at both ends. Write four O(1)
time procedures to insert elements into and delete elements from both ends of a deque implemented by an array.

1. **Insert at the front**: Before inserting, check if the deque is full. If there is space then move the front pointer one position back and place the new element at the front.

2. **Insert at the end**: Also check if the deque is full for this operation. If there is space, then place the new element at the rear position, then move the rear pointer forward.

3. **Delete from the front**: For this operation check if the deque is empty. If it is not empty, remove the element at the front, then move the next front pointer forward to the next position.

4. **Delete from the end**: For this operation you will also check if deque is empty, If it is not empty, remove the element at the rear, then move the rear pointer backward.
