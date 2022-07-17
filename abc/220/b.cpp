#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int k;
  string a, b;
  cin >> k >> a >> b;

  ll x = 0;
  ll y = 0;
  int lx = a.size();
  int ly = b.size();
  ll ans = 0;

  rep(i, lx) {
    x += ((int)(a[i] - '0')) * pow(k, lx - i - 1);
  }
  rep(i, ly) {
    y += ((int)(b[i] - '0')) * pow(k, ly - i - 1);
  }

  ans = x * y;
  cout << ans << endl;

  return 0;
}