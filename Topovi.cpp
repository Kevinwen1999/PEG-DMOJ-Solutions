#include <bits/stdc++.h>
using namespace std;
int N, K, P;
long long ans = 0;
map <int, int> rtot, ctot; // number of rows/cols that has certain xor val
map <int, int> rxor, cxor; // xor sum of certain row/col
map <pair <int,int>, int> power; // power value at certain index
void movepiece (int r, int c, int p)
{
    // remove existing seen points when current piece is present
    ans -= N - ctot[rxor[r]];
    ans -= N - rtot[cxor[c]];
    if (rxor[r]!=cxor[c]) // current index deleted twice
        ans += 1;

    // remove and add new row/col
    rtot[rxor[r]]--;
    rxor[r] ^= p;
    rtot[rxor[r]]++;
    ctot[cxor[c]]--;
    cxor[c] ^= p;
    ctot[cxor[c]]++;

    //adding new seen points when current piece disappear
    ans += N - ctot[rxor[r]];
    ans += N - rtot[cxor[c]];
    if (rxor[r]!=cxor[c]) // current index counted twice
        ans -= 1;
    power[{r,c}] ^= p;
}
int main()
{
    cin>>N>>K>>P;
    rtot[0] = N; ctot[0] = N;
    for (int i = 0, a, b, c; i < K; i++)
    {
        cin>>a>>b>>c;
        movepiece(a,b,c);
    }
    for (int i = 0, r1, c1, r2, c2; i < P; i++)
    {
        cin>>r1>>c1>>r2>>c2;
        int curpow = power[{r1,c1}];
        movepiece(r1,c1,curpow);
        movepiece(r2,c2,curpow);
        cout<<ans<<"\n";
    }
}
