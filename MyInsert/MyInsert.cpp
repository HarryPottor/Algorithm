#include <iostream>
using namespace std;

void showLine(int arr[], int len, int index);

void InsertSort(int arr[], int len, bool bShell)
{
	int div;
	div = bShell ? (len / 2) : 1;

	for (; div >= 1; div /=2)
	{
		for (int i = div; i < len; i++)
		{

			//------------------这里是 直接插入，设置哨兵----------------------------
			if ((!bShell) && arr[i] < arr[i-div])
			{
				int x = arr[i];
				int j = i - div;
				for (; j>=0 && arr[j] > x; j -= div)
				{
					arr[j + div] = arr[j];
				}
				arr[j + div] = x;
			}
			//----------------------这里是shell插入排序，没有设置哨兵----------------------------
			if (bShell)
			{
				for (int j = i-div; j >=0 && arr[j+div] < arr[j]; j-=div)
				{
					int t = arr[j];
					arr[j] = arr[j + div];
					arr[j + div] = t;
				}

			}
			showLine(arr, len, i);

		}
	}
}

void showLine(int arr[], int len, int index)
{
	cout << index << "th : ";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
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
	int *arr;
	int len;
	cout << "input lenth of arr:";
	cin >> len;
	arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		cout << "input " << i + 1 << "th :";
		cin >> arr[i];
	}
	cout << "source array: ";
	show(arr, len);
	InsertSort(arr, len, true);
	cout << "after sort: ";
	show(arr, len);

	delete[] arr;
	system("pause");
	return 0;
}