#include <iostream>
#include <algorithm>
#define MAXN 4001
using namespace std;
int b1[MAXN][MAXN], b2[MAXN][MAXN];
int arr[MAXN][MAXN];
//int color[MAXN][MAXN];
inline int color (int r, int c) {return (r%2==c%2);}
int R, C;
void update1(int x, int y, int v)
{
    for (; x <= R; x+=(x & -x))
    {
        for (int y1 = y; y1 <= C; y1 += (y1 & -y1))
            b1[x][y1] += v;
    }
}
void update2(int x, int y, int v)
{
    for (; x <= R; x+=(x & -x))
    {
        for (int y1 = y; y1 <= C; y1 += (y1 & -y1))
            b2[x][y1] += v;
    }
}
int query1(int x, int y)
{
    int sum = 0;
    for (; x > 0; x-=(x & -x))
    {
        for (int y1 = y; y1 > 0; y1 -= (y1 & -y1))
            sum += b1[x][y1];
    }
    return sum;
}
int query2(int x, int y)
{
    int sum = 0;
    for (; x > 0; x-=(x & -x))
    {
        for (int y1 = y; y1 > 0; y1 -= (y1 & -y1))
            sum += b2[x][y1];
    }
    return sum;
}
int main()
{
    scanf("%d %d", &R, &C);
    /*for (int i = 1; i <= R; i++)
    {
        color[i][1] = i % 2;
        for (int j = 2; j <= C; j++)
            color[i][j] = 1 - color[i][j-1];
    }*/
    int op;
    while (scanf("%d", &op) && op)
    {
        if (op == 1)
        {
            int r,c,x;
            scanf("%d%d%d", &r, &c, &x);
            int cc1 = color(r,c);
            int bb = arr[r][c];
            if (cc1)
                update1(r,c,x-bb);
            else
                update2(r,c,x-bb);
            arr[r][c] = x;
        }
        else if (op==2)
        {
            int r1, c1, r2, c2;
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            int cc1 = color(r1,c1);
            int sum1 = query1(r2,c2) - query1(r2,c1-1) - query1(r1-1, c2) + query1(r1-1, c1-1);
            int sum2 = query2(r2,c2) - query2(r2,c1-1) - query2(r1-1, c2) + query2(r1-1, c1-1);
            if (cc1)
                printf("%d\n", sum1-sum2);
            else
                printf("%d\n", sum2-sum1);
        }
        else break;
    }
}
