#include <bits/stdc++.h>
#define MAXN 4*1000001
#define INF 0x3f3f3f3f
using namespace std;
struct prob
{
    int mi, ma, vi, va;
};
int N, M;
prob node[MAXN], cur;
void buildtree(int stidx, int L, int R)
{
    if (L==R)
    {
        node[stidx].mi = node[stidx].ma = 0;
        node[stidx].vi = node[stidx].va = L;
        return;
    }
    int le = 2 * stidx, ri =  le + 1, mid = (L + R) / 2;
    buildtree(le, L, mid);
    buildtree(ri, mid+1, R);
    prob p1 = node[le], p2 = node[ri];
    //assign value to node[stidx];
    if (p1.mi<p2.mi)
    {
        node[stidx].mi = p1.mi;
        node[stidx].vi = p1.vi;
    }
    else
    {
        node[stidx].mi = p2.mi;
        node[stidx].vi = p2.vi;
    }
    if (p1.ma>=p2.ma)
    {
        node[stidx].ma = p1.ma;
        node[stidx].va = p1.va;
    }
    else
    {
        node[stidx].ma = p2.ma;
        node[stidx].va = p2.va;
    }
}
//call update(1,0,N-1, index_of_value, value);
void update(int stidx, int L, int R, int idx, int val)
{
    if (L==R)
    {
        if (val == -1)
        {
            node[stidx].mi = INF;
            node[stidx].ma = -INF;
        }
        else if (node[stidx].mi!=INF)
        {
            node[stidx].mi += val;
            node[stidx].ma += val;
        }
        return;
    }
    int le = 2 * stidx, ri = le + 1, mid = (L + R) / 2;
    if (idx <= mid)
        update(le, L, mid, idx, val);
    else
        update(ri, mid+1, R, idx, val);
    prob p1 = node[le], p2 = node[ri];
    //assign value to node[stidx];
    if (p1.mi==INF)
    {
        node[stidx].mi = p2.mi;
        node[stidx].vi = p2.vi;
    }
    else if (p2.mi==INF)
    {
        node[stidx].mi = p1.mi;
        node[stidx].vi = p1.vi;
    }
    else
    {
        if (p1.mi<p2.mi)
        {
            node[stidx].mi = p1.mi;
            node[stidx].vi = p1.vi;
        }
        else
        {
            node[stidx].mi = p2.mi;
            node[stidx].vi = p2.vi;
        }
    }
    if (p1.ma==-INF)
    {
        node[stidx].ma = p2.ma;
        node[stidx].va = p2.va;
    }
    else if (p2.ma==-INF)
    {
        node[stidx].ma = p1.ma;
        node[stidx].va = p1.va;
    }
    else
    {
        if (p1.ma>=p2.ma)
        {
            node[stidx].ma = p1.ma;
            node[stidx].va = p1.va;
        }
        else
        {
            node[stidx].ma = p2.ma;
            node[stidx].va = p2.va;
        }
    }
    //node[stidx] = merge result like in previous using node[le] and node[ri];
}
int main()
{
    cin>>N>>M;
    buildtree(1,0,N-1);
    //cout<<N<<"\n"
    for (int o = 0; o < M; o++)
    {
        int a, b;
        cin>>a>>b;
        //cout<<a<<" "<<b<<"\n";
        if (a==1)
        {
            update(1,0,N-1,b-1,-1);
        }
        else
        {
            update(1,0,N-1,b-1,1);
        }
        if (node[1].mi == INF)
        {
            cout<<"Make noise\n";
        }
        else
            cout<<node[1].va+1<<" "<<node[1].vi+1<<"\n";
    }
}
