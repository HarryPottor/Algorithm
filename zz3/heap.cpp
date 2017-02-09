#include <iostream>
using namespace std;

void swapval(int *a, int * b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//这里把数组变成 堆。
//实现方式：大循环是 挨个转变带叶子的根，将三角中最大或者最小的值放在小根上
//在大循环内部，如果发生了 数据对换，则把兑换的那个叶子作为小根进行递归。
//也就是说 三角形	a        如果发生了对换 变为了  b      那a所在的下边的三角中，需要重新检测。这一过程发生在 大循环的内部。
//			      b  c					    a    c
void func(int arr[], int len, int root)
{
	//这里是大循环的检测，如果大循环检测到了 根的-1，那么说明检测完毕了。
	if (root < 0)
	{
		return;
	}
	//获取 根的左右叶子的标号。
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	
	int min = root;
	//如果左右 叶子 都在数组内，需要 比较三个数
	if (left < len && right < len)
	{
		min = arr[left] < arr[right] ? left : right;
		min = arr[min] <  arr[root] ? min : root;
		if (min != root)
		{
			swapval(&arr[root], &arr[min]);
		}
	}
	else if (left < len) // 如果没有右叶子，只需要比较左叶子和root
	{
		if (arr[root] > arr[left])
		{
			min = left;
			swapval(&arr[root], &arr[left]);
		}
	}
	//如果三角中最小的仍是root，则return即可。
	if (min == root)
	{
		return;
	}
	func(arr, len, min);
}


void show(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void loopfunc(int arr[], int len)
{
	//如果长度为1，则说明其他的数据已经排好了。返回就行了。
	if (len == 1)
	{
		return;
	}
	//把数组变成堆！！！！！！！！！！！！！！！！！！！！！！！！
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		func(arr, len, i);
	}
	//把头与尾对调
	int t = arr[len - 1];
	arr[len - 1] = arr[0];
	arr[0] =t;
	//数组长度缩短1，进行递归。
	loopfunc(arr, len - 1);
}


//整体思想，把数组变成堆，然后把头（最大或者最小）与最后的元素调换。
//然后把剩下的数组变成堆，在把头（最大或者最小）与最后的元素调换。
//直到数组长度为1的时候。
int main()
{
	const int len = 9;
	int arr[len] = { 19,10,32,47,5,46,32,8,79 };

	loopfunc(arr, len);

	show(arr, len);

	system("pause");
	return 0;
}
