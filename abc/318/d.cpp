#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<tuple<ll, ll, ll>> weight;
  rep(i, N) {
    for (ll j = i + 1; j < N; ++j) {
      ll d;
      cin >> d;
      weight.emplace_back(d, i, j);
    }
  }

  sort(weight.rbegin(), weight.rend());

  ll ans = 0;
  set<ll> choose;
  for (auto [w, i, j] : weight) {
    if (choose.count(i) or choose.count(j)) continue;

    choose.emplace(i);
    choose.emplace(j);
    ans += w;
  }

  cout << ans << '\n';
}
