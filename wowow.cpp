#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAXN = 1000010;
int tree[MAXN];
void update(int x, int v)
{
    for (;x < MAXN; x+=(x & -x))
        tree[x]+=v;
}
long long query(int x)
{
    long long sum = 0;
    for (;x >0; x-=(x&-x))
        sum+=tree[x];
    return sum;
}
struct cmd
{
    char c;
    int x, r, k;
    cmd (char c_, int x_, int r_){c = c_; x = x_; r = r_;}
    cmd(char c_, int k_) {c = c_; k = k_;}
};
vector <cmd> allcmd;
vector <int> allrate, allpkey;
unordered_map <int,int> idx2key, key2idx, rate2idx;
int N;
int id2rate[MAXN], rate2id[MAXN];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    char C;
    int X, R, K;
    for (int i = 0 ; i < N; i++)
    {
        cin>>C;
        if (C== 'N' || C == 'M')
        {
            cin>>X>>R;
            allcmd.push_back(cmd(C, X, R));
            allpkey.push_back(X);
            allrate.push_back(R);
        }
        else
        {
            cin>>K;
            allcmd.push_back(cmd(C,K));
        }
    }
    sort(allpkey.begin(), allpkey.end());
    allpkey.erase(unique(allpkey.begin(), allpkey.end()), allpkey.end());
    sort(allrate.begin(), allrate.end());
    int cnt = 0;
    for (int i = 0 ; i < allpkey.size(); i++)
    {
        key2idx[allpkey[i]] = ++cnt;
        idx2key[cnt] = allpkey[i];
    }
    cnt = 0;
    for (int i = 0 ; i < allrate.size(); i++)
    {
        rate2idx[allrate[i]] = ++cnt;
    }
    int tot = 0, curid, currate;
    for (int i = 0 ; i < N; i++)
    {
        cmd cur = allcmd[i];
        if (cur.c=='N')
        {
            curid = cur.x; currate = cur.r;
            id2rate[key2idx[curid]] = rate2idx[currate];
            rate2id[rate2idx[currate]] = key2idx[curid];
            update(rate2idx[currate], 1);
            tot++;
        }
        else if (cur.c=='M')
        {
            curid = cur.x; currate = cur.r;
            update(id2rate[key2idx[curid]], -1);
            id2rate[key2idx[curid]] = rate2idx[currate];
            rate2id[rate2idx[currate]] = key2idx[curid];
            update(rate2idx[currate], 1);
        }
        else
        {
            int l = 1, h = cnt, mid;
            while (l <= h)
            {
                mid = l + (h-l) / 2;
                if (query(mid) > tot - cur.k)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            cout<<idx2key[rate2id[l]]<<"\n";
        }
    }
}
