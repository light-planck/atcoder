#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (auto& a : A) cin >> a;

  long double ans = 0;
  long double avg = accumulate(A.begin(), A.end(), 0ll) / (long double)N;
  for (auto a : A) {
    long double delta = abs(a - avg);
    if (delta >= 1) ans += abs(a - avg);
  }

  cout << llround(ans) / 2 << '\n';
}
