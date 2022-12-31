#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll cnt = 0;
  vector<ll> ans;
  if (n%2 == 1) {
    ans.emplace_back(1);
    --n;
  }

  while (n) {
    ans.emplace_back(2);
    n -= 2;
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << '\n';
  return 0;
}