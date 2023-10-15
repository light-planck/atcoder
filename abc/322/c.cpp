#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  queue<ll> A;
  rep(i, M) {
    ll a;
    cin >> a;
    --a;
    A.emplace(a);
  }

  rep(i, N) {
    cout << A.front() - i << '\n';

    if (i == A.front()) {
      A.pop();
    }
  }
}
