#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, h;
  cin >> n >> h;

  using P = pair<ll, ll>;
  vector<P> damages;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;

    damages.emplace_back(a, 0);
    damages.emplace_back(b, 1);
  }
  #define rrng(a) (a).rbegin(),(a).rend()
  sort(rrng(damages));

  ll cnt = 0;
  for (auto [damage, one_time] : damages) {
    if (one_time) {
      h -= damage;
      ++cnt;
    }
    else {
      auto round = [](ll a, ll b) { return (a + b - 1) / b; };
      cnt += round(h, damage);
      h = 0;
    }

    if (h <= 0) {
      cout << cnt << '\n';
      return 0;
    }
  }
  return 0;
}