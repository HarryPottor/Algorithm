
#include <iostream>
using namespace std;

int main()
{
	int a[5] = { 1,3,5,7,9 };
	int b[4] = { 2,4,6,8 };

	int *c = new int[9];
	int index = 0;
	for (size_t i = 0; i < 5; i++)
	{
		c[index++] = a[i];
	}
	for (size_t i = 0; i < 4; i++)
	{
		c[index++] = b[i];
	}
	for (size_t i = 0; i < 9; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < 9; i++)
	{
		for (int j = i; j < 9; j++)
		{
			if (c[j] < c[j-1] )
			{
				int t = c[j];
				c[j] = c[j - 1];
				c[j - 1] = t;
			}
		}
	}

	for (size_t i = 0; i < 9; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
