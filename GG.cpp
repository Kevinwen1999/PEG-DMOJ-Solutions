#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int l, r;
int psum[100001];
int main()
{
    string in;
    cin>>in;
    if (in[0] == 'G') psum[0]++;
    for (int i = 1; i < in.size(); i++)
    {
        if (in[i] == 'G') psum[i]++;
        psum[i]+=psum[i-1];
    }
    int T;
    cin>>T;
    while(T--)
    {
        cin>>l>>r;
        l = (l-1<0) ? 0 : psum[l-1];
        cout<<psum[r] - l<<endl;
    }
}
