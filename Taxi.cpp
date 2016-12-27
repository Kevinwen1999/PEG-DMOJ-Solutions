#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int V, E, P, D, R;
vector <pair <int, int> > adj[100010];
int dist[100010], done[100010], price[100010];
int dist1[100010], done1[100010], price1[100010];
void spfa(int st, int* dist, int* done, int* price)
{
    queue <int> buff;
    buff.push(st);
    done[st] = true;
    while (!buff.empty())
    {
         int cur = buff.front();
         buff.pop();
         done[cur] = false;
         for (auto i : adj[cur])
         {
             int newprice = price[cur];
             if (dist[cur]<10)
             {
                 if (dist[cur] + i.second > 10)
                 {
                     newprice += (10-dist[cur])*2 + (dist[cur] + i.second-10);
                 }
                 else
                 {
                     newprice += (i.second)*2;
                 }
             }
             else
                newprice += i.second;
             if (newprice < price[i.first])
             {
                 price[i.first] = newprice;
                 dist[i.first] = dist[cur] + i.second;
                 if (!done[i.first])
                 {
                     done[i.first] = true;
                     buff.push(i.first);
                 }
             }
         }
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E>>P>>D>>R;
    for (int i = 0, a, b, c; i < E; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    memset(price, 0x3f, sizeof price);
    dist[P] = 0;
    price[P] = 3;
    spfa(P, dist, done, price);
    if (price[D]==INF)
    {
        cout<<"Nooooooooo!!!";
        return 0;
    }
    memset(price1, 0x3f, sizeof price1);
    dist1[D] = dist[D];
    price1[D] = price[D];
    spfa(D,dist1,done1,price1);
    if (price1[R]==INF)
    {
        cout<<price1[D]<<"\nYippee!!!";
        return 0;
    }
    else
        cout<<price1[R];
}
