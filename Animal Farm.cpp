#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
int p[MAXN], rnk[MAXN];
void init(int N)
{
    for (int i = 0; i <= N; i++)
        p[i] = i, rnk[i] = 1;
}
int findp(int x)
{
    return p[x] == x ? x : (p[x] = findp(p[x]));
}
bool sameset(int x, int y)
{
    return findp(x) == findp(y);
}
void mergeset(int x, int y)
{
    if (!sameset(x, y))
    {
        x = findp(x), y = findp(y); // EXTREMELY IMPORTANT !!!!!!!!!
        if (rnk[x] > rnk[y])
            rnk[x] += rnk[y], p[y] = x;
        else
            rnk[y] += rnk[x], p[x] = y;
    }
}
int N;
int pen[10], price[10];
set < pair <int,int> > P;
map <pair <int,int> , int> M, ps;
vector < pair <int, pair <int,int> > > EdgeList, alt;
int main()
{
    cin>>N;
    for (int a = 1; a <=N; a++)
    {
        int S; cin>>S;
        for (int i = 0; i < S; i++)
            cin>>pen[i];
        for (int i = 0; i < S; i++)
            cin>>price[i];
        for (int i = 0; i < S; i++)
        {
            int f = pen[i], e = pen[(i+1)%S];
            if (f > e) swap(f,e);
            pair <int,int> b = {f,e};
            if (P.count(b))
            {
                EdgeList.push_back({price[i], {a, M[b]}});
                alt.push_back({price[i], {a, M[b]}});
                P.erase(b);
            }
            else
            {
                P.insert(b);
                M[b] = a;
                ps[b] = price[i];
            }
        }
    }
    for (auto i : P)
    {
        alt.push_back({ps[i],{0,M[i]}});
    }
    init(N);
    sort(EdgeList.begin(), EdgeList.end());
    sort(alt.begin(), alt.end());
    int mcost1 = 0;
    for (auto i : EdgeList)
    {
        if (!sameset(i.second.first, i.second.second))
        {
            mcost1 += i.first;
            mergeset(i.second.first, i.second.second);
        }
    }
    int mcost2 = 0;
    init(N);
    for (auto i : alt)
    {
        if (!sameset(i.second.first, i.second.second))
        {
            mcost2 += i.first;
            mergeset(i.second.first, i.second.second);
        }
    }
    cout<<min(mcost1, mcost2);
}
