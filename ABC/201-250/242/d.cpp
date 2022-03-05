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

  string s;
  cin >> s;

  ll q;
  cin >> q;

  while (q--) {
    ll t, k;
    cin >> t >> k;
    // --k;

    char ans = s[(k-1) % 3];
    if (t != 0) {
      ans = s[k % (2*t) - 1];
    }

    ans += t % 3;
    cout << ans << "\n";
  }
  return 0;
}