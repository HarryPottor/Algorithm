#include <iostream>
using namespace std;

class MyClass
{
public:

	int a;
private:

};

class MyClass2
{
public:
	MyClass2()
	{
		cout << "myclass2()" << endl;
	}
	
	MyClass2(int i)
	{
		cout << "myclass2(int i)" << endl;
	}/*
	MyClass2(int i = 1, int j = 2)
	{
		cout << "myclass2(int i, int j)" << endl;
	}
	*/
private:

};


int main()
{

	//没有构造函数的类，加括号 进行初始化；不加括号不进行初始化
	//加括号调用无参的构造函数； 不加括号调用 默认或者唯一的构造函数
	MyClass *mc1 = new MyClass;

	MyClass *mc2 = new MyClass();

	cout << mc1->a << endl;
	cout << mc2->a << endl;

	delete(mc1);
	delete(mc2);

	cout << "----------------------------------------" << endl;

	MyClass2 *mc21 = new MyClass2;

	MyClass2 *mc22 = new MyClass2();

	system("pause");
	return 0;
}