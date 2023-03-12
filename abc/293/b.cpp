#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i], --a[i];

  vector<bool> seen(n);
  rep(i, n) {
    if (seen[i]) continue;
    seen[a[i]] = true;
  }

  vector<ll> ans;
  rep(i, n) {
    if (not seen[i]) ans.emplace_back(i+1);
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}