#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<bool> connected(n);
  rep(i, m) {
    ll a;
    cin >> a;
    --a;
    connected[a] = true;
  }

  vector<ll> ans;
  rep(i, n) {
    if (connected[i]) ans.emplace_back(i+1);
    else {
      reverse(ans.begin(), ans.end());
      cout << i+1 << '\n';
      for (auto x : ans) cout << x << '\n';
      ans.clear();
    }
  }
  return 0;
}