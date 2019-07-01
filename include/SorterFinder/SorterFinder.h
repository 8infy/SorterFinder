#pragma once

#include <utility>
#include <vector>

class SorterFinder
{
public:

	/*--------------------------------------QUICK SORT OVERLOADS-------------------------------------*/
	template<typename T, typename Pred>
	static void QuickSort(T* array, size_t size, Pred predicate)
	{
		InternalQuickSort(array, 0, size - 1, predicate);
	}

	template<typename T>
	static void QuickSort(T* array, size_t size)
	{
		QuickSort(array, size, [](const T& x, const T& y)
		{
			if (x < y)
				return true;
			else
				return false;
		});
	}

	template<typename T, typename Pred>
	static void QuickSort(std::vector<T>& vec, Pred predicate)
	{
		QuickSort(vec.data(), vec.size(), predicate);
	}

	template<typename T>
	static void QuickSort(std::vector<T>& vec)
	{
		QuickSort(vec.data(), vec.size());
	}
	/*------------------------------------------------------------------------------------------------*/

	/*-------------------------------------MERGE SORT OVERLOADS---------------------------------------*/
	template<typename T, typename Pred>
	static void MergeSort(T* array, size_t size, Pred predicate)
	{
		InternalMergeSort(array, 0, size - 1, predicate);
	}

	template<typename T>
	static void MergeSort(T* array, size_t size)
	{
		MergeSort(array, size, [](const T& x, const T& y)
		{
			if (x < y)
				return true;
			else
				return false;
		});
	}

	template<typename T, typename Pred>
	static void MergeSort(std::vector<T>& vec, Pred predicate)
	{
		MergeSort(vec.data(), vec.size(), predicate);
	}

	template<typename T>
	static void MergeSort(std::vector<T>& vec)
	{
		MergeSort(vec.data(), vec.size());
	}
	/*------------------------------------------------------------------------------------------------*/

	/*-------------------------------------SHELL SORT OVERLOADS---------------------------------------*/
	template<typename T, typename Pred>
	static void ShellSort(T* array, size_t size, Pred predicate)
	{
		InternalShellSort(array, size, predicate);
	}

	template<typename T>
	static void ShellSort(T* array, size_t size)
	{
		ShellSort(array, size, [](const T& x, const T& y)
		{
			if (x < y)
				return true;
			else
				return false;
		});
	}

	template<typename T, typename Pred>
	static void ShellSort(std::vector<T>& vec, Pred predicate)
	{
		ShellSort(vec.data(), vec.size(), predicate);
	}

	template<typename T>
	static void ShellSort(std::vector<T>& vec)
	{
		ShellSort(vec.data(), vec.size());
	}
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------INSERTION SORT OVERLOADS------------------------------------*/
	template<typename T, typename Pred>
	static void InsertionSort(T* array, size_t size, Pred predicate)
	{
		InternalInsertionSort(array, size, predicate);
	}

	template<typename T>
	static void InsertionSort(T* array, size_t size)
	{
		InsertionSort(array, size, [](const T& x, const T& y)
		{
			if (x < y)
				return true;
			else
				return false;
		});
	}

	template<typename T, typename Pred>
	static void InsertionSort(std::vector<T>& vec, Pred predicate)
	{
		InsertionSort(vec.data(), vec.size(), predicate);
	}

	template<typename T>
	static void InsertionSort(std::vector<T>& vec)
	{
		InsertionSort(vec.data(), vec.size());
	}
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------SELECTION SORT OVERLOADS------------------------------------*/
	template<typename T, typename Pred>
	static void SelectionSort(T* array, size_t size, Pred predicate)
	{
		InternalSelectionSort(array, size, predicate);
	}

	template<typename T>
	static void SelectionSort(T* array, size_t size)
	{
		SelectionSort(array, size, [](const T& x, const T& y)
		{
			if (x < y)
				return true;
			else
				return false;
		});
	}

	template<typename T, typename Pred>
	static void SelectionSort(std::vector<T>& vec, Pred predicate)
	{
		SelectionSort(vec.data(), vec.size(), predicate);
	}

	template<typename T>
	static void SelectionSort(std::vector<T>& vec)
	{
		SelectionSort(vec.data(), vec.size());
	}
	/*------------------------------------------------------------------------------------------------*/

	/*----------------------------------------BUBBLE SORT OVERLOADS-----------------------------------*/
	template<typename T, typename Pred>
	static void BubbleSort(T* array, size_t size, Pred predicate)
	{
		InternalBubbleSort(array, size, predicate);
	}

	template<typename T>
	static void BubbleSort(T* array, size_t size)
	{
		BubbleSort(array, size, [](const T& x, const T& y)
		{
			if (x < y)
				return true;
			else
				return false;
		});
	}

	template<typename T, typename Pred>
	static void BubbleSort(std::vector<T>& vec, Pred predicate)
	{
		BubbleSort(vec.data(), vec.size(), predicate);
	}

