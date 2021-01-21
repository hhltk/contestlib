#include <iostream>
#include <vector>
#define sz(x) ((int)(x).size())
using namespace std;
using vi = vector<int>;
using graph = vector<vi>;

#include "lca.cpp"

namespace centroid {
	struct CentroidDecomp {
		vi subsz, del;
		graph g, ret;
		CentroidDecomp(graph &g) : subsz(sz(g)), del(sz(g)), g(g), ret(sz(g)) {
			recurse();
		}

	private:
		int calc_sizes(int s, int e = -1) {
			subsz[s] = 1;
			for (int u : g[s]) {
				if (u != e && !del[u]) {
					subsz[s] += calc_sizes(u, s);
				}
			}
			return subsz[s];
		}
		int find_root(int s, int t, int e = -1) {
			for (auto u : g[s]) {
				if (u != e && !del[u] && subsz[u] > t / 2) {
					return find_root(u, t, s);
				}
			}
			return s;
		}
		void recurse(int node = 0, int prev = -1) {
			int root = find_root(node, calc_sizes(node));
			del[root] = 1;
			if (prev != -1) ret[prev].push_back(root);
			for (int u : g[root]) if (!del[u]) recurse(u, root);
		}
	};
	// returns the decomposed tree and the root of the tree
	pair<graph, int> decomp(graph &g) {
		auto c = CentroidDecomp(g);
		vector<bool> seen(sz(g));
		for (auto x : c.ret) for (auto y : x) seen[y] = 1;
		int r = find(seen.begin(), seen.end(), 0) - seen.begin();
		return {c.ret, r};
	}
}
