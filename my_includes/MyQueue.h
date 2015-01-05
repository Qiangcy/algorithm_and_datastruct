#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Type> //模版一定要把聲明和實現放在一起
class MyQueue
{
private:
	int front, rear;
	bool empty_flag;
	Type data[10];
public:
	MyQueue() 
	{
		front = 0;
		rear = 0;
		empty_flag = 1;
	}

	void output_information();
	Type Front();
	Type Rear();
	bool empty();
    Type pop();
	bool pushme(Type a);
	Type& operator [] ( int i )
	{
		if ( i<0 || i>9 )
		{
			cerr<<"[] out of bounds"<<endl;
			//exit(1);                                    //异常退出程序
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
    cout<<"empty flag is "<<empty_flag;
	cout<<"front is  "<<front;
	cout<<" , rear is   "<<rear<<endl;
}
template <typename Type> 
Type MyQueue<Type>:: Rear () 
{
	if( rear==0 )
		if( empty_flag )
			return data[0];
		else
			return data[39];
	return data[rear-1];
}

template <typename Type>
Type  MyQueue<Type>::pop() 
{
	front++;
	if (rear==front)
        empty_flag=1;
	return data[front-1];
}

template <typename Type>
bool  MyQueue<Type>::empty() 
{
	if (rear==front && empty_flag)
		return 1;
    else
        return 0;
}


template <typename Type> 
bool MyQueue<Type>::pushme(Type a) 
{
	if (front==rear && !empty_flag)
	{
		cerr<<"queue is full"<<endl;
		return 0;
	}
	data[rear++] = a;
	if (rear>39)
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
