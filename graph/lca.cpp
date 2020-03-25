using pii = pair<int, int>;
using graph = vector<vi>;

struct LCA {
	int T = 0;
	vi time, dist;
	vector<pii> r;
	RMQ<pii> rmq;

	LCA(graph& g) : time(sz(g)), dist(sz(g)), rmq((dfs(0, 0, g), r)) {}

	void dfs(int s, int e, graph& g) {
		time[s] = r.size();
		r.push_back({dist[s], s});
		for (auto& u : g[s]) if (u != e) {
			r.push_back({dist[s], s});
			dist[u] = dist[s] + 1;
			dfs(u, s, g);
		}
	}
	int query(int a, int b) {
		a = time[a], b = time[b];
		return rmq.getval(min(a, b), max(a, b)).second;
	}
};
