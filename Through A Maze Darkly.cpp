#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 100010;
map <int,int> doormap[MAXN];
int maxpath[MAXN], startdist[MAXN];
int N;
struct door
{
    int nexRoom;
    int nexDoor;
    bool visited;
} curdoor;
vector <door> adj[MAXN];
void init_dist()
{
    for (int i = 0; i < N; i++)
        startdist[i] = -1;
}
void process_room(int CR, int dist)
{
    if (startdist[CR] == -1)
        startdist[CR] = dist;
    else
    {
        int path_dist = dist - startdist[CR];
        if (path_dist > maxpath[CR])
            maxpath[CR] = path_dist;
        startdist[CR] = dist;
    }
}
void explore_path(int startRoom, int startDoor)
{
    int curR = startRoom;
    int curD = startDoor;
    int dist = 0, pass = 0;
    init_dist();
    while (pass < 2)
    {
        process_room(curR, dist);
        dist++;
        adj[curR][curD].visited = true;
        int nR = adj[curR][curD].nexRoom;
        int nD = adj[curR][curD].nexDoor;
        curR = nR; curD = nD;
        if (curR == startRoom && curD == startDoor) pass++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int a; cin>>a;
        for (int j = 0,x; j < a; j++)
        {
            cin>>x; x--;
            curdoor.nexRoom = x;
            curdoor.visited = false;
            adj[i].push_back(curdoor);
            doormap[x][i] = j;
        }
    }
    for (int i = 0; i < N; i++)
    {
        int cnt = adj[i].size();
        for (int j = 0; j < cnt; j++)
        {
            int nxRoom = adj[i][j].nexRoom;
            int nxDoor = doormap[i][nxRoom] - 1;
            if (nxDoor == -1) nxDoor = (int)(adj[nxRoom].size())-1;
            adj[i][j].nexDoor = nxDoor;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (adj[i][j].visited==false)
                explore_path(i,j);
        }
    }
    int Q; cin>>Q;
    for (int i = 0; i < Q; i++)
    {
        int q; cin>>q;
        cout<<maxpath[--q]<<"\n";
    }
}
