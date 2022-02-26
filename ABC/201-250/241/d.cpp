#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  
  set<ll> st;
  priority_queue<ll, vector<ll>, greater<ll>> q1;

  rep(i, q) {
    ll t, x;
    cin >> t >> x;

    if (t == 1) {
      q1.push(x);
    }

    else {
      int k;
      cin >> k;
      --k;

      auto it = lower_bound(all(q1), x);
      if (t == 2) advance(it, -k);
      if (t == 3) advance(it, k);

      if (it == st.end()) {
        cout << -1 << "\n";
      }
      else {
        cout << *it << "\n";
      }
    }
  }
  return 0;
}