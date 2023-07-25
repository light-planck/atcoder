#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  ll n = 8;
  vector<ll> s(n);
  rep(i, n) cin >> s[i];

  auto check = [](vector<ll> s) {
    bool ok = true;

    auto sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    if (s != sorted_s) ok = false;

    for (auto x : s) {
      if (x < 100 or x > 675) ok = false;
    }

    for (auto x : s) {
      if (x % 25 != 0) ok = false;
    }

    return ok;
  };

  if (check(s)) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}