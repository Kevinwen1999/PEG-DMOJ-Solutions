#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct student
{
    string name;
    int total;
    bool operator<(const student &another) const
    {
        return total>another.total;
    }
} all[110];
int P, N;
int main()
{
    cin>>N>>P;
    for (int i = 0 ; i < N; i++)
        cin>>all[i].name;
    for (int i = 0 ; i < P; i++)
        for (int j = 0,a ; j < N; j++)
        {
            cin>>a;
            all[j].total+=a;
        }
    sort(all,all+N);
    int ran = 3;
    for (int i = 0 ; i < N; i++)
        {
            cout<<ran<<". "<<all[i].name<<endl;
            ran++;
        }
}
