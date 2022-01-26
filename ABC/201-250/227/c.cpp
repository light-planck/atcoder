#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// a <= b <= c
// aaa <= abb <= abc <= n
// a <= n ^ (1 / 3)
// b <= (n / a) ^ (1 / 2)
// b <= c <= n / ab

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  ll cnt = 0;
  for (ll a = 1; a * a * a <= n; a++) {
    for (ll b = a; a * b * b <= n; b++) {
      // cの取りうる個数
      // b <= c <= n / ab
      ll num = n / (a * b) - b + 1;
      cnt += num;
    }
  }
  cout << cnt << "\n";
  return 0;
}