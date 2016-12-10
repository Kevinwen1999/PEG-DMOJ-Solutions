#include <bits/stdc++.h>

using namespace std;
int N,H;
int graph[1600][1600];
bool visited[1600][1600];
int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};
int main()
{
    cin>>N>>H;
    for (int i = 0 ; i < N; i++)
        for (int j = 0 ; j < N; j++)
            cin>>graph[i][j];
    memset(visited,0,sizeof visited);
    queue <pair <int,int> > buff;
    buff.push(make_pair(0,0));
    visited[0][0] = 1;
    int ci, cj;
    pair<int, int> cur, tmp;
    bool flag = 0;
    while(!buff.empty())
    {
        cur = buff.front();
        buff.pop();
        ci = cur.first; cj = cur.second;
        if (ci==N-1&&cj==N-1)
        {
            flag = true;
            cout<<"yes\n"; break;
        }
        for (int i = 0 ; i < 4; i++)
        {
            ci = cur.first+di[i]; cj = cur.second +dj[i];
            if (ci<0||cj<0||ci>=N||cj>=N) continue;
            if (visited[ci][cj]) continue;
            if (abs(graph[cur.first][cur.second]-graph[ci][cj])>H) continue;
            visited[ci][cj] = 1;
            tmp = make_pair(ci,cj);
            buff.push(tmp);
        }
    }
    if (!flag)
        cout<<"no\n";
}
