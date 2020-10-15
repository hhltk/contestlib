// source: own, Benq
// O(n log n) preprocessing, O(1) queries
template <class T, class Comparator = std::less<T>> struct RangeMinimumQuery {
    vector<vector<int>> spr;
    vector<T> v;

    RangeMinimumQuery(const vector<T> &v) : v(v) {
        spr = {vector<T>(v.size())};
        iota(spr[0].begin(), spr[0].end(), 0);
        for (int j = 1; (1 << j) <= int(v.size()); ++j) {
            spr.push_back(vector<int>(int(v.size()) - (1 << j) + 1));
            for (int i = 0; i < int(spr[j].size()); ++i) {
                spr[j][i] = min(spr[j - 1][i], spr[j - 1][i + (1 << (j - 1))], Comparator{});
            }
        }
    }

    int argmin(int l, int r) {
        int d = 31 - __builtin_clz(r - l + 1);
        return min(spr[d][l], spr[d][r - (1 << d) + 1], Comparator{});
    }
    int getmin(int l, int r) {
        return v[argmin(l, r)];
    }
};
