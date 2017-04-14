#include <bits/stdc++.h>
#define pii pair <int,int>
#define INF 0x3f3f3f3f
using namespace std;
int N;
int ans = -INF;
struct state {
    int mask;
    int width;
    int length;
};
vector <pii> rs;
vector <state> ars;
queue <state> buff;
set <pair <int, pair <int,int> > > visited;
void check(int mask, int op) {
    int last = -1;
    int acc = 0;
//    cout<<"mask: "<<mask<<"\n";
    for (int i = 0; i < N; i++) {
        if (mask & (1<<i)) {
            if ((last == -1) || ((op ? rs[i].first : rs[i].second) == last)) {
                acc += op ? rs[i].second : rs[i].first;
                last = op ? rs[i].first : rs[i].second;
            }
            else {
                last = -2;
                break;
            }
        }
    }
    if (last == -2) return;
//    cout<<"shit, passed\n";
    ars.push_back((state){mask, min(last, acc), max(last, acc)});
}
state cur;
void pushcheck(int nmask, int a, int b, int c) {
    int nw, nl;
    nw = a + b;
    nl = c;
    if (nw > nl)
        swap(nw, nl);
    pair <int, pii> ns = make_pair(nmask, make_pair(nw, nl));
    if (!visited.count(ns)) {
        visited.insert(ns);
        buff.push((state){nmask, nw, nl});
    }
}
void bfs() {
    while(!buff.empty())
        buff.pop();
    visited.clear();
    for (state a : ars) {
//        cout<<a.mask<<" "<<a.width<<" "<<a.length<<"\n";
        buff.push(a);
        visited.insert(make_pair(a.mask, make_pair(a.width, a.length)));
    }
    while(!buff.empty()) {
        state cur = buff.front();
        buff.pop();
        if (cur.mask == (1<<N)-1) {
//            cout<<cur.length<<" "<<cur.width<<"\n";
//            cout<<2*(cur.length + cur.width)<<"\n";
            ans = max(ans, cur.length + cur.width);
            continue;
        }
        for (state nex : ars) {
            if ((nex.mask & cur.mask) != 0)
                continue;
            int nmask = nex.mask | cur.mask;
            if (cur.width == nex.width) {
                pushcheck(nmask, cur.length, nex.length, cur.width);
            }
            if (cur.width == nex.length) {
                pushcheck(nmask, cur.length, nex.width, cur.width);
            }
            if (cur.length == nex.width) {
                pushcheck(nmask, cur.width, nex.length, cur.length);
            }
            if (cur.length == nex.length) {
                pushcheck(nmask, cur.width, nex.width, cur.length);
            }
        }
    }
}
void exec() {
    ans = -INF;
    cin>>N;
    rs.clear();
    ars.clear();
    for (int i = 0, a, b; i < N; i++) {
        cin>>a>>b;
        if (a > b)
            swap(a,b);
        rs.push_back({a,b});
    }
    for (int m = 1; m < (1<<N); m++) {
        check(m,0);
        check(m,1);
    }
    bfs();
    if (ans == -INF) {
        cout<<"Not Possible\n";
    }
    else
        cout<<ans*2<<"\n";
}
int main() {
    int T = 10;
    while(T--) {
        exec();
    }
}
