#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector A(N, set<ll>());
  rep(i, N) {
    ll C;
    cin >> C;

    rep(j, C) {
      ll a;
      cin >> a;
      A[i].emplace(a);
    }
  }

  ll X;
  cin >> X;

  vector<pair<ll, ll>> winner;
  rep(i, N) {
    if (A[i].count(X)) {
      winner.emplace_back(A[i].size(), i + 1);
    }
  }
  sort(winner.begin(), winner.end());

  if (winner.size() == 0) {
    cout << 0 << '\n';
    exit(0);
  }

  ll min_count = winner[0].first;
  vector<ll> ans;
  for (auto [cnt, idx] : winner) {
    if (cnt != min_count) break;
    ans.emplace_back(idx);
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << '\n';
}
