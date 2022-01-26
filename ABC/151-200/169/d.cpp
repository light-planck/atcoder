#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 素因数分解
vector<pair<ll, ll>> FactorPrime(ll n) {
  vector<pair<ll, ll>> prime;

  for (ll i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;

    ll exponent = 0;
    while (n % i == 0) {
      ++exponent;
      n /= i;
    }

    prime.push_back(make_pair(i, exponent));
  }

  // 上の処理後にnが1でないならnは素数
  if (n != 1) {
    prime.push_back(make_pair(n, 1));
  }

  return prime;
}

ll CountExp(ll exp) {
  ll cnt = 0;
  ll i = 1;
  while (exp >= i) {
    exp -= i;
    ++i;
    ++cnt;
  }

  return cnt;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<pair<ll, ll>> prime = FactorPrime(n);

  ll cnt = 0;
  for (auto [p, exp] : prime) {
    cnt += CountExp(exp);
  }

  cout << cnt << "\n";
  return 0;
}