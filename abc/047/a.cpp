#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  if (a[0]+a[1] == a[2]) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}