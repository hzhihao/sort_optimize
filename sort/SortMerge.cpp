#include "stdafx.h"
#include "SortMerge.h"


SortMerge::SortMerge()
{
}


SortMerge::~SortMerge()
{
}
/*
* ��һ�������е�����������������ϲ���һ��
*
* ����˵����
*     a -- ���������������������
*     start -- ��1�������������ʼ��ַ��
*     mid   -- ��1����������Ľ�����ַ��Ҳ�ǵ�2�������������ʼ��ַ��
*     end   -- ��2����������Ľ�����ַ��
*/
void SortMerge::merge(int a[], int start, int mid, int end)
{
	int *tmp = (int *)malloc((end - start + 1) * sizeof(int));    // tmp�ǻ���2������������ʱ����
	int i = start;            // ��1��������������
	int j = mid + 1;        // ��2��������������
	int k = 0;                // ��ʱ���������

	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}

	while (i <= mid)
		tmp[k++] = a[i++];

	while (j <= end)
		tmp[k++] = a[j++];

	// ��������Ԫ�أ�ȫ�������ϵ�����a�С�
	for (i = 0; i < k; i++)
		a[start + i] = tmp[i];

	free(tmp);
}

/*
* �鲢����(��������)
*
* ����˵����
*     a -- �����������
*     start -- �������ʼ��ַ
*     endi -- ����Ľ�����ַ
*/
void SortMerge::merge_sort_up2down(int a[], int start, int end)
{
	if (a == NULL || start >= end)
		return;

	int mid = (end + start) / 2;
	merge_sort_up2down(a, start, mid); // �ݹ�����a[start...mid]
	merge_sort_up2down(a, mid + 1, end); // �ݹ�����a[mid+1...end]

										 // a[start...mid] �� a[mid...end]����������ռ䣬
										 // �����������һ������ռ�a[start...end]
	merge(a, start, mid, end);
}
/*
* ������a�����ɴκϲ�������a���ܳ���Ϊlen��������Ϊ���ɸ�����Ϊgap�������飻
*             ��"ÿ2�����ڵ�������" ���кϲ�����
*
* ����˵����
*     a -- �����������
*     len -- ����ĳ���
*     gap -- ������ĳ���
*/
void SortMerge::merge_groups(int a[], int len, int gap)
{
	int i;
	int twolen = 2 * gap;    // �������ڵ�������ĳ���

							 // ��"ÿ2�����ڵ�������" ���кϲ�����
	for (i = 0; i + 2 * gap - 1 < len; i += (2 * gap))
	{
		merge(a, i, i + gap - 1, i + 2 * gap - 1);
	}

	// �� i+gap-1 < len-1����ʣ��һ��������û����ԡ�
	// ����������ϲ���������������С�
	if (i + gap - 1 < len - 1)
	{
		merge(a, i, i + gap - 1, len - 1);
	}
}

/*
* �鲢����(��������)
*
* ����˵����
*     a -- �����������
*     len -- ����ĳ���
*/
void SortMerge::merge_sort_down2up(int a[], int len)
{
	int n;

	if (a == NULL || len <= 0)
		return;

	for (n = 1; n < len; n *= 2)
		merge_groups(a, len, n);
}