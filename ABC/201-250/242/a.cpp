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

  double a, b, c, x;
  cin >> a >> b >> c >> x;

  double ans = 1.0;
  if (b < x) {
    ans = 0;
    printf("%.10f\n", ans);
  }
  else if (x <= a) {
    printf("%.10f\n", ans);
  }
  else if (a + 1 <= x <= b) {
    ans = c / (b - a);
    printf("%.10f\n", ans);
  }
  return 0;
}