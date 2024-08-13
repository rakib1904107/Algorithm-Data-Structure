#include <bits/stdc++.h>
using namespace std;


///all the edges should be in the same connected component
///#undirected graph: euler path: all degrees are even or exactly two of them are odd.
///#undirected graph: euler circuit: all degrees are even


///euler path in an undirected graph
///it also finds circuit if it exists

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> path;
vector<bool> seen;

void dfs(int node) {
	while (!g[node].empty()) {
		auto it= g[node].back();
        int son=it.first,idx=it.second;
		g[node].pop_back();
		if (seen[idx]) { continue; }
		seen[idx] = true;
		dfs(son);
	}
	path.push_back(node);
}

int main() {
	cin >> n >> m;

	vector<int> degree(n, 0);
	g.resize(n);
	degree.resize(n);
	seen.resize(m);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back({y, i});
		g[y].push_back({x, i});
		degree[x]++;
		degree[y]++;
	}

    ///for circuit
	for (int node = 0; node < n; node++) {
		if (degree[node] % 2) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}

	dfs(0);

	if (path.size() != m + 1) {
		cout << "IMPOSSIBLE";
	} else {
		for (auto node : path) { cout << node + 1 << ' '; }
	}
}
