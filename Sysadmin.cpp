//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define EPS 1e-9
using namespace std;
int N, Q;
struct line
{
    int s, m, idx;
    line(int a, int b, int c) {s = a; m = b; idx = c;}
};
vector <line> all;
bool cmpl(const line &a, const line &b)
{
    if (a.s == b.s)
    {
        if (a.m==b.m)
            return a.idx < b.idx;
        return a.m > b.m;
    }
    return a.s > b.s;
}
struct node
{
    double x;
    int s, m, idx;
    node (double a, int b, int c, int d){x = a; s = b; m = c; idx = d;}
    node (double a, int b){x = a; idx = b; s = 0; m = 0;}
};
bool cmpn (const node &a, const node &b)
{
    if (a.x == b.x)
        return a.m < b.m;
    return a.x < b.x;
}
vector <node> stat;
int maxx = 0;
int main()
{
    scanf("%d%d", &N, &Q);
    for (int i = 0 ; i < N; i++)
    {
        int ss, mm;
        scanf("%d%d", &ss, &mm);
        all.push_back(line(ss,mm, i));
        if (all[i].s > all[maxx].s)
            maxx = i;
    }
    sort (all.begin(), all.end(), cmpl);
    stat.push_back(node(0, all[0].s, all[0].m, all[0].idx));
    for (int i = 1; i < N; i++)
    {
        node last = stat[stat.size()-1];
        if (all[i].m == last.m || all[i].idx == maxx) continue;
        double x = (last.s - all[i].s) / (double)(all[i].m - last.m);
        while (x > 0 && (x < last.x || (fabs(x - last.x) < EPS && all[i].m > last.m /*&& all[i].idx < last.idx*/)))
        {
            stat.pop_back();
            last = stat[stat.size()-1];
            x = (last.s - all[i].s) / (double)(all[i].m - last.m);
        }
        if (x > 0)
            stat.push_back(node(x, all[i].s, all[i].m, all[i].idx));
    }
    sort (stat.begin(),stat.end(),cmpn);
    /*for (node i : stat)
    {
        cout<<i.x<<"  "<<i.s<<"  "<<i.m<<"  "<<i.idx<<"\n";
    }*/
    for (int i = 0 ; i < Q; i++)
    {
        int q; scanf("%d", &q);
        if (q==0){cout<<maxx<<"\n"; continue;}
        int l = 0, h = stat.size()-1;
        while (l<=h)
        {
            int mid = l + (h-l) / 2;
            if (stat[mid].x < q)
                l = mid + 1;
            else
                h = mid - 1;
        }
        //int sth = lower_bound(stat.begin(), stat.end(), node(q,0), cmpn) - stat.begin();
        if (l == 0) cout<<stat[l].idx<<"\n";
        else cout<<stat[l-1].idx<<"\n";
    }
}
