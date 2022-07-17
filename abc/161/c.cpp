#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  ll r = n % k;
  ll ans = min(r, k - r);
  cout << ans << endl;
  return 0;
}