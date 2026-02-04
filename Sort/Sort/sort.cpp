#define  _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void InserSort(int* arr, int n)
{
	for(int i=0;i<n-1;i++)//end可以等于n吗？不可以，因为等于n时，end指向有序数组中的最后一个数据，指向n时说明已经没有待插入数据了，且此时end+1越界，故end最大等于n-1

	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end+1] = arr[end];
				end--;
			}
			else {
				break;
			}	
		}
		arr[end+1] = tmp;//前面一直在判断，跳出while循环后赋值
	}
}