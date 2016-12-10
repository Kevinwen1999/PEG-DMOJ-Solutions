#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;
const int MAXN= 1001;

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
    point() {x = y = 0.0;}
    point(double a, double b) {x = a; y = b;}
} points[MAXN];
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
int T;
int N, R;
vector < pair <double, pair <int,int> > > EdgeList;
int main()
{
    cin>>T;
    for (int cas = 1; cas <= T; cas++)
    {
        cin>>N>>R;
        EdgeList.clear();
        set <int> visited;
        int E = 0;
        int staten = 0;
        for (int i = 0 ; i < N; i++)
        {
            int a, b;
            cin>>a>>b;
            points[i] = point(a,b);
        }
        UnionFind State(N);
        for (int i = 0 ; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                double d = dist(points[i], points[j]);
                EdgeList.push_back(make_pair(d,make_pair(i,j)));
                E++;
            }
        }
        double roadcost = 0, railcost = 0;
        sort (EdgeList.begin(),EdgeList.end());
        UnionFind UF(N);
        for (int i = 0 ; i < E; i++)
        {
            pair <double, pair <int, int > > frontt = EdgeList[i];
            if (!UF.isSameSet(frontt.second.first, frontt.second.second))
            {
                if (frontt.first <= R) roadcost+=frontt.first;
                else railcost += frontt.first;

                UF.unionSet(frontt.second.first, frontt.second.second);
                if (frontt.first <= R)
                {
                    State.unionSet(frontt.second.first, frontt.second.second);
                }
            }
        }
        for (int i = 0 ; i < N; i++)
        {
            //cout<<"findset:"<<i<<" "<<State.findSet(i)<<"\n";
            int fs = State.findSet(i);
            //cout<<visited.count(fs)<<endl;
            if (visited.count(fs)==0)
            {
                staten++;
                visited.insert(fs);
            }
        }
        cout<<"Case #"<<cas<<": "<<staten<<" "<<round(roadcost)<<" "<<round(railcost)<<"\n";
    }
    return 0;
}
