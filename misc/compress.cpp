template<class T>
vector<int> compress(const vector<T>& orig) {
	auto c = orig;
	stable_sort(c.begin(), c.end());
	auto bins = [&](T x) {
		int l = 0, r = int(c.size());
		while (l < r) {
			int m = (l + r) / 2;
			if (c[m] >= x) r = m;
			else l = m + 1;
		}
		return l;
	};
	vector<int> ret(orig.size());
	for (int i = 0; i < int(ret.size()); ++i) ret[i] = bins(orig[i]);
	return ret;
}
