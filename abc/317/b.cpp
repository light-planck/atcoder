#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (auto& a : A) cin >> a;

  sort(A.begin(), A.end());
  rep(i, N - 1) {
    if (A[i + 1] - A[i] == 1) continue;
    cout << A[i] + 1 << '\n';
    break;
  }
}
