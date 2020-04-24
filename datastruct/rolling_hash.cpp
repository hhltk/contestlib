static const int MOD = 1e9 + 7;
using mint = modint<MOD>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int A[2] = {uniform_int_distribution<int>(1, MOD)(rng),
		  uniform_int_distribution<int>(1, MOD)(rng)};

struct rolling_hash {
	private:
	string s;
	vector<array<mint, 2>> h, p;
	int get(int a, int b, int c) {
		if (!a) return int(h[b][c]);
		return int(h[b][c] - h[a - 1][c] * p[b - a + 1][c]);
	}

	public:
	rolling_hash() {}
	rolling_hash(const string &s_) : s(s_) {
		for (int j = 0; j < 2; ++j) {
			h[0][j] = s[0];
			p[0][j] = 1;
			for (int i = 1; i < static_cast<int>(s.size()); ++i) {
				h[i][j] = h[i - 1][j] * A[j] + s[i];
				p[i][j] = p[i - 1][j] * A[j];
			}
		}
	}
	pair<int, int> get(int a, int b) {
		return {get(a, b, 0), get(a, b, 1)};
	}
	pair<int, int> get() { return get(0, s.size() - 1); }
};
