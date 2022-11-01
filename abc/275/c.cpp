#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
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
  ll n = 9;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  auto check = [&n, &s](vector<ll> i, vector<ll> j) {
    rep(k, 4) {
      if (i[k] < 0 or i[k] >= n) return false;
      if (j[k] < 0 or j[k] >= n) return false;
      if (s[i[k]][j[k]] == '.') return false;
    }
    return true;
  };

  using P = pair<ll, ll>;
  set<vector<P>> squares;

  auto push = [&squares](vector<ll> i, vector<ll> j) {
    vector<P> ij;
    rep(k, 4) ij.emplace_back(i[k], j[k]);
    sort(ij.begin(), ij.end());
    squares.emplace(ij);
  };

  rep(i0, n) rep(j0, n) {
    rep(i1, n) rep(j1, n) {
      if (i0 == i1 and j0 == j1) continue;

      vector<ll> i(4), j(4);
      i[0] = i0; j[0] = j0;
      i[1] = i1; j[1] = j1;

      ll di = i[1]-i[0];
      ll dj = j[1]-j[0];

      i[2] = i[1]-dj; j[2] = j[1]+di;
      i[3] = i[2]-di; j[3] = j[2]-dj;

      if (not check(i, j)) continue;

      push(i, j);
    }
  }

  cout << squares.size() << '\n';
  return 0;
}