template <typename T> T pow(T a, ll b) {
	T r = 1; for ( ; b; b /= 2, a *= a) if (b % 2) r *= a; return r;
}

template <int MOD> struct modint {
private:
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
	friend modint operator+(const modint &a, const modint &b) { return modint(a) += b; }
	friend modint operator-(const modint &a, const modint &b) { return modint(a) -= b; }
	friend modint operator*(const modint &a, const modint &b) { return modint(a) *= b; }
	friend modint operator/(const modint &a, const modint &b) { return modint(a) /= b; }
};
using mint=modint<int(1e9)+7>;

vector<mint> fact, ifact;
void init(int N = int(1e6)) {
	fact.resize(N + 1);
	ifact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
	ifact[N] = 1 / fact[N];
	for (int i = N; i > 0; --i) ifact[i - 1] = i * ifact[i];
}

mint choose(int a, int b) {
	if (a < b || b < 0) return 0;
	return fact[a] * ifact[b] * ifact[a - b];
}
