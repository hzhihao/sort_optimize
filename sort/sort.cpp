// sort.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"

using namespace std;
void swap(int &a, int &b)
{
	if (&a == &b)
		return;//如果是同一个地址，直接返回
	a ^= b;
	b ^= a;       //相当于b=a
	a ^= b;       //相当于a=b
}

int partition(int arr[], int l, int r) {
	int k = l, pivot = arr[r];
	for (int i = l; i < r; i++)
		if (arr[i] < pivot) 
			swap(arr[i], arr[k++]);
	swap(arr[k], arr[r]);
	return k;
}
//快速排序
void quicksort(int arr[], int l, int r) {
	if (l < r) {
		int pivot = partition(arr, l, r);
		quicksort(arr, l, pivot - 1);
		quicksort(arr, pivot + 1, r);
	}
}
//冒泡排序
void bubble_sort(int data[], int n)  //从小到大排序
{
	int exchange = n - 1;
	while (exchange)
	{
		int bound = exchange;   //限定本趟冒泡的边界
		exchange = 0;       //用于标记是否有交换记录，若有，则记录“下一趟要处理的最后一个位置”
		for (int j = 0; j < bound; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
				exchange = j;
			}
		}
	}
}

int main()
{
	int arr[8] = { 18,20,3,21,8,9,22,12 };
	int arr1[8],arr2[8];
	memcpy(arr1, arr, sizeof(int) * 8);
	memcpy(arr2, arr, sizeof(int) * 8);
	quicksort(arr, 0, 7);
	bubble_sort(arr1, 8);
	sort_STL(arr2,8);

	for (int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
	for (int i = 0; i < 8; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	for (int i = 0; i < 8; i++)
		printf("%d ", arr2[i]);
	printf("\n");

	return 0;
}



