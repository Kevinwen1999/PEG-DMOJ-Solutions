#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 270000;
int node[MAXN];
int gc[MAXN];
int cc[MAXN];
int N, M;
int A[100010];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
void buildtree(int stidx, int L, int R)
{
    if (L==R)
    {
        node[stidx] = L;
        gc[stidx] = A[L];
        cc[stidx] = 1;
        return;
    }
    int le = 2 * stidx, ri = le + 1, mid = (L + R) / 2;
    buildtree(le, L, mid);
    buildtree(ri, mid+1, R);
    int p1 = node[le], p2 = node[ri];
    int p3 = gc[le], p4 = gc[ri];
    node[stidx] = (A[p1]<=A[p2]) ? p1 : p2;
    gc[stidx] = gcd(p3, p4);
    /*for (int i = L; i <= R; i++)
    {
        if (A[i]==gc[stidx])
            cc[stidx]++;
    }*/
    if (p3 == gc[stidx]) cc[stidx]+=cc[le];
    else for (int i = L; i <= mid; i++) if (A[i]==gc[stidx]) cc[stidx]++;
    if (p4 == gc[stidx]) cc[stidx]+=cc[ri];
    else for (int i = mid+1; i <= R; i++) if (A[i]==gc[stidx]) cc[stidx]++;
}
//call query(1,0,N-1,i,j);
int queryrcm(int stidx, int L, int R, int i, int j) // i and j are the given range
{
    if (i > R || j < L) return -1; //out of range
    if (L >= i && R <= j) return node[stidx];
    int p1 = queryrcm(2*stidx, L, (L+R)/2, i,j);
    int p2 = queryrcm(2*stidx + 1, (L+R)/2 + 1, R, i,j);
    if (p1==-1) return p2;
    if (p2==-1) return p1;
    return (A[p1]<=A[p2]) ? p1 : p2;
}
int querygcd(int stidx, int L, int R, int i, int j)
{
    if (i > R || j < L) return -1; //out of range
    if (L >= i && R <= j) return gc[stidx];
    int p1 = querygcd(2*stidx, L, (L+R)/2, i,j);
    int p2 = querygcd(2*stidx + 1, (L+R)/2 + 1, R, i,j);
    if (p1==-1) return p2;
    if (p2==-1) return p1;
    return gcd(p1, p2);
}
int querycc(int stidx, int L, int R, int i, int j, int val)
{
    if (i > R || j < L) return -1; //out of range
    if (L >= i && R <= j)
    {
        if (gc[stidx]>val) return 0;
        if (L==R)
        {
            if (A[L]==val) return 1;
            else return 0;
        }
        if (gc[stidx]==val) return cc[stidx];
    }
    int p1 = querycc(2*stidx, L, (L+R)/2, i,j,val);
    int p2 = querycc(2*stidx + 1, (L+R)/2 + 1, R, i,j,val);
    if (p1==-1) return p2;
    if (p2==-1) return p1;
    return p1 + p2;
}
//call update(1,0,N-1, index_of_value, value);
void update(int stidx, int L, int R, int idx, int val)
{
    if (L==R)
    {
        node[stidx] = L;
        gc[stidx] = A[L];
        cc[stidx] = 1;
        return;
    }
    int le = 2 * stidx, ri = le + 1, mid = (L + R) / 2;
    if (idx <= mid)
        update(le, L, mid, idx, val);
    else
        update(ri, mid+1, R, idx, val);
    int p1 = node[le], p2 = node[ri];
    int p3 = gc[le], p4 = gc[ri];
    node[stidx] = (A[p1]<=A[p2]) ? p1 : p2;
    gc[stidx] = gcd(p3, p4);
    cc[stidx]=0;
    if (p3 == gc[stidx]) cc[stidx]+=cc[le];
    else for (int i = L; i <= mid; i++) if (A[i]==gc[stidx]) cc[stidx]++;
    if (p4 == gc[stidx]) cc[stidx]+=cc[ri];
    else for (int i = mid+1; i <= R; i++) if (A[i]==gc[stidx]) cc[stidx]++;
}
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0 ; i < N; i++)
        scanf("%d", &A[i]);
    buildtree(1, 0, N-1);
    char in;
    int n1, n2;
    for (int i = 0; i < M; i++)
    {
        scanf(" %c %d %d", &in, &n1, &n2);
        n1--;
        if (in == 'C')
        {
            A[n1] = n2;
            update(1,0,N-1, n1, n2);
        }
        else if (in == 'G')
        {
            n2--;
            printf("%d\n", querygcd(1,0,N-1,n1,n2));
        }
        else if (in == 'M')
        {
            n2--;
            printf("%d\n", A[queryrcm(1,0,N-1,n1,n2)]);
        }
        else if (in == 'Q')
        {
            n2--;
            int v = querygcd(1,0,N-1,n1,n2);
            printf("%d\n", querycc(1,0,N-1,n1,n2,v));
        }
    }
}
