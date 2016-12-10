#include <bits/stdc++.h>
using namespace std;
char graph[55][55];
int visited[55][55];
int l, w;
int si, sj;
int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};
int main()
{
    int T; cin>>T;
    while (T--)
    {
        memset(visited,-1,sizeof visited);
        cin>>l>>w;
        string in;
        for (int i = 0 ; i < w; i++)
        {
            cin>>in;
            for (int j = 0; j <l; j++)
            {
                graph[i][j] = in[j];
                if (graph[i][j] == 'C'){si = i; sj = j;}
            }
        }
        queue < pair <int,int> > buff;
        pair <int,int> cur = make_pair(si,sj), tmp;
        buff.push(cur);
        visited[si][sj] = 0;
        int ci, cj;
        bool flag = false;
        while(!buff.empty())
        {
            cur = buff.front();
            buff.pop();
            ci = cur.first; cj = cur.second;
            if (graph[ci][cj] =='W')
            {
                flag = true;
                if (visited[ci][cj]>=60) cout<<"#notworth\n"; else cout<<visited[ci][cj]<<"\n"; break;
            }
            for (int i = 0 ; i < 4; i++)
            {
                ci = cur.first+di[i]; cj = cur.second +dj[i];
                if (ci<0||cj<0||ci>=w||cj>=l) continue;
                if (graph[ci][cj]=='X'||visited[ci][cj]!=-1) continue;
                visited[ci][cj] = visited[cur.first][cur.second]+ 1;
                tmp = make_pair(ci,cj);
                buff.push(tmp);
            }
        }
        if (!flag)
            cout<<"#notworth\n";
    }
}
