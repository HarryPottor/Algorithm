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

void QuickSort(int arr[], int left, int right)
{
	cout << "left = " << left << " right= " << right << endl;
	if (left >= right)
	{
		return;
	}
	//注意这里一定保存一份数据
	int first = left;
	int last = right;
	int x = arr[first];
	
	while (last >first)
	{
		//注意这里 一定要带着=号，不然遇到相同的数字，前后都不收，则会死循环。
		//4******4*******4**，会卡死在后边的两个4
		while (last >first && arr[last] >= x)
		{
			last--;
		}
		arr[first] = arr[last];

		while (last > first && arr[first] <= x)
		{
			first++;
		}
		arr[last] = arr[first];
	}
	arr[first] = x;
	show(arr, 8);

	QuickSort(arr, left, first-1);
	QuickSort(arr, first+1, right);
}

int main()
{

	int arr[] = { 2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, len-1);
	show(arr, len);
	system("pause");
	return 0;
}