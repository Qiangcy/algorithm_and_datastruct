template <typename Type>
class List  
{
private:
	int length;
	Type  data[100];
public:
	/*List ( Type, int ): 
	element(Type), length( int )
	{
	maxsize=length*2;
	};*/
	void create_list( List <Type>* &L );
	void output_element( List <Type>* &L );
	int find_element( List <Type>* &L, Type C );
	bool insert_element( List <Type>* &L, int i, Type C );
	bool delete_element( List <Type>* &L, int i );
};

template <typename Type>
void List<Type> ::create_list( List <Type>* &L )
{
	std::cout<<"input  elements   ctrl+f end"<<std::endl;
	Type a;
	L->length=0;
	while ( std::cin>>a )
	{
		L->data[L->length]=a;
		L->length++;
	}
}

template <typename Type>
void List<Type> ::output_element( List <Type>* &L )
{
	for ( int i=0; i<L->length; i++ )
		std::cout<<L->data[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"length is   "<<L->length<<std::endl;
}



template <typename Type>
int List<Type> ::find_element( List <Type>* &L, Type C )
{
	for( int i=0; i<L->length; i++ )
	{
		if( C==L->data[i] )
			return i+1;
	}
	std::cout<<"Not "<<std::endl;
	return false;
}

template <typename Type>
bool List<Type> ::insert_element(List <Type>* &L, int i, Type C ) //i«∞√Ê≤Â»Î
{
	if( i<1 || i>L->length )
	{
		std::cout<<"Not"<<std::endl;
		return false;
	}
	for( int k=L->length-1; i-1<=k; k-- )
		L->data[k+1] = L->data[k];
	L->data[i-1]=C;
	L->length++;
	//if( L->length > L->maxsize )
	//{
	//	L->maxsize*2;
	//	return true;
	//}
	return true;
}

template <typename Type>
bool List<Type> ::delete_element(List <Type> * &L, int i)
{
	i=i-1;
	if( i>L->length || L->length==0 || i<1 )
		return false;
	for ( int k=L->length-1; i-1<k; i++ )
		L->data[i] = L->data[i+1];
	L->length--;
	return true;
}