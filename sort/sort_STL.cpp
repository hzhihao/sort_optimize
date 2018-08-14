#include "stdafx.h"
using namespace std;
/*
2018.8.14
C++模版库sort
https://www.cnblogs.com/AlvinZH/p/6784862.html?utm_source=itdadao&utm_medium=referral
*/

//自定义sort的第三个参数（比较函数）
bool cmp1(int a, int b)//int为数组数据类型
{
	return a<b;//默认的升序排列
			   //return a>b;//降序排列
}

//情况一：在结构体内部重载		注意：一定要重载<运算符，因为系统默认是降序，用的是<运算符。
typedef struct Student {
	int id;
	string name;
	double grade;

	/*bool operator<(const Student& s)
	{
		return id>s.id;//降序排列
					   //return id<s.id;//升序排列
	}*/
};


//情况二：在外部重载
bool operator<(const Student& s1, const Student& s2)
{
	return s1.id>s2.id;//降序排列
					   //return s1.id<s2.id;//升序排列
}

void sort_STL(int arr[], int length)
{
	/*
	调用标准库函数
	升序：sort(begin,end,less<data-type>())
	降序：sort(begin,end,greater<data-type>())	*/
	sort(arr, arr + length, cmp1);
	//sort(arr2, arr2 + 8, less<int>());
	//sort(arr2, arr2 + 8,greater<int>());

	//结构体排序
	//vector<Student> V;
	//sort(V.begin(), V.end());
}
