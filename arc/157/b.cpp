#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 5;
  for (ll bit = 0; bit < (1ll<<n); ++bit) {
    string s = "";
    rep(i, n) {
      if (bit>>i & 1) {
        s = '1' + s;
      }
      else s = '0' + s;
    }
    vector<ll> cnt(4);
    rep(i, n-1) {
      if (s[i] == '0' and s[i+1] == '0') ++cnt[0];
      if (s[i] == '0' and s[i+1] == '1') ++cnt[1];
      if (s[i] == '1' and s[i+1] == '0') ++cnt[2];
      if (s[i] == '1' and s[i+1] == '1') ++cnt[3];
    }
    cout << "__________" << '\n';
    cout << s << '\n';
    rep(i, 4) cout << cnt[i] << ' ';
    cout << '\n';
  }
  return 0;
}