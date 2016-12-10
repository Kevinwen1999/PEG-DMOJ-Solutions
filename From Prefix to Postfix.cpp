#include <bits/stdc++.h>
using namespace std;
string in;
bool isoper(char x)
{
    return (x=='+'||x=='-');
}
int main()
{
    while (1)
    {
        getline(cin, in);
        if (in == "0") break;
        reverse(in.begin(), in.end());
        stack <string> st;
        string fin;
        for (int i = 0 ; i < in.size(); i++)
        {
            if (in[i]==' ') continue;
            string tmp, t1, t2;
            stringstream ss;
            ss<<in[i];
            ss>>tmp;
            if (!isoper(in[i])) st.push(tmp);
            else
            {
                t1 = st.top(); st.pop();
                t2 = st.top(); st.pop();
                fin = t1 + " " + t2 + " " + tmp;
                st.push(fin);
            }
        }
        cout<<fin<<"\n";
    }
}
