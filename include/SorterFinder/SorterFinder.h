#pragma once

#include <utility>
#include <vector>

class SorterFinder
{
public:
	template<typename T>
	static void QuickSort(std::vector<T>& vec)
	{
		InternalQuickSort(vec, 0, vec.size() - 1);
	}

	template<typename T>
	static void MergeSort(std::vector<T>& vec)
	{
		InternalMergeSort(vec, 0, vec.size() - 1);
	}

	template<typename T>
	static void ShellSort(std::vector<T>& vec)
	{
		InternalShellSort(vec);
	}

	template<typename T>
	static void InsertionSort(std::vector<T>& vec)
	{
		InternalInsertionSort(vec);
	}

	template<typename T>
	static void SelectionSort(std::vector<T>& vec)
	{
		InternalSelectionSort(vec);
	}

	template<typename T>
	static void BubbleSort(std::vector<T>& vec)
	{
		InternalBubbleSort(vec);
	}

	template<typename T>
	static int BinarySearch(std::vector<T>& vec, const T& target)
	{
		return InternalBinarySearch(vec, target);
	}
private:
	/*---- RECURSIVE QUICK SORT (AVERAGE TIME COMPLEXITY: O(N LOG N), SPACE COMPLEXITY: O(LOG N)) ----*/
	template<typename T>
	static int InternalPartition(std::vector<T>& vec, unsigned int begin, unsigned int end)
	{
		for (int i = begin; i < end; i++)
		{
			if (vec[i] < vec[end])
			{
				std::swap(vec[i], vec[begin++]);
			}
		}

		std::swap(vec[begin], vec[end]);
		return begin;
	}

	template<typename T>
	static void InternalQuickSort(std::vector<T>& vec, unsigned int begin, unsigned int end)
	{
		if (begin < end)
		{
			int pivot = InternalPartition(vec, begin, end);

			InternalQuickSort(vec, begin, pivot - 1);
			InternalQuickSort(vec, pivot + 1, end);
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*----   RECURSIVE MERGE SORT (AVERAGE TIME COMPLEXITY: O(N LOG N), SPACE COMPLEXITY: O(N))   ----*/
	template<typename T>
	static void InternalMerge(std::vector<T>& vec, unsigned int begin, int middle, unsigned int end)
	{
		unsigned int leftIndex = 0;
		unsigned int rightIndex = 0;
		unsigned int vecIndex = begin;

		unsigned int leftArraySize = middle - begin + 1;
		unsigned int rightArraySize = end - middle;

		T* leftArray = new T[leftArraySize];
		T* rightArray = new T[rightArraySize];

		for (unsigned int i = 0; i < leftArraySize; i++)
			leftArray[i] = vec[begin + i];
		for (unsigned int i = 0; i < rightArraySize; i++)
			rightArray[i] = vec[middle + i + 1];

		while (leftIndex < leftArraySize && rightIndex < rightArraySize)
		{
			if (leftArray[leftIndex] <= rightArray[rightIndex])
				vec[vecIndex++] = leftArray[leftIndex++];
			else
				vec[vecIndex++] = rightArray[rightIndex++];
		}

		while (leftIndex < leftArraySize)
			vec[vecIndex++] = leftArray[leftIndex++];
		while (rightIndex < rightArraySize)
			vec[vecIndex++] = rightArray[rightIndex++];

		delete[] leftArray;
		delete[] rightArray;
	}
	template<typename T>
	static void InternalMergeSort(std::vector<T>& vec, unsigned int begin, unsigned int end)
	{
		if (begin < end)
		{
			int middle = (begin + end) / 2;

			InternalMergeSort(vec, begin, middle);
			InternalMergeSort(vec, middle + 1, end);

			InternalMerge(vec, begin, middle, end);
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*----      SHELL SORT (AVERAGE TIME COMPLEXITY: O(N (LOG N)^2), SPACE COMPLEXITY: O(1))      ----*/
	template<typename T>
	static void InternalShellSort(std::vector<T>& vec)
	{
		unsigned int j;
		T key;

		for (unsigned int gap = vec.size() / 2; gap > 0; gap /= 2)
		{
			for (unsigned int i = gap; i < vec.size(); i++)
			{
				j = i;
				key = vec[i];

				while (j >= gap && vec[j - gap] > key)
				{
					vec[j] = vec[j - gap];
					j -= gap;
				}
				vec[j] = key;
			}
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*----        INSERTION SORT (AVERAGE TIME COMPLEXITY: O(N^2), SPACE COMPLEXITY: O(1))        ----*/
	template<typename T>
	static void InternalInsertionSort(std::vector<T>& vec)
	{
		unsigned int j;
		T key;

		for (unsigned int i = 0; i < vec.size(); i++)
		{
			j = i;
			key = vec[i];

			while (j > 0 && vec[j - 1] > key)
			{
				vec[j] = vec[j - 1];
				--j;
			}
			vec[j] = key;
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*----        SELECTION SORT (AVERAGE TIME COMPLEXITY: O(N^2), SPACE COMPLEXITY: O(1))        ----*/
	template<typename T>
	static void InternalSelectionSort(std::vector<T>& vec)
	{
		unsigned int lastSortedIndex = 0;
		unsigned int currentSmallestIndex = 0;

		while (lastSortedIndex != vec.size() - 1)
		{
			for (unsigned int i = lastSortedIndex + 1; i < vec.size(); i++)
			{
				if (vec[i] < vec[currentSmallestIndex])
					currentSmallestIndex = i;
			}
			std::swap(vec[currentSmallestIndex], vec[lastSortedIndex]);

			lastSortedIndex++;
			currentSmallestIndex = lastSortedIndex;
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*----         BUBBLE SORT (AVERAGE TIME COMPLEXITY: O(N^2), SPACE COMPLEXITY: O(1))          ----*/
	template<typename T>
	static void InternalBubbleSort(std::vector<T>& vec)
	{
		bool unsorted = true;
		unsigned int maxSortedIndex = vec.size();

		while (unsorted)
		{
			unsorted = false;

			for (unsigned int i = 1; i < maxSortedIndex; i++)
			{
				if (vec[i] < vec[i - 1])
				{
					unsorted = true;
					std::swap(vec[i], vec[i - 1]);
				}
			}

			maxSortedIndex--;
		}
	}
	/*------------------------------------------------------------------------------------------------*/

	/*----                    BINARY SEARCH (AVERAGE TIME COMPLEXITY: O(LOG N)                    ----*/
	template<typename T>
	static int InternalBinarySearch(std::vector<T>& vec, const T& target)
	{
		int begin = 0;
		int end = (int)vec.size() - 1;
		unsigned int middle;

		while (begin <= end)
		{
			middle = (begin + end) / 2;

			if (vec[middle] == target)
				return middle;
			else if (vec[middle] < target)
				begin = middle + 1;
			else
				end = middle - 1;
		}

		return -1;
	}
	/*------------------------------------------------------------------------------------------------*/
};