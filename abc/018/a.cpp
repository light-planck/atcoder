#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  auto b = a;
  sort(b.rbegin(), b.rend());

  map<ll, ll> rank;
  rep(i, n) rank[b[i]] = i + 1;

  rep(i, n) {
    cout << rank[a[i]] << '\n';
  }
  return 0;
}