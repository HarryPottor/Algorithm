#include <iostream>
using namespace std;

void show(int arr[], int len);

void myswap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


void HeapAdjust(int arr[], int root, int len)
{
	int child;
	for (; root*2+1 < len; root = child)
	{
		child = 2 * root + 1;
		if (child < len - 1 && arr[child+1] > arr[child])
		{
			child++;
		}

		if (arr[child] > arr[root])
		{
			myswap(&arr[child], &arr[root]);
		}
		else
		{
			break;
		}
	}
	show(arr, len);
}

void HeapSort(int arr[], int len)
{
	for (int i = len/2-1; i >= 0; i--)
	{
		HeapAdjust(arr, i, len);
	}
	for (int i = len-1; i >=0 ; i--)
	{
		myswap(arr + i, arr);
		HeapAdjust(arr, 0, i);
	}
}

void show(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = {4444,1233,4565,322,227,113,894,73,12,43,25,78};

	int len = sizeof(arr) / sizeof(int);
	HeapSort(arr, len);
	show(arr, len);
	


	system("pause");
	return 0;
}