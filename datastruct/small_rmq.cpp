#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

// source: benq, own, kactl
template <typename T> struct RMQ {
	vector<vector<T>> spr;

	RMQ(const vector<T> &v) : spr(1, v) {
		for (int j = 1; (1 << j) <= sz(v); ++j) {
			spr.push_back(vector<T>(sz(v) - (1 << j) + 1));
			for (int i = 0; i < sz(spr[j]); ++i) {
				spr[j][i] = min(spr[j - 1][i], spr[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
	T get(int l, int r) {
		int d = 31 - __builtin_clz(r - l + 1);
		return min(spr[d][l], spr[d][r - (1 << d) + 1]);
	}
};
