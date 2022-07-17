#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll cnt1 = 0;
  rep(i, n) {
    if (a[i] == b[i]) ++cnt1;
  }
  
  // <b_value, b_idx>
  map<ll, ll> mp;
  rep(i, n) mp[b[i]] = i;

  ll cnt2 = 0;
  rep(i, n) {
    if (mp.count(a[i]) && mp[a[i]] != i) ++cnt2;
  }

  cout << cnt1 << "\n";
  cout << cnt2 << "\n";
  return 0;
}