vector<ll> dijkstra(int s, vector<vector<pair<int, int>>> &g) {
	vector<ll> dist(g.size());
	fill(dist.begin(), dist.end(), (ll) 1e18);
	priority_queue<pair<ll, int>> pq;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto k = pq.top(); pq.pop();
		if (-k.first > dist[k.second]) continue;
		for (auto &u : g[k.second]) {
			if (dist[k.second] + u.second < dist[u.first]) {
				dist[u.first] = dist[k.second] + u.second;
				pq.push({-dist[u.first], u.first});
			}
		}
	}
	return dist;
}
