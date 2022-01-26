#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

ll comb(int n, int r) {
  ll ans = 1;
  for (int i = 0; i < r; i++) {
    ans *= n - i;
    ans /= i + 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  map<string, ll> mp;
  rep(i, n) {
    string s;
    cin >> s;
    sort(all(s));
    mp[s]++;
  }
  ll ans = 0;
  for (auto x : mp) {
    if (x.second >= 2) ans += comb(x.second, 2);
  }
  cout << ans << endl;
  return 0;
}