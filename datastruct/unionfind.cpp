#include <vector>
using namespace std;

// source: kactl, own
struct UnionFind {
	vector<int> p;

	UnionFind(int n) : p(n, -1) {}

	int get(int s) {
		return p[s] < 0 ? s : (p[s] = get(p[s]));
	}

	bool unite(int a, int b) {
		a = get(a);
		b = get(b);
		if (a != b) {
			if (p[b] < p[a]) {
				swap(a, b);
			}
			p[a] += p[b];
			p[b] = a;
		}
		return a != b;
	}
};
