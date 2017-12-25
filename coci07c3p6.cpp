#include <bits/stdc++.h>
#define MAXN 250010
#define ll long long
using namespace std;
int A[MAXN];
struct node {
	int freq[10];
	int sum = 0;
	int lazy = 0;
} seg[MAXN * 4], dummy;
void pushup(int s, int l, int r) {
	seg[s].sum = 0;
	for (int i = 0; i < 10; i++) {
		seg[s].freq[i] = seg[l].freq[i] + seg[r].freq[i];
		seg[s].sum += seg[s].freq[i] * i;
	}
}
int tmp[10];
void pushdown(int s, int l, int r, int L, int R) {
	memcpy(tmp, seg[s].freq, sizeof tmp);
	seg[s].sum = 0;
	int v = seg[s].lazy;
	for (int i = 0; i < 10; i++) {
		seg[s].freq[(i + v) % 10] = tmp[i];
	}
	for (int i = 0; i < 10; i++) {
		seg[s].sum += seg[s].freq[i] * i;
	}
	seg[s].lazy = 0;
	if (L == R) return;
	seg[l].lazy += v;
	seg[r].lazy += v;
}
void build(int s, int L, int R) {
	if (L == R) {
		seg[s].freq[A[L]] = 1;
		seg[s].sum = A[L];
		return;
	}
	int l = s * 2, r = s * 2 + 1, mid = (L + R) / 2;
	build(l, L, mid); build(r, mid + 1, R);
	pushup(s, l, r);
}
int ql, qr, qv = 1;
void update(int s, int L, int R) {
	int l = s * 2, r = s * 2 + 1, mid = (L + R) / 2;
	if (seg[s].lazy != 0) {
		pushdown(s, l, r, L, R);
	}
	if (L > R || L > qr || R < ql) return;
	if (L >= ql && R <= qr) {
		seg[s].lazy += qv;
		pushdown(s, l, r, L, R);
		return;
	}
	update(l, L, mid); update(r, mid + 1, R);
	pushup(s, l, r);
}
void combine(node &a, node &b) {
	a.sum = 0;
	for (int i = 0; i < 10; i++) {
		a.freq[i] += b.freq[i];
		a.sum += a.freq[i] * i;
	}
}
node query(int s, int L, int R) {
	int l = s * 2, r = s * 2 + 1, mid = (L + R) / 2;
	if (seg[s].lazy != 0) {
		pushdown(s, l, r, L, R);
	}
	if (L > R || L > qr || R < ql) return dummy;
	if (L >= ql && R <= qr) {
		return seg[s];
	}
	node p1 = query(l, L, mid), p2 = query(r, mid + 1, R);
	combine(p1, p2);
	return p1;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	string in; cin >> in;
	for (int i = 0; i < in.size(); i++) {
		A[i] = in[i] - '0';
	}
	build(1, 0, N - 1);
	for (int i = 0; i < M; i++) {
		cin >> ql >> qr;
		ql--, qr--;
		node x = query(1, 0, N - 1);
		cout << x.sum << "\n";
		update(1, 0, N - 1);
	}
}
