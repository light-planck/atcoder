#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll cnt = 0;
  ll num = 1;
  rep(i, n) {
    if (a[i] == num) {
      ++num;
    }
    else {
      ++cnt;
    }
  }

  if (num == 1) cout << -1 << "\n";
  else cout << cnt << "\n";
  return 0;
}