#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string in;
string hardcode[10] = {"ook","ookook","oog","ooga","ug","mook","mookmook","oogam","oogum","ugug"};
int dp[810][810];
int len;
int check[810][810];
bool isword(int start, int fin)
{
    if (check[start][fin]!=-1)
    {
        if(check[start][fin]==1)
            return true;
        else
            return false;
    }
    check[start][fin] = 0;
    int length = fin - start +1;
    string sub = in.substr(start,length);
    for (int i = 0 ; i < 10; i++)
        if (sub == hardcode[i])
            {
                check[start][fin]=1;
                break;
            }
    if(check[start][fin]==1)
            return true;
        else
            return false;
}
int recur (int start, int fin)
{
    if (dp[start][fin]!=-1) return dp[start][fin];
    int ans = 0;
    int length = fin - start +1;
    if (isword(start,fin)) ans++;
    if (length<=2) return dp[start][fin]= ans;
    for (int i = start; i < fin; i++)
    {
        if (isword(start,i))
            ans+=recur(i+1,fin);
    }
    return dp[start][fin] = ans;
}
int main()
{
    int times = 10;
    while (times--)
    {
        cin>>in;
        memset(dp,-1,sizeof dp);
        memset(check,-1,sizeof check);
        len = in.size();
        cout<<recur(0,len-1)<<endl;
    }
}
