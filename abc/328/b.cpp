#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> D(N);
  for (auto& d : D) cin >> d;

  ll ans = 0;
  for (ll m = 1; m <= N; ++m) {
    for (ll d = 1; d <= D[m - 1]; ++d) {
      string s = to_string(m) + to_string(d);
      set<char> st;
      for (auto c : s) st.emplace(c);
      if (ssize(st) == 1) ++ans;
    }
  }

  cout << ans << '\n';
}
