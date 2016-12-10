#include <iostream>
using namespace std;
bool dp[50][50][50][50];
int ary[5][4] = {{2,1,0,2},{1,1,1,1},{0,0,2,1},{0,3,0,0},{1,0,0,1}};
bool loosing(int a, int b, int c, int d)
{
    if (a<0||b<0||c<0||d<0) return false;
    else return !dp[a][b][c][d];
}
int main()
{
    int T;
    cin>>T;
    for (int i = 0 ; i < 31; i++)
        for (int j = 0 ; j < 31; j++)
            for (int k = 0 ; k < 31; k++)
                for (int l = 0 ; l < 31; l++)
                    for (int a = 0; a < 5; a++)
                    {
                        if (loosing(i-ary[a][0],j-ary[a][1],k-ary[a][2],l-ary[a][3]))
                            dp[i][j][k][l] = 1;
                    }
    while (T--)
    {
        int a, b, c,d;
        cin>>a>>b>>c>>d;
        if (!dp[a][b][c][d])
            cout<<"Roland"<<endl;
        else
            cout<<"Patrick"<<endl;
    }
}
