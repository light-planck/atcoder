#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (auto &a : A) cin >> a;

  ranges::sort(A, ranges::greater());
  ll max_a = A[0];
  for (auto a : A) {
    if (a == max_a) continue;
    cout << a << '\n';
    exit(0);
  }
}
