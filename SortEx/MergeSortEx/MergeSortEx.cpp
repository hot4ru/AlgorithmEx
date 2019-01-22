// MergeSortEx.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

const int SIZE = 8;
//将数组arr[start--mid]和arr[mid+1--end]重新排序
void merge(int arr[], const int start, const int mid, const int end)
{
	int size = end - start + 1;
	int* temp = new int[size];
	for (int i = 0, j = start, k = mid + 1; i < size; i++)
	{
		if (j > mid && k <= end)
		{
			temp[i] = arr[k++];
		}
		else if (k > end && j <= mid)
		{
			temp[i] = arr[j++];
		}
		else if (arr[j] < arr[k])
		{
			temp[i] = arr[j++];
		}
		else
		{
			temp[i] = arr[k++];
		} 

	}

	for (int i = 0; i < size; i++)
	{
		arr[i + start] = temp[i];
	}

	delete[] temp;
}


void myMergeSort(int arr[], const int start, const int end)
{
	int mid = (end + start) / 2;
	if (mid - start + 1 > 1)
	{
		myMergeSort(arr, start, mid);
		myMergeSort(arr, mid + 1, end);
	}
	merge(arr, start, mid, end);
}

int main()
{
	int iarr[] = { 3,41,52,26,38,57,9,49 };
	//int iarr[] = { 1,41,52,100,2,3,7,49 };
	//myMergeSort(iarr, SIZE);
	myMergeSort(iarr, 0, 7);

	for (int i = 0; i < SIZE; i++)
	{
		cout << iarr[i] << endl;
	}
    std::cout << "Hello World!\n"; 
}

