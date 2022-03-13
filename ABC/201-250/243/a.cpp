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

  ll v, a, b, c;
  cin >> v >> a >> b >> c;

  while (true) {
    if (v < a) {
      cout << "F" << "\n";
      break;
    }
    v -= a;

    if (v < b) {
      cout << "M" << "\n";
      break;
    }
    v -= b;

    if (v < c) {
      cout << "T" << "\n";
      break;
    }
    v -= c;
  }
  return 0;
}