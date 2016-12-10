#include <bits/stdc++.h>
using namespace std;
int adj[110][110];
unordered_map <int,int>M;
int N;
int V, tot;
vector<int> topological_sort()
{
	vector<int> result;
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
        visited[i] = false;
	while (true)
    {
		bool allVisited = true;
		for (int i = 0; i < V; i++)
            allVisited = allVisited & visited[i];
		if (allVisited) return result;
		vector<int> inDegree;
		for (int i = 0; i < V; i++)
        {
			if (!visited[i])
			{
				int indeg = 0;
				for (int j = 0; j < V; j++)
					if (!visited[j] && adj[j][i])
                        indeg += 1;
				if (indeg == 0) inDegree.push_back(i);
			}
		}
		sort(inDegree.begin(), inDegree.end());
		if (inDegree.empty())
        {
			vector<int> e;
			return e;
		}
		for (int i = 0; i <= 0; i++)
        {
			int cur = inDegree[i];
			visited[cur] = true;
			for (int j = 0; j < V; j++)
            {
				adj[cur][j] = 0;
				adj[j][cur] = 0;
			}
			result.push_back(cur);
		}
	}
}
string o[110];
int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        string cur; cin>>cur;
        int a, b; cin>>a>>b;
        if (M.count(a)==0)
        {
            M[a] = tot++;
            o[M[a]] = "";
        }
        if (M.count(b)==0)
        {
            M[b] = tot++;
            o[M[b]] = "";
        }
        //adj[M[a]][M[b]] = 1;
        adj[M[b]][M[a]] = 1;
        o[M[a]] = cur;
    }
    V = tot;
    vector <int> all = topological_sort();
    if (all.size()==0)
    {
        cout<<"Impossible\n";
    }
    else
    {
        for (int i : all)
            cout<<o[i]<<endl;
    }
}
