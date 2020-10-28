#include <bits/stdc++.h>
using namespace std;

// FIXME: Implement FastInput & FastOutput and make
// function the same way as std::cin and std::cout

// source: kactl, own
struct Reader {
  char buf[1 << 20];
  int it = 0, n = 0;
  char operator()() {
    if (it >= n) {
      buf[0] = 0;
      it = 0;
      n = fread(buf, 1, sizeof(buf), stdin);
    }
    return buf[it++];
  }
} reader;
int next_int() {
  char c = reader();
  while (c != '-' && (isdigit(c) == 0)) {
    c = reader();
  }
  if (c == '-') {
    return -next_int();
  }
  int a = c - '0';
  while (isdigit(c = reader()) != 0) {
    a = a * 10 + c - '0';
  }
  return a;
}
