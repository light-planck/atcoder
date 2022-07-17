#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll l, q;
  cin >> l >> q;
  set<ll> st;
  st.insert(0);
  st.insert(l);

  rep(i, q) {
    int c, x;
    cin >> c >> x;
    
    if (c == 1) {
      st.insert(x);
    }
    else {
      auto it = st.lower_bound(x);
      int len = *it - *prev(it);
      cout << len << "\n";
    }
  }
  return 0;
}