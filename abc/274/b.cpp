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
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  // vector<ll> x(w+1);
  rep(j, w) {
    ll cnt = 0;
    rep(i, h) {
      if (s[i][j] == '#') ++cnt;
    }
    cout << cnt << '\n';
  }

  // for (auto cnt : x) cout << cnt << '\n';
  return 0;
}