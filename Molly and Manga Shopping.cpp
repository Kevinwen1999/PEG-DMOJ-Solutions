#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
struct query
{
    int l, r, bucket, id, anss;
} aq[MAXN];
bool cmp1 (const query &a, const query &b)
{
    if (a.bucket == b.bucket)
        return a.r < b.r;
    return a.bucket < b.bucket;
}
bool cmp2 (const query &a, const query &b)
{
    return a.id < b.id;
}
int N, Q;
int ori[MAXN];
int rt = 317;
int ans;
int cnt[MAXN];
inline bool test(int i)
{
    return cnt[ori[i]]>0&& !(cnt[ori[i]]&1);
}
void add(int i)
{
    bool valid = test(i);
    cnt[ori[i]]++;
    if (!valid && test(i))
        ans++;
    else if (valid && !test(i))
        ans--;
}
void rmv (int i)
{
    bool valid = test(i);
    cnt[ori[i]]--;
    if (valid && !test(i))
        ans--;
    else if (!valid && test(i))
        ans++;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0; i < N; i++)
        cin>>ori[i];
    cin>>Q;
    for (int i = 0; i < Q; i++)
    {
        cin>>aq[i].l>>aq[i].r; aq[i].l--, aq[i].r--;
        aq[i].id = i; aq[i].bucket = aq[i].l / rt;
    }
    sort(aq, aq+Q, cmp1);
//    for (int i = 0; i < Q; i++)
//        cout<<aq[i].id<<" "<<aq[i].bucket<<"\n";
    int CL = 0, CR = 0;
    for (int i = 0; i < Q; i++)
    {
        while (CL < aq[i].l)
        {
            rmv(CL);
            CL++;
        }
        while (CL > aq[i].l)
        {
            add(CL-1);
            CL--;
        }
        while(CR <= aq[i].r)
        {
            add(CR);
            CR++;
        }
        while(CR > aq[i].r+1)
        {
            rmv(CR-1);
            CR--;
        }
        aq[i].anss = ans;
    }
    sort(aq, aq+Q, cmp2);
    for (int i = 0; i < Q; i++)
        printf("%d\n", aq[i].anss);
}

