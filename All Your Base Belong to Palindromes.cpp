//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int X, cur;
int main()
{
    cin>>X;
    vector <int> converted, valid;
    for (int b = 2; b <= sqrt(X)+1; b++)
    {
        converted.clear();
        cur = X;
        while (cur!=0)
        {
            converted.push_back(cur%b);
            cur/=b;
        }
        //reverse(converted.begin(), converted.end());
        bool OK = true;
        int sz = (int)converted.size();
        for (int i = 0 ; i <= (sz / 2) && OK; i++)
        {
            if (converted[i] != converted[sz - i - 1])
                OK = false;
        }
        if (sz==1) OK = true;
        if (OK) valid.push_back(b);
    }
    for (int a = sqrt(X)-1; a >=1; a--)
    {
        if (X % a==0)
        {
            valid.push_back((X/a)-1);
        }
    }
    sort(valid.begin(), valid.end());
    valid.erase(unique(valid.begin(),valid.end()),valid.end());
    for (int i = 0; i < valid.size(); i++)
        cout<<valid[i]<<"\n";
}
