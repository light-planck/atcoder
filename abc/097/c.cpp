#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll k;
  cin >> k;

  ll n = s.size();
  set<string> st;
  for (ll l = 0; l < n; ++l) {
    string t;

    for (ll r = l; r < min(l+k, n); ++r) {
      t += s[r];
      st.emplace(t);
    }
  }

  auto itr = st.begin();
  advance(itr, k-1);
  cout << *itr << '\n';
  return 0;
}