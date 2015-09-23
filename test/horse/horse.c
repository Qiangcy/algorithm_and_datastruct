#include <stdio.h>
#include <stdlib.h>
#include "MyStack.h"
typedef struct _point {
    int x, y;
} point;

int is_ok(int a[][5], MyStack <point> *pre_stack, point *init)
{
    if(pre_stack->empty())
        return 1;
    point temp = pre_stack->pop();
    if(temp.x==init->x && temp.y==init->y) {
        return 1;
    }else
        return 0;
}

int main()
{
    int a[4][5], flag[4][5];
    int b,c;
    printf("please input init a,b\n");
    scanf("%d,%d", &b, &c);
    point current_point, pre_point;
    current_point.x = b;
    current_point.y = c;

    MyStack <point> pre_stack;
    pre_stack.pushme(current_point);

    while (is_ok(a, &pre_stack, &current_point)) {
        pre_point = pre_stack.pop();
        flag[pre_point.x][pre_point.y] = 1;
    }
    return 0;
}
