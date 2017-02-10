#include <iostream>
using namespace std;

void show(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void myswap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void BubbleSort(int arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 1; j < len-i; j++)
		{
			if (arr[j] < arr[j-1])
			{
				myswap(arr + j, arr + j - 1);
			}
		}

	}
}


int main()
{
	int arr[] = { 1,2,67,3,4,1,5,7 };
	int len = sizeof(arr) / sizeof(int);
	BubbleSort(arr, len);
	show(arr, len);

	system("pause");
	return 0;
}