//��shell����ļ����Ϊ1��ʵ����ֱ�Ӳ�������


#include <iostream>
using namespace std;
void show(int *arr, int count);
void ShellInsert(int arr[], int count);
void ShellInsert2(int arr[], int count);
void print(int *arr, int count, int index);
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
	ShellInsert(arr, count);
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

void ShellInsert(int arr[], int len)
{

	for (int div = len/2; div >= 1; div/=2)
	{
		for (int i = div; i < len; i++)
		{
			for (int j = i; j >=div && arr[j] < arr[j-div]; j-=div)
			{
				//��Ϊ���Ա��� ǰ�ߵ�������˳��ģ����ֻҪ��ͣ�Ľ����Ϳ��ԡ�
				//���磬��Ϊ���Ա���4*6*8, ����4*6*8*2����2�Ž�ȥ��ʱ���Ҫ�����ͺ���
				//ǰ����ʲôʱ���ϵģ�i=2ʱ������4*6��i=4ʱ����4*6*8
				int x = arr[j];
				arr[j] = arr[j - div];
				arr[j - div] = x;
				cout << "swap" << endl;
			}
			print(arr, len, i);
		}
		cout << "---------------------------" << endl;

	}

}
//�����shell����
void ShellInsert2(int arr[], int len)
{
	for (int div = len / 2; div >= 1; div /= 2)
	{
		for (int i = div; i < len; i++)
		{
			if (arr[i] < arr[i-div])
			{
				int x = arr[i];
				int j;
				for (j = i-div; j >=0 &&arr[j] > x; j-=div)
				{
					arr[j + div] = arr[j];
				}
				arr[j+div] = x;
				
			}
			print(arr, len, i); 
		}
		cout << "------------div---------------" << div << endl;
	}
}

void print(int *arr, int count, int index)
{
	cout << index << " : ";
	for (size_t i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}