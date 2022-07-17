#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, q;
  cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> c(n);
  rep(i, n) c[i] = a[i] - (i + 1);

  rep(i, q) {
    ll k;
    cin >> k;
    int idx = lower_bound(all(c), k) - c.begin();

    // cn < k
    if (idx == n) {
      cout << a[n-1] + k - c[n-1] << endl;
    }
    else {
      cout << (a[idx] - 1) - (c[idx] - k) << endl;
    }
  }
  return 0;
}