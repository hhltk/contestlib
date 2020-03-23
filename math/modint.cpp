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
