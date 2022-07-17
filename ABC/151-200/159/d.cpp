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
  map<int, int> mp;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    mp[a[i]]++;
  }
  ll sum = 0;
  for (auto x : mp) {
    if (x.second < 2) continue;
    sum += comb(x.second, 2);
  }
  rep(i, n) {
    ll ans = sum;
    int num = mp[a[i]];
    ans -= comb(num, 2);
    ans += comb(num - 1, 2);
    cout << ans << endl;
  }
  return 0;
}