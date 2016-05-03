#include "MyStack.h"
#include "function.h"
/*TODO
 * :1:log是以10为底的工程对数2:ln 是以e为底的自然对数3:C 计算组合数 输入规则 如计算 3取2的组合   输入表达式 3C24:A 计算排列数 输入规则 如计算 3取2的排列   输入表达式 3A2
! 计算阶乘
^    x的y次方 输入 x^y
*/
int main()
{
    for(; ;){
        string nifix_expression, numbers;
        cin >> std::ws;//discard spaces
        getline(cin, nifix_expression);
        cout<<"origin : "<<nifix_expression<<endl;

        auto it = find(begin(nifix_expression), end(nifix_expression), ' ');
        if(it == end(nifix_expression))
            it = find(begin(nifix_expression), end(nifix_expression), '\t');
        while(it != end(nifix_expression)) {
            nifix_expression.erase(it);
            cout<<"after "<<nifix_expression<<endl;
            it = find(begin(nifix_expression), end(nifix_expression), ' ');
            if(it == end(nifix_expression))
                it = find(begin(nifix_expression), end(nifix_expression), '\t');
        }

        MyStack<string> postfix_expression;
        MyStack<char> operaters;
        double result;

        for(int i=0; i<nifix_expression.length(); i++ )
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
}
