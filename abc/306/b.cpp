#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main() { 
  ll n = 64;
  
  ll ans = 0;
  rep(i, n) {
    ull a;
    cin >> a;
    ans += a * (1ll << i);
  }

  cout << ans << '\n';
}