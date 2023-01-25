#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, l;
  cin >> n >> l;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll seat = 1;
  rep(i, n) {
    if (a[i] == 2 and seat >= l) {
      cout << "No" << '\n';
      return 0;
    }

    seat += a[i] + 1;
  }

  cout << "Yes" << '\n';
  return 0;
}