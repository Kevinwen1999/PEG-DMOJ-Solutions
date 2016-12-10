#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int N;
const int MAXN = 500010;
map<char, int> dic;
string ori, mp, tmp;
int b[MAXN], n, m = 9;
string match = "HAILHYDRA";
void kmpPreprocess()
{
    memset(b, 0, sizeof b);
    int i = 0, j = -1; b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && match[i] != match[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}
bool kmpSearch()
{
    int i = 0, j = 0;
    while (i < n)
    {
        while (j >=0 && tmp[i] != match[j]) j = b[j];
        i++; j++;
        if (j==m)
        {
            return true;
            // j = b[j];
        }
    }
    return false;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>ori;
    tmp = ori;
    n = ori.size();
    cin>>N;
    kmpPreprocess();
    for (int i = 0; i < N; i++)
    {
        cin>>mp;
        for (int j = 0 ; j < 26; j++)
        {
            dic[mp[j]] = j;
        }
        for (int j = 0 ; j < ori.size(); j++)
        {
            //cout<<(int)ori[j]<<" "<<((int)ori[j]) % 65<<"\n";
            tmp[j] = 'A' + dic[ori[j]];
        }
        //cout<<tmp<<"\n";
        if (kmpSearch())
        {   cout<<tmp; return 0;}
    }
    cout<<"KeyNotFoundError\n";
}
