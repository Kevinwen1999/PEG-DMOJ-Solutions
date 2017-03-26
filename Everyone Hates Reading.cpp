#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int N, M;
int wordtot = 0, nodetot = 0;
int matrix[MAXN][26];
vector <int> finished[MAXN], notcomplete[MAXN];
void update(string& cur) {
    int ptr = 0, lastnode = 0;
    while(ptr < cur.size()) {
        int cc = cur[ptr]-'a';
        if (!matrix[lastnode][cc]) {
            matrix[lastnode][cc] = ++nodetot;
        }
        int curnode = matrix[lastnode][cc];
        if (ptr == cur.size()-1) {
            finished[curnode].push_back(wordtot);
        }
        else {
            notcomplete[curnode].push_back(wordtot);
        }
        lastnode = curnode;
        ptr++;
    }
}
int query (string& cur, int l, int r) {
    int ptr = 0, lastnode = 0, sum = 0;
    while(ptr < cur.size()) {
        int cc = cur[ptr]-'a';
        int curnode = matrix[lastnode][cc];
        if (curnode == 0) break;
        if (ptr == cur.size()-1){
            sum += upper_bound(notcomplete[curnode].begin(), notcomplete[curnode].end(), r)
            - lower_bound(notcomplete[curnode].begin(), notcomplete[curnode].end(), l);
        }
        sum += upper_bound(finished[curnode].begin(), finished[curnode].end(), r)
            - lower_bound(finished[curnode].begin(), finished[curnode].end(), l);
        lastnode = curnode;
        ptr++;
    }
    return sum;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        string cur;
        cin>>cur;
        wordtot++;
        update(cur);
    }
    for (int i = 0; i < M; i++){
        string cur;
        cin>>cur;
        int l, r;
        cin>>l>>r;
        printf("%d\n", query(cur, l, r));
    }
}
