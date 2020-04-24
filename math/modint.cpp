template <typename T> T pow(T a, ll b) {
	T r = 1;
	for (; b; b /= 2, a *= a)
		if (b % 2) r *= a;
	return r;
}

// source: ecnerwala, own, benq
template <int MOD> struct modint {
	int v;
	modint() : v(0) {}
	modint(ll x) : v(x % MOD) {
		if (v < 0) v += MOD;
	}
	explicit operator int() const { return v; }
	explicit operator ll() const { return v; }

	friend ostream &operator<<(ostream &out, const modint &a) {
		return out << int(a);
	}
	friend istream &operator>>(istream &in, modint &a) {
		ll x;
		in >> x;
		a = modint(x);
		return in;
	}

	modint inv() const {
		return pow(*this, MOD - 2);
	} // only works if MOD is prime
	friend modint inv(const modint &x) { return x.inv(); }

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
	modint &operator/=(const modint &a) { return *this *= a.inv(); }

	friend modint operator+(const modint &a, const modint &b) {
		return modint(a) += b;
	}
	friend modint operator-(const modint &a, const modint &b) {
		return modint(a) -= b;
	}
	friend modint operator*(const modint &a, const modint &b) {
		return modint(a) *= b;
	}
	friend modint operator/(const modint &a, const modint &b) {
		return modint(a) /= b;
	}
};

using mint = modint<MOD>;
