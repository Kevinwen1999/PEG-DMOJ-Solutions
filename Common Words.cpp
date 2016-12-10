#include <bits/stdc++.h>
using namespace std;
int a[1010];
int M, K;
struct name
{
    string n;
    int freq;
    bool operator < (const name &a) const
    {
        return freq > a.freq;
    }
}cur;
vector <name> V;
int main()
{
    int T; cin>>T;
    while (T--)
    {
        unordered_map <string, int> m1;
        unordered_map <int, string> m2;
        cin>>M>>K;
        int tot= 0 ;
        memset(a,0,sizeof a);
        V.clear();
        for (int i = 0; i < M; i++)
        {
            string n; cin>>n;
            if (m1.count(n)==0) m1[n] = tot, m2[tot++] = n;
            a[m1[n]]++;
        }
        for (int i = 0; i < tot; i++)
        {
            string n = m2[i];
            cur.freq = a[m1[n]]; cur.n = n;
            V.push_back(cur);
        }
        sort(V.begin(),V.end());
        cout<<K;
        if (K % 100 < 20 && K % 100 > 10 || K > 1000)
            cout<<"th";
        else if (K % 10 == 1)
            cout<<"st";
        else if (K % 10 == 2)
            cout<<"nd";
        else if (K % 10 == 3)
            cout<<"rd";
        else
            cout<<"th";
        cout<<" most common word(s):\n";
        if (K-1 >= V.size() || (K-2 >= 0 && V[K-2].freq == K-1))
        {
            cout<<"\n";
            continue;
        }
        else
        {
            for (int i = K-1; i < V.size(); i++)
            {
                if (V[i].freq == V[K-1].freq)
                    cout<<V[i].n<<"\n";
                else
                    break;
            }
        }
        cout<<"\n";
    }
}
