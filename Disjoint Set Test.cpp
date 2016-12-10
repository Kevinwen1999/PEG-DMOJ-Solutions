#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
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
vector < pair <int, pair <int,int> > > EdgeList;
vector <int> ans;
UnionFind UF(100001);
int main()
{
    int E, V;
    scanf("%d%d",&V,&E);
    for (int i = 0 , w = 1, u ,v; i < E ; i++)
    {
        scanf("%d %d", &u,&v);
        EdgeList.push_back(make_pair(w++,make_pair(u,v)));
    }
    sort (EdgeList.begin(),EdgeList.end());
    for (int i = 0 ; i < E; i++)
    {
        pair <int, pair <int, int > > frontt = EdgeList[i];
        if (!UF.isSameSet(frontt.second.first, frontt.second.second))
        {
            ans.push_back(frontt.first);
            UF.unionSet(frontt.second.first, frontt.second.second);
        }
    }
    if (ans.size()!=V-1)
    {
        printf("Disconnected Graph\n");
        return 0;
    }
    for (int i : ans)
        printf("%d\n", i);
    return 0;
}
