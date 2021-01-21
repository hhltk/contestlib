// source: Benq

#include <utility>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

// Use with pairs to get a multiset
// Useful functions:
// 	tree.order_of_key
// 	tree.find_by_order

template<class T>
int at_most(indexed_set<pair<T, int>>& t, T k) {
	return t.order_of_key({k, INF});
}

template<class T>
int at_least(indexed_set<pair<T, int>>& t, T k) {
	return t.size() - at_most(t, k - 1);
}

template<class T>
int range_sum(indexed_set<pair<T, int>>& t, T l, T r) {
	return at_most(t, r) - at_most(t, l - 1);
}
