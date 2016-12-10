#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N, M;
const int MAXN = 1000 + 1;
int ori[MAXN][MAXN];
int height[MAXN][MAXN];
struct Rect
{
    int c, h, color;
    long long sum;
    Rect(int cc = 0 , int hh = 0 , int oo = 0, long long ssum = 0)
    {
        c = cc;
        h = hh;
        color = oo;
        sum = ssum;
    }
}rect[MAXN];

int main()
{
    scanf(" %d %d", &M, &N);
    for (int i = 0 ; i < M; i++)
        for (int j = 0 ; j < N; j++)
            scanf(" %d", &ori[i][j]);
    long long cnt = 0;
    for (int i = 0 ; i < M; i++)
    {
        int top = -1;
        for (int j = 0 ; j < N; j++)
        {
            height[i][j] = 1;
            if (i > 0 && ori[i-1][j] == ori[i][j]) height[i][j] += height[i-1][j];
            int hori = 1;
            while (top >= 0 && rect[top].color == ori[i][j] && rect[top].h >= height[i][j])
            {
                hori += rect[top--].c;
            }
            long long sum = hori * height[i][j];
            if (rect[top].color==ori[i][j]) sum+=rect[top].sum;
            cnt += sum;
            rect[++top] = Rect(hori, height[i][j], ori[i][j], sum);
        }
    }
    printf("%lld\n", cnt);
}
