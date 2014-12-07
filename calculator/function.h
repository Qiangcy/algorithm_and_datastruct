#include "MyStack.h"

bool IsNumber(char);

bool IsOperator(char);

bool OperatersAnalyse( MyStack<string> &postfix_expression, MyStack<char> &operaters , char Oper );

double Calculate( MyStack<string> postfix_expression );

double simple_caculate( double a, char oper, double b );

