#include <limits>
#include <utility>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// source: Benq, own
namespace pbds {
	const int INF = std::numeric_limits<int>::max();
	using namespace __gnu_pbds;

	template<class T, class C = std::less<std::pair<T, int>>>
	using set = tree<std::pair<T, int>, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

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
	template<class T>
	void erase(set<std::pair<T, int>>& s, T x) {
		s.erase(s.lower_bound(std::make_pair(x, -INF)));
	}
} // namespace pbds
