#ifdef DEBUG


#include <iostream>
using namespace std;

void ShellInser(int arr[], int len)
{
	for (int div = len/2; div >=1 ; div/=2)
	{
		for (int i = div; i < len; i++)
		{
			for (int j = i; j >=0 && (arr[j] < arr[j-div]); j-=div)
			{
				int x = arr[j];
				arr[j] = arr[j - div];
				arr[j - div] = x;
			}

		}
	}

}

void show(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = { 5,4,3,2,1 };

	ShellInser(arr, 5);

	show(arr, 5);


	system("pause");
	return 0;
}
#endif // DEBUG