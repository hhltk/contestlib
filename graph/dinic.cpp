#include <limits>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

struct Dinic {
	vector<vector<pair<int, int>>> g;
	vector<ll> w;
	Dinic(int n) : g(n){};

	void addedge(int a, int b, int c, bool directed) {
		g[a].emplace_back(b, int(w.size()));
		w.push_back(c);
		g[b].emplace_back(a, int(w.size()));
		w.push_back(directed ? 0 : c);
	}

	vector<int> calclvls(int source) {
		vector<int> lvl(g.size(), -1);
		queue<int> q;
		q.push(source);
		lvl[source] = 0;
		while (!q.empty()) {
			int s = q.front();
			q.pop();
			for (auto &[u, id] : g[s]) {
				if (lvl[u] == -1 && w[id] > 0) {
					lvl[u] = lvl[s] + 1;
					q.push(u);
				}
			}
		}
		return lvl;
	}

	ll dfs(int node, int sink, ll x, vector<int> &c,
	       const vector<int> &lvl) {
		if (node == sink) {
			return x;
		}
		ll r = 0;
		for (int &ct = c[node]; ct < int(g[node].size()); ++ct) {
			if (x == 0) {
				break;
			}
			auto [u, id] = g[node][ct];
			if (w[id] < 0 || lvl[node] + 1 != lvl[u]) {
				continue;
			}
			ll f = dfs(u, sink, min(x, w[id]), c, lvl);
			w[id] -= f;
			w[id ^ 1] += f;
			x -= f;
			r += f;
			if ((w[id] != 0) && x == 0) {
				return r;
			}
		}
		return r;
	}

	ll push(int source, int sink) {
		ll flow = 0;
		ll f;
		do {
			vector<int> lvl = calclvls(source);
			vector<int> c(g.size());
			f = dfs(source, sink, numeric_limits<ll>::max(), c,
				lvl);
			flow += f;
		} while (f > 0);
		return flow;
	}
};
