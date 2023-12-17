#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> cnt(N);
  ll max_a = 0;
  ll idx = 0;
  rep(i, M) {
    ll a;
    cin >> a;
    --a;
    ++cnt[a];

    if (cnt[a] > max_a) {
      max_a = cnt[a];
      idx = a;
    } else if (cnt[a] == max_a and a < idx) {
      idx = a;
    }

    cout << idx + 1 << '\n';
  }
}
