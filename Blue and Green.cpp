#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int N, M;
int S, L, R, I;
string in;
long long ori;
long long dist[1<<20];
bool done[1<<20];
queue <long long> buff;
int main()
{
    memset(dist,63,sizeof dist);
    cin>>N>>M;
    cin>>S>>L>>R>>I;
    cin>>in;
    for (int i = 0 ; i < N; i++)
        if (in[i]=='B') ori = ori | (1<<i);

    dist[ori] = 0;
    buff.push(ori);
    done[ori] = true;
    int mask, shifted, newd, last;
    while (!buff.empty())
    {
        mask = buff.front();
        buff.pop();
        done[mask] = false;
        newd = dist[mask] + S;
        //case S
        if (newd <= M)
        {
            for (int i = 0 ; i < N; i++)
            {
                shifted = mask ^ (1<<i);
                if (dist[shifted] > newd)
                {
                    dist[shifted] = newd;
                    if (!done[shifted])
                    {
                        done[shifted] = true;
                        buff.push(shifted);
                    }
                }
            }
        }
        //case L
        newd = dist[mask] + L;
        last = mask & (1);
        shifted = mask >> 1;
        if (last) shifted = shifted | (1<<(N-1));
        if (newd <= M && dist[shifted] > newd)
        {
            dist[shifted] = newd;
            if (!done[shifted])
            {
                done[shifted] = true;
                buff.push(shifted);
            }
        }
        //case R
        newd = dist[mask] + R;
        int last = mask & (1<<(N-1));
        shifted = mask << 1;
        shifted &= ~(1<<N);
        if (last) shifted = shifted | (1);
        if (newd <= M && dist[shifted] > newd)
        {
            dist[shifted] = newd;
            if (!done[shifted])
            {
                done[shifted] = true;
                buff.push(shifted);
            }
        }
        //case I
        newd = dist[mask] + I;
        shifted = mask;
        for (int i = 0 ; i < N; i++)
            shifted ^= (1<<i);
        if (newd <= M && dist[shifted] > newd)
        {
            dist[shifted] = newd;
            if (!done[shifted])
            {
                done[shifted] = true;
                buff.push(shifted);
            }
        }
    }

    long long cnt = 0;
    for (long long i = 0 ; i < (1<<N); i++)
        if (dist[i]<INF)
            cnt++;
    cout<<cnt<<"\n";
}
