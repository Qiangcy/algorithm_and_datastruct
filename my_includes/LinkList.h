#include <iostream>
using namespace std;
template <typename Type>
class LinkList  
{
public:
	Type  data;
	LinkList* next;
	LinkList()
	{
		next=NULL;
	}
	LinkList <Type>  ( const LinkList<Type>  & RightSides );
	LinkList <Type>* get_headptr( ) const;
	void create_linklist( LinkList <Type>* &L );
	void output_element( LinkList <Type>* &L ) const;
	void find_element( LinkList <Type>* &L, Type C ) const;
	bool insert_element( LinkList <Type>* L, int n, Type C );
	bool delete_element( LinkList <Type>* &L, int n );
	void  destroy_linklist( LinkList <Type>* &L );
	LinkList <Type>* reverse_list( LinkList <Type>* &L );
	//~	LinkList<Type> ()
	//{
	//	next->destroy_linklist( next );
	//}
};



template <typename Type>
LinkList<Type>:: LinkList ( const LinkList<Type>  & RightSides )
//复制构造函数 注意：深拷贝（new，指针方向）  还有next
{
	cout<<"copy:*********************************"<<endl;
	next = new LinkList<Type>;
	next->data = RightSides.data;//复制第一个节点

	LinkList<Type>* rightsidesptr = new LinkList<Type>;
	rightsidesptr = RightSides.next;

	LinkList<Type>* newone =new LinkList<Type>;
	next->next = newone;

	if ( rightsidesptr == NULL )
	{
		next->next = NULL;
		delete newone;
	}

	LinkList<Type>* saver =new LinkList<Type>;

	while ( rightsidesptr != NULL )
	{
		newone->data = rightsidesptr->data;
		saver = newone;
		newone->next = new LinkList<Type>;
		newone = newone->next ;

		rightsidesptr = rightsidesptr->next;
	}
	saver->next = NULL;
	delete newone;
}

template <typename Type>
LinkList <Type>* LinkList<Type>::get_headptr( ) const
{
	return next;
}


template <typename Type>
void LinkList<Type>::create_linklist( LinkList <Type>* &L )
{
	std::cout<<"input  elements   ctrl+f end"<<std::endl;
	Type a;
	LinkList<Type> *Node = L;
	LinkList<Type> *saver;
	while ( std::cin>>a )
	{
		saver=Node;
		Node->data=a;
		LinkList<Type> *temp=new LinkList<Type>;
		Node->next=temp;
		Node=temp;
	}
	saver->next=NULL;
}


template <typename Type>
void LinkList<Type>::output_element( LinkList <Type>* &L ) const
{
	if( L==NULL )
		cout<<"空表"<<endl;
	LinkList <Type> *temp=L;
	while ( temp != NULL ) 
	{
		cout<<temp->data<<"   ";
		temp=temp->next;
	}
	cout<<endl;
}


template <typename Type>
void LinkList<Type>::find_element( LinkList <Type>* &L,  Type C  ) const
{
	LinkList <Type> *temp=L;
	bool flag=0;
	for ( int i=1; temp!=NULL; temp=temp->next, i++ )
	{
		if ( temp->data==C )
		{
			cout<<i<<" ";
			flag=1;
		}
	}
	if ( flag==0 )
	{
		cout<<"can't find "<<C<<endl;
	}
}


template <typename Type>
bool LinkList<Type>::insert_element( LinkList <Type>* L, int n, Type C ) 
{
	if ( n<0 )
		cout<<"插入错误，位置不存在"<<endl;
	if ( n==0 )
	{
		LinkList <Type> *insert_one=new LinkList <Type>;
		insert_one->data=C;
		insert_one->next=L;
		L=insert_one;
		return true;
	}
	LinkList <Type> *temp=L;
	for ( int i=0; i<n-1; i++)
	{
		if ( temp->next==NULL )
		{
			cout<<"插入错误，超出位置。"<<endl;
			return false;
		}
		else
			temp=temp->next;
	}

	LinkList <Type> *insert_one=new LinkList <Type>;
	insert_one->next=temp->next;
	insert_one->data=C;
	temp->next=insert_one;
	return true;
}


