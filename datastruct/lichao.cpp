#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
struct Line {
	T a, b;
	Line(T a, T b) : a(a), b(b) {}
	T operator()(T x) {
		return x * a + b;
	}
};

template <typename T>
struct LiChao {
	const T INF = numeric_limits<T>::max() >> 2;
	int n;
	vector<Line<T>> p;
	vector<int> xs;
	LiChao(int n, vector<int> &basex) : n(n), p(n * 2, Line<T>(0, INF)), xs(n * 2) {
		for (int i = 0; i < int(basex.size()); ++i)
			xs[i + n] = basex[i];
		for (int i = int(basex.size()); i < n; ++i)
			xs[i + n] = i > 0 ? xs[i + n - 1] + 1 : 0;
		for (int i = n - 1; i > 0; --i)
			xs[i] = xs[i * 2];
	}
	void add_line(Line<T> x) {
		int s = 1;
		while (s < n) {
			int p1 = xs[s * 2], p2 = xs[s * 2 + 1];
			bool bp1 = x(p1) < p[s](p1), bp2 = x(p2) < p[s](p2);
			if (bp2)
				swap(x, p[s]);
			s = s * 2 + (bp1 == bp2);
		}
		if (x(xs[s]) < p[s](xs[s]))
			p[s] = x;
	}
	T get_best(int i) {
		int s = i + n;
		T ret = INF;
		while (s) {
			ret = min(ret, p[s](xs[i + n]));
			s /= 2;
		}
		return ret;
	}
};

// int main() {
// 	vector<int> xs((1 << 20));
// 	iota(begin(xs), end(xs), 0);
// 	LiChao<ll> tree((1 << 20), xs);
//
// 	int n, e;
// 	cin >> n >> e;
// 	vector<int> a(n), b(n);
// 	for (auto& x : a)
// 		cin >> x;
// 	for (auto& x : b)
// 		cin >> x;
//
// 	tree.add_line(Line<ll>(e, 0));
//
// 	ll x;
//
// 	for (int i = 0; i < n; ++i) {
// 		x = tree.get_best(a[i]);
// 		tree.add_line(Line<ll>(b[i], x));
// 	}
//
// 	cout << x << '\n';
// }
