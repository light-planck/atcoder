#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  deque<ll> deq;
  rep(i, n) {
    ll a;
    cin >> a;
    deq.emplace_back(a);
  }

  rep(i, k) {
    deq.pop_front();
    deq.emplace_back(0);
  }

  for (auto a : deq) cout << a << '\n';
  return 0;
}