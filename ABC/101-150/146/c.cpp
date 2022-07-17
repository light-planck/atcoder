#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

bool IsOk(ll idx, ll a, ll b, ll x) {
  ll d = to_string(idx).size();
  return a * idx + b * d <= x;
}

ll BinarySearch(ll a, ll b, ll x) {
  ll ok = 0;
  ll ng = 1e9 + 1;

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (IsOk(mid, a, b, x)) ok = mid;
    else ng = mid;
  }

  return ok;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll a, b, x;
  cin >> a >> b >> x;
  
  ll ans = BinarySearch(a, b, x);
  cout << ans << "\n";
  return 0;
}