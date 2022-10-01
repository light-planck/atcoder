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
  cin >> n >> q;

  vector a(n, vector<ll>());
  rep(i, n) {
    ll l;
    cin >> l;
    rep(j, l) {
      ll ai;
      cin >> ai;
      a[i].emplace_back(ai);
    }
  }

  while (q--) {
    ll s, t;
    cin >> s >> t;
    --s; --t;
    cout << a[s][t] << '\n';
  }
  return 0;
}