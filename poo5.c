#include<stdio.h>

void mani(){
    int a;
    printf("a = %d\n",a);

    // (< ,++)  (>, --)
    //1.for(initialization;condition;incre){body}
    int i;
    for(i =11;i<=5;i++){
        printf("i = %d\n",i);
    }
    
    for (i=5;i>=1;i--){
        printf("i = %d\n",i);
    }

    //while(condition){body}
    int j=1;
    white(j<=5){
        printf("j = %d\n",j);
        j++;
    }

    //do{body} white(condition)
    int k=11;
    do{
        printf("k = %d\n",k);
        k++;
        
    }
    while(k <= 5);
}