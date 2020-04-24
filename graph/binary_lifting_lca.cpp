using vi = vector<int>;
using graph = vector<vi>;
#define sz(x) (int)x.size()

// source: own
// O(\log N) query after O(N \log N) preprocessing
struct LCA {
	int k;
	vi dep;
	vector<vi> spr;

	LCA(graph &g) : k(31 - __builtin_clz(sz(g))), dep(sz(g)), spr(sz(g), vi(k + 1)) {
		dfs(0, 0, g);
	}

	void dfs(int s, int e, graph &g) {
		spr[s][0] = e;
		for (int j = 0; j < k; ++j)
			spr[s][j + 1] = spr[spr[s][j]][j];
		for (auto &u : g[s])
			if (u != e) {
				dep[u] = dep[s] + 1;
				dfs(u, s, g);
			}
	}

	int up(int a, int b) {
		for (int j = k; j >= 0; --j) {
			if (b >= (1 << j))
				a = spr[a][j], b -= 1 << j;
		}
		return a;
	}

	int query(int a, int b) {
		if (dep[a] < dep[b])
			swap(a, b);
		a = up(a, dep[a] - dep[b]);
		for (int j = k; j >= 0; --j) {
			if (spr[a][j] != spr[b][j])
				a = spr[a][j], b = spr[b][j];
		}
		return a == b ? a : spr[a][0];
	}
};
