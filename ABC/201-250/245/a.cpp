#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a < c) {
    cout << "Takahashi" << "\n";
  }
  else if (a > c) {
    cout << "Aoki" << "\n";
  }
  else {
    if (b <= d) {
      cout << "Takahashi" << "\n";
    }
    else {
      cout << "Aoki" << "\n";
    }
  }
  return 0;
}