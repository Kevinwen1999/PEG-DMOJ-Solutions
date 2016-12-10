#include <bits/stdc++.h>
using namespace std;
struct level
{
    bool a, b, c;
} cur;
vector <level> v;
int tl = 18;
int main()
{
    cur.a = cur.b = cur.c = 0;
    for (int i = 0; i < 18; i++)
    {
        v.push_back(cur);
    }
    int N; cin>>N;
    for (int a = 0; a < N; a++)
    {
        string o1, o2;
        cin>>o1>>o2;
        string::size_type sz;
        int lv = stoi(o1,&sz);
        string letter = o1.substr(sz);
        if (lv > tl)
        {
            cur.a = cur.b = cur.c = 0;
            v.push_back(cur);
            tl++;
        }
        if (letter == "A")
        {
            v[lv-1].a = true;
        }
        else if (letter == "B")
        {
            v[lv-1].b = true;
        }
        else
        {
            v[lv-1].c = true;
        }
        if (lv != tl && (v[lv-1].a && v[lv-1].b) || (v[lv-1].b && v[lv-1].c))
        {
            cout<<"The tower collapses after removing "<<o1<<"\n";
            return 0;
        }
        //-----------------------------------------------------------------------
        lv = stoi(o2,&sz);
        letter = o2.substr(sz);
        if (lv > tl)
        {
            cur.a = cur.b = cur.c = 0;
            v.push_back(cur);
            tl++;
        }
        if (letter == "A")
        {
            v[lv-1].a = false;
        }
        else if (letter == "B")
        {
            v[lv-1].b = false;
        }
        else
        {
            v[lv-1].c = false;
        }
        if (lv != tl && (v[lv-1].a && v[lv-1].b) || (v[lv-1].b && v[lv-1].c))
        {
            cout<<"The tower collapses after placing "<<o2<<"\n";
            return 0;
        }
    }
    cout<<"The tower never collapses\n";
    return 0;
}
