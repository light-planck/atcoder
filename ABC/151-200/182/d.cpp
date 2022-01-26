#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> sum(n + 1);
  rep(i, n) sum[i + 1] = sum[i] + a[i];

  ll max_x = 0;
  ll max_dx = 0;
  ll x = 0;
  rep(i, n) {
    max_dx = max(max_dx, sum[i + 1]);
    max_x = max(max_x, x + max_dx);
    x += sum[i + 1];
  }

  cout << max_x << "\n";
  return 0;
}