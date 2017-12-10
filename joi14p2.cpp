#include <bits/stdc++.h>
#define MAXN 600010
#define ll long long
using namespace std;

vector <int> av;
unordered_map <int, int> um;

int N, K;
int A[MAXN], B[MAXN], Q[MAXN];
int last_idx[MAXN];
int SPT[MAXN][30];
vector <int> qry[MAXN];

void buildSPT(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		SPT[i][0] = i;
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			SPT[i][j] = (a[SPT[i][j - 1]] > a[SPT[i + (1 << (j - 1))][j - 1]]) ? SPT[i][j - 1] : SPT[i + (1 << (j - 1))][j - 1];
		}
	}
}
int querySPT(int i, int j, int a[]) {
	int k = log((double)(j - i + 1)) / log(2.0);
	return (a[SPT[i][k]] > a[SPT[j - (1 << k) + 1][k]]) ? SPT[i][k] : SPT[j - (1 << k) + 1][k];
}

int bit[MAXN];
void update(int x, int v) {
	for (;x <= av.size(); x += (x & -x))
		bit[x]+=v;
}
int query(int a) {
	if (a < 0) return 0;
	int sum  = 0;
	for (; a > 0; a-=(a & -a))
		sum+=bit[a];
	return sum;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		av.push_back(A[i]);
		av.push_back(B[i]);
	}
	for (int i = 0; i < K; i++) {
		cin >> Q[i];
		av.push_back(Q[i]);
	}
	
	sort(av.begin(), av.end());
	av.erase(unique(av.begin(), av.end()), av.end());
	for (int i = 0; i < av.size(); i++) {
		um[av[i]] = i + 1;
	}
	
	for (int i = 0; i < N; i++) {
		A[i] = um[A[i]];
		B[i] = um[B[i]];
	}
	for (int i = 0; i < K; i++) {
		Q[i] = um[Q[i]];
	}
	
	memset(last_idx, -1, sizeof last_idx);
	for (int i = 0; i < K; i++) {
		last_idx[Q[i]] = i;
	}

	buildSPT(av.size(), last_idx);
	
	for (int i = 0; i < N; i++) {
		int a = A[i], b = B[i];
		if (a > b) swap(a, b);
		b--;
		int ans;
		if (b < a) ans = -1;
		else ans = last_idx[querySPT(a, b, last_idx)];
		qry[ans == -1 ? K : ans].push_back(i);
	}

	int tot = 0;
	ll fa = 0;
	for (int i = K - 1; i >= 0; i--) {
		for (int j : qry[i]) {
			int ta = tot - query(max(A[j], B[j]) - 1);
			int get;
			if (ta % 2) get = av[(A[j] > B[j] ? B[j] : A[j]) - 1];
			else get = av[(A[j] > B[j] ? A[j] : B[j]) - 1];
			fa += get;
		}
		tot++;
		update(Q[i], 1);
	}
	for (int j : qry[K]) {
		int ta = tot - query(max(A[j], B[j]) - 1);
		if (ta % 2) fa += av[B[j] - 1];
		else fa += av[A[j] - 1];
	}
	cout << fa << "\n";
}