	template<typename T>
	static void BubbleSort(std::vector<T>& vec)
	{
		BubbleSort(vec.data(), vec.size());
	}
	/*------------------------------------------------------------------------------------------------*/

	/*-------------------------------------BINARY SEARCH OVERLOADS------------------------------------*/
	template<typename T>
	static int BinarySearch(std::vector<T>& vec, const T& target)
	{
		return InternalBinarySearch(vec.data(), vec.size() - 1, target);
	}

	template<typename T>
	static int BinarySearch(T* array, size_t size, const T& target)
	{
		return InternalBinarySearch(array, size - 1, target);
	}
	/*------------------------------------------------------------------------------------------------*/

	/*-------------------------------------FIND UNION OVERLOADS---------------------------------------*/
	template<typename T>
	static std::vector<T> FindUnion(std::vector<T>& vec1, std::vector<T>& vec2)
	{
		return InternalFindUnion(vec1.data(), vec1.size(), vec2.data(), vec2.size());
	}

	template<typename T>
	static std::vector<T> FindUnion(T* array1, size_t size1, T* array2, size_t size2)
	{
		return InternalFindUnion(array1, size1, array2, size2);
	}
	/*------------------------------------------------------------------------------------------------*/

	/*-------------------------------------FIND INTERSECTION OVERLOADS--------------------------------*/
	template<typename T>
	static std::vector<T> FindIntersection(std::vector<T>& vec1, std::vector<T>& vec2)
	{
		return InternalFindIntersection(vec1.data(), vec1.size(), vec2.data(), vec2.size());
	}

	template<typename T>
	static std::vector<T> FindIntersection(T* array1, size_t size1, T* array2, size_t size2)
	{
		return InternalFindIntersection(array1, size1, array2, size2);
	}
	/*------------------------------------------------------------------------------------------------*/

	SorterFinder() = delete;
private:
	/*-----RECURSIVE QUICK SORT (AVERAGE TIME COMPLEXITY: O(N LOG N), SPACE COMPLEXITY: O(LOG N))-----*/
	template<typename T, typename Pred>
	static int InternalPartition(T* array, unsigned int begin, unsigned int end, Pred predicate)
	{
		for (unsigned int i = begin; i < end; i++)
		{
			if (predicate(array[i], array[end]))
			{
				std::swap(array[i], array[begin++]);
			}
		}

		std::swap(array[begin], array[end]);
		return begin;
	}

