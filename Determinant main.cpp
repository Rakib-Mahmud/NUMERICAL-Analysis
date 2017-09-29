#include<iostream>
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
    int n,m;
    cout<<"Enter the order of matrix\n" ;
    cin>>n>>m;
    double mat[10][10],adj[10][10];
    int i, j;
    cout<<"Enter the elements"<<endl;
    for(i=0;i<n;i++)

    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<"Matrix can be represented :\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl<<endl;
    }
    double detr=det(n,mat);
    cout<<"\nDeterminant -> "<<detr<<endl;
    cout<<"Transpose Matrix :\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<mat[j][i]<<"  ";
        }
        cout<<endl<<endl;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adj[i][j]=pow(-1,(i+j))*cofac(i,j,n,mat);
        }
    }
    cout<<"Adjoint Matrix : \n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<adj[j][i]<<"  ";
        }
        cout<<endl<<endl;
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
    cout<<"Inverse Matrix : \n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl<<endl;
    }
        return 0;
}
