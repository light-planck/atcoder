#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll ans = 0;
  rep(i, n-2) {
    string t = s.substr(0, i+1);
    string u = s.substr(i+1);

    set<char> x;
    for (auto c : t) x.emplace(c);

    set<char> y;
    for (auto c : u) y.emplace(c);

    ll cnt = 0;
    for (auto c : x) if (y.count(c)) ++cnt;

    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}