#include <bits/stdc++.h>
using namespace std;
int D, F, T;
int wait[1010];
vector <int> adj[1010];
int last[1010];
int tot[1010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>D;
    for (int i = 1; i <= D; i++)
        cin>>wait[i];
    cin>>F;
    for (int i = 0, a, b; i < F; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cin>>T;
    memset(last,-1,sizeof last);
    last[1] = 0;
    for (int i = 0; i <= T; i++)
    {
        //cout<<"in second "<<i<<"\n";
        for (int j = 1; j <= D; j++)
        {
            if (i < last[j] || i > last[j]) continue;
            if (i == last[j])
                tot[j]++;
            //cout<<"dog "<<j<<" barls\n";
            for (int k : adj[j])
            {
                if (i > last[k])
                {
                    //cout<<"dog "<<k<<" hears the bark and bark in second "<<i+wait[k]<<"\n";
                    last[k] = i + wait[k];
                }
            }
        }
    }
    for (int i = 1; i <= D; i++)
    {
        cout<<tot[i]<<"\n";
    }
}
