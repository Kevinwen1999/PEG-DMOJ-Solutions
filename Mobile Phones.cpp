#include <iostream>
#include <cstring>
using namespace std;
int S;
const int MAXN = 1030;
int bit[MAXN][MAXN];
void update(int x, int y, int v)
{
    for (; x < MAXN; x+=(x & -x))
    {
        for (int y1 = y; y1 < MAXN; y1 += (y1 & -y1))
            bit[x][y1] += v;
    }
}
int query(int x, int y)
{
    int sum = 0;
    for (; x > 0; x-=(x & -x))
    {
        for (int y1 = y; y1 > 0; y1 -= (y1 & -y1))
            sum += bit[x][y1];
    }
    return sum;
}
//(range x1, y1, x2, y2) = query(x2,y2) - query(x2,y1-1) - query(x1-1, y2) + query(x1-1, y1-1)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int opcode;
    while (true)
    {
        cin>>opcode;
        if (opcode == 0)
        {
            cin>>S;
        }
        else if (opcode == 1)
        {
            int x, y, a;
            cin>>x>>y>>a;
            update(x+1,y+1,a);
        }
        else if (opcode == 2)
        {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            x1++,x2++,y1++,y2++;
            cout<<query(x2,y2) - query(x2,y1-1) - query(x1-1, y2) + query(x1-1, y1-1)<<"\n";
        }
        else
        {
            break;
        }
    }
}
