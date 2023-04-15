#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;


deque<ll> deq;
mint ans;


void solve() {
  ll t;
  cin >> t;

  if (t == 1) {
    ll x;
    cin >> x;

    ans *= 10;
    ans += x;
    deq.emplace_back(x);
  }

  if (t == 2) {
    ans -=  deq[0] * mint(10).pow(deq.size()-1);
    deq.pop_front();
  }

  if (t == 3) cout << ans.val() << '\n';
}


int main() {
  ll q;
  cin >> q;

  ans = 1;
  deq.emplace_back(1);
  
  while (q--) solve();
  return 0;
}