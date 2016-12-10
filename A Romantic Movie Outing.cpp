#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define B 1500
using namespace std;
int bit[2*B+100][2*B+100];
void update(int x1, int y, int v)
{
    for (int x = x1; x <= 2*B+2; x+=(x & -x))
    {
        for (int y1 = y; y1 <= 2*B+2; y1 += (y1 & -y1))
            bit[x][y1] += v;
    }
}
int query(int x1, int y)
{
    int sum = 0;
    for (int x = x1; x > 0; x-=(x & -x))
    {
        for (int y1 = y; y1 > 0; y1 -= (y1 & -y1))
            sum += bit[x][y1];
    }
    return sum;
}
bool seat[B+10][B+10];
int L, T;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>L>>T;
    char op; int r, c;
    for (int i = 0; i < T; i++)
    {
        cin>>op>>r>>c;

        if (op=='E' && r <= B)
        {
            update(r-c+B,r+c,1);
            seat[r][c] = true;
        }
        else if (op=='L' && r <= B)
        {
            update(r-c+B,r+c,-1);
            seat[r][c] = false;
        }
        else if (op == 'S')
        {
            if (seat[r][c] || seat[r][c+1])
                cout<<"No\n";
            else
                cout<<query(r-c+B,r+c) + query(r-c-1+B,r+c+1)<<"\n";
        }
    }
    int min1 = INF, min2 = INF;
    for (int i = L+1; i <= L + 501; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if (!seat[i][j])
            {
                int cur = query(i-j+B, i+j);
                if (cur < min1)
                {
                    min2 = min1;
                    min1 = cur;
                }
                else if (cur < min2)
                    min2 = cur;
            }
        }
    }
    cout<<min1+min2;
}
