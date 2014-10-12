#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

template <typename Type> //模版一定要把聲明和實現放在一起
class MyStack
{
private:
	int top ;
	//int size ;
	//vector <Type> data;
 	Type data[100];
public:
	MyStack(int a=100)
	{
		top = 0;
//		size = a;
//		data(100);
	}
 
	int Top( );
	Type  pop();
	bool pushme( Type);
	Type& operator [] ( int i )
	{
		if ( i>=top )
		{
			cerr<<"[] out of bounds"<<endl;
	 		system("pause");
	 		exit(1);                                    //异常退出程序
		}
		return data[i];
	}

};



template <typename Type> 
int MyStack<Type>::Top( )//MyStack<Type>& a
{
	return top;
}

template <typename Type>
Type  MyStack<Type>::pop()
{
	if( top==0 )
	{
		cerr<<"pop:  out of bounds"<<endl;
     	system("pause");
 		exit(1);                                    //异常退出程序
	}
	return  data[--top];
}


template <typename Type> 
bool MyStack<Type>::pushme( Type a )
{
	data[top++] = a;
	return true;
}
 