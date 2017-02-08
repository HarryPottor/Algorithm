//围城一个圈圈，数到7的人出去，

#include <iostream>
using namespace std;

int main()
{	
	int a[20] = { 0 };
	int count = 0;
	int i = 0;
	int tem = 0;
	while (count != 20)
	{
		if (i == 20)
		{
			i = 0;
		}
		if (a[i] != 0)
		{
			i++;
			continue;
		}
		tem++;
		if (tem == 7)
		{
			a[i] = 1;
			cout << i+1 << " ";
			count++;
			tem = 0;
		}
		i++;
		
	}


	cout << endl;
	system("pause");
	return 0;
}