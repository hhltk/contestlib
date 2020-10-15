// source: kactl, own
struct UnionFind {
    int cmp_cnt;
    vector<int> p;
    UnionFind(int n) : cmp_cnt(n), p(n, -1) {
    }

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    int find(int s) {
        return p[s] < 0 ? s : p[s] = find(p[s]);
    }

    int size(int s) {
        return -p[find(s)];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (p[b] < p[a])
                swap(a, b);
            p[a] += p[b];
            p[b] = a;
            cmp_cnt--;
        }
        return a != b;
    }
};
