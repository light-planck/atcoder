#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, x;
  cin >> n >> x;

  string s;
  cin >> s;

  deque<ll> deq;
  while (x) {
    if (x & 1) deq.emplace_front(1);
    else deq.emplace_front(0);

    x >>= 1;
  }

  for (int i = 0; i < n; ++i) {

    // 1/2
    if (s[i] == 'U') {
      deq.pop_back();
    }

    // *2
    else if (s[i] == 'L') {
      deq.emplace_back(0);
    }

    // *2 + 1
    else {
      deq.emplace_back(1);
    }
  }

  ll base = 1;
  ll ans = 0;
  while (deq.size()) {
    ll d = deq.back();
    deq.pop_back();

    ans += d * base;
    base <<= 1;
  }

  cout << ans << "\n";
  return 0;
}