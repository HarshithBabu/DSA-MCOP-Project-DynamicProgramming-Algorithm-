
#include<stdio.h>
#include<limits.h> // use limits.h header for better INT_MAX value
#include <stdlib.h>

int count_lines()
{
  FILE *fp = fopen("input.txt","r");
  int ch=0;
  int lines=0;
  lines++;
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
        lines++;
    }
  fclose(fp);
  return lines;
}
void PrintParenthesis(int i, int j, int n, int *bracket)
{
    static int ind=1;
    if(i==j)
    {
        printf("A");
        printf("%d",ind++);
        return;
    }
    printf("(");
    PrintParenthesis(i,*((bracket+i*n)+j),n,bracket);
    PrintParenthesis(*((bracket+i*n)+j)+1,j,n,bracket);
    printf(")");
}
void MCMO(int p[], int n)
{
    long long int M[n][n];
    //long long int M[n][n]={0};
    //memset(M,0,n*sizeof(M[0][0]));
    int bracket[n][n];
    for(int i=1;i<n;i++)
       { M[i][i]=0;
        bracket[i][i]=0;}
    for(int len=2;len<n;len++)
    {
        for(int i=1;i<n-len+1;i++)
        {
            int j=i+len-1; M[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                long long int cost=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
                 if(cost<M[i][j])
                {

                    bracket[i][j]=k;
                     M[i][j]=cost;
                }
                printf("The cost for M[%d][%d] is %lld at k equal to %d\n",i,j,cost,k);
            }
        }
        printf("\n");
    }
    printf("\nThe Cost-Matrix is given by:\n");
     for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {

            if(i>j)
                printf("X\t");
            else
                printf("%lld\t",M[i][j]); //space

        }
        printf("\n"); //bracket
    }
    printf("Optimal Paranthesization occurs at \n");
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {

            if(i>j)
                printf("X\t");
            else
                printf("%d\t",bracket[i][j]); //space

        }
        printf("\n"); //bracket
    }
    printf("\nOptimal Cost: %lld \n",M[1][n-1]);
     printf("Optimal Parenthesization:");
    PrintParenthesis(1,n-1,n,(int *)bracket);
}
int main()
{
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    int n=count_lines();
    int arr[n];
    for(int i=0;i<n;i++)
        fscanf(fptr, "%d", &arr[i]);
    MCMO(arr,n);
     return 0;
}
