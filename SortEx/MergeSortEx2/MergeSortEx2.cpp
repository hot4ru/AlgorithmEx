// MergeSortEx2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
const int SIZE = 16;

//组合两个已经排好序的数组
//start开始位置
//mid中间位置
//end结束位置
void merge(int *arr, const int start, const int mid, const int end)
{
	int *temp = new int[end - start + 1];
	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	/*
	for (int index = 0; index < k; index++)
	{
		arr[start + index] = temp[index];
	}
	*/
	memcpy(arr + start, temp, k * sizeof(int));

	delete[] temp;
}

void myMergeSort(int *arr, const int start, const int end)
{
	if (NULL == arr || start >= end) return;
	int mid = (start + end) / 2;
	myMergeSort(arr, start, mid);
	myMergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
	
}



int main()
{
	int iarr[16] = { 0,2,4,12,6,1,98,55,34,87,9,34,66,21,67,8 };
	myMergeSort(iarr, 0, 15);
	for (int i = 0; i < 16; i++)
	{
		cout << iarr[i] << endl;
	}
    //std::cout << "Hello World!\n"; 
}

