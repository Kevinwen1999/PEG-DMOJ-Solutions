#include <iostream>
#include <string>
using namespace std;
string letters = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    string in, tar, tmp;
    cin>>in>>tar;
    tmp = in;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0 ; j < in.size(); j++)
        {
            int n = in[j] - 97 - i;
            n = (n+26) % 26;
            tmp[j] = letters[n];
        }
        if (tmp.find(tar)!=string::npos)
            {cout<<i<<"\n"<<tmp; break;}
    }
}
