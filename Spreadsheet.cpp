#include <bits/stdc++.h>
using namespace std;
string sheet[11][11];
int val[11][11];
bool visited[11][11];
int recur(int i, int j)
{
    if (val[i][j]!=-2) return val[i][j];
    if (visited[i][j]) return -1;
    visited[i][j] = true;
    string cur = sheet[i][j];
    int sum = 0;
    for (int i = 0; i < cur.size(); i+=3)
    {
        string sub = cur.substr(i,2);
        int ix = sub[0] - 'A', jx = sub[1] - '0' -1;
        int v = recur(ix,jx);
        if (v==-1)
        {
            return -1;
        }
        sum += v;
    }
    visited[i][j] = false;
    return val[i][j] =sum;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin>>sheet[i][j];
            val[i][j] = -2;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!isupper(sheet[i][j][0]))
            {
                val[i][j] = stoi(sheet[i][j], nullptr, 10);
            }
        }
    }
    /*while (true)
    {

    }*/
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (val[i][j]!=-2) continue;
            memset(visited,0,sizeof visited);
            val[i][j] = recur(i,j);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (val[i][j]==-1)
                cout<<"* ";
            else
                cout<<val[i][j]<<" ";
        }
        cout<<"\n";
    }
}
