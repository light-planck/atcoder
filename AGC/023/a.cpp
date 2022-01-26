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
  rep(i, n) cin >> a[i];

  vector<ll> s(n+1);
  rep(i, n) s[i + 1] = s[i] + a[i];

  map<ll, ll> mp;
  rep(i, n+1) mp[s[i]]++;

  ll ans = 0;

  for (auto i : mp) {
    ans += i.second * (i.second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}