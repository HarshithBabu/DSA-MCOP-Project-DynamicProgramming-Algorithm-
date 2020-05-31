
#include<iostream>
#include<conio.h>
using namespace std;
void PrintParenthesis(int i, int j, int n, int *bracket)
{
    static int ind=1;
    if(i==j)
    {
        printf("%c",Mname++);
        return;
    }
    printf("(");
    PrintParenthesis(i,*((bracket+i*n)+j),n,bracket,Mname);
    PrintParenthesis(*((bracket+i*n)+j)+1,j,n,bracket,Mname);
    printf(")");
}
void MCMO(int p[], int n)
{
    int M[n][n];
    int bracket[n][n];
    for(int i=1;i<n;i++)
    {
        M[i][i]=0;
    }
    for(int len=2;len<n;len++)
    {
        for(int i=1;i<n-len+1;i++)
        {
            int j=i+len-1;
            M[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
               int cost=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
               if(cost<M[i][j])
               {
                  M[i][j]=cost;
                  bracket[i][j]=k;
               }
            }
        }
    }

    printf("\nThe Cost-Matrix is given by:\n");
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(i>j)
                printf("X\t");
            else
                printf("%d \t",M[i][j]);
        }
        printf("\n");
    }
    printf("\nOptimal Cost:%d",M[1][n-1]);
    printf("Optimal Parenthesization:");
    char Mname='A';
    PrintParenthesis(1,n-1,n,(int *)bracket,Mname);
}
int main()
{
    int n;
    printf("Enter number of matrices:");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter dimensions of the matrices:\n");
    for(int i=0;i<n;i++)
    {
       scnaf("%d",arr[i]);
       MCMO(arr,n+1);
       getch();
       return 0;
    }
}
