//��ּ˼���ǣ����������黮��Ϊ2�Σ��ڷ�Ϊ4�Σ��ڷ�Ϊ8��
//ʹ�õķ����ǣ� mid = (start + end)/2,ǰһ���� [start, mid] ��һ����[mid+1, end], 
//Ȼ���ٽ��еݹ飬�� (start, mid) (mid+1, end) ���ݸ�(start, end);
//����������start < end;

//�ڷ�Ϊ���κ󣬽���������򣬺ϲ���һ�Ρ�
//����          [0,1,2,3,4,5] ��Ϊ
//              [0,1,2]  [3,4,5] *5�ٷ�Ϊ
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
//������ �ĺ�������飬�鲢Ϊһ�����顣
//������������飬��ʵ��һ������� ǰ�����Σ���mid�ֿ������Ρ�
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
	//���������������������
	//��if������while�������while��ִ����00��11���󣬻�ص�ѭ������ִ��00��11��������ѭ��
	if (start < end)
	{
		mid = (start + end) / 2;
		MergeSort(arr, tmp, start, mid); //0��0
		MergeSort(arr, tmp, mid + 1, end);//1��1
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