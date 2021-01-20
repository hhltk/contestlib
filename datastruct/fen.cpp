#include <vector>

// source: kactl
template <typename T>
struct FenTree {
	std::vector<T> tree;
	FenTree(typename std::vector<T>::size_type n) : tree(n) {}
	// a[i] += dif
	void update(int i, T d) {
		for (; i < int(tree.size()); i |= i + 1) tree[i] += d;
	}
	// \sum_{i \in [0, r]} a[i]
	T query(int r) {
		T ret = 0;
		for (; r > 0; r &= r - 1) ret += tree[r - 1];
		return ret;
	}
	// returns min pos such that sum of [0, pos] >= sum
	// n if no sum is >= sum
	// -1 if empty sum is.
	int lower_bound(T sum) {
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << std::__lg(tree.size() + 1); pw; pw >>= 1) {
			if (pos + pw <= int(tree.size()) && tree[pos + pw - 1] < sum) {
				pos += pw, sum -= tree[pos - 1];
			}
		}
		return pos;
	}
};
