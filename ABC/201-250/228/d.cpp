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

  int n = 1 << 20;
  vector<ll> a(n, -1);

  // 置換してないaのidx
  set<int> st;
  rep(i, n) st.insert(i);

  rep(i, q) {
    ll t, x;
    cin >> t >> x;

    if (t == 1) {
      int h = x % n;
      auto it = st.lower_bound(h);
      
      // 末尾の場合
      if (it == st.end()) {
        it = st.begin();
      }

      a[*it] = x;

      // 置換したidxを削除
      st.erase(it);
    }
    else {
      cout << a[x % n] << "\n";
    }
  }
  return 0;
}