#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<string> S(N);
  for (auto& s : S) cin >> s;

  vector<ll> wins(N);
  rep(i, N) {
    rep(j, N) {
      if (S[i][j] == 'o') {
        ++wins[i];
      }
    }
  }

  vector<pair<ll, ll>> ans;
  rep(i, N) { ans.emplace_back(wins[i], -(i + 1)); }
  ranges::sort(ans, ranges::greater());

  for (auto [_, i] : ans) cout << -i << '\n';
}
