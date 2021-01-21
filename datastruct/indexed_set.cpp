// source: Benq

#include <limits>
#include <utility>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

namespace pbds {
	const int INF = std::numeric_limits<int>::max();

	using namespace __gnu_pbds;

	template<class T>
	using set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

	// Use with pairs to get a multiset
	// Useful functions:
	// 	tree.order_of_key
	// 	tree.find_by_order

	template<class T>
	int at_most(set<std::pair<T, int>>& s, T k) {
		return s.order_of_key({k, INF});
	}

	template<class T>
	int at_least(set<std::pair<T, int>>& s, T k) {
		return s.size() - at_most(s, k - 1);
	}

	template<class T>
	int range_sum(set<std::pair<T, int>>& s, T l, T r) {
		return at_most(s, r) - at_most(s, l - 1);
	}

	template<class T>
	void insert(set<std::pair<T, int>>& s, T x) {
		static int t = 0;
		s.insert(std::make_pair(x, t++));
	}
} // namespace pbds
