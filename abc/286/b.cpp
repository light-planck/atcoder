#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  string ans = "";
  char prev = '.';
  for (auto c : s) {
    if (prev == 'n' and c == 'a') {
      ans.pop_back();
      ans += "nya";
    }
    else ans += c;

    prev = c;
  }

  cout << ans << '\n';
  return 0;
}