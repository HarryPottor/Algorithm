//主旨思想是：将整个数组划分为2段，在分为4段，在分为8段
//使用的方法是： mid = (start + end)/2,前一段是 [start, mid] 后一段是[mid+1, end], 
//然后再进行递归，把 (start, mid) (mid+1, end) 传递给(start, end);
//结束条件是start < end;

//在分为两段后，将其进行排序，合并成一段。
//例如          [0,1,2,3,4,5] 分为
//              [0,1,2]  [3,4,5] *5再分为
//          [0,1][2,2]*2  [3,4][5,5]*4
//   [0,0][1,1]*1         [3,3][4,4]*3


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
//将两个 拍好序的数组，归并为一个数组。
//这里的两个数组，其实是一个数组的 前后两段，以mid分开的两段。
void Merge(int source[], int temp[], int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i != mid + 1 && j != end + 1)
	{
		if (source[i] > source[j])
		{
			temp[k++] = source[j++];
		}
		else
		{
			temp[k++] = source[i++];
		}
	}

	while (i != mid + 1)
	{
		temp[k++] = source[i++];
	}

	while (j != end + 1)
	{
		temp[k++] = source[j++];
	}

	for (int i = 0; i < end + 1; i++)
	{
		source[i] = temp[i];
	}

}


void MergeSort(int arr[], int tmp[], int start, int end)
{
	int mid;
	//这里！！！！！！！！！！
	//是if，不是while，如果是while，执行完00，11，后，会回到循环继续执行00，11。进行死循环
	if (start < end)
	{
		mid = (start + end) / 2;
		MergeSort(arr, tmp, start, mid); //0，0
		MergeSort(arr, tmp, mid + 1, end);//1，1
		Merge(arr, tmp, start, mid, end);
	}
}

int main()
{
	int s1[] = { 1,3,5,7,9,11,  2,4,6,8,10, 11 };
	int len1 = sizeof(s1) / sizeof(int);
	int *t = new int[len1];
	MergeSort(s1, t, 0, len1 - 1);
	show(s1, len1);



	system("pause");
	return 0;
}