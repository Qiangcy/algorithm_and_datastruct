#include <iostream>
#include "LinkList.h"  
using namespace std;
int main()
{
	// 	LinkList<int>  L1;
	LinkList<int> *L=new LinkList<int>;
	// 	L = & L1;
	L->create_linklist( L );
	L->output_element( L );
	L->find_element( L, 10000  );
	cout<<endl;	
	L->insert_element( L, 5, 10000 );
	cout<<"*****插入后********"<<endl;
	L->output_element( L );
	L=L->reverse_list( L );
	cout<<"******倒转后*******"<<endl;
	L->output_element( L );
	cout<<"******删除后*******"<<endl;
	L->delete_element( L, 1 );
	L->output_element( L );
	cout<<"*****插入后********"<<endl;
	L->insert_element( L, 0, 10000 );
	L->output_element( L );
	L=L->reverse_list( L );
	cout<<"******新链接表开始构造*******"<<endl;

	LinkList<int> newone( *L  );
	LinkList<int> *P=new LinkList<int>;
	P= newone.get_headptr(); 
	L->destroy_linklist( L );
	L->output_element( L );
	P->output_element( P );
	P->find_element( P, 10000  ); 

	LinkList<int> newtwo( *P  );
	P->destroy_linklist( P );
	P->output_element( P );
	LinkList<int> *Q=new LinkList<int>;
	Q= newtwo.get_headptr(); 
	Q->output_element( Q );
	cout<<endl;	
	return 0;
}
