// source: ksun48
struct info {
	int su, mi;
};

info combine(info a, info b) {
	return {a.su + b.su, min(a.mi, a.su + b.mi)};
}

struct node {
	node *l, *r;
	info a;
};

node *build(int l, int r) {
	node *x = new node();
	if (l == r) {
		x->a = {0, 0};
	} else {
		x->l = build(l, (l + r) / 2);
		x->r = build((l + r) / 2 + 1, r);
		x->a = combine(x->l->a, x->r->a);
	}
	return x;
}

void change(node *x, int l, int r, int k, int y) {
	if (k < l || r < k) return;
	if (l == r) {
		x->a.su += y;
		x->a.mi += y;
	} else {
		change(x->l, l, (l + r) / 2, k, y);
		change(x->r, (l + r) / 2 + 1, r, k, y);
		x->a = combine(x->l->a, x->r->a);
	}
}

info query(node *x, int l, int r, int L, int R) {
	if (r < L || R < l) return {0, 0};
	if (L <= l && r <= R) return x->a;
	return combine(query(x->l, l, (l + r) / 2, L, R), query(x->r, (l + r) / 2 + 1, r, L, R));
}
