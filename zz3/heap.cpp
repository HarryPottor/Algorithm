#include <iostream>
using namespace std;

void swapval(int *a, int * b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//����������� �ѡ�
//ʵ�ַ�ʽ����ѭ���� ����ת���Ҷ�ӵĸ�������������������С��ֵ����С����
//�ڴ�ѭ���ڲ������������ ���ݶԻ�����Ѷһ����Ǹ�Ҷ����ΪС�����еݹ顣
//Ҳ����˵ ������	a        ��������˶Ի� ��Ϊ��  b      ��a���ڵ��±ߵ������У���Ҫ���¼�⡣��һ���̷����� ��ѭ�����ڲ���
//			      b  c					    a    c
void func(int arr[], int len, int root)
{
	//�����Ǵ�ѭ���ļ�⣬�����ѭ����⵽�� ����-1����ô˵���������ˡ�
	if (root < 0)
	{
		return;
	}
	//��ȡ ��������Ҷ�ӵı�š�
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	
	int min = root;
	//������� Ҷ�� ���������ڣ���Ҫ �Ƚ�������
	if (left < len && right < len)
	{
		min = arr[left] < arr[right] ? left : right;
		min = arr[min] <  arr[root] ? min : root;
		if (min != root)
		{
			swapval(&arr[root], &arr[min]);
		}
	}
	else if (left < len) // ���û����Ҷ�ӣ�ֻ��Ҫ�Ƚ���Ҷ�Ӻ�root
	{
		if (arr[root] > arr[left])
		{
			min = left;
			swapval(&arr[root], &arr[left]);
		}
	}
	//�����������С������root����return���ɡ�
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
	//�������Ϊ1����˵�������������Ѿ��ź��ˡ����ؾ����ˡ�
	if (len == 1)
	{
		return;
	}
	//�������ɶѣ�����������������������������������������������
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		func(arr, len, i);
	}
	//��ͷ��β�Ե�
	int t = arr[len - 1];
	arr[len - 1] = arr[0];
	arr[0] =t;
	//���鳤������1�����еݹ顣
	loopfunc(arr, len - 1);
}


//����˼�룬�������ɶѣ�Ȼ���ͷ����������С��������Ԫ�ص�����
//Ȼ���ʣ�µ������ɶѣ��ڰ�ͷ����������С��������Ԫ�ص�����
//ֱ�����鳤��Ϊ1��ʱ��
int main()
{
	const int len = 9;
	int arr[len] = { 19,10,32,47,5,46,32,8,79 };

	loopfunc(arr, len);

	show(arr, len);

	system("pause");
	return 0;
}
