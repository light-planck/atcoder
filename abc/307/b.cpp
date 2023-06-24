#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  ll n;
  cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  auto is_palindrome = [](string s) {
    ll n = s.size();
    rep(i, n) {
      if (s[i] != s[n-1-i]) {
        return false;
      }
    }
    return true;
  };

  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      string t = s[i] + s[j];
      string u = s[j] + s[i];
     
      if (is_palindrome(t) or is_palindrome(u)) {
        cout << "Yes" << '\n';
        exit(0);
      }
    }
  }

  cout << "No" << '\n';
  return 0;
}
