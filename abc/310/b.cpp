#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> P(N);
  vector F(N, set<ll>());
  rep(i, N) {
    ll C;
    cin >> P[i] >> C;

    rep(j, C) {
      ll f;
      cin >> f;
      F[i].emplace(f);
    }
  }

  // iがjの機能をすべて持つか
  auto contains = [&](ll i, ll j) {
    bool has = true;
    for (auto f : F[j]) {
      if (not F[i].count(f)) has = false;
    }
    return has;
  };

  // iがjにはない機能を1つ以上もつか
  auto has_new_functions = [&](ll i, ll j) {
    bool has = false;
    for (auto f : F[i]) {
      if (not F[j].count(f)) has = true;
    }
    return has;
  };

  auto check = [&](ll i, ll j) {
    if (P[i] < P[j]) return false;
    if (not contains(j, i)) return false;
    if (P[i] <= P[j] and (not has_new_functions(j, i))) return false;
    return true;
  };

  bool ok = false;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (i == j) continue;
      if (check(i, j)) ok = true;
    }
  }

  if (ok)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
  return 0;
}