struct SegmentTree {
	int n;
	vector<int> p, l;
	SegmentTree(int n) : n(n), p(n * 4), l(n * 4) {}
	int query(int s, int l, int r, int x, int y) {
		if (x <= l && r <= y) return p[s];
		if (y <= l || r <= x) return 0;
		push(s);
		int m = (l + r) / 2;
		return max(query(s * 2, l, r, x, m),
			   query(s * 2 + 1, l, r, m, y));
	}
	void change(int s, int l, int r, int x, int y, int k) {
		if (x <= l && r <= y) return apply(s, k);
		if (y <= l || r <= x) return;
		push(s);
		int m = (l + r) / 2;
		change(s * 2, l, r, x, m, k);
		change(s * 2 + 1, l, r, m, y, k);
		pull(s);
	}
	void push(int s) {
		apply(s * 2, l[s]);
		apply(s * 2 + 1, l[s]);
	}
	void apply(int s, int x) {
		p[s] += x;
		l[s] += x;
	}
	void pull(int s) { p[s] = max(p[s * 2], p[s * 2 + 1]); }
	int query(int l, int r) { return query(1, l, r, 0, n); }
	void change(int l, int r, int k) { change(1, l, r, 0, n, k); }
};
