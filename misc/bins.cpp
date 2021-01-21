// Finds the partition point of f in range [l, r)
// i.e. minimum x such that f(x) = true and x \in [l, r)
auto bins = [](auto l, auto r, auto f) {
	while (l < r) {
		int m = l + (r - l) / 2;
		if (f(m)) r = m;
		else
			l = m + 1;
	}
	return l;
};
