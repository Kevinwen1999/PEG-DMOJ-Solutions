#include <bits/stdc++.h>
#define MAXN 510
using namespace std;
int N;
int sid, eid;
int pfirst = 0x3f3f3f3f, pp;
int xtot;
map <int , set <int> > hm;
vector <int> adj[MAXN];
struct clas
{
    int pi,si;
    set <int> stus;
};
bool cmp (clas &a, clas &b)
{
    return a.pi<b.pi;
}
vector <clas> allc;
set <pair <int,int> > pos;
int dist[MAXN];
void bfs()
{
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    queue <int> buff; buff.push(0);
    while (!buff.empty())
    {
        int cur = buff.front(); buff.pop();
//        cout<<"cur == "<<cur<<"\n";
        for (int i : adj[cur])
        {
//            cout<<"next:"<<i<<"\n";
            if (dist[i] > dist[cur]+1)
            {
                dist[i] = dist[cur] + 1;
                buff.push(i);
            }
        }
    }
}
int main()
{
    cin>>N;
    cin>>sid>>eid;
    clas cc; cc.pi = 0; cc.stus.insert(sid);
    allc.push_back(cc);
    for (int i = 0, tp, ts; i < N; i++)
    {
        cin>>tp>>ts;
        clas cur; cur.pi = tp; cur.si = ts;
        for (int j = 0, a; j < ts; j++)
        {
            cin>>a;
            cur.stus.insert(a);
            if (a==sid && pfirst > tp) {pfirst = min(pfirst, tp);pp=i;}
        }
        allc.push_back(cur);
    }
    sort(allc.begin(),allc.end(), cmp);
//    for (auto i : allc)
//        cout<<i.si<<"\n";
    for (int i = 0; i <= N; i++)
    {
//        cout<<i<<" class\n";
        clas cur = allc[i];
        for (int j : cur.stus)
        {
            if (!hm[j].empty())
                for (int k : hm[j])
                {
                    if (allc[k].pi!=cur.pi)
                    {
                        if (pos.count({k,i})) continue;
//                        cout<<"connect "<<k<<" to "<<i<<"\n";
                        adj[k].push_back(i);
                        pos.insert({k,i});
                    }

                }
            hm[j].insert(i);
        }
    }
    bfs();
    int minn = 0x3f3f3f3f, idx;
    for (int i = 0; i <= N; i++)
    {
        clas cur = allc[i];
        if (cur.stus.count(eid))
        {
            if (minn > dist[i])
            {
                minn = dist[i];
                idx = cur.pi;
            }
            else if (minn == dist[i])
                idx = min(idx, cur.pi);
        }
    }
    if (minn == 0x3f3f3f3f) cout<<"delivery failure\n";
    else cout<<minn<<"\n"<<idx<<"\n";
}
