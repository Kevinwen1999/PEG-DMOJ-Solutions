#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 50;
int adj[51][51];
int dist[51];
bool taken[51];
int N;
char in;
int a, b;
int main()
{
    adj[1][6] = adj[6][1] = 1;
    adj[2][6] = adj[6][2] = 1;
    adj[3][6] = adj[6][3] = 1;
    adj[4][6] = adj[6][4] = 1;
    adj[5][6] = adj[6][5] = 1;
    adj[7][6] = adj[6][7] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[3][5] = adj[5][3] = 1;
    adj[3][15] = adj[15][3] = 1;
    adj[4][5] = adj[5][4] = 1;
    adj[7][8] = adj[8][7] = 1;
    adj[8][9] = adj[9][8] = 1;
    adj[9][12] = adj[12][9] = 1;
    adj[9][10] = adj[10][9] = 1;
    adj[10][11] = adj[11][10] = 1;
    adj[11][12] = adj[12][11] = 1;
    adj[12][13] = adj[13][12] = 1;
    adj[13][14] = adj[14][13] = 1;
    adj[13][15] = adj[15][13] = 1;
    adj[16][18] = adj[18][16] = 1;
    adj[16][17] = adj[17][16] = 1;
    adj[17][18] = adj[18][17] = 1;
    while (1)
    {
        cin>>in;
        if (in == 'q') break;
        if (in == 'i')
        {
            cin>>a>>b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        else if (in == 'd')
        {
            cin>>a>>b;
            adj[a][b] = 0;
            adj[b][a] = 0;
        }
        else if (in == 'n')
        {
            cin>>a;
            int cnt = 0;
            for (int i = 1; i <= MAXN; i++)
                if (adj[a][i]) cnt++;
            cout<<cnt<<"\n";
        }
        else if (in == 'f')
        {
            cin>>a;
            memset(taken, 0, sizeof taken);
            int cnt = 0;
            for (int i = 1; i <= MAXN; i++)
            {
                if (adj[a][i])
                    for (int j = 1; j <= MAXN; j++)
                        if (adj[i][j]&&!adj[a][j]&&j!=a&&!taken[j]) cnt++, taken[j] = true;
            }
            cout<<cnt<<"\n";
        }
        else if (in == 's')
        {
            cin>>a>>b;
            queue <int> buff;
            memset(dist, 63, sizeof dist);
            dist[a] = 0;
            buff.push(a);
            int cur;
            while (!buff.empty())
            {
                cur = buff.front();
                buff.pop();
                if (cur==b) break;
                for (int i = 1 ; i <= MAXN; i++)
                {
                    if (adj[cur][i] &&dist[i]==INF)
                    {
                        dist[i] = dist[cur]+1;
                        buff.push(i);
                    }
                }
            }
            if (dist[b]==INF)
                cout<<"Not connected\n";
            else
                cout<<dist[b]<<"\n";
        }
    }
}
