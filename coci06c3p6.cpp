#include <bits/stdc++.h>
#define MAXN 500010
#define ll long long
using namespace std;

int N, M;
int bef[MAXN], aft[MAXN];
void del(int a) {
	int a1 = bef[a], a2 = aft[a];
	aft[a1] = a2, bef[a2] = a1;
}
void add(int a, int b) {
	int b1 = bef[b];
	aft[b1] = a, bef[a] = b1;
	aft[a] = b, bef[b] = a;
}
int al[MAXN];
void test() {
	int st = 0, i = 0;
	while (st != N + 1) {
		if (st) {
			al[i++] = st;
		}
		st = aft[st];
	}
}
int leng, tail[MAXN], LIS[MAXN];
vector <int> f;
void lis() {
	leng = 1;
	tail[0] = al[0];
	for (int i = 1; i < N; i++) {
		if (al[i] < tail[0]) {
			LIS[al[i]] = 0;
			tail[0] = al[i];
		} else if (al[i] > tail[leng - 1]) {
			LIS[al[i]] = tail[leng - 1];
			tail[leng++] = al[i];
		} else {
			int l = 0, r = leng - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (tail[mid] < al[i]) 
					l = mid + 1;
				else
					r = mid - 1;
			}
			tail[r + 1] = al[i];
			LIS[al[i]] = tail[r];
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	aft[0] = 1; bef[N + 1] = N;
	for (int i = 1; i <= N; i++) {
		bef[i] = i - 1;
		aft[i] = i + 1;
	}
	char op; int a, b;
	for (int i = 0; i < M; i++) {
		scanf(" %c %d %d", &op, &a, &b);
		if (op == 'A') {
			del(a);
			add(a, b);	
		} else {
			del(a);
			add(a, aft[b]);
		}	
	}
	test();
	lis();
	printf("%d\n", N - leng);
	for (int i = tail[leng - 1]; i; i = LIS[i]) {
		f.push_back(i);
	}
	int j = N;
	for (int i = 0; i < leng && j; i++) {
		while (j != f[i]) {
			printf("B %d %d\n", j, f[i]);
			j--;
		}
		j--;
	}
	while (j != 0) {
		printf("A %d %d\n", j, j + 1);
		j--;
	}
	return 0;
}
