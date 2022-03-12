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

  int v, a, b, c;
  vector<int> sha(3);
  cin >> v;
  rep(i, 3) cin >> sha[i];

  while (v >= 0) {
    rep(i, 3) {
      if (v - sha[i] < 0) {
        if (i == 0) {
          cout << "F" << "\n";
        }
        else if (i == 1) {
          cout << "M" << "\n";
        }
        else {
          cout << "T" << "\n";
        }
        return 0;
      }
      else {
        v -= sha[i];
      }
    }
  }
  return 0;
}