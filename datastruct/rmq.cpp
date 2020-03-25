#define sz(x) (int) x.size()
#define all(x) begin(x), end(x)
using vi = vector<int>;

template <typename T> struct RMQ {
	vector<vi> spr;
	vector<T> v;
	int lvl(int x) { return 31 - __builtin_clz(x); }
	int combine(int a, int b) { return v[a] <= v[b] ? a : b; }
	RMQ(const vector<T> &v_) : v(v_) {
		spr = {vi(sz(v))}; iota(all(spr[0]), 0);
		for (int j = 1; (1 << j) <= sz(v); ++j) {
			spr.push_back(vi(sz(v) - (1 << j) + 1));
			for (int i = 0; i < sz(spr[j]); ++i) {
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
