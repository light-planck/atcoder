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

  ll n, x;
  cin >> n >> x;
  
  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      x /= 2;
    }
    else if (s[i] == 'L') {
      x *= 2;
    }
    else {
      x = 2 * x + 1;
    }
  }

  cout << x << "\n";
  return 0;
}