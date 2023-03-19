#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> ans;
  rep(i, n) {
    ll a;
    cin >> a;
    if (a%2 == 0) ans.emplace_back(a);
  }

  for (auto x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}