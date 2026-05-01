NeoVerseCity Assignment:

How to run the program:

Uncomment the method on NeoVerseCity.cpp that you want to execute.

Part 1

Part 1 Big O analysis:
Operation - search in Vector
Algorithm - find_if
Complexity - O(n), linear seacrch 

Part 2
Big O analysis:

Why is a vector suitable for fast access:
- It is suitable because it can access elements directly using index without checking other elements.
- This makes it faster to retrieve data                           

Why is a linked list suitable for unbounded logs:
- Unlike a vector, linked list can grow dynamically. New logs cann be added to the list without worrying about memory limits or resizing.
- Each node will point to the next element

Compare insertion and traversal complexities:
- Both linked list and vector take O(n) to traverse. 
- Linked list is better for inserting data as there is no need to shift elements when adding new ones
- Vector is better for data retrieval as it can directly access elements using index

Vector:

Operation - data insertion 
Algorithm - push_back
Complexity - O(1), amortized. Faster when adding elements at the end

Operation - Removing data
Algorithm - loop and erase
Complexity - O(n), due to search and shifting elements

Operation – Accessing data
Algorithm – indexing
Complexity – O(1), constant time

Operation – Traverse data
Algorithm – loop
Complexity – O(n), linear traversal. It must loop through each element

Linked List:

Operation – Inserting log
Algorithm – push_back
Complexity – O(1). It is always fast because there is no need to shift elements when inserting data

Operation – Removal of logs
Algorithm – iterator + erase
Complexity – O(n), due to traversal

Operation – Search logs
Algorithm – loop
Complexity – O(n)

Operation – Traversing through logs
Algorithm – loop
Complexity – O(n). It must visit each node using pointers.

Part 3
Big O analysis:

Explain why stack vs queue is appropriate
- Queue are better for events because they ensure that events are resolved in the order they arrive. It uses FIFO - first in first out
- Stack is appropriate as it enusres that the most critical events are handled first. It uses LIFO - last in first out

Queue:

Operation – Adding an event
Algorithm – push
Complexity – O(1)

Operation – Processing an event
Algorithm – front + pop
Complexity – O(1)

Operation – Displaying events
Algorithm – traversal (loop)
Complexity – O(n)

Stack:

Operation – Adding an emergency event
Algorithm – push
Complexity – O(1)

Operation – Resolving emergency event
Algorithm – top + pop
Complexity – O(1)

Operation – Displaying emergency events
Algorithm – traversal (loop)
Complexity – O(n)

Part 7
Persisting data (engineers.dat)
Engineers are saved when they are created by the admin
Sample Engineer (Id = 1, Name = Pat, Password = 123, Clearance level = low)
Sample Engineer (Id = 2, Name = Patience, Password = 1234, Clearance level = High)

Persisting data (events.dat)
Engineers are saved when events are created
Sample Event ()
Sample Event ()

Persisting data (city_log.dat)
Engineers are saved when they are created
Sample Log ()
Sample Log ()




Part 5 Big O analysis:


Operation – Sorting data
Algorithm – sort
Complexity – O(n log n)
Justification - It is faster than other algorithms. It is optpmised for performance-critical systems and it is highly efficient for ordering large datasets

Operation – Search 
Algorithm – find_if
Complexity – O(n), linear search
Justification - It finds based on a condition. Since data is not sorted, it is the most appropriate and simple approach.

Operation – Finding minimum
Algorithm – min_element
Complexity – O(n)
Justification - It was chosen because it effeciently scans dataset without the need to sort data. Sorting data could lead to expensive operation.

Operation – Finding maximum
Algorithm – max_element
Complexity – O(n)
Justification - It was chosen because it effeciently scans dataset to find the maximum without the need to sort data. Sorting data could lead to expensive operation.

Operation – Counting elements
Algorithm – count_if
Complexity – O(n)
Justification - It was chosen because it performs a single travesal and it provides a simple and efficient way that meets the given condition