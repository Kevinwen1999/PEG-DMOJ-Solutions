#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int N, L, M;
vector <string> list [30];
vector <string> finall;
int main()
{
    cin>>N>>L;
    string temp;
    for (int i = 0 ; i < N; i++)
    {
        cin>>M;
        for (int j = 0 ; j < M; j++)
        {
            cin>>temp;
            list[i].push_back(temp);
        }
    }
    queue < pair <string, int> > buff;
    for (int i = 0 ; i < list[0].size(); i++)
        buff.push(make_pair(list[0][i],0));
    while(!buff.empty())
    {
        pair <string, int> top = buff.front();
        buff.pop();
        finall.push_back(top.first);
        for (int i = top.second+1; i < N; i++)
        {
            for (int j = 0 ; j < (int)list[i].size(); j++)
            {
                temp = top.first+list[i][j];
                if(temp.size()<=L)
                    buff.push(make_pair(temp,i));
            }
        }
    }
    sort(finall.begin(),finall.end());
    for (int i = 0 ; i  < (int)finall.size(); i++)
        cout<<finall[i]<<endl;
    return 0;
}
