#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 100010
using namespace std;
int arr[100010];
int mint[4*100010], maxt[4*100010];
int N, K;
int builtmaxt(int L, int R, int tid)
{
    if (L==R)
    {
        return maxt[tid] = arr[L];
    }
    return maxt[tid] = max(builtmaxt(L,(L+R)/2, tid<<1), builtmaxt((L+R)/2+1, R, tid<<1|1));
}
int querymax(int L, int R, int le, int re, int tid)
{
    if (L>=le && R<= re) return maxt[tid];
    if (le>R || re < L) return -1;
    return max(querymax(L, (L+R)/2, le, re, tid<<1), querymax((L+R)/2+1, R, le, re, tid<<1|1));
}
int builtmint(int L, int R, int tid)
{
    if (L==R)
    {
        return mint[tid] = arr[L];
    }
    return mint[tid] = min(builtmint(L,(L+R)/2, tid<<1), builtmint((L+R)/2+1, R, tid<<1|1));
}
int querymin(int L, int R, int le, int re, int tid)
{
    if (L>=le && R<= re) return mint[tid];
    if (le>R || re < L) return INF;
    return min(querymin(L, (L+R)/2, le, re, tid<<1), querymin((L+R)/2+1, R, le, re, tid<<1|1));
}
int searchmax(int l, int r)
{
    int s = l;
    int mid;
    while (l<=r)
    {
        mid = (l+r)/2;
        //cout<<l<<" "<<r<<endl;
        if (querymax(1,N,s,mid,1) - querymin(1,N,s,mid,1)<=K)
            l = mid+1;
        else
            r = mid-1;
    }
    return r;
}
int maxl[MAXN];
int findlastinrange(int l, int r)
{
    int mid;
    int e = r;
    while(l<=r)
    {
        mid = (l+r)/2;
        //cout<<mid<<"\n";
        if (mid+maxl[mid]-1 < e)
        {
            l = mid+1;
        }
        else
            r = mid-1;
    }
    return l;
}
struct node
{
    int maxlength;
    int index;
} mx;
node st[4*MAXN];
void buildtree(int L, int R, int tid)
{
    if (L==R)
    {
        st[tid].maxlength = maxl[L];
        st[tid].index = L;
        return;
    }
    int mid = (L+R)/2;
    buildtree(L,mid, tid<<1); buildtree(mid+1, R, tid<<1|1);
    if (st[tid<<1].maxlength >= st[tid<<1|1].maxlength)
        st[tid] = st[tid<<1];
    else
        st[tid] = st[tid<<1|1];
}
node querytree(int L, int R, int le, int re, int tid)
{
    if (L>=le && R<=re) return st[tid];
    if (le>R || re < L) return (node){-1,-1};
    int mid = (L+R)/2;
    node n1 = querytree(L,mid,le,re,tid<<1), n2 = querytree(mid+1,R,le,re,tid<<1|1);
    if (n1.maxlength>=n2.maxlength)
        return n1;
    else
        return n2;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for (int i = 1; i <= N; i++)
        cin>>arr[i];
    builtmaxt(1,N,1);
    builtmint(1,N,1);
    for (int i = 1; i <= N; i++)
    {
        maxl[i] = searchmax(i,N) - i + 1;
        //cout<<maxl[i]<<"\n";
    }
    buildtree(1,N,1);
    //cout<<findlastinrange(1,N);
    int Q; cin>>Q;
    for (int x = 0; x < Q; x++)
    {
        //cout<<"------\n";
        int a, b; cin>>a>>b;
        int last = findlastinrange(a,b);
        //cout<<last<<"\n";
        int ansl = -1, ansidx;
        //if (last==a) {cout<<a<<" "<<b<<"\n"; continue;}

        mx = querytree(1,N,a,last-1,1);
        ansl = min(b-mx.index+1, mx.maxlength);
        ansidx = mx.index;

        int ans2 = b-last+1;
        if (ans2 > ansl)
        {
            //cout<<last<<endl;
            ansl = ans2;
            ansidx = last;
        }
        //cout<<ans2<<"\n";
        cout<<ansidx<<" "<<ansidx+ansl-1<<"\n";
    }
    //cout<<maxl[3]<<" "<<maxl[4];
}
