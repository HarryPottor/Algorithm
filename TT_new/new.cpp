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

	//û�й��캯�����࣬������ ���г�ʼ�����������Ų����г�ʼ��
	//�����ŵ����޲εĹ��캯���� �������ŵ��� Ĭ�ϻ���Ψһ�Ĺ��캯��
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