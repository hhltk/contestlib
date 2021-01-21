#include <algorithm>
#include <vector>
using namespace std;

template<class T>
void compress(vector<T>& v) {
	vector<pair<T, int>> p(v.size());
	for (int i = 0; i < int(v.size()); ++i) p[i] = {v[i], i};
	sort(p.begin(), p.end());
	T pr = p[0].first;
	int k = 0;
	for (auto [x, i] : p) {
		k += pr != x;
		pr = x;
		v[i] = k;
	}
}

int main() {}
