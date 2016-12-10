#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int R, C, T;
int si, sj, ei, ej;
char graph[1010][1010];
int visited[1010][1010];
bool istele[1010][1010];
int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};
int main()
{
    cin>>R>>C;
    cin>>si>>sj>>ei>>ej;
    for (int i = 0; i < R; i++)
        cin>>graph[i];
    cin>>T;
    vector <pair <int,int> > tele;
    memset(istele,0,sizeof istele);
    for (int i = 0, a,b ; i < T; i++)
    {
        cin>>a>>b;
        tele.push_back(make_pair(a,b));
        istele[a][b] = 1;
    }
    memset(visited,63,sizeof visited);
    queue <pair <int,int> > buff;
    visited[si][sj] = 0;
    buff.push(make_pair(si,sj));
    pair <int,int> cur, tmp;
    int ci, cj;
    while (!buff.empty())
    {
        cur = buff.front();
        buff.pop();
        if (cur.first==ei && cur.second==ej) break;
        if (istele[cur.first][cur.second]) continue;
        for (int i = 0 ; i < 4; i++)
        {
            ci = cur.first+di[i]; cj = cur.second +dj[i];
            if (ci<0||cj<0||ci>=R||cj>=C) continue;
            if (visited[ci][cj]<=visited[cur.first][cur.second]) continue;
            if (graph[ci][cj]=='X') continue;
            visited[ci][cj] = visited[cur.first][cur.second]+1;
            tmp = make_pair(ci,cj);
            buff.push(tmp);
        }
    }
    int ans = INF, mi, mj;
    for (int i = 0 ; i < T; i++)
    {
        cur = tele[i];
        if(ans>visited[cur.first][cur.second])
        {
            ans = visited[cur.first][cur.second];
            mi = cur.first; mj = cur.second;
        }
    }
    if (visited[ei][ej]==INF)
    {
        while (!buff.empty()) buff.pop();
        buff.push(make_pair(mi,mj));
        while (!buff.empty())
        {
            cur = buff.front();
            buff.pop();
            if (cur.first==ei && cur.second==ej) break;
            for (int i = 0 ; i < 4; i++)
            {
                ci = cur.first+di[i]; cj = cur.second +dj[i];
                if (ci<0||cj<0||ci>=R||cj>=C) continue;
                if (visited[ci][cj]<=visited[cur.first][cur.second]) continue;
                if (graph[ci][cj]=='X') continue;
                visited[ci][cj] = visited[cur.first][cur.second]+1;
                tmp = make_pair(ci,cj);
                buff.push(tmp);
            }
        }
    }
    cout<<((visited[ei][ej]-ans < 0) ? 0 : visited[ei][ej]-ans)<<"\n";
}
