#include<iostream>
using namespace std;
/*int row;
int col;*/

int backtrack(int**dp,int rowx,int colx);

int main()
{
    int row;
    int col;
    cin>>row>>col;
    int **dp;
    dp = new int *[row];
    for(int i = 0; i <row; i++)
        dp[i] = new int[col];
    int ncage;
    cin>>ncage;
    for (int i = 0; i < ncage; i++)
    {
        int rowx,colx;
        cin>>rowx>>colx;
        dp[rowx-1][colx-1] = -1;
    }
    dp[0][0] = 1;
    backtrack(dp,row-1,col-1);
    cout<<dp[row-1][col-1];
    return 0;
}
int backtrack(int**dp,int rowx,int colx)
{
    if (rowx>=0&&colx>=0)
    {
        if (dp[rowx][colx] == -1)
        {
            return 0;
        }
        else
        {
            if (dp[rowx][colx] == 0)
            {
                dp[rowx][colx] = backtrack(dp,rowx-1,colx) + backtrack(dp,rowx,colx-1);
                return dp[rowx][colx];
            }
            else
            {
                return dp[rowx][colx];
            }
        }
    }
    else
    {
        return 0;
    }
}
