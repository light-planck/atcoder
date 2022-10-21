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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w, i, j;
  cin >> h >> w >> i >> j;
  --i; --j;

  ll n;
  cin >> n;

  // i行目にある壁の列数
  map<ll, set<ll>> ij;
  // j列目にある壁の行数
  map<ll, set<ll>> ji;

  rep(i_, n) {
    ll r, c;
    cin >> r >> c;
    --r; --c;

    if (not ij.count(r)) {
      ij[r].emplace(-1);
      ij[r].emplace(w);
    }
    ij[r].emplace(c);

    if (not ji.count(c)) {
      ji[c].emplace(-1);
      ji[c].emplace(h);
    }
    ji[c].emplace(r);
  }

  ll q;
  cin >> q;
  while (q--) {
    char c; ll l;
    cin >> c >> l;

    if (c == 'L') {
      if (ij.count(i)) {
        auto itr = ij[i].lower_bound(j);
        j = max(j-l, *(--itr)+1);
      }
      else j = max(0LL, j-l);
    }
    if (c == 'R') {
      if (ij.count(i)) {
        auto itr = ij[i].lower_bound(j);
        j = min(j+l, *(itr)-1);
      }
      else j = min(w-1, j+l);
    }
    if (c == 'U') {
      if (ji.count(j)) {
        auto itr = ji[j].lower_bound(i);
        i = max(i-l, *(--itr)+1);
      }
      else i = max(0LL, i-l);
    }
    if (c == 'D') {
      if (ji.count(j)) {
        auto itr  =ji[j].lower_bound(i);
        i = min(i+l, *(itr)-1);
      }
      else i = min(h-1, i+l);
    }

    cout << i+1 << " " << j+1 << '\n';
  }
  return 0;
}