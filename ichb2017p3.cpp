#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;
int N, Q;
unsigned int A[MAXN];
unsigned int seg[4 * MAXN];
void buildtree(int tidx, int L, int R) {
	if (L == R) {
		seg[tidx] = A[L];
		return;
	}
	int mid = (L + R) >> 1;
	buildtree(tidx * 2, L, mid);
	buildtree(tidx * 2 + 1, mid + 1, R);
	seg[tidx] = seg[tidx * 2] & seg[tidx * 2 + 1];
}
void update(int tidx, int L, int R, int idx) {
	if (L == R) {
		seg[tidx] = A[idx];
		return;
	}
	int mid = (L + R) >> 1;
	if (idx <= mid) {
		update(tidx * 2, L, mid, idx);
	} else {
		update(tidx * 2 + 1, mid + 1, R, idx);
	}
	seg[tidx] = seg[tidx * 2] & seg[tidx * 2 + 1];
}
unsigned int ans;
void query(int tidx, int L, int R, int QL, int QR) {
	if (QL <= L & R <= QR) {
		ans &= seg[tidx];
		return;
	}
	int mid = (L + R) >> 1;
	if (QL <= mid) {
		query(tidx * 2, L, mid, QL, QR);
	}
	if (QR > mid) {
		query(tidx * 2 + 1, mid + 1, R, QL, QR);
	}
}
int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
		cin >> A[i];
    }
	buildtree(1, 0, N - 1);
	for (int i = 0; i < Q; i++) {
		char op; cin >> op;
		if (op == 'Q') {
			unsigned int x, y, val; cin >> x >> y >> val; x--; y--;
			ans = val;
			query(1, 0, N - 1, x, y);
			cout << ans << "\n";
		} else {
			unsigned int idx, val; cin >> idx >> val; idx--;
			A[idx] = val;
			update(1, 0, N - 1, idx);
		}
	}
}
