struct edge {
	int a, b, c;
	bool operator<(const edge &x) const {
		return c < x.c;
	}
};

pair<ll, vector<vector<pair<int, int>>>> create_mst(vector<edge>& edg, int n) {
	sort(edg.begin(), edg.end());
	vector<vector<pair<int, int>>> g(n);
	DSU k(n);
	ll r = 0;
	for (edge u : edg) {
		if (k.unite(u.a, u.b)) {
			r += u.c;
			g[u.a].emplace_back(u.b, u.c);
			g[u.b].emplace_back(u.a, u.c);
		}
	}
	if (k.sz != 1) r = -1;
	return {r, g};
}
