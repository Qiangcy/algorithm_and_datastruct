#include "MyStack.h"
#include "function.h"
/*����˵��:1:log����10Ϊ�׵Ĺ��̶���2:ln ����eΪ�׵���Ȼ����3:C ��������� ������� ����� 3ȡ2�����   ������ʽ 3C24:A ���������� ������� ����� 3ȡ2������   ������ʽ 3A2
5:! ����׳�
6:^    x��y�η� ���� x^y
*/
int main()
{
	while(1)
	{
		string nifix_expression, numbers;
		cin>>nifix_expression;
		MyStack<string> postfix_expression;
		MyStack<char> operaters;
		double result;

		for(unsigned int i=0; i<nifix_expression.length(); i++ )
		{
			if( IsNumber( nifix_expression[i] ) )
				numbers += nifix_expression[i];
			else
			{
				if( numbers !="" )
					postfix_expression.pushme( numbers );//  et: 1033+12;
				if( nifix_expression[i]=='/' && i+1<nifix_expression.length() &&nifix_expression[i+1]=='0' )   
				{
					cout<<"Error /0"<<endl;
					system("pause");
					return 0;
				}
				else if( i==0 )
					operaters.pushme( nifix_expression[0] );//et: (11+3)+2
				else
					OperatersAnalyse( postfix_expression, operaters, nifix_expression[i] );
				numbers = "";
			}
		}
		if( numbers !="" )
			postfix_expression.pushme( numbers ); 
		while( operaters.Top() !=0 )
		{
			char temp = operaters.pop();
			char *p = &temp;
			string a(p);
			postfix_expression.pushme( a );
		}	
		//while( postfix_expression.Top()!=0 )
		//{
		//	string temp = postfix_expression.pop();
		//	temp = temp+"\0";
		//	cout<<temp<<endl;
		//}
		result = Calculate( postfix_expression );
		cout<<result<<endl;
	}
	system("pause");
}
