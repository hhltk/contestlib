
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
int rand() { return uniform_int_distribution<T>()(rng); }
