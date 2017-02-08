#include <iostream>
using namespace std;
void show(int *arr, int count);
void DirectInsert(int arr[], int count);

int main()
{
	int count;
	cout << "input array count: ";
	cin >> count;

	int *arr;
	arr = new int[count];

	for (int i = 0; i < count; i++)
	{
		cout << "input " << i + 1 << "th :";
		cin >> arr[i];
	}
	show(arr, count);
	cout << "----------after sort -------------" << endl;
	DirectInsert(arr, count);
	show(arr, count);
	system("pause");
	return 0;
}

void show(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void DirectInsert(int arr[], int count)
{
	for (int i = 1; i < count; i++)
	{
		if (arr[i] > arr[i-1])
		{
			int x = arr[i];
			int j;
			for (j = i-1; j >=0 && arr[j] < x; --j)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = x;
		}
	}
}