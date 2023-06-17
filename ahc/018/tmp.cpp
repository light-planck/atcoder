#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
ll n = 5;
struct Pos {
  ll y, x;
  Pos(ll y=0, ll x=0) : y(y), x(x) {}
};
Pos idx2pos(ll i) {
  ll y = i/n;
  ll x = i%n;
  return Pos{y, x};
}
ll pos2idx(Pos pos) {
  return n*pos.y + pos.x;
}

int main() {
  Pos p = idx2pos(24);
  cout << p.y << " " << p.x << '\n';
  cout << pos2idx(p) << '\n';
  return 0;
}