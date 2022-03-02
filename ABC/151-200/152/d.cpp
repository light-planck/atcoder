#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;


// xの末尾をb、先頭をaとして
// pair<a, b>
pair<ll, ll> divide_ab(ll x) {
  // 末尾
  ll b = x % 10;

  string s = to_string(x);
  // 先頭
  ll a = s[0] - '0';

  return make_pair(a, b);
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  // mp[<先頭, 末尾>]となるような数の個数
  map<pair<ll, ll>, ll> mp;

  for (ll i = 1; i <= n; ++i) {
    pair<ll, ll> ab = divide_ab(i);
    ++mp[ab];
  }

  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    pair<ll, ll> ab = divide_ab(i);
    pair<ll, ll> ba = make_pair(ab.second, ab.first);
    ans += mp[ba];
  }

  cout << ans << "\n";
  return 0;
}