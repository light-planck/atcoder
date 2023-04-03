#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  map<string, ll> cnt;
  rep(i, n) {
    string s;
    cin >> s;
    ++cnt[s];
  }

  ll ans = 0;
  string name = "";
  for (auto [s, x] : cnt) {
    if (x > ans) {
      ans = x;
      name = s;
    }
  }

  cout << name << '\n';
  return 0;
}