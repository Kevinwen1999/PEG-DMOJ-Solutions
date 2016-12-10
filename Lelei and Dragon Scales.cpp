#include <iostream>
#include <cstring>
using namespace std;
int W, H, N;
const int MAXN = 251;
int grid[MAXN][MAXN];

int main()
{
    scanf("%d%d%d", &W, &H, &N);
    for (int i = 0 ; i < H; i++)
    {
        for (int j = 0 ; j < W; j++)
        {
            scanf("%d", &grid[i][j]);
            if (i > 0) grid[i][j] += grid[i-1][j];
            if (j > 0) grid[i][j] += grid[i][j-1];
            if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
        }
    }
    int maxx = 0;
    for (int i = 0 ; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            for (int m = 1; m <= N && (i+m-1) < H; m++)
            {
                int l = min ((int)(N/m) + j - 1, W-1);
                int k = i + m - 1;
                int sum = grid[k][l];
                if (i > 0) sum -= grid[i-1][l];
                if (j > 0) sum -= grid[k][j-1];
                if (i > 0 && j > 0) sum += grid[i-1][j-1];
                maxx = max(maxx, sum);
            }
        }
    }
    cout<<maxx<<"\n";
}
