#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
string  S, T;
int bl= 0, br = 0, al = 0;
int main()
{
    cin>> N;
    while (N--)
    {
        cin>>S>>T;
        bool OK = false, rever = false;
        if (S == T) {cout<<"YES\n"; continue;}
        bl = 0; br = 0;
        for (int i = 0 ; i < S.size(); i++)
        {
            if (S[i]=='B') bl++;
        }
        for (int i = 0 ; i < T.size(); i++)
        {
            if (T[i]=='B') br++;
        }
        if (br < bl) {cout<<"NO\n"; continue;}
        if ((br - bl) % 2 == 1) {reverse(S.begin(), S.end()); rever = true;}
        int pos = T.find(S,0);
        if (pos == string::npos) {cout<<"NO\n"; continue;}
        while (pos != string::npos && !OK)
        {
            bl = 0; br = 0, al = 0;
            int l = pos, r = l + (int)S.size()-1;
            pos = T.find(S,pos+1);
            for (int i = 0 ; i < l; i++)
            {
                if (T[i]=='B') bl++;
                else al++;
            }
            for (int i = r+1 ; i < T.size(); i++)
            {
                if (T[i]=='B') br++;
            }
            if (rever)
            {
                if (r+1 != T.size()-1 && T[r+1]=='A') continue;
                if (bl > br || br-bl !=1) continue;
            }
            else
            {
                if (l-1 != -1 && T[l-1]=='A') continue;
                if (bl != br) continue;
            }
            cout<<"YES\n";
            OK = true;
        }
        if (!OK) cout<<"NO\n";
    }
}
