template <typename T> struct RMQ {
	int lvl(int x) { return 31 - __builtin_clz(x); }
	vector<vector<int>> spr;
	vector<T> v;
	int combine(int a, int b) { return v[a] <= v[b] ? a : b; }
	RMQ() {}
	RMQ(vector<T> &v_) : v(v_) {
		spr = {vector<int>(v.size())};
		iota(spr[0].begin(), spr[0].end(), 0);
		for (int j = 1; (1 << j) <= (int) v.size(); ++j) {
			spr.push_back(vector<int>(v.size() - (1 << j) + 1));
			for (int i = 0; i < (int) spr[j].size(); ++i) {
				spr[j][i] = combine(spr[j - 1][i], spr[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
	int get(int l, int r) {
		int d = lvl(r - l + 1);
		return combine(spr[d][l], spr[d][r - (1 << d) + 1]);
	}
	int getval(int l, int r) { return v[get(l, r)]; }
};
