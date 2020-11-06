#include <functional>
#include <numeric>
#include <vector>
using namespace std;

// source: own, Benq
// O(n log n) preprocessing, O(1) queries
template <class T, class Comparator = less<T>> struct RangeMinimumQuery {
	vector<vector<int>> spr;
	vector<T> v;

	RangeMinimumQuery(const vector<T> &v) : v(v) {
		spr = {vector<int>(v.size())};
		iota(spr[0].begin(), spr[0].end(), 0);
		for (int j = 1; (1 << j) <= int(v.size()); ++j) {
			spr.push_back(
			    vector<int>(int(v.size()) - (1 << j) + 1));
			for (int i = 0; i < int(spr[j].size()); ++i) {
				spr[j][i] =
				    Comparator()(
					v[spr[j - 1][i]],
					v[spr[j - 1][i + (1 << (j - 1))]])
					? i + (1 << (j - 1))
					: i;
			}
		}
	}

	int argmin(int l, int r) {
		int d = 31 - __builtin_clz(r - l + 1);
		return Comparator()(v[spr[d][l]], v[spr[d][r - (1 << d) + 1]])
			   ? r - (1 << d) + 1
			   : l;
	}
	T getmin(int l, int r) {
		return v[argmin(l, r)];
	}
};
