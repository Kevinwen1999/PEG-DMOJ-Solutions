#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int M, N;
const int MAXN = 1000001;
int tails[MAXN];
vector <int> in2;
int leng = 0;
unordered_map <int,int> m;
int main()
{
    scanf("%d", &M);
    int temp;
    for (int i = 0 ; i < M; i++)
        scanf("%d", &temp), m[temp] = i;
    scanf("%d", &N);
    for (int i = 0 ; i < N; i++)
    {
        scanf("%d", &temp);
        if (m.count(temp))
            in2.push_back(m[temp]);
    }
    memset(tails, 63, sizeof tails);
    tails[0] = 0;
    for (int i = 0 ; i < in2.size(); i++)
    {
        int l = 1, h = leng;
        while (l <= h)
        {
            int mid = l + (h-l) / 2;
            if (in2[tails[mid]] >= in2[i])
                h = mid - 1;
            else
                l = mid + 1;
        }
        tails[l] = i;
        leng = max(leng, l);
    }
    cout<<leng<<"\n";
}
