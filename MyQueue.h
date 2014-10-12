#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Type> //ģ��һ��Ҫ�����͌��F����һ��
class MyQueue
{
private:
	int front, rear;
	bool empty_flag;
	Type data[10];
public:
	MyQueue(int a=100) 
	{
		front = 0;
		rear = 0;
		empty_flag = 1;
	}

	void output_information();
	Type Front();
	Type Rear();
	bool empty();
	bool pop();
	bool pushme(Type a);
	Type& operator [] ( int i )
	{
		if ( i<0 || i>9 )
		{
			cerr<<"[] out of bounds"<<endl;
			system("pause");
			exit(1);                                    //�쳣�˳�����
		}
		return data[i];
	}
};


template <typename Type> 
Type MyQueue<Type>:: Front () 
{
	return data[front]; 
}

template <typename Type> 
void MyQueue<Type>:: output_information()  
{
	cout<<"front is  "<<front<<endl;
	cout<<"rear is   "<<rear<<endl;
}
template <typename Type> 
Type MyQueue<Type>:: Rear () 
{
	if( rear==0 )
		if( empty_flag )
			return data[0];
		else
			return data[9];
	return data[rear-1];
}

template <typename Type>
bool  MyQueue<Type>::pop() 
{
	front++;
	return 1;
}

template <typename Type>
bool  MyQueue<Type>::empty() 
{
	if (rear==front && empty_flag)
		return 1;
}


template <typename Type> 
bool MyQueue<Type>::pushme(Type a) 
{
	if (front==rear && !empty_flag)
	{
		cerr<<"stack is full"<<endl;
		return 0;
	}
	data[rear++] = a;
	if (rear>9)
		rear = 0;
	empty_flag = 0;
	return 1; 
}

//#include <iostream>
//#include "MyQueue.h"
//using namespace std;
//int main()
//{
//	MyQueue<int> Queue;
//	Queue.pushme(0);
//	Queue.pushme(1);  Queue.pushme(2);Queue.pushme(3);Queue.pushme(4);Queue.pushme(5);Queue.pushme(6);Queue.pushme(7);Queue.pushme(8);
//	Queue.pushme(9); 
//	Queue.pop();
//	Queue.pop();
//	Queue.pushme(222); 
//	Queue.output_information() ;
//	cout<<Queue.Front()<<endl;
//	cout<<Queue.Rear()<<endl;
//	return 0;
//}
