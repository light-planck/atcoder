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
  string march = "MARCH";
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vector<ll> sum(5);
  ll ans = 0;
  rep(i, n) {
    if (s[i][0] == march[0]) sum[0]++;
    if (s[i][0] == march[1]) sum[1]++;
    if (s[i][0] == march[2]) sum[2]++;
    if (s[i][0] == march[3]) sum[3]++;
    if (s[i][0] == march[4]) sum[4]++;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += sum[i] * sum[j] * sum[k];
      }
    }
  }
  cout << ans << endl;
  return 0;
}