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
  map<ll, ll> mp;
  ll ans = 0;
  rep(i, n) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (auto i : mp)for (auto j : mp) {
    if (i.first > j.first) continue;
    if (i.first == j.first) continue;
    ll num = i.second * j.second;
    ans += num * (i.first - j.first) * (i.first - j.first);
  }
  cout << ans << endl;
  return 0;
}