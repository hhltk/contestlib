struct DSU {
	int n, sz;
	vector<int> p;
	DSU(int n_) : n(n_) {
		p.assign(n, -1);
		sz = n;
	}
	int find(int s) {
		if (p[s] < 0) return s;
		return p[s] = find(p[s]);
	}
	bool unite(int a, int b) {
		a = find(a); b = find(b);
		if (a != b) {
			if (p[b] < p[a]) swap(a, b);
			p[a] += p[b];
			p[b] = a;
			sz--;
		}
		return a != b;
	}
};
