#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(M);
  for (auto& a : A) cin >> a;

  vector<string> S(N);
  for (auto& s : S) cin >> s;

  vector<ll> points(N);
  rep(i, N) {
    points[i] = i + 1;
    rep(j, M) {
      if (S[i][j] == 'o') points[i] += A[j];
    }
  }

  vector<pair<ll, ll>> sorted_points;
  rep(i, M) sorted_points.emplace_back(A[i], i);
  ranges::sort(sorted_points, ranges::greater());

  rep(i, N) {
    ll max_point = 0;

    rep(j, N) {
      if (i == j) continue;
      max_point = max(max_point, points[j]);
    }

    ll cnt = 0;
    ll cur = 0;
    ll point = points[i];
    while (point <= max_point) {
      auto [p, j] = sorted_points[cur];

      if (S[i][j] == 'x') {
        point += p;
        ++cnt;
      }

      ++cur;
    }

    cout << cnt << '\n';
  }
}
