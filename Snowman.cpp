#include <iostream>
#include <cstring>
using namespace std;

int M, N, S;
int sz[11];
char grid[11][11];
bool recur(int cur)
{
    if (cur==S) return true;
    bool OK = false;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + sz[cur] <= M)
            {
                OK = true;
                for (int l = 0; l < sz[cur] && OK; l++)
                    OK &= (grid[i+l][j] == '0');
                if (OK)
                {
                    for (int l = 0; l < sz[cur]; l++)
                        grid[i+l][j] = '1';
                    if (recur(cur+1))
                        return true;
                    for (int l = 0; l < sz[cur]; l++)
                        grid[i+l][j] = '0';
                }
            }
            if (j + sz[cur] <= N)
            {
                OK = true;
                for (int l = 0; l < sz[cur] && OK; l++)
                    OK &= (grid[i][j+l] == '0');
                if (OK)
                {
                    for (int l = 0; l < sz[cur]; l++)
                        grid[i][j+l] = '1';
                    if (recur(cur+1))
                        return true;
                    for (int l = 0; l < sz[cur]; l++)
                        grid[i][j+l] = '0';
                }
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d %d %d", &M, &N, &S);
    for (int i = 0; i < S; i++) scanf("%d", &sz[i]);
    for (int i = 0; i < M; i++) scanf("%s", &grid[i]);
    if (recur(0)) cout<<"yes";
    else cout<<"no";
}
