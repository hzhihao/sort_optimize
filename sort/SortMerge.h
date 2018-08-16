#pragma once
//πÈ≤¢≈≈–Ú
class SortMerge
{
public:
	SortMerge();
	~SortMerge();
	void merge(int a[], int start, int mid, int end);
	void merge_sort_up2down(int a[], int start, int end);
	void merge_groups(int a[], int len, int gap);
	void merge_sort_down2up(int a[], int len);
};

