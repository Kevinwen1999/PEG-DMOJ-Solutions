#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 5001
using namespace std;
string in;

//char in[MAXN];
bool conv[MAXN];
int N;
int sum[MAXN][MAXN], low[MAXN][MAXN], high[MAXN][MAXN];
int val;
int tot, firsttwoseg, totmin;
int i, j;
//inline int min(int a, int b) {return a < b ? a : b ;}
//inline int max(int a, int b) {return a > b ? a : b ;}
int main()
{
    cin>>in;
    //scanf("%s", &in);
    //N = strlen(in);
    N = in.size();
    /*if (N%2)
    {
        printf("impossible");
        return 0;
    }*/
    for (int i = 0; i < N; i++)
        if (in[i]=='(') conv[i] = 1;
    for (i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            if (j == i)
                sum[i][j] = low[i][j] = high[i][j] = (conv[i] ? 1 : -1);
            else
            {
                val = (conv[j] ? 1 : -1);
                sum[i][j] = sum[i][j-1] + val;
                if (low[i][j-1] < sum[i][j]) low[i][j] = low[i][j-1];
                else low[i][j] = sum[i][j];
                if (high[i][j-1] > sum[i][j]) high[i][j] = high[i][j-1];
                else high[i][j] = sum[i][j];
                //low[i][j] = min(low[i][j-1], sum[i][j]);
                //high[i][j] = max(high[i][j-1], sum[i][j]);
            }
        }
        if (i==0)
        {
            if (sum[0][N-1] == 0 && low[0][N-1] == 0)
            {
                printf("possible");
                return 0;
            }
        }
    }
    //int ilimit = !conv[0] ? 1: N;
    //int jstart = conv[N-1] ? N-1: 0;
    for (i = 0; i < N; i++) // reverse interval i to j
    {
        if (i > 0 && low[0][i-1] < 0) continue;
        for (j = i; j < N; j++)
        {
            if (j < N-1 && conv[N-1]) continue;
            tot = -sum[i][j];
            if (i > 0)
                tot += sum[0][i-1];
            if (j < N-1)
                tot += sum[j+1][N-1];
            if (tot != 0) // number of ( and ) doesn't match
                continue;
            // Since now the number of ( nad ) matches, we only need to find out any sequence have ) that are not pair with (

            firsttwoseg = -sum[i][j];
            if (i > 0)
            {
                firsttwoseg += sum[0][i-1];
                totmin = sum[0][i-1] - high[i][j];
                if (totmin < 0 ) continue;
            }
            else
                totmin = -high[i][j];
            if (totmin < 0 ) continue;
            if (j==N-1)
            {
                printf("possible");
                return 0;
            }
            if (firsttwoseg + low[j+1][N-1] < 0 ) continue;

            printf("possible");
            return 0;
        }
    }
    printf("impossible");
}
