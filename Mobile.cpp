#include <bits/stdc++.h>
#define B 10000
#define MAXN 100010 + B
using namespace std;
struct node
{
    int left;
    int right;
};
int N;
node t1[MAXN], t2[MAXN];
set<int> tid[2*MAXN+1+2*MAXN];
void mark(int tidx, int u)
{
    tid[t1[u].left+B].insert(2*tidx);
    tid[t1[u].right+B].insert(2*tidx+1);
    if (t1[u].left > 0)
        mark(2*tidx,t1[u].left);
    if (t1[u].right > 0)
        mark(2*tidx+1,t1[u].right);
}
bool check(int tidx, int u)
{
    if (t2[u].left > 0 && t2[u].right > 0)
    {
        if ((check(tidx*2, t2[u].left) && check(tidx*2+1,t2[u].right))||(check(tidx*2+1, t2[u].left) && check(tidx*2,t2[u].right)))
            return true;
        else
            return false;
    }
    else if (t2[u].left > 0)
    {
        if ((check(tidx*2, t2[u].left) && (tid[t2[u].right+B].count(tidx*2+1)))||((check(tidx*2+1,t2[u].left) && (tid[t2[u].right+B].count(tidx*2)))))
            return true;
        else
            return false;
    }
    else if (t2[u].right > 0)
    {
        if ((check(tidx*2, t2[u].right) && (tid[t2[u].left+B].count(tidx*2+1)))||((check(tidx*2+1, t2[u].right) && (tid[t2[u].left+B].count(tidx*2)))))
            return true;
        else
            return false;
    }
    else
    {
        if (((tid[t2[u].left+B].count(tidx*2))&& (tid[t2[u].right+B].count(tidx*2+1)) ) ||( (tid[t2[u].left+B].count(tidx*2+1)) && (tid[t2[u].right+B].count(tidx*2))))
            return true;
        else
            return false;
    }
}
int main()
{
    cin>>N;
    int pre = N;
    for (int i = 1; i <= N; i++)
    {
        cin>>t1[i].left>>t1[i].right;
    }
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        cin>>t2[i].left>>t2[i].right;
    }
    if (pre!=N)
    {
        cout<<"Fred and Mary have different mobiles.";
        return 0;
    }
    tid[1+B].insert(1);
    mark(1,1);
    bool ans = check(1,1);
    if (ans)
        cout<<"Fred and Mary might have the same mobile.";
    else
        cout<<"Fred and Mary have different mobiles.";
}
