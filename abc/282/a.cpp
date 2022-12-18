#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll k;
  cin >> k;

  string ans = "";
  rep(i, k) {
    ans += 'A'+i;
  }
  cout << ans << '\n';
  return 0;
}