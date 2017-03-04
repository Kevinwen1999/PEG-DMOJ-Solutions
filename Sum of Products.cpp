#include <bits/stdc++.h>
using namespace std;
int N, ptr;
char p1[300];
string S, cop;
stack <string> st;
vector <string> p2, temp1, temp2, temp3;
stack < vector <string> > p3;
vector <string> p4;
int main()
{
    cin >> N;
    while (N--)
    {
        cin >> S;
        ptr = 0;
        for (int i = 0; i < S.size(); i++)
        {
            p1[ptr++] = S[i];
            if (i < S.size())
            {
                if ((isalpha(S[i]) || S[i] == ')') && (isalpha(S[i+1]) || S[i+1] == '('))
                    p1[ptr++] = '*';
//                if (isalpha(S[i]) && S[i+1] == '(')
//                    p1[ptr++] = '*';

            }
        }
        while(!st.empty()) st.pop();
        p2.clear();
        for (int i = 0; i < ptr; i++)
        {
            stringstream ss;
            if (isalpha(p1[i]))
            {
                ss<<p1[i];
                ss>>cop;
                p2.push_back(cop);
            }
            else if (p1[i]=='*' || p1[i]=='(')
            {
                ss<<p1[i];
                ss>>cop;
                st.push(cop);
            }
            else if (p1[i]=='+')
            {
                while (!st.empty() && st.top()=="*")
                {
                    p2.push_back(st.top());
                    st.pop();
                }
                ss<<p1[i];
                ss>>cop;
                st.push(cop);
            }
            else if (p1[i]==')')
            {
                while (!st.empty() && st.top()!="(")
                {
                    p2.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
        }
        while (!st.empty())
        {
            p2.push_back(st.top());
            st.pop();
        }
//        for (auto i : p2)
//            cout<<i<<"\n";
        for (int i = 0; i < p2.size(); i++)
        {
            if (p2[i] == "+")
            {
                temp1 = p3.top(); p3.pop();
                temp2 = p3.top(); p3.pop();
                for (auto i : temp2)
                    temp1.push_back(i);
                p3.push(temp1);
            }
            else if (p2[i] == "*")
            {
                temp1 = p3.top(); p3.pop();
                temp2 = p3.top(); p3.pop();
                temp3.clear();
                for (int i = 0; i < temp1.size(); i++)
                    for (int j = 0; j < temp2.size(); j++)
                        temp3.push_back(temp1[i]+temp2[j]);
                p3.push(temp3);
            }
            else
            {
                temp1.clear();
                temp1.push_back(p2[i]);
                p3.push(temp1);
                temp1.clear();
            }
        }
        p4 = p3.top(); p3.pop();
        for (int i = 0; i < p4.size(); i++)
            sort(p4[i].begin(), p4[i].end());
        sort(p4.begin(), p4.end());
        for (int i = 0; i < p4.size(); i++)
        {
            cout<<p4[i];
            if (i < p4.size()-1)
                cout<<"+";
        }
        cout<<"\n";
    }
}
