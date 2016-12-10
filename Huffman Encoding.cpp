#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map <string, string> m;
vector <string> v;
int main()
{
    int N; cin>>N;
    for (int i = 0; i < N; i++)
    {
        string a, b;
        cin>>a>>b;
        m[a] = b;
        v.push_back(a);
    }
    string in;
    cin>>in;
    while (in.size() > 0)
    {
        for (int i = 0; i < N; i++)
        {
            string cur = v[i], b = m[cur];
            if (b.size() > in.size()) continue;
            string f = in.substr(0,b.size());
            if (f==b)
            {
                cout<<cur;
                in = in.substr((int)b.size());
                break;
            }
        }
    }
    return 0;
}
