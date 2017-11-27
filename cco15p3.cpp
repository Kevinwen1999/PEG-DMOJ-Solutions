#include <bits/stdc++.h>
#define MAXN 1622010
#define LG 30
#define ld long double
#define ll long long
#define EPS 1e-9
using namespace std;
ld X;
int K, N, Q;
struct line {
	ld b, y2, c;
	ld slope;
	void calc() {
		slope = (y2 - b) / (ld)(X);
	}
} tl;
inline bool equal(ld a, ld b) {
	return fabs(a - b) < EPS;
}
vector <line> vl;
vector <ld> allx;
vector <pair <int, int> > aq[2010];
unordered_map <ld, int> mp;
ll pre[MAXN];
int SPT[MAXN][LG];
int NP;
void buildSPT(int n, ll A[]) {
	for (int i = 0; i < n; i++) {
		SPT[i][0] = i;
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			SPT[i][j] = (A[SPT[i][j - 1]] > A[SPT[i + (1 << (j - 1))][j - 1]]) ? SPT[i][j - 1] : SPT[i + (1 << (j - 1))][j - 1];
		}
	}
}
int querySPT(int i, int j, ll A[]) {
	int k = log((ld)(j - i + 1)) / log(2.0);
	return (A[SPT[i][k]] > A[SPT[j - (1 << k) + 1][k]]) ? SPT[i][k] : SPT[j - (1 << k) + 1][k];
}
bool valid(ld x) {
	return (x > -EPS && (x < X || equal(x, X)));
}
ld fround(ld x) {
	return round(x * 1000000) / 1000000;
}
int main() {
	cin >> X >> K >> N >> Q;
	for (int i = 0, a, b, c; i < N; i++) {
		cin >> tl.b >> tl.y2 >> tl.c;
		tl.calc();
		vl.push_back(tl);
	}
	for (int i = 0, a, b; i < Q; i++) {
		cin >> a >> b; a--;
		aq[a].push_back({i, b});
	}

	vector <pair<int ,ll> > ans;
	for (int i = 0; i < N; i++) {
		allx.clear();
		mp.clear();
		allx.push_back(0), allx.push_back(X);
		for (int j = 0; j < N; j++) {
			if (j == i) continue;
			if (equal(vl[i].slope, vl[j].slope)) continue;
			ld x = (vl[j].b - vl[i].b) / (vl[i].slope - vl[j].slope);
			if (valid(x)) allx.push_back(fround(x));
		}
		for (auto j : aq[i]) {
			allx.push_back(j.second), allx.push_back(j.second + K);
		}
		sort(allx.begin(), allx.end());
		allx.erase(unique(allx.begin(), allx.end()), allx.end());
		NP = allx.size();
		for (int j = 0; j < NP; j++)
			pre[j] = 0;
		for (int j = 0; j < NP; j++) {
			mp[allx[j]] = j;	
		}
		for (int j = 0; j < N; j++) {
			if (i == j) continue;	
			ld x = (vl[j].b - vl[i].b) / (vl[i].slope - vl[j].slope);
			x = fround(x);
			int id0 = 0, idx = mp[x], idX = NP - 1;
			if (vl[i].b > vl[j].b) {
				if (vl[i].slope > vl[j].slope || equal(vl[i].slope, vl[j].slope)) continue;
				else {
					if (valid(x)) {
						pre[idx] += vl[j].c;
					}
				}
			} else if (vl[i].b < vl[j].b) {	
				if (vl[j].slope > vl[i].slope || equal(vl[i].slope, vl[j].slope)) {
					pre[id0] += vl[j].c;
				}
				else {
					pre[id0] += vl[j].c;	
					if (valid(x)) {
						pre[idx] -= vl[j].c;
					}
				}
			}
		}
		for (int j = 0; j < NP - 1; j++) {
			if (j) pre[j] += pre[j - 1];
		}
		for (int j = 0; j < NP - 1; j++) {
		}
		buildSPT(NP - 1, pre);
		for (auto j : aq[i]) {
			int id1 = mp[j.second], id2 = mp[j.second + K] - 1;
			ll as = pre[querySPT(id1, id2, pre)];
			ans.push_back({j.first, as});
		}
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i.second << "\n";
	}
}

