#include <bits/stdc++.h>
using namespace std;

int N, S;
int mys[20], dp[1<<11][16];
set <pair <int,int> > cmp[1<<11];
int CountOnesFromInteger(int value)
{
    int cnt;
    for (cnt = 0; value != 0; cnt++, value &= value-1);
    return cnt;
}
void gen(int idx, int original_mask, int choice_mask)
{
    if (idx==N)
    {
        if (CountOnesFromInteger(choice_mask) % 2)
        {
            int other_half = original_mask & (~choice_mask);
            cmp[original_mask].insert(make_pair(choice_mask, other_half));
        }
        return;
    }
    if (original_mask & (1<<idx))
    {
        gen(idx + 1, original_mask, choice_mask | (1<<idx));
    }
    gen(idx+1, original_mask, choice_mask);
}
int recur (int mask, int s)
{
    if (~dp[mask][s]) return dp[mask][s];
    int &ans = dp[mask][s] = 0;
    for (int idx = 0; idx < N; idx++)
    {
        if (mask & (1<<idx)) mask ^= (1<<idx);
        else continue;
        if (!mask)
        {
            ans = max(ans, (mys[idx]+s)*(mys[idx]+s)+s); break;
        }
        for (auto i : cmp[mask])
        {
            for (int a = 0; a <= s; a++)
            {
                for (int b = 0; b <= s-a; b++)
                {
                    int c = s-a-b;
                    int add_boxes = recur(i.first, a)*recur(i.second, b)+c;
                    int only_s = (mys[idx]+c)*(mys[idx]+c)+c;
                    ans = max(ans, min(add_boxes, only_s));
                }
            }
        }
        mask^=(1<<idx);
    }
    return ans;
}
int main()
{
    cin>>N>>S;
    for (int i = 0 ; i < N; i++)
        cin>>mys[i];
    memset(dp, -1, sizeof dp);
    for (int mask = 0; mask < (1<<N); mask++)
    {
        gen(0,mask,0);
    }
    cout<<(recur((1<<N)-1, S));
}
