#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int N;
int a[110], b[110],x,y;
int main()
{
    cin>>N;
    stack <int> aa,bb;
    for (int i = 0; i < N; i++)
    {
        cin>>x>>y;
        aa.push(x); bb.push(y);
    }
    for (int i = 0; i < N; i++)
    {
        x = aa.top();
        aa.pop();
        a[i] = x;
        y = bb.top();
        bb.pop();
        b[i] = y;
    }
    long long asum = 0, bsum = 0,a1,a2;
    for (int i = 0 ; i < N; i++)
    {
        a1 = i;
        if (a1+1==N)a2 = 0;
        else a2 = a1+1;
        long long an1, an2;
        an1 = a[a1]*b[a2]; an2 = b[a1]*a[a2];
        asum+=an1; bsum+=an2;
    }
    long long ans = abs(asum-bsum);
    ans = ceil(0.5*ans);
    cout<<ans<<endl;
}
