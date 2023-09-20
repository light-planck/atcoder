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

  auto get_direction = [&](char c) -> pair<ll, ll> {
    switch (c) {
      case 'R':
        return {1, 0};
        break;
      case 'L':
        return {-1, 0};
        break;
      case 'U':
        return {0, 1};
        break;
      case 'D':
        return {0, -1};
      default:
        return {0, 0};
        break;
    }
  };

  ll x = 0;
  ll y = 0;

  rep(i, N) {
    auto [dx, dy] = get_direction(S[i]);

    --H;
    x += dx;
    y += dy;

    if (H < K and items.contains({x, y})) {
      H = K;
      items.erase({x, y});
    }

    if (i < N - 1 and H == 0) {
      cout << "No" << '\n';
      exit(0);
    }
  }

  cout << "Yes" << '\n';
}
