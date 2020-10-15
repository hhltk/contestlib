// source: benq, own
template <typename T> struct minmaxdeque {
    bool max_mode;
    int l = 0, r = 0;
    deque<pair<T, int>> d;

    minmaxdeque(bool max_mode_ = false) : max_mode(max_mode_) {
    }

    bool compare(T a, T b) {
        return (max_mode && a <= b) || (!max_mode && b <= a);
    }
    void push(T x) {
        while (d.size() && compare(d.back().first, x))
            d.pop_back();
        d.push_back({x, r++});
    }
    void pop() {
        if (d.front().second == l++)
            d.pop_front();
    }
    T get() {
        return d.size() ? d.front().first
                        : (max_mode ? 0 : numeric_limits<T>::max());
    }
};
