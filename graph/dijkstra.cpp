vector<ll> dijkstra(int s, vector<vector<pair<int, int>>> &g) {
	const ll INF = 1e18;
	vector<ll> dist(g.size(), INF);
	priority_queue<pair<ll, int>> pq;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto k = pq.top();
		pq.pop();
		if (-k.first > dist[k.second]) continue;
		for (auto &u : g[k.second]) {
			ll off = dist[k.second] + u.second;
			if (off < dist[u.first]) {
				dist[u.first] = off;
				pq.push({-off, u.first});
			}
		}
	}
	return dist;
}
