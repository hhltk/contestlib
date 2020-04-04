struct mint {
 	int v;
	explicit operator int() const { return v; } 
	mint() : v(0) {}
	mint(ll v_) : v(v_ % MOD) { if ( v < 0) v += MOD; }
};
mint& operator+=(mint& a, mint b) { if (a.v += b.v >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if (a.v -= b.v < 0) a.v += MOD; return a; }
mint& operator*=(mint& a, mint b) { a.v = ll(a.v) * ll(b.v) % MOD; return a; }
mint pow(mint a, ll b) { mint r(1); while (b) { if (b % 2) r *= a; a *= a; b /= 2; } return r; }
mint inv(mint a) { return pow(a, MOD - 2); }
mint& operator/=(mint& a, mint b) { a *= inv(b); return a; }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return a *= b; }
mint operator/(mint a, mint b) { return a /= b; }
