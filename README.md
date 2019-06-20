# SorterFinder
A header-only library, which sorts your arrays with all kinds of different sorting algorithms. Also supports some searching algorithms + union/intersection. Intended as an educational tool. Feel free to change/use the code however you want.
---
## Note: All public member functions are available in 2 overloads: 
- `ExampleFunction(std::vector<T>& vec)` -> Takes in a vector of type T.
- `ExampleFunction(T* array, size_t size)` -> Takes in an array and its corresponding size.
## Currently supported sorting algorithms:
- `SorterFinder::QuickSort(...)` -> Recursive quick sort, average time complexity: O(n(log n)), space complexity O(log n).
- `SorterFinder::MergeSort(...)` -> Recursive merge sort, average time complexity: O(n(log n)), space complexity O(n).
- `SorterFinder::ShellSort(...)` -> Shell sort, average time complexity: O(n(log n)^2), space complexity O(1).
- `SorterFinder::InsertionSort(...)` -> Insertion sort, average time complexity: O(n^2), space complexity O(1).
- `SorterFinder::SelectionSort(...)` -> Selection sort, average time complexity: O(n^2), space complexity O(1).
- `SorterFinder::BubbleSort(...)` -> Bubble sort, average time complexity: O(n^2), space complexity O(1).
## Searchin algortihms:
- `SorterFinder::BinarySearch(...)` -> Binary search, average time complexity: O(log n), space complexity O(1). Only works on sorted arrays/vectors.
## Intersection/Union:
- `SorterFinder::FindUnion(...)` -> Finds the union of two sorted arrays/vectors. Returns the result in a vector. Time complexity: O(n).
- `SorterFinder::FindIntersection(...)` -> Finds the intersection of two sorted arrays/vectors. Returns the result in a vector. Time complexity: O(n).
