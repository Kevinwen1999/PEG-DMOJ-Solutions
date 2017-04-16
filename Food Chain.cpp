#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;
int N, K, pt = 0;
int p[3*MAXN];
struct animal {
    int self;
    int eat;
    int eaten;
};
animal all[MAXN];
void init(int n) {
    for (int i = 0; i <= n; i++) {
        all[i].self = ++pt;
        p[pt] = pt;
        all[i].eat = ++pt;
        p[pt] = pt;
        all[i].eaten = ++pt;
        p[pt] = pt;
    }
}
int findp(int x) {
    return p[x] == x ? x : (p[x] = findp(p[x]));
}
bool sameset(int x, int y) {
    return findp(x) == findp(y);
}
void mergeset(int x, int y) {
    x = findp(x), y = findp(y);
    if (x == y) return;
    p[x] = y;
}
bool trivial(int a, int b, int op) {
    if (op == 2 && a == b) return true;
    if (a > N || b > N) return true;
    return false;
}
int main() {
    scanf("%d%d", &N, &K);
    init(N);
    int tot = 0;
    for (int i = 0; i < K; i++) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (trivial(a, b, op)) {
//            cout<<"shit\n";
            tot++;
            continue;
        }
        if (op == 1) {
            if (sameset(all[a].self, all[b].eaten)) {
//                cout<<"11\n";
                tot++;
                continue;
            }
            if (sameset(all[a].self, all[b].eat)) {
//                cout<<"12\n";
                tot++;
                continue;
            }
            if (sameset(all[a].eat, all[b].eaten)) {
//                cout<<"13\n";
                tot++;
                continue;
            }
            if (sameset(all[a].eat, all[b].self)) {
//                cout<<"14\n";
                tot++;
                continue;
            }
            if (sameset(all[a].eaten, all[b].self)) {
//                cout<<"15\n";
                tot++;
                continue;
            }
            if (sameset(all[a].eaten, all[b].eat)) {
//                cout<<"16\n";
                tot++;
                continue;
            }
            mergeset(all[a].self, all[b].self);
            mergeset(all[a].eat, all[b].eat);
            mergeset(all[a].eaten, all[b].eaten);
        }
        else {
            if (sameset(all[a].self, all[b].self)) {
//                cout<<"21\n";
                tot++;
                continue;
            }
            if (sameset(all[a].self, all[b].eat)){
//                cout<<"22\n";
                tot++;
                continue;
            }
            if (sameset(all[a].eat, all[b].eat)) {
//                cout<<"23\n";
                tot++;
                continue;
            }
            if (sameset(all[a].eat, all[b].eaten)) {
//                cout<<"24\n";
                tot++;
                continue;
            }
            if (sameset(all[a].eaten, all[b].eaten)) {
//                cout<<"25\n";
                tot++;
                continue;
            }
            if (sameset(all[a].eaten, all[b].self)) {
//                cout<<"26\n";
                tot++;
                continue;
            }
            mergeset(all[a].self, all[b].eaten);
            mergeset(all[a].eat, all[b].self);
            mergeset(all[a].eaten, all[b].eat);
        }
    }
    printf("%d\n", tot);
}
