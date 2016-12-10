#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int adj[10][10];
int V = 7;

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

int main()
{
	adj[0][6] = adj[0][3] = adj[2][3] = adj[1][0] = adj[2][4] = 1;
	while(1)
    {
		int a, b;
		cin >> a >> b;
        if (a==0 && b==0) break;
        a--; b--;
        adj[a][b] = 1;
	}
	vector<int> result = topological_sort();
	if (result.empty())
    {
        cout<<"Cannot complete these tasks. Going to bed."<<endl;
        return 0;
    }
	for (int n = 0; n < result.size(); n++)
		cout << ++result[n] <<" ";
}