template <typename Type>
LinkList <Type>* LinkList<Type>::reverse_list( LinkList <Type>* &L )
{
	LinkList <Type> *p, *temp, *head;
    head= L;
    p = head->next;
    head->next = NULL;
    while(p) {
        temp = p->next;

        p->next = head;
        head = p;

        p = temp;
    }
    return head;
//	if ( L->next ==NULL )//一个结点的情况
//		return L;
//	LinkList <Type> *q=new  LinkList <Type>;
//	LinkList <Type> *o=new  LinkList <Type>;
//	q=L->next;
//	o=q->next;
//	L->next=NULL;
//	while( o!=NULL && o->next != NULL )
//	{
//		q->next=L;
//		L=q;
//		q=o;
//		o=o->next;
//	}
//	q->next=L;
//	if ( o!=NULL )//两个以上结点的情况，处理o
//	{
//		o->next=q;
//		return o;
//	}
//	else
//		return q;//两个结点的情况

}

template <typename Type>
bool LinkList<Type>::delete_element( LinkList <Type>* &L, int n )
{
    cout<<"in delete "<<n<<endl;
	LinkList <Type> *temp=L;
	if ( n==1 )
	{
        cout<<"in 1"<<endl;
		if ( L->next==NULL )
		{
        cout<<"in 2"<<endl;
			L=NULL;
		}
        else
        {
            cout<<"in 3"<<endl;
            L=L->next;
        }
        cout<<"in 4"<<endl;
        delete temp;
        return true;
    }
    else
    {
        for ( int i=0; i<n-2  ; i++)
        {
            if ( temp->next==NULL || temp->next->next==NULL )
            {
                cout<<"删除错误，超出位置。"<<endl;
                return false;
            }
            temp=temp->next;
        }

        if ( temp->next==NULL || temp->next->next==NULL )
        {
            cout<<"删除错误，超出位置。"<<endl;
            return false;
        }
        LinkList <Type> *deleteone=temp->next;
        temp->next=temp->next->next;
        delete deleteone;
        return true;
    }
}


    template <typename Type>
void LinkList<Type>::destroy_linklist( LinkList <Type>* &L )
{
    while( L!= NULL )
    {
        LinkList <Type>* temp = L;
        L = L->next;
        delete temp;
    }
}

//
//
//测试
//
//#include <iostream>
//#include "LinkList.h"  
//using namespace std;
//int main()
//{
//	// 	LinkList<int>  L1;
//	LinkList<int> *L=new LinkList<int>;
//	// 	L = & L1;
//	L->create_linklist( L );
//	L->output_element( L );
//	L->find_element( L, 10000  );
//	cout<<endl;	
//	L->insert_element( L, 5, 10000 );
//	cout<<"*****插入后********"<<endl;
//	L->output_element( L );
//	L=L->reverse_list( L );
//	cout<<"******倒转后*******"<<endl;
//	L->output_element( L );
//	cout<<"******删除后*******"<<endl;
//	L->delete_element( L, 1 );
//	L->output_element( L );
//	cout<<"*****插入后********"<<endl;
//	L->insert_element( L, 0, 10000 );
//	L->output_element( L );
//	L=L->reverse_list( L );
//	cout<<"******新链接表开始构造*******"<<endl;
//
//	LinkList<int> newone( *L  );
//	LinkList<int> *P=new LinkList<int>;
//	P= newone.get_headptr(); 
//	L->destroy_linklist( L );
//	L->output_element( L );
//	P->output_element( P );
//	P->find_element( P, 10000  ); 
//
//	LinkList<int> newtwo( *P  );
//	P->destroy_linklist( P );
//	P->output_element( P );
//	LinkList<int> *Q=new LinkList<int>;
//	Q= newtwo.get_headptr(); 
//	Q->output_element( Q );
//	cout<<endl;	
//	system("pause");
//	return 0;
//}
