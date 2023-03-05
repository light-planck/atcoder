#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  map<char, ll> cnt;
  for (auto c : s) {
    ++cnt[c];
  }

  ll odd = 0;
  for (auto [c, num] : cnt) {
    if (num%2 != 0) ++odd;
  }

  if (odd <= 1) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}