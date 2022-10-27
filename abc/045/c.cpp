#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


auto Slice(string& s, ll l, ll r) { return s.substr(l, r-l); }


int main() {
  string s;
  cin >> s;

  ll n = s.size();
  ll ans = 0;

  for (ll bit = 0; bit < 1<<(n-1); ++bit) {
    ll prev = 0;
    ll now = 0;
    rep(i, n-1) {
      if (bit>>i & 1) {
        string str = Slice(s, prev, i+1);
        now += stoll(str);
        prev = i + 1;
      }
    }
    now += stoll(Slice(s, prev, n));
    ans += now;
  }

  cout << ans << '\n';
  return 0;
}