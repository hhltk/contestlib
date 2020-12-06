#include <functional>
#include <vector>
using namespace std;

// Basic segment tree. Takes the size of tree, an identity value
// and a binary function as parameters
template <typename T>
struct Tree {
  int n; // Has to be a power of 2
  T I;
  function<T(T, T)> f;
  vector<T> t;

  Tree(int n, T I, function<T(T, T)> f) : n(n), I(I), f(f), t(n * 2, I) {}

  void change(int k, T x) {
    for (t[k += n] = x; (k /= 2) != 0;) {
      t[k] = f(t[k * 2], t[k * 2 + 1]);
    }
  }
  T query(int a, int b) {
    T r = I;
    for (a += n, b += n; a <= b; a /= 2, b /= 2) {
      if (a % 2 == 1) {
        r = f(t[a++], r);
      }
      if (b % 2 == 0) {
        r = f(r, t[b--]);
      }
    }
    return r;
  }
};
