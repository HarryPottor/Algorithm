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
void Merge(int source[], int temp[], int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i != mid+1 && j != end+1)
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

	while (i != mid+1)
	{
		temp[k++] = source[i++];
	}

	while (j != end+1)
	{
		temp[k++] = source[j++];
	}

	for (int i = 0; i < end+1; i++)
	{
		source[i] = temp[i];
	}

}


void MergeSort(int arr[], int tmp[], int start, int end)
{
	cout << "start = " << start << " end = " << end << endl;
	int mid;
	while (start < end)
	{
		cout << "------------------------" << start << ":" << end << endl;
		mid = (start + end) / 2;
		MergeSort(arr, tmp, start, mid);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		MergeSort(arr, tmp, mid+1, end);
		//Merge(arr, tmp, start, mid, end);
	}

	cout << "==========================" << endl;
}



int main()
{
	int s1[] = {1,3,5,7,9,11,  2,4,6,8,10, 11 };
	int len1 = sizeof(s1) / sizeof(int);
	int *t = new int[len1];
	MergeSort(s1, t, 0, len1-1);
	show(s1, len1);



	system("pause");
	return 0;
}