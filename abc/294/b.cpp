#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll h, w;
  cin >> h >> w;

  rep(i, h) {
    rep(j, w) {
      ll a;
      cin >> a;
      if (a == 0) cout << '.';
      else cout << (char)('A' + a-1);
    }
    cout << '\n';
  }
  return 0;
}