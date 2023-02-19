#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  set<ll> st = set(a.begin(), a.end());
  ll ans = 0;
  ll prev = -1;
  for (auto x : st) {
    if (ans == k) break;
    
    if (x == prev+1) {
      ++ans;
      prev = x;
    }
    else break;
  }

  cout << ans << '\n';
  return 0;
}