#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll ans = 0;
  ll x = 0;
  rep(i, n) {
    if (s[i] =='I') ++x;
    else --x;

    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, x);
  }

  cout << ans << '\n';
  return 0;
}