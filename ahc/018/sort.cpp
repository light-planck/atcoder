#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct Pos {
  ll y, x;
  Pos(ll y=0, ll x=0) : y(y), x(x) {}
};


int main() {
  vector<pair<int, Pos>> v;
  v.emplace_back(15, Pos{1, 100});
  v.emplace_back(15, Pos{15, 1});
  auto compare = [](auto s,auto t) { return make_tuple(s.first, s.second.x, s.second.y) > make_tuple(t.first, t.second.x, t.second.y); };
  sort(v.begin(),v.end(), compare);
  for (auto [d, p] : v) {
    cout << d << " " << p.y << " " << p.x << '\n';
  }
  return 0;
}