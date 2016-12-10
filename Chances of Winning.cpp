#include <bits/stdc++.h>
using namespace std;
int yourteam;
int G;
int arr[6][2] = {{1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}};
set <string> visited;
int ans = 0;
bool winning (string s)
{
    int score[5] = {0,0,0,0,0};
    for (int i = 0 ; i < 6; i++)
    {
        if (s[i] == 'W')
        {
            score[arr[i][0]]+=3;
        }
        else if (s[i]=='L')
        {
            score[arr[i][1]]+=3;
        }
        else
        {
            score[arr[i][0]]+=1;
            score[arr[i][1]]+=1;
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        if (i==yourteam) continue;
        if (score[i] >= score[yourteam])
            return false;
    }
    return true;
}
void recur (string state, int cnt)
{
    if (cnt==6)
    {
        if (visited.count(state) == 0)
        {
            visited.insert(state);
            if (winning(state))
                ans+=1;
        }
    }
    for (int i = 0 ; i < 6; i++)
    {
        string next = state;
        if (state[i] == '?')
        {
            next[i] = 'W';
            recur(next, cnt+1);
            next[i] = 'L';
            recur(next, cnt+1);
            next[i] = 'T';
            recur(next, cnt+1);
        }
    }
}
int main()
{
    cin>>yourteam>>G;
    string ini = "??????";
    char st;
    for (int i = 0; i < G; i++)
    {
        int a, b, as, bs;
        cin>>a>>b>>as>>bs;
        if (a > b) {swap(a,b);swap(as,bs);}
        if (as > bs) st = 'W';
        else if (as < bs) st = 'L';
        else st = 'T';
        for (int i = 0; i < 6; i++)
        {
            if (arr[i][0]==a && arr[i][1]==b)
            {
                ini[i] = st;
            }
        }
    }
    recur(ini, G);
    cout<<ans<<"\n";
}
