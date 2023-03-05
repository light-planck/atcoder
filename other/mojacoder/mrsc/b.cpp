#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m, s;
  cin >> n >> m >> s;

  map<ll, ll> cnt;
  rep(_, n) {
    ll l;
    cin >> l;
    rep(i, l) {
      ll a;
      cin >> a;
      --a;
      ++cnt[a];
    }
  }

  vector<ll> ans(m);
  bool ok = true;
  for (auto [gem, num] : cnt) {
    if (num < s or num%s != 0) {
      ok = false;
      auto round = [](ll a, ll b) { return (a + b - 1) / b; };
      ans[gem] = round(num, s) * s - num;
    }
    // else {
    //   ans[gem] = num / s;
    // }
  }

  if (ok) {
    cout << "equality" << '\n';
    return 0;
  }

  for (auto x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}