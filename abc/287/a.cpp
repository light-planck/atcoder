#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll cnt = 0;
  rep(i, n) {
    string s;
    cin >> s;

    if (s == "For") ++cnt;
  }

  if (cnt > n/2) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}