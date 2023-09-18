#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;

  vector<pair<ll, ll>> decrease;
  ll sum = 0;
  rep(i, N) {
    ll a, b;
    cin >> a >> b;

    sum += b;
    decrease.emplace_back(a, b);
  }
  ranges::sort(decrease);

  ll ans = 1;
  while (sum > K) {
    
  }
  return 0;
}
