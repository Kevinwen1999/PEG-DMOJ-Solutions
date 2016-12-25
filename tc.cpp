#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
struct person {
    int a, b, c;
    bool operator < (const person &p) const {
        return make_pair(a, b) < make_pair(p.a, p.b);
    }
    bool operator == (const person &p) const {
        return make_pair(a, b) == make_pair(p.a, p.b);
    }
} ppl[300004];
ll BIT[300004], ans[300004];

void update(int ind) {
    for(;ind<=300000;ind+= ind & -ind)
        BIT[ind]++;
}

ll sum(int ind) {
    ll res = 0;
    for(;ind;ind -= ind & - ind)
        res += BIT[ind];
    return res;
}

int main() {
    scanf("%d", &N);
    for(int i=0, a, b;i<N;i++) {
        scanf("%d%d", &a, &b);
        ppl[i] = {a, b, i};
    }
    sort(ppl, ppl + N);
    for(int i=0;i<N;i++) {
        int ind = ppl[i].b;
        if(i && ppl[i]==ppl[i-1])
            ans[ppl[i].c] = ans[ppl[i - 1].c];
        else
            ans[ppl[i].c] = sum(ind);
        update(ind);
    }
    for(int i=0;i<N;i++) printf("%lld\n", ans[i]);
}
