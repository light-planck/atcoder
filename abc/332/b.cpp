#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll K, G, M;
  cin >> K >> G >> M;

  ll g = 0;
  ll m = 0;
  ll cnt = 0;
  while (cnt < K) {
    if (g == G) {
      g = 0;
    } else if (m == 0) {
      m = M;
    } else {
      ll delta = min(G - g, m);
      g += delta;
      m -= delta;
    }

    ++cnt;
  }

  cout << g << ' ' << m << '\n';
}
