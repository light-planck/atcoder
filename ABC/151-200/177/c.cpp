#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> s(n+1);
  rep(i, n) {
    cin >> a[i];
    s[i+1] = s[i] + a[i];
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ll sum = (s[n] - s[i+1] + mod) % mod;
    sum *= a[i];
    sum %= mod;
    ans += sum;
    ans %= mod;
  }

  cout << ans << endl;
  return 0;
}