#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
inline long long max(long long a,long long b) {return a<b?b:a;}
inline long long min(long long a,long long b) {return a>b?b:a;}
vector < pair <long long , long long > > domino;
vector < pair <long long , long long > > direction;
long long N, a, b,height,place,leftt,rightt,mostright;
vector <long long> canreachl,canreachr;
long long dp[110000],root[110000];
int main()
{
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
        pair <long long,long long> cur = domino[i];
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
                if (root[j]==-1)
                    root[j] = i;
            }
        }
    }
    dp[0] = 1;
    mostright = direction[0].second;
    for (int i = 1; i < N; i++)
    {
        leftt = direction[i].first-1;
        if (leftt<0)leftt = 1;
        else leftt = dp[leftt]+1;

        if (i>mostright)
            rightt = dp[i-1]+1;
        else
        {
            if (root[i-1]-1<0) rightt = 1;
            else rightt = dp[root[i-1]-1]+1;
        }
        dp[i] = min(leftt,rightt);
        if (direction[i].second>mostright)
            mostright = direction[i].second;
    }

    cout<<dp[N-1]<<endl;
    return 0;

}
