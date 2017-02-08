#ifdef hahaha 


#include <iostream>

using namespace std;

void print(int *arr, int count, int index)
{
	cout << index << " : ";
	for (size_t i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void DirectInsert(int *arr, int count)
{
	for (size_t i = 1; i < count; i++)
	{
		if (arr[i] < arr[i-1])
		{
			int x = arr[i];
			arr[i] = arr[i - 1];
			int j = i - 1;
			while (j > 0 && arr[j-1] > x)
			{
				arr[j] = arr[j - 1];
				j--;
				cout << "j = " << j << endl;
			}
			arr[j] = x;
		}
		print(arr, 6, i);
	}
}

void InsertSort(int a[], int n)
{
	for (size_t i = 1; i < n; i++)
	{
		if (a[i] < a[i-1])
		{
			int x = a[i];
			int j;
			for (j = i-1; j >=0&&a[j] >x; --j)
			{
				a[j + 1] = a[j];
			}
			a[j+1] = x;
		}
	}
}


int main()
{
	int arr[6] = {6,3,4,5,1,2};

	DirectInsert(arr, 6);
	cout << "------------------------------------" << endl;
	int arr2[6] = { 6,3,4,5,1,2 };
	InsertSort(arr2, 6);
	
	
	
	print(arr2, 6, 999);

	system("pause");
	return 0;
}
#endif // !1