#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N), B(N);
  rep(i, N) {
    ll a, b;
    cin >> a >> b;
    A[i] = a;
    B[i] = b;
  }

  vector<ll> idx(N);
  iota(idx.begin(), idx.end(), 0);
  auto compare = [&](ll i, ll j) {
    return A[i] * (A[j] + B[j]) > A[j] * (A[i] + B[i]);
  };
  ranges::stable_sort(idx, compare);

  for (auto i : idx) {
    cout << i + 1 << '\n';
  }
}
