#include <bits/stdc++.h>

using namespace std;
int N, len;
int main()
{
    cin>>N;
    cin.ignore();
    while (N--)
    {
    	string in;
        getline(cin,in);
        len = in.size();
        stringstream ss(in);
        vector <string> vs;
        vs.clear();
        string tmp;
        while(ss.good())
        {
            ss>>tmp;
            vs.push_back(tmp);
        }
        vector <string> fp;
        fp.clear();
        int ptr = 0;
        while(true)
        {
            string c = vs[ptr++];
            if (c == "X")
            {
                string before = fp.back();
                fp.pop_back();
                string cc = vs[ptr++];
                string result = "(" + before + " X " + cc + ")";
                fp.push_back(result);
            }
            else
            {
                fp.push_back(c);
            }
            if (ptr == vs.size())
                break;
        }

        ptr = 0;
        vector <string> sp;
        while (ptr < fp.size())
        {
            string c = fp[ptr++];
            if (c == "+" || c == "-")
            {
                string before = sp.back();
                sp.pop_back();
                string cc = fp[ptr++];
                sp.push_back("(" + before + " " + c + " "+ cc + ")");
            }
            else
                sp.push_back(c);
        }
        sp[0].erase(sp[0].begin());
        sp[0].erase(sp[0].end()-1);
        cout<<sp[0];
        cout<<endl<<endl;
    }
}
