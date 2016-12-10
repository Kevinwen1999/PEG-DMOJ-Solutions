#include <bits/stdc++.h>
using namespace std;
bool ison(int n, int idx) { return n & (1 << idx); }
int seton(int n, int idx) { return n | (1 << idx); }
int setoff(int n, int idx) { return n & ~(1 << idx); }
int m, n, a, b, c, fin, start;
bool visited[1 << (4*5+1)], isEden[1<<(4*5+1)], state[6][6];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool nstate[6][6];
int intid(int x, int y) { return x * n + y; }
vector <int> adj[(1<<21)];
queue <pair <int,int> > Q;
int main()
{
    cin>>m>>n>>a>>b>>c;
    string in;
    for (int i = 0 ; i < m; i++)
    {
        cin>>in;
        for (int j = 0 ; j < n; j++)
            if (in[j] == '*')
                start = seton(start, intid(i, j));
    }
    for (int st = 0; st  < (1<<(m*n)); st++)
    {
        memset(state, 0, sizeof state);
        memset(nstate, 0, sizeof nstate);
        // current state decompress
        for (int i = 0 ; i < m; i++)
            for (int j = 0 ; j < n; j++)
            {
                if (ison(st, intid(i,j)))
                    state[i][j] = true;
            }
        // calculate next state
        for (int i = 0 ; i < m; i++)
            for (int j = 0 ; j < n; j++)
            {
                int cnt = 0;
                for (int k = 0 ; k < 8; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    if (state[nx][ny]) cnt++;
                }
                if (state[i][j])
                {
                    if (cnt < a || cnt > b) nstate[i][j] = false;
                    else nstate[i][j] = true;
                }
                else
                {
                    if (cnt > c) nstate[i][j] = true;
                    else nstate[i][j] = false;
                }
            }
        int intns = 0;
        for (int i = 0 ; i < m; i++)
            for (int j = 0 ; j < n; j++)
                if (nstate[i][j])
                    intns = seton(intns, intid(i, j));
        if (intns == st)
            isEden[st] = true;
        else
            adj[intns].push_back(st);
    }
    bool hasanswer = false;
    Q.push(make_pair(start, 0));
    int cur, moves;
    while (!Q.empty())
    {
        cur = Q.front().first, moves = Q.front().second;
        Q.pop();
        if (adj[cur].size()==0)
        {
            cout<<moves<<"\n";
            hasanswer = true;
            break;
        }
        if (visited[cur]) continue;
        else visited[cur] = true;
        for (int i = 0 ; i < adj[cur].size(); i++)
        {
            Q.push(make_pair(adj[cur][i], moves+1));
        }
    }
    if (!hasanswer)
        cout<<"-1\n";
}
