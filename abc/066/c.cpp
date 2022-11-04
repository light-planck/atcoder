#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  deque<ll> deq;
  bool reversed = false;
  rep(i, n) {
    if (reversed) deq.emplace_front(a[i]);
    else deq.emplace_back(a[i]);
    reversed ^= 1;
  }

  if (reversed) reverse(deq.begin(), deq.end());
  for (auto b : deq) cout << b << '\n';
  return 0;
}