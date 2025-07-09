# Requirements of C++ Node and Data Structures
**Project Name**: C++ Node and Data Structures  
**Author**: Chip Hardy  
**Date**: 7/7/2025  
**Status**: Planning  
## Summary
This project is a library of data structures and algorithms in C++ for practice creating data structures and for usage in future projects. 
The library will include implementations of common data structures such as linked lists, stacks, queues, trees, graphs, and hash tables. 
It will also include implementations of common algorithms such as search and sort algorithms. 
The library will be designed to be easy to use and implement in other projects. 
It will also include benchmark testing for time and memory complexity of each algorithm.
## Objectives
- Practice creating data structures and algorithms in C++.
- Create a library of data structures and algorithms in C++ for use in future projects.
- Provide a template design for easy use and implementation in other projects.
- Provide a package for easy installation and use of the library.
- Provide benchmark testing for time and memory complexity of each algorithm.
- Provide documentation for the library and its usage.
## Scope
### In-scope
- All data structures listed in functional requirement 1.
- All algorithms listed in functional requirement 2.
- A command-line benchmark testing tool for time and memory complexity of each algorithm.
- A template design for easy use and implementation in other projects.
- A package for easy installation and use of the library.
- Documentation for the library and its usage.
- Unit tests for all data structures and algorithms.
### Out-of-scope
- Implementations of data structures and algorithms not listed in functional requirements.
- A graphic user interface (GUI) or web-based interfaces for the library.
- Database connectivity.
- Languages other than C++
    - **Note**: There could be future libraries that implement the same data structures in different languages, but that would be outside the scope of this project.
## Stakeholders
- **Project Owner**: Chip Hardy (chiphardy1995@icloud.com)
- **Project Contributors**: Open to contributions from other developers
- **Project Users**: Developers who want to use the library in their projects
## Requirements
### Business Requirements
1. Provide a library of data structures and algorithms in C++ for practice and future projects
2. Create a template design for easy use and implementation in other projects
3. Provide a package for easy installation and use of the library
4. Provide benchmark testing for time and memory complexity of each algorithm
5. Provide documentation for the library and its usage
### Functional Requirements
- 1 Data Structures Implementations
    - 1.1 Doubly Linked List
        - 1.1.1 Insertion of a value
        - 1.1.2 Access of a specific value
    - 1.2 FIFO Queue
        - 1.2.1 Enqueue/Push a value to back of queue
        - 1.2.2 Dequeue/Pop remove a value from the front of queue
        - 1.2.3 Peek the value at front of queue without removing
    - 1.3 LIFO Stack
        - 1.3.1 Push a value to the top of the stack
        - 1.3.2 Pop a value from the top of the stack
        - 1.3.3 Peek a value at the top of the stack
    - 1.4 Binary Tree
        - 1.4.1 Insertion of a value
        - 1.4.2 Safe deletion of a value
        - 1.4.3 Search of a value in a tree
        - 1.4.4 Traversal (Pre-order, In-order, Post-order)
    - 1.5 Binary Search Tree
        - 1.5.1 Insertion of a value
        - 1.5.2 Safe deletion of a value
        - 1.5.3 Search of a value in a tree
        - 1.5.4 Traversal (Pre-order, In-order, Post-order)
    - 1.6 Binary Indexed Tree
        - 1.6.1 Update a specific index with a value
        - 1.6.2 Safe deletion of a value at a specific index
        - 1.6.3 Query the value at a specific index
    - 1.7 AVL Tree
        - 1.7.1 Insertion of a value
        - 1.7.2 Safe deletion of a value
        - 1.7.3 Automatic rebalancing
        - 1.7.4 Search of a value in a tree
        - 1.7.5 Traversal (Pre-order, In-order, Post-order)
    - 1.8 Red Black Tree
        - 1.8.1 Insertion of a value
        - 1.8.2 Safe deletion of a value
        - 1.8.3 Automatic rebalancing
        - 1.8.4 Search of a value in a tree
        - 1.8.5 Traversal (Pre-order, In-order, Post-order)
    - 1.9 Undirected Graph
        - 1.9.1 Insertion of a vertex
        - 1.9.2 Safe deletion of a vertex
        - 1.9.3 Search of a vertex in a graph
        - 1.9.4 Traversal (BFS, DFS)
    - 1.10 Directed Graph
        - 1.10.1 Insertion of a vertex
        - 1.10.2 Safe deletion of a vertex
        - 1.10.3 Search of a vertex in a graph
        - 1.10.4 Traversal (BFS, DFS)
    - 1.11 Hash Table
        - 1.11.1 Insertion of a value
        - 1.11.2 Safe deletion of a value
        - 1.11.3 Search of a value in a hash table
        - 1.11.4 Collision resolution (Chaining, Open Addressing)
    - 1.12 Heap
        - 1.12.1 Insertion of a value
        - 1.12.2 Peeking the maximum or minimum value
        - 1.12.3 Pop of the maximum or minimum value
        - 1.12.4 Heapify (Building a heap from an array)
        - 1.12.5 Priority Queue (Max-Heap, Min-Heap)
        - 1.12.6 Safe deletion of a value
