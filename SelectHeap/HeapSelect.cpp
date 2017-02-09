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

//��ɶ�
void HeapAdjust(int arr[], int mid, int len)
{
	int child;
	//����midΪ�������ǣ������child�����˽���������Ҫ����childΪ��������
	//���Ҷ�ӳ�����len����˵��û��Ҷ�ӣ� ���˳�ѭ����
	//������� ���������Ҳ�˳�ѭ����
	for (; 2* mid +1 < len; mid = child)
	{
		child = 2 * mid + 1;
		//��Ϊ����ȫ�����������������ж��Ƿ�����Ҷ�ӡ�
		if (child < len - 1 && arr[child+1] < arr[child])
		{
			++child;
		}
		else
		{
			//û�� ��Ҷ��
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
		//��һ�δ� ��Ҷ�ӵ����ĸ���ʼ�� ����ɶѡ����һ��֮��ֻҪ��root��ʼ�����ˣ���β�����󣬴�root��ʼ������
		HeapAdjust(arr, i, len);
	}

	show(arr, len);
	for (int i = len -1; i>0 ; i--)
	{
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		show(arr, len);
		//��β�����󣬴�root����һ�μ��ɡ�
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