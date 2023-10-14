#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  set<ll> st;
  rep(i, N) {
    ll a;
    cin >> a;
    st.emplace(a);
  }

  if (ssize(st) == 1)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
}
