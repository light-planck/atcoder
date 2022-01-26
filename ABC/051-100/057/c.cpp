#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int solve(ll x) {
  int cnt = 0;
  while (x > 0) {
    x /= 10;
    cnt++;
  }
  return cnt;
}

int main() {
  ll n;
  cin >> n;
  int ans = inf;
  for (ll a = 1; a <= sqrt(n); a++) {
    if (n % a == 0) {
      ll b = n / a;
      int al = solve(a);
      int bl = solve(b);
      int f = max(al, bl);
      ans = min(ans, f);
    }
  }
  cout << ans << endl;
  return 0;
}

//n = 100のとき
//(a, b) = (1, 100), (2, 50), ...
//(10, 10), ...
//a < bとするならば
//a = sqrt(n)まで調べればよい