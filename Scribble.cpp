#include <bits/stdc++.h>
using namespace std;
int K;
int N;
unordered_map<char, int> m;
int s[10], r[10];
int oc[10];
int main()
{
    int K; cin>>K;
    for (int i = 0; i < K; i++)
    {
        char c; cin>>c;
        m[c] = i;
        cin>>s[i]>>r[i];
    }
    cin>>N;
    int ma = 0;
    for (int i = 0; i < N; i++)
    {
        string in;
        cin>>in;
        bool OK = true;
        int sum = 0;
        memset(oc,0,sizeof oc);
        for (char c : in)
        {
            if (m.count(c)==0)
            {
                OK = false;
                break;
            }
            int idx = m[c];
            oc[idx]++;
            if (oc[idx] > r[idx])
            {
                OK = false;
                break;
            }
            sum += s[idx];
        }
        if (OK)
        {
            ma = max(ma, sum);
        }
    }
    cout<<ma<<endl;
}
