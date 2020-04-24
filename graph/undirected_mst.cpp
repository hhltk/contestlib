using ll = long long;
using graph = vector<vector<pair<int, int>>>;

// returns -1 if there is no mst
pair<ll, graph> create_mst(vector<pair<int, pair<int, int>>> edg, int n) {
	sort(edg.begin(), edg.end());
	graph g(n);
	DSU dsu(n);
	ll r = 0;
	for (auto &[w, x] : edg) {
		auto &[a, b] = x;
		if (dsu.unite(a, b)) {
			r += w;
			g[a].emplace_back(b, w);
			g[b].emplace_back(a, w);
		}
	}
	if (dsu.sz != 1)
		r = -1;
	return {r, g};
}
