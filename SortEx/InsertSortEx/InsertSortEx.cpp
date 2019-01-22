// InsertSortEx.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 7;

int length(int arr[])
{
	return (NULL == arr) ? 0 : (sizeof(arr) / sizeof(*arr));
}

void myInsertSort(int arr[],const int size)
{
	if (size < 2)//length(arr) < 2)
	{
		return;
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			int temp = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > temp)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = temp;
		}
	}
}

void myInsertSort2(int arr[], const int size)
{
	if (size < 2)
	{
		return;
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			int temp = i;
			int j = i - 1;
			while (j >= 0 && arr[j] < temp)//diffrence: arr[j] < temp ~ arr[j] > temp
			{
				arr[j + 1] = arr[j];
				//arr[j] = temp;
				j--;
			}
			arr[j + 1] = temp;
		}
	}
}

template<typename T>
void mySwap(T& first, T& second)
{
	T temp;
	temp = first;
	first = second;
	second = temp;
}

void mySelectSort(int arr[], const int size)
{
	if (size < 2)
	{
		return;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] > arr[j])
				{
					mySwap<int>(arr[i], arr[j]);
				}
			}
		}
	}
}



int main()
{
	//int* pi = (int*)malloc(sizeof(int) * 2);
	//*pi = 1;
	//*(pi+1) = 2;
	//cout << *(pi+1) << endl;

	int i_arr[SIZE] = { 2,4,1,2,6,7,3 };
	mySelectSort(i_arr, SIZE);
	//myInsertSort2(i_arr, SIZE);
	//clock_t t_begin, t_finish;
	//t_begin = clock();
	//myInsertSort(i_arr, SIZE);
	//t_finish = clock();
	//cout << "time used: " << t_finish - t_begin << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i_arr[i] << endl;
	}


    std::cout << "Hello World!\n"; 
}


