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

  ll q;
  cin >> q;

  multiset<ll> mt;
  while (q--) {
    ll c, x;
    cin >> c >> x;

    if (c == 1) {
      mt.insert(x);
    }
    else {
      ll k;
      cin >> k;

      ll ans = -1;
      bool ok = true;
      if (c == 2) {
        auto itr = mt.upper_bound(x);

        rep(i, k) {
          if (itr == mt.begin()) {
            ok = false;
            break;
          }

          --itr;
        }

        if (ok) ans = *itr;
      }
      if (c == 3) {
        auto itr = mt.lower_bound(x);
        
        rep(i, k-1) {
          if (itr == mt.end()) {
            ok = false;
            break;
          }

          ++itr;
        }

        if (ok && itr != mt.end()) ans = *itr;
      }

      cout << ans << "\n";
    }
  }
  return 0;
}