#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  set<ll> st;
  rep(i, n) {
    ll a;
    cin >> a;

    if (st.count(a)) st.erase(a);
    else st.emplace(a);
  }

  cout << st.size() << '\n';
  return 0;
}