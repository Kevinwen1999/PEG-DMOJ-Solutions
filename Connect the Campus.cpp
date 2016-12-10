#include <bits/stdc++.h>
using namespace std;
int N;
class UnionFind
{
    private:
        vector < int > p;
        vector <int> rankx;
    public:
        UnionFind(int N) { rankx.assign(N, 0); p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j)
        {
            if (!isSameSet(i,j))
            {
                int x = findSet(i), y = findSet(j);
                if (rankx[x] > rankx[y])
                    p[y] = x;
                else
                {
                    p[x] = y;
                    if (rankx[x] == rankx[y])
                        rankx[y]++;
                }
            }
        }
};

struct point
{
    double x, y;
} curp;
double dist (point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
vector <point> ap;
set <int> prec[755];
vector < pair <double, pair <int,int> > > EdgeList;
pair <double, pair <int,int> > cur;
vector <pair <int,int> >sol;
double mst_cost;
int main()
{
    cin>>N;
    UnionFind u(N);
    for (int i = 0; i < N; i++)
    {
        cin>>curp.x>>curp.y;
        ap.push_back(curp);
    }
    int M; cin>>M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin>>a>>b;
        a--; b--;
        if (a>b)
        {
            a = a ^b; b = a ^ b; a = a ^b;
        }
        prec[a].insert(b);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double d = dist(ap[i],ap[j]);
            cur = make_pair(d, make_pair(i, j));
            if (prec[i].count(j) > 0)
            {
                //mst_cost += d;
                u.unionSet(i,j);
            }
            else
            {
                EdgeList.push_back(cur);
            }
        }
    }
    sort(EdgeList.begin(), EdgeList.end());
    for (int i = 0; i < EdgeList.size(); i++)
    {
        cur = EdgeList[i];
        if (!u.isSameSet(cur.second.first, cur.second.second))
        {
            mst_cost+=cur.first;
            u.unionSet(cur.second.first, cur.second.second);
            sol.push_back({cur.second.first, cur.second.second});
        }
    }
    printf("%.2lf\n", mst_cost);
    for (auto i : sol)
    {
        printf("%d %d\n", i.first+1, i.second+1);
    }
}
