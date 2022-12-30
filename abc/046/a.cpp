#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  set<ll> st;
  rep(i, 3) {
    ll a;
    cin >> a;
    st.emplace(a);
  }

  cout << st.size() << '\n';
  return 0;
}