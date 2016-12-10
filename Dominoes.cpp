#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector < pair <ll , ll > > domino;
vector < pair <ll , ll > > direction;
ll N, a, b,height,place,leftt,rightt,mostright;
vector <ll> canreachl,canreachr;
ll dp[110000],root[110000];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    memset(root,-1,sizeof root);
    for (int i = 0 ; i < N; i++)
    {
        cin>>a>>b;
        domino.push_back(make_pair(a,b));
    }
    sort(domino.begin(),domino.end());
    for (int i = 0 ; i < N; i++)
    {
        pair <ll,ll> cur = domino[i];
        place = cur.first; height = cur.second;
        direction.push_back(make_pair(i,i));
        canreachl.push_back(place-height>0?place-height:1);
        canreachr.push_back(place+height);
        for (int j = i-1; j >= 0; j--)
        {
            if (domino[j].first>=canreachl[i])
            {
                direction[i].first = j;
                canreachl[i] = min(canreachl[i],canreachl[j]);
            }
            else
                break;
        }
    }
    for (int i = 0 ; i < N; i++)
    {
        if (root[i]!=-1)continue;
        root[i] = i;
        for (int j = i+1 ; j < N; j++)
        {
            if (domino[j].first<=canreachr[i])
            {
                direction[i].second = j;
                canreachr[i] = max(canreachr[i],canreachr[j]);
                root[j] = i;
            }
            else
                break;
        }
    }
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        leftt = direction[i].first-1;
        if (leftt<0)leftt = 1;
        else leftt = dp[leftt]+1;

        if (root[i]-1<0) rightt = 1;
        else rightt = dp[root[i]-1]+1;

        dp[i] = min(leftt,rightt);
    }

    cout<<dp[N-1];
    return 0;

}
