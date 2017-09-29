#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

double d = 0;
double det(int n, double mat[10][10])
{
    int c, subi, i, j, subj;
    double submat[10][10];
    if (n == 2)
    {
        return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {
        for(c = 0; c < n; c++)
        {
                subi = 0;
            for(i = 1; i < n; i++)
            {
                subj = 0;
                  for(j = 0; j < n; j++)
                    {
                        if (j == c)
                        {
                            continue;
                        }
                        submat[subi][subj] = mat[i][j];

                    subj++;

                }
                    subi++;
                }
            d = d + (pow(-1 ,c) * mat[0][c] * det(n - 1 ,submat));
        }
    }
    return d;
}
double cofac(int r,int c,int n,double mat[10][10])
{
    double temp[10][10];int subi=0,subj=0;
    for(int row=0;row<n;row++){
            subj=0;
        for(int col=0;col<n;col++){

            if(row==r||col==c){
                continue;
            }
            else{
                temp[subi][subj++]=mat[row][col];
                if(subj==n-1){
                    subi++;
                }
            }
        }
    }
    return det((n-1),temp);
}

int main()
{
    double adj[10][10],mat[10][10],b[10][1];
    int i,j,n;
    cout<<"What is the size of the system (n)?\n";
    cin>>n;
    cout<<"Input coefficients a(i , j), row-wise:"<<endl;
    for(i=0;i<n;i++)

    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<"Input vector b :\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<1;j++)
        {
            cin>>b[i][j];
        }
    }
    double detr=det(n,mat);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adj[i][j]=pow(-1,(i+j))*cofac(i,j,n,mat);
        }
    }

if(detr==0){
        cout<<"Inverse is not possible(singular)\n";
     }
     else{
        detr=(1/detr);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                mat[i][j]=adj[j][i]*detr;
            }
        }
    }
    double sum=0;
    for(i=0;i<n;i++){
            sum=0;
        for(j=0;j<n;j++){
            sum=sum+mat[i][j]*b[j][0];
        }
        adj[i][0]=sum;
    }
    cout<<"Solution vector x :\n";
    for(i=0;i<n;i++){
        for(j=0;j<1;j++){
            printf("%.4lf  ",adj[i][j]);
        }
        cout<<endl<<endl;
    }
}
