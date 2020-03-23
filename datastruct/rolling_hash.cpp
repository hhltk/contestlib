template <typename T> T pow(T a, ll b) {
	T r = 1; for ( ; b; b /= 2, a *= a) if (b % 2) r *= a; return r;
}

template <int MOD_> struct modint {
private:
	static constexpr int MOD = MOD_;
	int v;
public:
	modint() : v(0) {}
	modint(ll x) : v(x % MOD) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }

	friend ostream &operator<<(ostream &out, const modint &a) { return out << int(a); }
	friend istream &operator>>(istream &in, modint &a) { ll x; in >> x; a = modint(x); return in; }

	friend bool operator==(const modint &a, const modint &b) { return a.v == b.v; }
	friend bool operator!=(const modint &a, const modint &b) { return a.v != b.v; }

	modint inv() const {
		modint r = v;
		r = pow(r, MOD - 2);
		return r;
	}
	friend modint inv(const modint &x) { return x.inv(); }
	modint neg() const {
		return modint(v ? MOD - v : 0);
	}
	friend modint neg(const modint &x) { return x.neg(); }

	modint operator-() const {
		return neg();
	}
	modint operator+() const {
		return mogint(*this);
	}

	modint &operator++() {
		v++;
		if (v == MOD) v = 0;
		return *this;
	}
	modint &operator--() {
		v--;
		if (v < 0) v += MOD;
		return *this;
	}

	modint operator++(int) {
		modint a = *this;
		v++;
		if (v == MOD) v = 0;
		return a;
	}
	modint operator--(int) {
		modint a = *this;
		v--;
		if (v < 0) v += MOD;
		return a;
	}

	modint &operator+=(const modint &a) {
		v += a.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modint &operator-=(const modint &a) {
		v -= a.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modint &operator*=(const modint &a) {
		v = ll(v) * ll(a.v) % MOD;
		return *this;
	}
	modint &operator/=(const modint &a) {
		return *this *= a.inv();
	}

	friend modint operator++(const modint &a, int) { modint r = a; ++a; return r; }
	friend modint operator--(const modint &a, int) { modint r = a; --a; return r; }
	friend modint operator++(const modint &a) { return ++a; }
	friend modint operator--(const modint &a) { return ++a; }
	friend modint operator+(const modint &a, const modint &b) { return modint(a) += b; }
	friend modint operator-(const modint &a, const modint &b) { return modint(a) -= b; }
	friend modint operator*(const modint &a, const modint &b) { return modint(a) *= b; }
	friend modint operator/(const modint &a, const modint &b) { return modint(a) /= b; }
};

static const int MOD = 1e9 + 7;
using mint=modint<MOD>;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int A[2] = {uniform_int_distribution<int>(1, MOD)(rng), uniform_int_distribution<int>(1, MOD)(rng)};

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
	rolling_hash(string s_) : s(s_) {
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
	pair<int, int> get() {
		return get(0, s.size() - 1);
	}
	
};
