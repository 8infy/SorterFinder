#include <iostream>
#include <vector>

#include <SorterFinder/SorterFinder.h>

template<typename T>
void printArray(T* array, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    // ------ QUICKSORT ------
    int unsortedVanillaArray[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    // Quicksorting an unsorted vanilla array
    // First parameter takes in a pointer to the first element
    // Second parameter is the size of the array
    SorterFinder::QuickSort(unsortedVanillaArray, 9);

    std::cout << "Sorted with quicksort:" << std::endl;
    // should print out {1 2 3 4 5 6 7 8 9}
    printArray(unsortedVanillaArray, 9);

    // ------------------------

    // ----- MERGE SORT -------
    std::vector<int> unsortedVector = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    // Merge sorting an unsorted vector
    // Yup, this simple, just give it the vector
    SorterFinder::MergeSort(unsortedVector);

    std::cout << "\nSorted with merge sort:" << std::endl;
    // should print out {1 2 3 4 5 6 7 8 9}
    printArray(unsortedVector.data(), 9);

    // ------------------------

    // ------ SHELL SORT ------
    std::vector<int> unsortedVector1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Shell sorting another unsorted vector
    // This time we give it a predicate so that it does the sorting in ascending order
    SorterFinder::ShellSort(unsortedVector1, [](int x, int y) { return x > y; });

    std::cout << "\nSorted with shell sort:" << std::endl;
    // should print out {9 8 7 6 5 4 3 2 1}
    printArray(unsortedVector1.data(), 9);

    // ------------------------

    // ---- INSERTION SORT ----
    std::vector<int> unsortedVector2 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    // Same thing as last time, just give it the vector
    SorterFinder::InsertionSort(unsortedVector2);

    std::cout << "\nSorted with insertion sort:" << std::endl;
    // should print out {1 2 3 4 5 6 7 8 9}
    printArray(unsortedVector2.data(), 9);

    // ------------------------

    // ---- SELECTION SORT ----
    std::vector<int> unsortedVector3 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    // Insertion sorting the vector
    SorterFinder::InsertionSort(unsortedVector3);

    std::cout << "\nSorted with selection sort:" << std::endl;
    // should print out {1 2 3 4 5 6 7 8 9}
    printArray(unsortedVector3.data(), 9);

    // ------------------------

    // ---- BUBBLE SORT ----
    float* heapAllocatedArray = new float[9];

    for (size_t i = 0; i < 9; i++)
        heapAllocatedArray[i] = 9.0f - static_cast<float>(i);

    // Bubble sorting our heap-allocated array of floats
    SorterFinder::BubbleSort(heapAllocatedArray, 9);

    std::cout << "\nSorted with bubble sort:" << std::endl;
    // should print out {1 2 3 4 5 6 7 8 9}
    printArray(heapAllocatedArray, 9);

    delete[] heapAllocatedArray; // never forget to clean up after yourself
    // ------------------------

    // ---- BINARY SEARCH -----
    std::vector<int> secretVector = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Binary searching the number 5 in our vector
    // Should return the index of number 5 in the vector
    int index = SorterFinder::BinarySearch(secretVector, 5);

    // index1 is -1 because the number 25 is not present in the vector
    int index1 = SorterFinder::BinarySearch(secretVector, 25);

    std::cout << "\nNumber 5 is at index: " << index << ", number 25 is at index: " << index1 << std::endl;

    // ------------------------

    // ----- INTERSECTION -----
    std::vector<int> firstVector = { 1, 2, 3, 4, 4, 4, 4, 4, 6, 999, 9999999, 12345678 };
    std::vector<int> secondVector = { 1, 2, 4, 4, 4, 4, 6, 7, 7, 7, 999, 234234234 };

    // Find the intersection of two vectors and returns the resulting vector (also works with vanilla arrays)
    std::vector<int> intersection = SorterFinder::FindIntersection(firstVector, secondVector);

    std::cout << "\nThe intersection of two vectors is:" << std::endl;
    printArray(intersection.data(), intersection.size());

    // ------------------------

    // ----- UNION -----
    std::vector<int> firstVector1 = { 1, 2, 3, 4, 4, 4, 4, 4, 6, 999, 9999999, 12345678 };
    std::vector<int> secondVector1 = { 1, 2, 4, 4, 4, 4, 6, 7, 7, 7, 999, 234234234 };

    // Find the union of two vectors and returns the resulting vector (also works with vanilla arrays)
    std::vector<int> myUnion = SorterFinder::FindUnion(firstVector, secondVector);

    std::cout << "\nThe union of two vectors is:" << std::endl;
    printArray(myUnion.data(), myUnion.size());

    // ------------------------

    std::cin.get();
    return 0;
}
