#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


auto Slice(string& s, ll l, ll r) { return s.substr(l, r-l); }


int main() {
  string s;
  cin >> s;

  ll k;
  cin >> k;

  ll n = s.size();
  set<string> st;
  for (ll l = 0; l < n; ++l) {
    for (ll r = l+1; r <= n; ++r) {
      string t = Slice(s, l, r);
      st.emplace(t);

      if ((ll)st.size() >= k + 1) {
        auto it = st.end();
        advance(it, -1);
        st.erase(*it);
      }
    }
  }

  auto itr = st.begin();
  advance(itr, k-1);
  cout << *itr << '\n';
  return 0;
}