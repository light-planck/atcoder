#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll k;
  cin >> k;

  string ans;
  while (k > 0) {
    if (k & 1) {
      ans += "2";
    }
    else ans += "0";
    
    k >>= 1;
  }

  reverse(all(ans));
  cout << ans << "\n";
  return 0;
}