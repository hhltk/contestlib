mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
int rand() {
	return uniform_int_distribution<T>()(rng);
}


// source: cses.fi/ioi16/list, cses.fi/alon20/list, mango_lassi
struct Treap {
	Treap *l, *r;
	int prior, sz, v;

	Treap(int v_) : l(0), r(0), prior(rand<int>()), sz(1), v(v_) {}

	void push() {}

	void update() {
		sz = 1 + getsz(l) + getsz(r);
	}

	static Treap* merge(Treap* a, Treap* b) {
		if (a) a->push();
		if (b) b->push();
		if (!a || !b) return (a ? a : b);
		
		Treap* r;
		if (a->prior < b->prior) {
			if (a->r) a->r->push();
			a->r = merge(a->r, b);
			r = a;
		} else {
			if (b->l) b->l->push();
			b->l = merge(a, b->l);
			r = b;
		}
		r->update();
		return r;
	}

	static pair<Treap*, Treap*> split(Treap* a, int k) {
		if (!a) return {0, 0};
		a->push();
		int al = a->l ? a->l->sz : 0;
		Treap *r;
		if (al >= k) {
			tie(r, a->l) = split(a->l, k);
			a->update();
			return {r, a};
		} else {
			tie(a->r, r) = split(a->r, k - al - 1);
			a->update();
			return {a, r};
		}
	}
};
