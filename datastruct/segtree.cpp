// source: own
template<typename T>
struct Tree {
	int n; // has to be a power of 2
	T I;
	function<T(T, T)> f;
	vector<T> t;
	Tree(int _n, T _I, function<T(T, T)> _f) : n(_n), I(_I), f(_f), t(n * 2, I) {}
	void change(int k, T x) {
		for (t[k += n] = x; k /= 2;) t[k] = f(t[k * 2], t[k * 2 + 1]);
	}
	T query(int a, int b) {
		T r = I;
		for (a += n, b += n; a <= b; a /= 2, b /= 2) {
			if (a % 2 == 1) r = f(t[a++], r);
			if (b % 2 == 0) r = f(r, t[b--]);
		}
		return r;
	}
};
