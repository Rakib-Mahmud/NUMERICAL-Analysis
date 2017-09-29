#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

int factorial(int n)
{
    if(n>=1){
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
}

double exponents(int n,double x)
{
    double sum=0;
    for(int i=0;i<n;i++){
        sum=sum+(pow(x,i)/factorial(i));
    }
    return sum;
}

int main()
{
    int n;double x;
    cout<<"Enter Numbers of Terms to be calculated :"<<endl<<"->";
    cin>>n;
    cout<<"Enter the exponents :"<<endl<<"->";
    cin>>x;
    printf("e^x = %.2lf\n",exponents(n,x));
}
