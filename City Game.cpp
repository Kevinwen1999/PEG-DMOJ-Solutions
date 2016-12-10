#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N, M;
const int MAXN = 1000 + 1;
char grid[MAXN][MAXN];
int height[MAXN];

struct Rect
{
    int c, h;
    Rect(int cc = 0 , int hh = 0 )
    {
        c = cc;
        h = hh;
    }
}rect[MAXN];

int main()
{
    scanf(" %d", &T);
    while (T--)
    {
        scanf(" %d %d", &M, &N);
        for (int i = 0 ; i < M; i++)
            for (int j = 0 ; j < N; j++)
                scanf(" %c", &grid[i][j]);
        memset(height, 0, sizeof height);
        int maxa = 0;
        for (int i = 0 ; i < M; i++)
        {
            int top = -1;
            for (int j = 0 ; j < N; j++)
            {
                if (grid[i][j] == 'R')
                {
                    height[j] = 0;
                    top = -1;
                }
                else
                {
                    height[j]++;
                    Rect r(j, height[j]);
                    if (top == -1) rect[++top] = r;
                    else
                    {
                        while (top >=0 && rect[top].h >= r.h)
                            r.c = rect[top--].c;
                        rect[++top] = r;
                    }
                    for (int k = 0 ; k <= top; k++)
                        maxa = max(maxa, rect[k].h*(j - rect[k].c + 1));
                }
            }
        }
        printf("%d\n", maxa * 3);
    }
}
