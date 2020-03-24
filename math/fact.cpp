using mint = modint<int(1e9)+7>;

vector<mint> fact, ifact;
void init(int N = int(1e6)) {
	fact.resize(N + 1);
	ifact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
	ifact[N] = 1 / fact[N];
	for (int i = N; i > 0; --i) ifact[i - 1] = i * ifact[i];
}

mint choose(int a, int b) {
	if (a < b || b < 0) return 0;
	return fact[a] * ifact[b] * ifact[a - b];
}
