#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.rbegin(), a.rend());

  string s = "";
  char c = a[0] + '0';
  char d = a[1] + '0';
  s += c; s += d;

  cout << stoll(s) + a[2] << '\n';
  return 0;
}