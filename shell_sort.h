void shellsort(int k[],int n)
{
	int i, j, flag ,gap = n;
	int gap_count[]={5, 3, 1};
    int tmp;
	int z=0;
    while(gap_count[z] >=1){
			printf("\n\n");
			printf("gap=%d: ",gap_count[z]);
		gap=gap_count[z];
    do{                        /*������Ӧ��ð������*/
        flag = 0;
        for(i=1;i<=n-gap;i++){
            j = i + gap;
            if(k[i]>k[j]){
                tmp = k[i];
                k[i] = k[j];
                k[j] = tmp;
                flag = 1;
                }
            }
         }while(flag !=0);
		    for(i=1;i<=11;i++)                            /*��ʾԭ����֮�е�Ԫ��*/
			printf("%d ",k[i]);
	z++;
    }

}