#include <bits/stdc++.h>
#define MAXN 100010
#define MAXQ 320
using namespace std;
int A[100010];
int totm = 0;
unordered_map <int, int> MP, occur;
unordered_set <int> emp;
multiset<int> MS[MAXQ];
bitset<1010> BS[MAXQ];
int N, Q, sq;
void update(int idx, int val) {
    MS[idx/sq].erase(MS[idx/sq].lower_bound(A[idx]));
    occur[A[idx]]--;
    if (!MS[idx/sq].count(A[idx])) {
        BS[idx/sq][MP[A[idx]]] = 0;
    }
    if (occur[A[idx]] <= 0) {
        emp.insert(MP[A[idx]]);
    }
    A[idx] = val;
    if (!occur.count(val) || occur[val] == 0 ||!MP.count(val))
    {
        if (!emp.empty()) {
            MP[A[idx]] = *(emp.begin());
            emp.erase(emp.begin());
        }
        else MP[A[idx]] = totm++;
    }
    if (!occur.count(val)) occur[val] = 0;
    occur[val]++;
    MS[idx/sq].insert(val);
    BS[idx/sq][MP[A[idx]]] = 1;
}
int query(int L, int R) {
    int sl = L/sq, sr = R/sq;
    bitset<1010> bs;
    if (sl == sr) {
        for (int i = L; i <= R; i++) {
            bs[MP[A[i]]] = 1;
        }
        return bs.count();
    }
    for (int i = L; i/sq == sl; i++) {
        bs[MP[A[i]]] = 1;
    }
    for (int i = sl + 1; i < sr; i++) {
        bs |= BS[i];
    }
    for (int i = sr*sq; i <= R; i++) {
        bs[MP[A[i]]] = 1;
    }
    return bs.count();
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>Q;
    sq = sqrt(N);
    for (int i = 0; i < N; i++) {
        cin>>A[i];
        if (!MP.count(A[i])) MP[A[i]] = totm++;
        MS[i/sq].insert(A[i]);
        if (!occur.count(A[i])) occur[A[i]] = 0;
        occur[A[i]]++;
        BS[i/sq][MP[A[i]]] = 1;
    }
    for (int i = 0, op, a, b; i < Q; i++) {
        cin>>op>>a>>b;
        if (op == 1) {
            update(a-1, b);
        }
        else {
            cout<<query(a-1, b-1)<<"\n";
        }
    }
}
