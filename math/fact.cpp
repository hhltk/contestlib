vector<mint> fact, ifact;

void verify_facts(int n) {
    if (int(fact.size()) >= n)
        return;
    if (fact.empty()) {
        fact.push_back(1);
        ifact.push_back(1);
    }
    while (int(fact.size()) < n) {
        fact.push_back(fact.back() * fact.size());
        ifact.push_back(1 / fact.back());
    }
}

mint choose(int a, int b) {
    if (a < b || b < 0)
        return 0;
    verify_facts(a);
    return fact[a] * ifact[b] * ifact[a - b];
}
