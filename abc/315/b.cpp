#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll M;
  cin >> M;

  vector<ll> D(M);
  for (auto& d : D) cin >> d;

  ll mid = (accumulate(D.begin(), D.end(), 0ll) + 1) / 2;
  ll sum = 0;
  rep(i, M) {
    if (sum + D[i] >= mid) {
      cout << i + 1 << " " << mid - sum << '\n';
      break;
    }
    sum += D[i];
  }
}
