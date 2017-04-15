#include <bits/stdc++.h>
#define MAXN 2002
using namespace std;
struct state {
    char dir;
    int i;
    int j;
};
int N, M;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
deque <state> row[MAXN], col[MAXN];
vector <pair <int,int> > ans;
int tot = 0;
void check(deque <state> dq[], char a1, char a2, int n) {
    for (int i = 0; i < n; i++) {
        if (dq[i].empty()) continue;
        while (!dq[i].empty() && visited[dq[i].front().i][dq[i].front().j])
            dq[i].pop_front();
        while (!dq[i].empty() && visited[dq[i].back().i][dq[i].back().j])
            dq[i].pop_back();
        if (dq[i].empty()) continue;
        while (!dq[i].empty() && dq[i].front().dir == a1) {
            visited[dq[i].front().i][dq[i].front().j] = true;
            ans.push_back({dq[i].front().i, dq[i].front().j});
            dq[i].pop_front();
        }
        if (dq[i].empty()) continue;
        while(!dq[i].empty() && dq[i].back().dir == a2) {
            visited[dq[i].back().i][dq[i].back().j] = true;
            ans.push_back({dq[i].back().i, dq[i].back().j});
            dq[i].pop_back();
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        cin>>grid[i];
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.') continue;
            tot++;
            row[i].push_back((state){grid[i][j], i, j});
            col[j].push_back((state){grid[i][j], i, j});
        }
    }
    while ((int)ans.size() < tot) {
        check(row, 'W', 'E', N);
        check(col, 'N', 'S', M);
    }
    for (auto i : ans) {
        printf("(%d,%d)\n", i.first, i.second);
    }
}