- 2 Algorithm Implementation
    - 2.1 Linear Search
    - 2.2 Binary Search
    - 2.3 Fibonacci Search
    - 2.4 Selection Sort
    - 2.5 Bubble Sort
    - 2.6 Insertion Sort
    - 2.7 Quick Sort
    - 2.8 Recursive Merge Sort
    - 2.9 Multithreaded Merge Sort
    - 2.10 Breadth-First Search (BFS)
    - 2.11 Depth-First Search (DFS)
    - 2.12 Shortest Path Algorithm (Dijkstra's Algorithm)
    - 2.13 Minimum Spanning Tree Algorithm (Kruskal's Algorithm)
    - 2.14 A* Algorithm
- 3 Library Usability
    - 3.1 Template Design
    - 3.2 Distributable library package
- 4 Benchmark Testing
    - 4.1 Time Complexity Analysis
    - 4.2 Memory Complexity Analysis
    - 4.3 Test Result Reporting
### Non-functional Requirements
- 1 Performance
    - 1.1 Time Efficiency
    - 1.2 Memory Efficiency
- 2 Documentation
    - 2.1 Project Documentation
    - 2.2 Source Code Documentation
- 3 Portability
    - 3.1 Compatible with Different C++ Compilers
    - 3.2 Easy build instructions
    - 3.3 Compatible with Different Operating Systems
    - 3.4 Easy to install package
    - 3.5 Compatibility with CXX standards
## Constraints
- Project is open source, currently with one developer
- Project should be completed within 2 months
- Goal budget is $0, all funds will be from personal savings
- Keep dependencies to a minimum, only use standard C++ libraries
- Project must be easy to use and implement in other projects
- Project must be well documented and easy to understand
## CBA
- **Cost**: $0 (personal savings)
- **Benefit**:
    - Provides a library of data structures and algorithms in C++ for practice and future projects
    - Provides a template design for easy use and implementation in other projects
    - Provides a package for easy installation and use of the library
- **Alternatives**:
    - Use existing libraries such as STL, Boost, or other C++ libraries
- **Risks**:
    - Project may have bugs or incomplete features
    - Project may not be completed within the 2 month timeframe
## Roadmap
### Algorithms
- List search algorithms
    - Linear Search
    - Binary Search
    - Fibonacci Search
- List sort algorithms
    - Selection Sort
    - Bubble Sort
    - Insertion Sort
    - Quick Sort
    - Recursive Merge Sort
    - Multithreaded Merge Sort
- Graph search algorithms
    - Breadth-First Search (BFS)
    - Depth-First Search (DFS)
    - Dijkstra's Algorithm
    - Kruskal's Algorithm
### Data Structures
- Linear Data Structures
    - Doubly Linked List
    - FIFO Queue
    - LIFO Stack
- Trees
    - Binary Tree
    - Binary Search Tree
    - Binary Indexed Tree
    - AVL Tree
    - Red Black Tree
- Graphs
    - Undirected Graph
    - Directed Graph
- Hash Table
- Heap
### Testing
- Unit test for all data structures and algorithms
- Integration test for package usability
- Benchmark testing for time and memory complexity of each algorithm
### Package Installation
- Create a header-only library
- Provide build instructions
- Installable package for easy installation of library and testing code
