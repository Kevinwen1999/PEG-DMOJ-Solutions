#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
const int MAXN = 100001;
using namespace std;
int N;
int X[MAXN], Y[MAXN];
map <int,int> xm , ym;
int xcnt, ycnt;
vector <int> xa[MAXN], ya[MAXN];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0 ; i < N; i++)
    {
        cin>>X[i]>>Y[i];
        if (xm.count(X[i])==0)
            xm[X[i]] = xcnt++;
        if (ym.count(Y[i])==0)
            ym[Y[i]] = ycnt++;
        xa[xm[X[i]]].push_back(Y[i]);
        ya[ym[Y[i]]].push_back(X[i]);
    }
    for (int i = 0 ; i < MAXN; i++)
    {
        sort(xa[i].begin(), xa[i].end());
        sort(ya[i].begin(), ya[i].end());
    }
    long long ans = 0, tmp;
    long long xpos, ypos, xleft, xright, yup, ydown;
    for (int i = 0 ; i < N; i++)
    {
        xpos = lower_bound(ya[ym[Y[i]]].begin(),ya[ym[Y[i]]].end(), X[i]) - ya[ym[Y[i]]].begin();
        ypos = lower_bound(xa[xm[X[i]]].begin(),xa[xm[X[i]]].end(), Y[i]) - xa[xm[X[i]]].begin();
        xleft = xpos; xright = ya[ym[Y[i]]].size() - xpos - 1;
        ydown = ypos; yup = xa[xm[X[i]]].size() - ypos - 1;
        tmp = (xleft * ydown) * (yup * xright) + (xleft * yup) * (xright * ydown);
        ans += tmp;
    }
    cout<<ans;
}
