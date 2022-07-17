#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  map<int, int> mp;
  int cnt = 0;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (mp[c[i]] == 0) cnt++;
    mp[c[i]]++;
    if (i - k >= 0) {
      mp[c[i-k]]--;
      if (mp[c[i-k]] == 0) cnt--;
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}