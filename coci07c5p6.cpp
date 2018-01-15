#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
#define ll long long
#define MOD 1000000007
#define MAXN 40
#define MAXM 30010
#define MAXNODE 1000010
#define SIGMA 30
#define prm 100003
using namespace std;
ll x, y, d;
ll f1[MAXN], f2[MAXN];
ll prex[MAXN];
ll e[MAXN];
void extendedeuclid(ll a, ll b, ll &x, ll &y, ll &d) {
    if (!b) {x = 1; y = 0; d = a; return;}
    extendedeuclid(b, a % b, x, y, d);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
void precalc_exponents() {
    prex[0] = 1;
    extendedeuclid(MOD, 1, x, y, d);
    e[0] = y;
    for (int i = 1; i < MAXN; i++) {
        prex[i] = (prex[i - 1] * prm) % MOD;
        extendedeuclid(MOD, prex[i] % MOD, x, y, d);
        e[i] = y;
    }
}
void hash_string(string& in, ll F[], int p) {
    for (int i = 0; i < in.size(); i++) {
        F[i] = (((in[i] - 'a' + 1) % MOD) * (prex[i] % MOD)) % MOD;
        if (i) F[i] = (F[i] + F[i - 1]) % MOD;
    }
}

int N, Q;
int val[MAXNODE];
int sz;
int root;
struct TrieNode {
    char chr;
    int lchild; // pointing to first child
    int rchild; // pointing to adjacent siblings
};
TrieNode trie[MAXNODE];
int NewNode(char c) {
    trie[sz].lchild = trie[sz].rchild = -1;
    trie[sz++].chr = c;
    return sz - 1;
}
void init_trie(bool x) {
    sz = 0;
    root = NewNode(0);;
}
void TrieInsert(string &s) {
    int slen = s.size();
    int cur = trie[root].lchild; // current node
    int par = root; // parent of cur
    for (int i = 0; i < slen; i++) {
        if (cur == -1) { // current node for s[i] DNE
            trie[par].lchild = cur = NewNode(s[i]);
            // modify value associated with cur here
        } else {
            // modify value associated with cur here
            while (trie[cur].rchild != -1 && trie[cur].chr != s[i]) // keep going right to siblings
                cur = trie[cur].rchild;
            if (trie[cur].chr != s[i]) { // if corresponding node is not found
                trie[cur].rchild = NewNode(s[i]);
                cur = trie[cur].rchild;
            }
        }
        val[cur]++;
        par = cur;
        cur = trie[par].lchild; // keep going down
    }
}
ll Ask(string &s, int fa) {
    int u = 0;
    int last = fa;
    int cval;
    ll ans = fa;
    int dep = 0;
    int slen = s.size();
    int cur = trie[root].lchild; // current node
    int par = root; // parent of cur
    for (int i = 0; i < slen; i++) {
        if (cur == -1) { // current node for s[i] DNE
            break;
        } else {
            // modify value associated with cur here
            while (trie[cur].rchild != -1 && trie[cur].chr != s[i]) // keep going right to siblings
                cur = trie[cur].rchild;
            if (trie[cur].chr != s[i]) { // if corresponding node is not found
                break;;
            }
        }
        cval = val[cur];
        if (cval != last) {
            ans += dep * (last - cval);
            last = cval; 
        }
        par = cur;
        cur = trie[par].lchild; // keep going down
        dep++;
    }
    ans += dep * (last);
    return ans;
}
struct dic {
    ll av;
    int idx;
    bool operator < (const dic& cunt) const {
        return av < cunt.av;
    }
};
struct qry {
    int idx1;
    int idx2;
    string s;
    ll ans;
};
bool cmp1(qry &a, qry &b) {
    return a.idx1 < b.idx1;
}
bool cmp2(qry &a, qry &b) {
    return a.idx2 < b.idx2;
}
set <dic> sd;
vector <qry> vq;
vector <string> alls;
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> N;
    string shit;
    precalc_exponents();
    vq.reserve(MAXM);
    alls.reserve(MAXM);
    for (int i = 0; i < N; i++) {
        cin >> shit;
        hash_string(shit, f1, prm);
        alls.push_back(shit);
        sd.insert((dic){f1[(int)shit.size() - 1], i});
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> shit;
        hash_string(shit, f1, prm);
        auto it = sd.lower_bound((dic){f1[(int)shit.size() - 1], 0});
        if (it == sd.end() || it->av != f1[(int)shit.size() - 1]) {
            vq.push_back((qry){N - 1, i, shit, 0});
        } else {
            vq.push_back((qry){it->idx, i, shit, 0});
        }
    }
    sort(vq.begin(), vq.end(), cmp1);
    int st = -1;
    init_trie(true);
    for (int i = 0; i < Q; i++) {
       while (st < vq[i].idx1) {
           TrieInsert(alls[++st]);
       }
       vq[i].ans = Ask(vq[i].s, st + 1);
    }
    sort(vq.begin(), vq.end(), cmp2);
    for (int i = 0; i < Q; i++) {
        cout << vq[i].ans << "\n";
    }
}
