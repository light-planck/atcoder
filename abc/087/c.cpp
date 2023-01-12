#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector a(2, vector<ll>(n));
  rep(i, 2) rep(j, n) cin >> a[i][j];

  const vector<pair<ll, ll>> dij = {{0, -1}, {-1, 0}};

  auto sum = a;
  rep(i, 2) rep(j, n) {
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };

    ll add = 0;
    for (auto [di, dj] : dij) {
      ll pi = i + di; ll pj = j + dj;
      if (pi < 0 or pi >= 2) continue;
      if (pj < 0 or pj >= n) continue;
      chmax(add, sum[pi][pj]);
    }

    sum[i][j] += add;
  }

  cout << sum[1][n-1] << '\n';
  return 0;
}