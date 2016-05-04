#include "function.h"
bool IsNumber(char a)
{
    if( a=='.' || (a>='0' && a<='9') )
        return true;
    else
        return false;
}

bool IsOperator(char a)
{
    if ( a=='+' || a=='-' || a=='*' || a=='/')
        return true;
    else
        return false;
}

bool OperatersAnalyse(MyStack<string> &postfix_expression, MyStack<char> &operaters , char Oper)
{
    char temp;
    if(Oper==')') {
        temp =  operaters.pop();
        while(temp != '(') {
            char *p = &temp;
            string a(p);
            postfix_expression.pushme(a);
            temp = operaters.pop();
        }
    }else if(Oper=='*' || Oper=='/') {
        if(operaters.Top()!=0 &&
                (operaters[operaters.Top()-1] == '*' || operaters[operaters.Top()-1] == '/')){
            while(operaters.Top()!=0 && operaters[ operaters.Top()-1 ]!='(') {
                temp = operaters.pop();
                char *p = &temp;
                string a(p);
                postfix_expression.pushme(a);
                if (operaters.Top()>=1)
                    if (operaters[operaters.Top()-1] =='+' || operaters[operaters.Top()-1] == '-')
                        break;
            }
        }
        operaters.pushme(Oper);
    } else {//+ -
        while(operaters.Top()!=0 && Oper!='(' && operaters[ operaters.Top()-1 ]!='(') {
            temp = operaters.pop();
            char *p = &temp;
            string a(p);
            postfix_expression.pushme( a );
        }
        operaters.pushme(Oper);
    }
    return true;
}

double Calculate(MyStack<string> postfix_expression)
{
    MyStack<double> numbers;
    int length = postfix_expression.Top();
    for(int i=0; i!=length; ++i) {
        if (IsOperator(postfix_expression[i][0])==false){ //is number
            double number =  atof(postfix_expression[i].c_str());
            numbers.pushme(number);
        }else {
            double b = numbers.pop();
            double a = numbers.pop();
            double c = simple_caculate(a, postfix_expression[i][0], b);
            numbers.pushme(c);
        }
    }
    return numbers.pop();
}

double simple_caculate(double a, char oper, double b)
{
    double result = 0;
    switch( oper )
    {
        case '+': result = a+b; break;
        case '-': result = a-b; break;
        case '*': result = a*b; break;
        case '/': result = a/b; break;
    }
    return result;
}
