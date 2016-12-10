#include <bits/stdc++.h>
using namespace std;
char g[51][51];
int M, N, K;
int di[8] = {1,0,-1,0,1,1,-1,-1};
int dj[8] = {0,1,0,-1,1,-1,1,-1};
int main()
{
    int T; cin>>T;
    while (T--)
    {
        cin>>M>>N;
        string tmp;
        for (int i = 0; i < M; i++)
        {
            cin>>tmp;
            for (int j = 0; j < N; j++)
            {
                g[i][j] = tolower(tmp[j]);
            }
        }
        cin>>K;
        for (int a = 0; a < K; a++)
        {
            cin>>tmp;
            for (int c = 0; c < tmp.size(); c++)
                tmp[c] = tolower(tmp[c]);
            int len = tmp.size();
            bool found = false;
            for (int i = 0; i < M && !found; i++)
            {
                for (int j = 0; j < N && !found; j++)
                {
                    if (g[i][j] == tmp[0])
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            int ii = di[k], jj = dj[k];
                            int ei = i + ii*(len-1), ej = j + jj*(len-1);
                            if (ei < 0 || ei >= M || ej < 0 || ej >= N) continue;
                            bool OK = true;
                            for (int m = 1; m < len; m++)
                            {
                                ei = i + ii*(m), ej = j + jj*(m);
                                if (g[ei][ej] != tmp[m])
                                {
                                    OK = false;
                                    break;
                                }
                            }
                            if (OK)
                            {
                                found = true; break;
                            }
                        }
                        if (found)
                        {
                            cout<<i+1<<" "<<j+1<<"\n";
                        }
                    }
                }
            }
        }
        cout<<"\n";
    }
}
