#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M, P;
  cin >> N >> M >> P;

  ll ans = 0;
  ll now = M;
  while (now <= N) {
    ++ans;
    now += P;
  }

  cout << ans << '\n';
}
