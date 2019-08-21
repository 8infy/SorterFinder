# SorterFinder
A header-only library, which sorts your arrays with all kinds of different sorting algorithms. Also supports some searching algorithms + union/intersection. Intended as an educational tool. Feel free to change/use the code however you want.
---
## Each sorting member function is available in 4 overloads 
-   `SorterFinder::QuickSort(std::vector<T>& vec)` -> Takes in a vector of type T.
-   `SorterFinder::QuickSort(std::vector<T>& vec, Pred predicate)` -> Takes in a vector of type T, as well as a predicate (function/functor/lambda/any callable).
-   `SorterFinder::QuickSort(T* array, size_t size)` -> Takes in an array and its corresponding size.
-   `SorterFinder::QuickSort(T* array, size_t size, Pred predicate)` -> Takes in an array and its corresponding size, as well as a predicate (function/functor/lambda/any callable).
---
## Note: All sorting functions do the sorting in ascending order by default unless you provide a predicate of your own.
## Example of a predicate
`bool descending(int x, int y) { return x > y; }`    
`myVec` before sorting: 1, 2, 3.  
`SorterFinder::QuickSort(myVec, descending);`  
`myVec` after sorting: 3, 2, 1.

---
## Currently supported sorting algorithms
-   `SorterFinder::QuickSort(...)` -> Recursive quick sort, average time complexity: O(n(log n)), space complexity O(log n).
-   `SorterFinder::MergeSort(...)` -> Recursive merge sort, average time complexity: O(n(log n)), space complexity O(n).
-   `SorterFinder::ShellSort(...)` -> Shell sort, average time complexity: O(n(log n)^2), space complexity O(1).
-   `SorterFinder::InsertionSort(...)` -> Insertion sort, average time complexity: O(n^2), space complexity O(1).
-   `SorterFinder::SelectionSort(...)` -> Selection sort, average time complexity: O(n^2), space complexity O(1).
-   `SorterFinder::BubbleSort(...)` -> Bubble sort, average time complexity: O(n^2), space complexity O(1).
## Searching algortihms
-   `SorterFinder::BinarySearch(...)` -> Binary search, average time complexity: O(log n), space complexity O(1). Only works on sorted arrays/vectors.
## Intersection/Union
-   `SorterFinder::FindUnion(...)` -> Finds the union of two sorted arrays/vectors. Returns the result in a vector. Time complexity: O(n).
-   `SorterFinder::FindIntersection(...)` -> Finds the intersection of two sorted arrays/vectors. Returns the result in a vector. Time complexity: O(n).
