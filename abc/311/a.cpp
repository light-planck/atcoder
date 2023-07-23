#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  ll n;
  cin >> n;

  string s;
  cin >> s;

  map<char, ll> cnt;

  auto check = [&]() {
    return cnt['A'] >= 1 and cnt['B'] >= 1 and cnt['C'] >= 1;
  };

  rep(i, n) {
    ++cnt[s[i]];
    if (check()) {
      cout << i+1 << '\n';
      break;
    }
  }
  return 0;
}