#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, S, K;
  cin >> N >> S >> K;

  ll sum = 0;
  rep(i, N) {
    ll p, q;
    cin >> p >> q;
    sum += p * q;
  }

  if (sum < S) sum += K;
  cout << sum << '\n';
}
