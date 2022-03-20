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

  string t;
  cin >> t;

  ll x = 0;
  ll y = 0;

  // 0:東　1:南　2:西　3:北
  ll dir = 0;

  for (int i = 0; i < n; ++i) {
    if (t[i] == 'S') {
      if (dir == 0) ++x;
      if (dir == 1) --y;
      if (dir == 2) --x;
      if (dir == 3) ++y;
    }
    if (t[i] == 'R') {
      ++dir;
      dir %= 4;
    }
  }

  cout << x << " " << y << "\n";
  return 0;
}