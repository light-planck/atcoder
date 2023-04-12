#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> s(n);
  rep(i, n) cin >> s[i];

  rep(i, n) {
    if (s[i] == 0) {
      cout << n << '\n';
      return 0;
    }
  }

  ll ans = 0;
  deque<ll> deq;
  ll prod = 1;

  rep(i, n) {
    deq.emplace_back(s[i]);
    prod *= s[i];

    while (not deq.empty() and prod > k) {
      prod /= deq[0];
      deq.pop_front();
    }

    ans = max(ans, (ll)deq.size());
  }

  cout << ans << '\n';
  return 0;
}