#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  set<char> st;
  rep(i, n) {
    char c;
    cin >> c;
    st.emplace(c);
  }

  if (st.size() == 3) cout << "Three" << '\n';
  else cout << "Four" << '\n';
  return 0;
}