#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<pair<ll, ll>> events;
  rep(i, N) {
    ll a;
    cin >> a;
    events.emplace_back(a, 0);
  }
  rep(i, M) {
    ll b;
    cin >> b;
    events.emplace_back(b + 1, 1);
  }
  ranges::sort(events);

  ll cnt_a = 0;
  ll cnt_b = M;
  for (auto [price, type] : events) {
    if (type == 0)
      ++cnt_a;
    else
      --cnt_b;

    if (cnt_a >= cnt_b) {
      cout << price << '\n';
      exit(0);
    }
  }
}
