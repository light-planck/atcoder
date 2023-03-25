#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  set<string> st = {"and", "not", "that", "the", "you"};
  bool ok = false;
  rep(i, n) {
    string s;
    cin >> s;
    if (st.count(s)) ok = true;
  }

  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}