#include <bits/stdc++.h>
#define INF 99999.0
using namespace std;
struct node
{
    int i, j, fuel;
};
int N, M, F, k;
double price[101][101];
double dist[101][101][101];
bool inqueue[101][101][101];
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    while (T--)
    {
        cin>>M>>N>>F>>k;
        double c;
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                price[i][j] = INF;
                for (int l = 0; l <= F; l++)
                    dist[i][j][l] = INF;
            }
        }
        for (int i = 0, a, b; i < k; i++)
        {
            cin>>a>>b>>c;
            price[a][b] = min(c, price[a][b]);
        }
        if (F >= M+N)
        {
            cout<<"0.00\n";
            continue;
        }
        queue <node> buff;
        buff.push((node){1,1,F});
        dist[1][1][F] = 0;
        inqueue[1][1][F] = true;
        while (!buff.empty())
        {
            node cur = buff.front();
            buff.pop();
            inqueue[cur.i][cur.j][cur.fuel] = false;
            if (!cur.fuel && price[cur.i][cur.j]==INF) continue;
            for (int i = 0; i < 4; i++)
            {
                int ni = cur.i+di[i], nj = cur.j+dj[i];
                if (ni <= 0 || nj <= 0 || ni > M || nj > N) continue;
                if (price[cur.i][cur.j]!=INF)
                {
                    for (int pf = cur.fuel>0?0:1; cur.fuel+pf <= F; pf++)
                    {
                        double newdist = dist[cur.i][cur.j][cur.fuel] + pf*price[cur.i][cur.j];
                        if (dist[ni][nj][cur.fuel+pf-1] > newdist)
                        {
                            dist[ni][nj][cur.fuel+pf-1] = newdist;
                            if (!inqueue[ni][nj][cur.fuel+pf-1])
                            {
                                inqueue[ni][nj][cur.fuel+pf-1] = true;
                                buff.push((node){ni,nj,cur.fuel+pf-1});
                            }
                        }
                    }
                }
                else
                {
                    if (!cur.fuel) continue;
                    if (dist[ni][nj][cur.fuel-1] > dist[cur.i][cur.j][cur.fuel])
                    {
                        dist[ni][nj][cur.fuel-1] = dist[cur.i][cur.j][cur.fuel];
                        if (!inqueue[ni][nj][cur.fuel-1])
                        {
                            inqueue[ni][nj][cur.fuel-1] = true;
                            buff.push((node){ni,nj,cur.fuel-1});
                        }
                    }
                }
            }
        }
        double ans = INF;
        for (int i = 0; i <= F; i++)
            ans = min(ans, dist[M][N][i]);
        if (ans >= INF)
            cout<<"Stranded on the shoulder\n";
        else
            cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
}
