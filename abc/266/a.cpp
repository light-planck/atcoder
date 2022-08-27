#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  // auto round = [](ll a, ll b) { return (a + b - 1) / b; };
  ll n = s.size() - 1;
  cout << s[n / 2] << '\n';
  return 0;
}