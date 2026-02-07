#define  _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void InsertSort(int* arr, int n)
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

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int* a, int n)
{
	int exchange = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				exchange = 1;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}


//void ShellSort(int* arr, int n) 
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0;i < n - gap;i++)
//		{
//			int end = i;
//			int tmp = arr[end + gap];
//			while (end >= 0)
//			{
//				if (arr[end] > tmp)
//				{
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else {
//					break;
//				}
//			}
//			arr[end + gap] = tmp;
//		}
//	}
//
//}

void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1) {
		//此处gap必须 > 1
		gap = gap/ 3 + 1;
		//以6为例，gap=3、2、1…最后对gap==1，进行直接插入排序，如若条件为gap>=1，那么就会进入死循环
		for (int i = 0;i < n - gap;i++)//注意此处的循环条件，
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp) 
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end+gap] = tmp;
		}
	}
}

void SelectSort(int* arr, int n)
{
	int begin=0;
	int end = n-1;
	while (begin < end) {
		int mini = begin;
		int maxi = begin;//这个刚刚我写成end了，hhhhh
		for (int i = begin + 1;i <= end;i++)
		{
			if (arr[i] > arr[maxi])
				maxi = i;
			if (arr[i] < arr[mini])
				mini = i;
		}
		if (maxi == begin)//此时不仅要交换mini和begin，又要交换maxi和end，也就是交换了两次
			//为了防止这种状况，
		{
			maxi = mini;
		}
		swap(&arr[begin], &arr[mini]);
		swap(&arr[end], &arr[maxi]);
		begin++;
		end--;
	}
}