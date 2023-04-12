#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  deque<ll> deq;
  ll sum = 0;
  rep(i, n) {
    deq.emplace_back(a[i]);
    sum += a[i];

    while (not deq.empty() and ((sum-a[i]) != (sum^a[i]))) {
      sum -= deq[0];
      deq.pop_front();
    }

    ans += deq.size();
  }

  cout << ans << '\n';
  return 0;
}