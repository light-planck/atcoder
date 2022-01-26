#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.rbegin(), a.rend());

  ll sum = a[0];
  for (int i = 1; i < n - 1; ++i) {
    sum += a[(i + 2 - 1) / 2];
  }

  cout << sum << "\n";
  return 0;
}