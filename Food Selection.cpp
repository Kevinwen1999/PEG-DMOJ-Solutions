#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int N,C,F,S;
int main()
{
    cin>>C>>F>>S>>N;
    cin.ignore();
    for (int i = 0 ; i < N; i++)
    {
        string str;
        getline(cin, str);
        stringstream ss;
        ss << str;
        float x, c, f, s;
        ss>>x>>c>>f>>s;
        string name, tmp;
        ss>>name;
        while ((ss>>tmp))
        {
            name = name + " " + tmp;
        }
        if ((c/x<=C) && (f/x<=F) && (s/x<=S))
        {
            cout<<name<<endl;
        }
    }
}
