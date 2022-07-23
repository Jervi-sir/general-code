#include <stdio.h>
typedef struct complex
{float real;
 float img;
} complex;

complex add(complex n1,complex n2);
complex Uadd(int,complex)
float real(complex);
float img(complex);

int main()
{
    complex n1, n2, temp;
    printf("complex number \n");
    printf("Enter real and imaginary part respectively:\n");
    scanf("%f %f", &n1.real, &n1.img);
    real(n1);
    img(n1);

    printf("\nFor 2nd complex number \n");  
    scanf("%f %f", &n2.real, &n2.img);
    temp = add(n1, n2);    
    printf("Sum = %.1f + %.1fi", temp.real, temp.img);
  

}
float real(complex co){printf("real = %f",co.real);}
float img(complex co){printf("img = %f",co.img);}

complex add(complex n1, complex n2)
{    complex temp;
     temp.real = n1.real + n2.real;
     temp.img = n1.img + n2.img;
     return(temp);
}

complex Uadd(int n,complex co)
{   complex temp; 
    int i; 

    if(n>0) temp=add(temp,co);
    else return temp;
 
}
 









