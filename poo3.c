#include<stdio.h>
void main()
{
      //1.assignment -> =,+= ,-= ,*= ,/=
      int a = 12;
      printf("a = %d\n",a);
      
      a += 2; //a = a+2
      printf("a = %d\n",a);

      int b = 1;

      a -= b; //a =a-b
      printf("a = %d\n",a);

      a *=2;
      printf("a = %d\n",a);
      
      //2.Arithmetic -> +,-,*,/,%
      int i,j;
      printf("enter vaiue of i = ");
      scanf("%d" ,&i);
      printf("enter vaiue of j = ");
      scanf("%d" ,&j);

      printf("%d\n",(i+j));
      printf("%d\n",(i-j));
      printf("%d\n",(i*j));
      printf("%d\n",(i/j));
      printf("%d/n",(i%j));

      peintf("enter amount of ordre : ");
      float amount;
      scanf("%f",&amount);

      float gst = (amount*18)/100;
      float final_amount = amount+gst;
      printf("your bill is : %f\n",final_amount);


      float base = 34.3;
      float height = 2.3;
      float areaOfTraingle = (base*height)/2;
      printf("area of triangle = %f\n",areaOfTraingle);

      //3.unary -> ++,--
      i++; //i = i+1
      printf("i = %d\n",i); //14

      int i1 = ++i;
      


}