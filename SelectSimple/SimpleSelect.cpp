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
	//��Ϊ����������ȣ���ˣ�����һ���ǲ��ñȵģ�
	//����3��������ֻҪ2��ѭ���ͺã��ҵ�����С�ʹ�С�ģ�ʣ�µ����������ġ�
	for (int i = 0; i < len-1; i++)
	{
		//�ҳ���С�� ���
		int index = i;
		//��ΪindexΪi�ˣ� ��ˣ�j���Դ�i+1��ʼ
		//��Ϊÿ��ѭ��ͷ�������Ѿ������ã���ˣ�ͷ�ڲ��ϵ����̡�
		for ( int j= i +1; j< len; j++)
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		//����С��ŵ�ֵ �� ǰͷ��ֵ���н�����
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

//��Ԫѡ������ͬʱѡ��������С��
void DloubleSimpleSelect(int arr[], int len)
{
	//������Ϊ��ͬʱѡ������ã�������ѭ������һ�롣
	//�������飬����5����ѭ��2�Σ��м���������� �жϣ���Ϊѡ����ĸ�����û���������϶������м�
	//ż�����飬����6����ѭ��3�Σ�6�������жϵ��ˡ�
	for (int i = 0; i < len/2; i++)
	{
		int min = i;
		int max = i;
		//��Ϊͬʱ���� ͷ��β����ˣ�ÿ��ѭ���ķ�Χ��ͷ��β��������һ����
		//��Ϊmin��max���Ǵ�i��ʼ�ģ����j���Դ�i+1��ʼ��
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
		//�����Сֵλ�ò��� ͷ��λ�ã�����н���
		if (min != i)
		{
			int t = arr[min];
			arr[min] = arr[i];
			arr[i] = t;
		}
		//������ֵλ����ͷ��λ�ã���ʱ �����ϲ���������ֵ���Ѿ���������min��λ�ô��������Ҫ��������max
		if (max == i)
		{
			max = min;
		}
		//������ֵλ�� ����β��λ�ã�����н�����
		if (max != len-i-1)
		{
			int t = arr[max];
			arr[max] = arr[len - i - 1];
			arr[len - i - 1] = t;
		}


		show(arr, len);
	}

}