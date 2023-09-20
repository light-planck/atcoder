#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll N, M, H, K;
  cin >> N >> M >> H >> K;

  string S;
  cin >> S;

  set<pair<ll, ll>> items;
  rep(i, M) {
    ll x, y;
    cin >> x >> y;
    items.emplace(x, y);
  }


}
