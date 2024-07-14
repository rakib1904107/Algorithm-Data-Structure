#include <bits/stdc++.h>
using namespace std;


///all the edges should be in the same connected component
///#directed graph: euler path: for all -> indeg = outdeg or nodes having indeg > outdeg = outdeg > indeg = 1 and for others in = out
///#directed graph: euler circuit: for all -> indeg = outdeg


///euler path in a directed graph
///it also finds circuit if it exists

int n, m;
vector<vector<int>> g;
vector<int> in, out, path;

void dfs(int node) {
	while (!g[node].empty()) {
		int son = g[node].back();
		g[node].pop_back();
		dfs(son);
	}
	path.push_back(node);
}

int main() {
	cin >> n >> m;

	g.resize(n + 1);
	in.resize(n + 1);
	out.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		out[x]++;
		in[y]++;
	}

    ///for euler path
	bool flag = true;
	for (int node = 2; node < n && flag; node++) {
		if (in[node] != out[node]) { flag = false; }
	}
	if (out[1] != in[1] + 1 || out[n] != in[n] - 1 || !flag) {
		cout << "IMPOSSIBLE";
		return 0;
	}

                             ///	for euler circuit
/// bool flag = true;
///	for (int node = 1; node <= n && flag; node++) {
///		if (in[node] != out[node]) { flag = false; }
///	}
///	if(!flag){
///        cout << "IMPOSSIBLE";
///		return 0;
///	}

	dfs(1);

	reverse(path.begin(), path.end());
	if (path.size() != m + 1 || path.back() != n) {
		cout << "IMPOSSIBLE";
	} else {
		for (auto node : path) { cout << node << ' '; }
	}
}
