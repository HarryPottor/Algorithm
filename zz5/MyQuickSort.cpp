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
void quicksort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int f = left;
	int l = right;
	int x = arr[f];
	while (f < l)
	{
		while (f < l && arr[l] >= x)
		{
			l--;
		}
		arr[f] = arr[l];
		while (f<l && arr[f] <= x)
		{
			f++;
		}
		arr[l] = arr[f];

	}
	arr[f] = x;

	quicksort(arr, left, f - 1);
	quicksort(arr, f + 1, right);
}




int main()
{
	int arr[] = { 3,4,5,1,5,4,3,7,9,6,5,32,99 };
	int len = sizeof(arr) / sizeof(int);
	quicksort(arr, 0, len - 1);
	show(arr, len);

	system("pause");
	return 0;
}