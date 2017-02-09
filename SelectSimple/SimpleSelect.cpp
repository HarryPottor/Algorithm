#include<iostream>
using namespace std;

void SimpleSelect(int arr[], int len);
void DloubleSimpleSelect(int arr[], int len);
void show(int arr[], int len);


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
	//DloubleSimpleSelect(arr, len);
	SimpleSelect(arr, len);
	cout << "after sort: ";
	show(arr, len);



	system("pause");
	return 0;
}

void SimpleSelect(int arr[], int len)
{
	//因为总是两两相比，因此，总有一个是不用比的，
	//例如3个数排序，只要2次循环就好，找到了最小和次小的，剩下的数就是最大的。
	for (int i = 0; i < len-1; i++)
	{
		//找出最小的 标号
		int index = i;
		//因为index为i了， 因此，j可以从i+1开始
		//因为每次循环头的数据已经被设置，因此，头在不断的缩短。
		for ( int j= i +1; j< len; j++)
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		//将最小标号的值 与 前头的值进行交换。
		if (index != i)
		{
			int t = arr[index];
			arr[index] = arr[i];
			arr[i] = t;
		}
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

//二元选择排序，同时选出最大和最小。
void DloubleSimpleSelect(int arr[], int len)
{
	//这里因为是同时选择和设置，因此外层循环减少一半。
	//奇数数组，例如5，可循环2次，中间的数可跳过 判断，因为选择的四个数中没有它，它肯定是在中间
	//偶数数组，例如6，可循环3次，6个数都判断到了。
	for (int i = 0; i < len/2; i++)
	{
		int min = i;
		int max = i;
		//因为同时设置 头与尾，因此，每次循环的范围，头与尾都将缩进一个。
		//因为min和max都是从i开始的，因此j可以从i+1开始。
		for (int j = i+1; j < len -i; j++)
		{
			if (arr[j] > arr[max])
			{
				max = j;
				continue;
			}
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		//如果最小值位置不在 头的位置，则进行交换
		if (min != i)
		{
			int t = arr[min];
			arr[min] = arr[i];
			arr[i] = t;
		}
		//如果最大值位置在头的位置，此时 经过上步，最大的数值，已经交换到了min的位置处，因此需要重新设置max
		if (max == i)
		{
			max = min;
		}
		//如果最大值位置 不在尾的位置，则进行交换。
		if (max != len-i-1)
		{
			int t = arr[max];
			arr[max] = arr[len - i - 1];
			arr[len - i - 1] = t;
		}


		show(arr, len);
	}

}