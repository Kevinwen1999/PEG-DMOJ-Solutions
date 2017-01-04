#include <bits/stdc++.h>
using namespace std;
vector <int> xcor, ycor;
unordered_map <int,int>  hashx, hashy;
struct query
{
    int idx, down, up, t;
    bool operator< (const query &a) const
    {
        if (idx == a.idx)
        {
            return t > a.t;
        }
        return idx < a.idx;
    }
};
vector <query> allx, ally;
int val[20020], mod[20020], buff[20020];
int main()
{
    int T; cin>>T;
    for (int i = 0, x1, x2, y1, y2; i < T; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        xcor.push_back(x1); xcor.push_back(x2);
        ycor.push_back(y1); ycor.push_back(y2);
        allx.push_back((query){x1, y1, y2, 1}); allx.push_back((query){x2, y1, y2, -1});
        ally.push_back((query){y1, x1, x2, 1}); ally.push_back((query){y2, x1, x2, -1});
    }
    sort(allx.begin(), allx.end());
    sort(ally.begin(), ally.end());
    sort(xcor.begin(), xcor.end()); xcor.erase(unique(xcor.begin(), xcor.end()), xcor.end());
    sort(ycor.begin(), ycor.end()); ycor.erase(unique(ycor.begin(), ycor.end()), ycor.end());
    for (int i = 0; i < xcor.size(); i++)
        hashx[xcor[i]] = i;
    for (int i = 0; i < ycor.size(); i++)
        hashy[ycor[i]] = i;

    int ptr = 0;
    int lastidx, curidx;
    int ans = 0;
    //vertical edges
    for (; ptr < allx.size();)
    {
        curidx = allx[ptr].idx;
        while (ptr < allx.size() && allx[ptr].idx == curidx)
        {
            for (int i = hashy[allx[ptr].down]; i < hashy[allx[ptr].up]; i++)
            {
                val[i] += allx[ptr].t;
                mod[i] = allx[ptr].t;
            }
            ptr++;
        }
        for (int i = 0; i < ycor.size()-1; i++)
        {
            if (mod[i])
            {
                if (mod[i]==1 && buff[i]==0)
                    ans += (ycor[i+1]-ycor[i]);
                else if (mod[i]==-1 && val[i]+buff[i]==0)
                    ans += (ycor[i+1]-ycor[i]);
                mod[i]=0;
                buff[i] += val[i];
                val[i] = 0;
            }
        }
    }
    //horizontal edges
    ptr = 0;
    memset(val, 0, sizeof val);
    memset(buff, 0, sizeof buff);
    memset(mod, 0, sizeof mod);
    for (; ptr < ally.size();)
    {
        curidx = ally[ptr].idx;
        while (ptr < ally.size() && ally[ptr].idx == curidx)
        {
            for (int i = hashx[ally[ptr].down]; i < hashx[ally[ptr].up]; i++)
            {
                val[i] += ally[ptr].t;
                mod[i] = ally[ptr].t;
            }
            ptr++;
        }
        for (int i = 0; i < xcor.size()-1; i++)
        {
            if (mod[i])
            {
                if (mod[i]==1 && buff[i]==0)
                    ans += (xcor[i+1]-xcor[i]);
                else if (mod[i]==-1 && val[i]+buff[i]==0)
                    ans += (xcor[i+1]-xcor[i]);
                mod[i]=0;
                buff[i] += val[i];
                val[i] = 0;
            }
        }
    }
    cout<<ans<<"\n";
}
