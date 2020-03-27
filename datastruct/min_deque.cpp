// source: benq
template <typename T, T v>
struct min_deque {
	int l = 0, r = 0;
	deque<pair<T, int>> d;
	void push(T x) {
		while (d.size() && d.back().first >= x) d.pop_back();
		d.push_back({x, r++});
	}
	void pop() {
		if (d.front().second == l++) d.pop_front();
	}
	T get() {
		return d.size() ? d.front().first : v;
	}
};
