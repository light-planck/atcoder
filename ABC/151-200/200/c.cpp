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

  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i] %= 200;
  }

  vector<ll> cnt(200);
  rep(i, n) cnt[a[i]]++;

  ll ans = 0;
  rep(i, 200) {
    ll c = cnt[i];
    ans += c * (c - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}