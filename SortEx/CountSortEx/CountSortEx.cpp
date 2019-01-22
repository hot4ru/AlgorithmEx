// CountSortEx.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "time.h"

using namespace std;

void myCountSort(int* arr,int size, int maxNum)
{
	//maxNum++;

	int* temp1 = new int[maxNum + 1];
	int* temp2 = new int[maxNum + 1];
	memset(temp1, 0, sizeof(int) * (maxNum + 1));
	memset(temp2, 0, sizeof(int) * (maxNum + 1));
	//计数器对应的值+1
	for (int i = 0; i < size; i++)
	{
		temp1[arr[i]] ++;
	}
	//所有的值加上前一个值
	int sum = 0;
	for (int i = 0; i < maxNum + 1; i++)
	{
		sum += temp1[i];
		temp2[i] = sum;
	}

	int* sortedArr = new int[size];
	memset(sortedArr, 0, sizeof(int) * size);
	//找位置
	for (int i = size - 1; i >= 0; i--)
	{
		sortedArr[temp2[arr[i]] - 1] = arr[i];
		temp2[arr[i]] --;
	}
	//copy数组
	for (int i = 0; i < size; i++)
	{
		arr[i] = sortedArr[i];
	}

	delete[] temp1;
	delete[] temp2;
	delete[] sortedArr;
}

int main()
{
	int arr[40] = {1,2,3,2,4,4,10,7,2,1,1,2,3,2,4,4,10,7,2,1,1,2,3,2,4,4,10,7,2,1,1,2,3,2,4,4,10,7,2,1};
	clock_t cBegin, cFinish;
	cBegin = clock();
	myCountSort(arr, 40, 10);
	cFinish = clock();
	cout << "time used: " << cFinish - cBegin << endl;
	for (int i = 0; i < 40; i++)
	{
		cout << arr[i] << "\n";
	}

    std::cout << "Hello World!\n"; 
}


