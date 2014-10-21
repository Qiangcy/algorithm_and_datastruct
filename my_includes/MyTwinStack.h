#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Type> //模版一定要把聲明和實現放在一起
class MyStack
{
private:
	int top_1, top_2;
	Type data[1000];
public:
	MyStack(int a=100)
	{
		top_1 = 0;
		top_2 = 99;
	}

	int Top(int number);
	Type pop(int number);
	bool pushme(int number, Type a);
	Type& operator [] ( int i )
	{
		if ( i>=top_1 && i<top_2 )
		{
			cerr<<"[] out of bounds"<<endl;
			system("pause");
			exit(1);                                    //异常退出程序
		}
		return data[i];
	}
};


template <typename Type> 
int MyStack<Type>:: Top (int number) 
{
	if(number==1)
		return top_1; 
	else
		return top_2;
}

template <typename Type>
Type  MyStack<Type>::pop(int number) 
{
	if( (top_1==0 && number==1) || (number==2 && top_2==99) )
	{
		cerr<<"pop:  out of bounds"<<endl;
		system("pause");
		exit(1);                                    //异常退出程序
	}
	else
	{
		if (number==1)
			return  data[--top_1];
		else
			return  data[++top_2];
	}
}


template <typename Type> 
bool MyStack<Type>::pushme(int number, Type a) 
{
	if (top_1+1==top_2)
	{
		cerr<<"stack is full"<<endl;
		return 0;
	}
	if (number==1)
		data[top_1++] = a;
	else
		data[top_2--] = a;
	return true; 
}

