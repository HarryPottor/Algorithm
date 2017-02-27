#include <iostream>
using namespace std;


void HeapAdjust(int arr[], int mid, int len);

void QuickSort(int arr[], int left, int right);

void DoMarge(int arr[], int temp[], int left,int mid, int right);
void BeforeMarge(int arr[], int temp[], int len, int left, int right);
int main()
{

	int arr[] = { 4,23,2,6,4,3,2,7,9,0,9 };
	int len = sizeof(arr) / sizeof(int);
	
	/* 直接插入排序
	for (int i = 1; i < len; i++)
	{
		int x = arr[i];
		int j = i-1;
		for (; j >=0 && arr[j] > x ; j--)
		{
			arr[j + 1] = arr[j];
		}

		arr[j + 1] = x;
	}
	*/

	//希尔排序
	/*
	for (int div = len/2; div > 0 ; div /=2)
	{
		
		for (int i = div; i < len; i++)
		{
			int j = i - div;
			for (; arr[j] >arr[j+div]; j-=div)
			{
				int t = arr[j];
				arr[j] = arr[j + div];
				arr[j+div] = t;
			}

		}

	}
	*/

	//简单选择排序，找出最小的,和前头的0，1，2，3.。。位置交换
	/*
	for (int i = 1; i < len; i++)
	{
		int min = i-1;
		for (int j = i; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (arr[min] < arr[i-1])
		{
			int t = arr[min];
			arr[min] = arr[i - 1];
			arr[i - 1] = t;
		}
	}
	*/

	//堆排序
	/*
	for (int i = len/2-1; i >= 0; i--)
	{
		HeapAdjust(arr, i, len);
	}
	for (int i = len-1; i >= 0 ; i--)
	{
		int t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;

		HeapAdjust(arr, 0, i);
	}
	*/

	//冒泡排序
	/*
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 1; j < len - i; j++)
		{
			if (arr[j-1] > arr[j])
			{
				int t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
			}
		}
	}
	*/
	//快速排序
	/*
	QuickSort(arr, 0, len - 1);
	*/

	//归并排序
	int *temp = new int[len];
	BeforeMarge(arr, temp, len, 0, len - 1);
	delete[] temp;


	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
	system("pause");
	return 0;
}

void HeapAdjust(int arr[], int mid, int len)
{
	int child;
	for ( ; 2 * mid + 1 < len; mid = child)
	{
		child = 2 * mid + 1;
		if ((child < len - 1) &&(arr[child+1] < arr[child]))
		{
			child++;
		}

		if (arr[child] < arr[mid])
		{
			int t = arr[child];
			arr[child] = arr[mid];
			arr[mid] = t;
		}
		else
		{
			break;
		}
	}
}

void QuickSort(int arr[], int first, int last)
{
	if (first >= last)
	{
		return;
	}
	int left = first;
	int right = last;
	int x = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= x)
		{
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] < x)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = x;
	QuickSort(arr, first, left - 1);
	QuickSort(arr, right + 1, last);
}

void DoMarge(int arr[], int temp[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i!= mid+1 && j != right+1)
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
	while (i!=mid+1)
	{
		temp[k++] = arr[i++];
	}
	while (j!=right+1)
	{
		temp[k++] = arr[j++];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
}

void BeforeMarge(int arr[], int temp[], int len, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	BeforeMarge(arr, temp, len, left, mid);
	BeforeMarge(arr, temp, len, mid+1, right);
	DoMarge(arr, temp, left, mid, right);
}
