#include <bits/stdc++.h>

using namespace std;
long long search_used(bool *used, long long key, long long n)
{
        long long i;
        for(i=1; i<=n; i++)
        {
                if(used[i]==false)
                {
                        key--;
                }
                if(key==0)
                        return i;
        }
        return 0;
}
void kthpermutation(long long n, long long k)
{
        long long i;
        long long key, value;
        bool *used=new bool[n+1];
        long long *fact=new long long[n];
        long long *ans=new long long[n];
        for(i=0; i<=n; i++)
                used[i]=false;
        fact[n-1]=1;
        for(i=n-2; i>=0; i--)
        {
                fact[i]=fact[i+1]*(n-i-1);
        }
        k--;
        for(i=0; i<n; i++)
        {
                key=k/fact[i];
                value=search_used(used, key+1, n);
                ans[i]=value;
                used[value]=true;
                k=k%fact[i];
        }
        for(i=0; i<n; i++)
        {
                cout<<ans[i]<<" ";
        }
        cout<<endl;
        delete[] used;
        delete[] fact;
        delete[] ans;
}
long long N, Q, q;
int main()
{
    cin>>N>>Q;
    for (long long i = 0 ; i < Q; i++)
    {
        cin>>q;
        kthpermutation(N, q+1);
    }
}
