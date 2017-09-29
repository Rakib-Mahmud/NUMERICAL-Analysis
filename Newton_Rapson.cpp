#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    double x=0,a=0,b=0,y=0,z=0,dif=1,x1=0.00001;
    cout<<"Enter the initial value :\n";
    cin>>x;
     printf("\n  \t n \t Xn \tXn+1 \t f(x) \n");
        printf(" \t--- \t---\t---\t-------\n");
    int i=1;
    while(dif>0.001){

        z=pow(x,3)-2*x-5;
        y=3*(x*x)-2;
        x1=x-(z/y);
        printf("\n\t %d \t%.3lf \t%.4lf  %lf \n",i,x,x1,z);
        dif=fabs(x-x1);
        x=x1;
        i++;
    }

    printf("\n\tResult is = %lf\n",x);

    return 0;
}


