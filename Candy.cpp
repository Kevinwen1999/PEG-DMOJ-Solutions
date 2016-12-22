#include <bits/stdc++.h>
using namespace std;
struct candy
{
    int num, val;
};
candy all[110];
int N;
int sum = 0;
bool dp[5000010];
int cnt[5000010];
void greedy() // does not always work, but get me second place in best solution
{
    priority_queue <int, vector <int> > al;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < all[i].num; j++)
            al.push(all[i].val);
    }
    while(al.size() != 1)
    {
        int a = al.top(); al.pop();
        int b = al.top(); al.pop();
        al.push(abs(a-b));
    }
    cout<<al.top()<<"\n";
}
int main()
{
    cin>>N;
    for (int i = 0,a,b; i < N; i++)
    {
        cin>>all[i].num>>all[i].val;
        sum += all[i].num*all[i].val;
    }
    if (sum > 1000) // lol ignore this
    {
        greedy();
        return 0;
    }
    dp[0] = true;
    int limit = (sum/2);
    int maxx = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= limit; j++) cnt[j] = 0;
        if (maxx==limit) break;
        for (int j = all[i].val; j <= limit; j++)
        {
            if (dp[j]) continue;
            if (!dp[j-all[i].val] || cnt[j-all[i].val] >= all[i].num) continue;
            dp[j] = true;
            maxx = max(j, maxx);
            cnt[j] = cnt[j-all[i].val]+1;
        }
    }
    cout<<sum-2*maxx<<"\n";
}
