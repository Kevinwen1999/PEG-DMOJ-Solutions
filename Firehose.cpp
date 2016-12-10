#include <bits/stdc++.h>
using namespace std;
int LEN = 1000000;
vector <int> houses;
int H, K;
int mk(int radius)
{
    int best = LEN;
    int sze = houses.size();
    int dia = radius * 2;
    int x = 0;
    while (x < sze && houses[x] <= houses[0] + dia)
    {
        int cur = 1, y = x + 1;
        if (y == sze) return 1;
        int fin = houses[x+1];
        cur++;
        while (y < sze)
        {
            if (houses[y] > fin + dia)
            {
                fin = houses[y];
                cur++;
            }
            y++;
        }
        best = min(best, cur);
        x++;
    }
    return best;
}
int main()
{
    cin>>H;
    for (int i = 0, in ; i < H; i++)
    {
        cin>>in;
        houses.push_back(in);
    }
    sort(houses.begin(), houses.end());
    cin>>K;
    int l = 0, h = LEN, mid, ans;
    while (l <= h)
    {
        mid = l + (h-l) / 2;
        if (mk(mid)<= K)
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout<<ans<<"\n";
}
