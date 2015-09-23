#include <stdio.h>
#include <stdlib.h>
#define blue 1
#define red 0
int is_last_one(int *a, int *mem)
{
    int i = 0, count = 0, record=0;
    while(i < 40) {
        if(a[i] != -1) {
            count++;
            record = i;
        }
        if(count > 2)
            return -1;
        ++i;
    }
    if(count == 1) {
        *mem = 1;
        return record;
    }else if(count == 2) {
        *mem = 2;
        return record;
    }
    return record;
}

int main()
{
    int a[40], i, randnum, tmp1=1, tmp2=2, times=100, record, redget=0, blueget=0, mem, sum=0;
    printf("input times \n");
    scanf("%d", &times);
    sum = times;
    while(times > 0) {
        for(i=0; i<40; ++i) {
            if(i < 20)
                a[i] = 1;
            else
                a[i] = 0;
        }

        randnum = 40;
        record = is_last_one(a, &mem);
        while(record == -1) {
            do {
                tmp1 = rand() % randnum;
                tmp2 = rand() % randnum;
            }while(tmp1==tmp2 && a[tmp1]!=-1 && a[tmp2]!=-1);

            if(a[tmp1] == a[tmp2]) {//get two ball
                a[tmp1] = -1;
                a[tmp2] = -1;
            }else {
                if(a[tmp1] == blue) {//get one blue
                    a[tmp1] = -1;
                }else {
                    a[tmp2] = -1;
                }
            }

            record = is_last_one(a, &mem);
        }

        if(mem == 1) {
            printf("record is %d\n", record);
            if(a[record] == red)
                redget++;
            else
                blueget++;
        }else if(mem == 2) {
            printf("NOPE!\n");
        }
        times--;
    }
    printf("red is %d\n", redget);
    printf("blue is %d\n", blueget);
//    sum = sum + redget + blueget;
    printf("sum is %d\n", sum);
    double result = (double)redget/sum;
    printf("result is %lf\n", result);
    printf("red is %lf\n", result*100);
    return 0;
}


