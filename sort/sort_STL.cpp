#include "stdafx.h"
using namespace std;
/*
2018.8.14
C++ģ���sort
https://www.cnblogs.com/AlvinZH/p/6784862.html?utm_source=itdadao&utm_medium=referral
*/

//�Զ���sort�ĵ������������ȽϺ�����
bool cmp1(int a, int b)//intΪ������������
{
	return a<b;//Ĭ�ϵ���������
			   //return a>b;//��������
}

//���һ���ڽṹ���ڲ�����		ע�⣺һ��Ҫ����<���������ΪϵͳĬ���ǽ����õ���<�������
typedef struct Student {
	int id;
	string name;
	double grade;

	/*bool operator<(const Student& s)
	{
		return id>s.id;//��������
					   //return id<s.id;//��������
	}*/
};


//����������ⲿ����
bool operator<(const Student& s1, const Student& s2)
{
	return s1.id>s2.id;//��������
					   //return s1.id<s2.id;//��������
}

void sort_STL(int arr[], int length)
{
	/*
	���ñ�׼�⺯��
	����sort(begin,end,less<data-type>())
	����sort(begin,end,greater<data-type>())	*/
	sort(arr, arr + length, cmp1);
	//sort(arr2, arr2 + 8, less<int>());
	//sort(arr2, arr2 + 8,greater<int>());

	//�ṹ������
	//vector<Student> V;
	//sort(V.begin(), V.end());
}
