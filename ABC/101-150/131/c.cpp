#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// a, bの最大公約数
ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  else return gcd(b, a % b);
}

// a, bの最小公倍数
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll e = lcm(c, d);
  ll ans = (b - a + 1) - ((b / c - (a - 1) / c) + (b / d - (a - 1) / d) - (b / e - (a - 1) / e));
  cout << ans << endl;
  return 0;
}