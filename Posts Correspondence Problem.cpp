#include <bits/stdc++.h>
using namespace std;
int M, N;
vector <string> sa, sb;
bool visited[100];
int steps, pa[100];
bool OK = false;
void recur(string a, string b, int cnt)
{
    if (cnt > M)
    {
        return;
    }
    if (a==b && a !="")
    {
        OK = true;
        steps = cnt;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        string aa = a + sa[i], bb = b + sb[i];
        recur(aa,bb,cnt+1);
        if (OK)
        {
            pa[cnt] = i;
            return;
        }
    }
}
int main()
{
    cin>>M>>N;
    for (int i = 0; i < N; i++)
    {
        string cur; cin>>cur;
        sa.push_back(cur);
    }
    for (int i = 0; i < N; i++)
    {
        string cur; cin>>cur;
        sb.push_back(cur);
    }
    recur("","",0);
    if (OK)
    {
        cout<<steps<<"\n";
        for (int i = 0; i < steps; i++)
            cout<<pa[i]+1<<"\n";
    }
    else
    {
        cout<<"No solution.\n";
    }
}
