#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  set<char> st;
  for (auto c : s) st.emplace(c);
  ll n = s.size();

  if ((ll)st.size() == n) cout << "yes" << '\n';
  else cout << "no" << '\n';
  return 0;
}