	template<typename T, typename Pred>
	static void InternalQuickSort(T* array, unsigned int begin, unsigned int end, Pred predicate)
	{
		if (begin < end)
		{
			int pivot = InternalPartition(array, begin, end, predicate);

			InternalQuickSort(array, begin, pivot - 1, predicate);
			InternalQuickSort(array, pivot + 1, end, predicate);
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*-------RECURSIVE MERGE SORT (AVERAGE TIME COMPLEXITY: O(N LOG N), SPACE COMPLEXITY: O(N))-------*/
	template<typename T, typename Pred>
	static void InternalMerge(T* array, unsigned int begin, int middle, unsigned int end, Pred predicate)
	{
		unsigned int leftIndex = 0;
		unsigned int rightIndex = 0;
		unsigned int arrayIndex = begin;

		unsigned int leftArraySize = middle - begin + 1;
		unsigned int rightArraySize = end - middle;

		T* leftArray = new T[leftArraySize];
		T* rightArray = new T[rightArraySize];

		for (unsigned int i = 0; i < leftArraySize; i++)
			leftArray[i] = array[begin + i];
		for (unsigned int i = 0; i < rightArraySize; i++)
			rightArray[i] = array[middle + i + 1];

		while (leftIndex < leftArraySize && rightIndex < rightArraySize)
		{
			if (predicate(leftArray[leftIndex], rightArray[rightIndex]))
				array[arrayIndex++] = leftArray[leftIndex++];
			else
				array[arrayIndex++] = rightArray[rightIndex++];
		}

		while (leftIndex < leftArraySize)
			array[arrayIndex++] = leftArray[leftIndex++];
		while (rightIndex < rightArraySize)
			array[arrayIndex++] = rightArray[rightIndex++];

		delete[] leftArray;
		delete[] rightArray;
	}
	template<typename T, typename Pred>
	static void InternalMergeSort(T* array, unsigned int begin, unsigned int end, Pred predicate)
	{
		if (begin < end)
		{
			int middle = (begin + end) / 2;

			InternalMergeSort(array, begin, middle, predicate);
			InternalMergeSort(array, middle + 1, end, predicate);

			InternalMerge(array, begin, middle, end, predicate);
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*----------SHELL SORT (AVERAGE TIME COMPLEXITY: O(N (LOG N)^2), SPACE COMPLEXITY: O(1))----------*/
	template<typename T, typename Pred>
	static void InternalShellSort(T* array, size_t size, Pred predicate)
	{
		unsigned int j;
		T key;

		for (unsigned int gap = size / 2; gap > 0; gap /= 2)
		{
			for (unsigned int i = gap; i < size; i++)
			{
				j = i;
				key = array[i];

				while (j >= gap && predicate(key, array[j - gap]))
				{
					array[j] = array[j - gap];
					j -= gap;
				}
				array[j] = key;
			}
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*------------INSERTION SORT (AVERAGE TIME COMPLEXITY: O(N^2), SPACE COMPLEXITY: O(1))------------*/
	template<typename T, typename Pred>
	static void InternalInsertionSort(T* array, size_t size, Pred predicate)
	{
		unsigned int j;
		T key;

		for (unsigned int i = 0; i < size; i++)
		{
			j = i;
			key = array[i];

			while (j > 0 && predicate(key, array[j - 1]))
			{
				array[j] = array[j - 1];
				--j;
			}
			array[j] = key;
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*------------SELECTION SORT (AVERAGE TIME COMPLEXITY: O(N^2), SPACE COMPLEXITY: O(1))------------*/
	template<typename T, typename Pred>
	static void InternalSelectionSort(T* array, size_t size, Pred predicate)
	{
		unsigned int lastSortedIndex = 0;
		unsigned int currentMostSuitableIndex = 0;

		while (lastSortedIndex != size - 1)
		{
			for (unsigned int i = lastSortedIndex + 1; i < size; i++)
			{
				if (predicate(array[i], array[currentMostSuitableIndex]))
					currentMostSuitableIndex = i;
			}
			std::swap(array[currentMostSuitableIndex], array[lastSortedIndex]);

			lastSortedIndex++;
			currentMostSuitableIndex = lastSortedIndex;
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*-------------BUBBLE SORT (AVERAGE TIME COMPLEXITY: O(N^2), SPACE COMPLEXITY: O(1))--------------*/
	template<typename T>
	static void InternalBubbleSort(T* array, size_t size)
	{
		bool unsorted = true;
		unsigned int maxSortedIndex = size;

		while (unsorted)
		{
			unsorted = false;

			for (unsigned int i = 1; i < maxSortedIndex; i++)
			{
				if (predicate(array[i], array[i - 1]))
				{
					unsorted = true;
					std::swap(array[i], array[i - 1]);
				}
			}

			maxSortedIndex--;
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------BINARY SEARCH (AVERAGE TIME COMPLEXITY: O(LOG N))-----------------------*/
	template<typename T>
	static int InternalBinarySearch(T* array, size_t size, const T& target)
	{
		int begin = 0;
		int end = (int)size;
		unsigned int middle;

		while (begin <= end)
		{
			middle = (begin + end) / 2;

			if (array[middle] == target)
				return middle;
			else if (array[middle] < target)
				begin = middle + 1;
			else
				end = middle - 1;
		}

		return -1;
	}
	/*------------------------------------------------------------------------------------------------*/

	/*---------------------FINDS THE UNION OF 2 SORTED ARRAYS (LINEAR COMPLEXITY)---------------------*/
	template<typename T>
	static std::vector<T> InternalFindUnion(T* array1, size_t size1, T* array2, size_t size2)
	{
		std::vector<T> result;
		result.reserve(size1 >= size2 ? size1 : size2);

		unsigned int i = 0;
		unsigned int j = 0;

		while (i < size1 && j < size2)
		{
			while (i + 1 < size1 && array1[i] == array1[i + 1])
				i++;
			while (j + 1 < size2 && array2[j] == array2[j + 1])
				j++;

			if (array1[i] < array2[j])
				result.push_back(array1[i++]);
			else if (array2[j] < array1[i])
				result.push_back(array2[j++]);
			else
			{
				result.push_back(array1[i++]);
				j++;
			}
		}

		while (i < size1)
			result.push_back(array1[i++]);
		while (j < size2)
			result.push_back(array2[j++]);

		return result;
	}
	/*------------------------------------------------------------------------------------------------*/

	/*------------------FINDS THE INTERSECTION OF 2 SORTED ARRAYS (LINEAR COMPLEXITY)-----------------*/
	template<typename T>
	static std::vector<T> InternalFindIntersection(T* array1, size_t size1, T* array2, size_t size2)
	{
		std::vector<T> result;

		unsigned int i = 0;
		unsigned int j = 0;

		while (i < size1 && j < size2)
		{
			while (i + 1 < size1 && array1[i] == array1[i + 1])
				i++;
			while (j + 1 < size2 && array2[j] == array2[j + 1])
				j++;

			if (array1[i] < array2[j])
				i++;
			else if (array2[j] < array1[i])
				j++;
			else
			{
				result.push_back(array1[i++]);
				j++;
			}
		}

		return result;
	}
	/*------------------------------------------------------------------------------------------------*/
};