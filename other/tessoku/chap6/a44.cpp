#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, q;
  cin >> n >>  q;

  vector<ll> a(n);
  iota(a.begin(), a.end(), 1);

  bool reversed = false;
  while (q--) {
    ll type, x, y;
    cin >> type;

    if (type == 1) {
      cin >> x >> y;
      --x;

      if (reversed) a[n-1-x] = y;
      else a[x] = y;
    }

    if (type == 2) reversed ^= 1;

    if (type == 3) {
      cin >> x;
      --x;

      if (reversed) cout << a[n-1-x] << '\n';
      else cout << a[x] << '\n';
    }
  }
  return 0;
}