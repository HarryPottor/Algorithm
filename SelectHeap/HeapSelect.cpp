#include<iostream>

using namespace std;

void show(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//变成堆
void HeapAdjust(int arr[], int mid, int len)
{
	int child;
	//调整mid为顶的三角，如果与child进行了交换，则需要调整child为顶的三角
	//如果叶子超出了len，则说明没有叶子， 则退出循环。
	//或者如果 无需调整，也退出循环。
	for (; 2* mid +1 < len; mid = child)
	{
		child = 2 * mid + 1;
		//因为是完全二叉树，可以这样判断是否有右叶子。
		if (child < len - 1 && arr[child+1] < arr[child])
		{
			++child;
		}
		else
		{
			//没有 右叶子
		}

		if (arr[child] < arr[mid])
		{
			int tmp = arr[mid];
			arr[mid] = arr[child];
			arr[child] = tmp;
		}
		else
		{
			break;
		}

	}
}

void HeapSort(int arr[], int len)
{
	for (int i = len/2 -1; i >=0 ; i--)
	{
		//第一次从 有叶子的最后的根开始， 整理成堆。组成一次之后，只要从root开始就行了，首尾互换后，从root开始调整。
		HeapAdjust(arr, i, len);
	}

	show(arr, len);
	for (int i = len -1; i>0 ; i--)
	{
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		show(arr, len);
		//首尾互换后，从root调整一次即可。
		HeapAdjust(arr, 0, i);
	}
}

int main()
{
	int i;
	int num[] = { 1,10,3,4,5,6,7,8,9 };
	HeapSort(num, sizeof(num) / sizeof(int));
	for (i = 0; i<sizeof(num) / sizeof(int); i++)
	{
		printf("%d ", num[i]);
	}
	printf("\nok\n");

	system("pause");
	return 0;
}