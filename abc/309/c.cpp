#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;

  map<ll, ll> decrease;
  ll sum = 0;
  rep(i, N) {
    ll a, b;
    cin >> a >> b;

    sum += b;
    decrease[a] += b;
  }

  if (sum <= K) {
    cout << 1 << '\n';
    exit(0);
  }

  for (auto [day, dec] : decrease) {
    sum -= dec;
    if (sum <= K) {
      cout << day + 1 << '\n';
      break;
    }
  }
  return 0;
}
