#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  ll m = 12;
  vector<ll> numbers;
  rep(i, m) { numbers.emplace_back(stoll(string(i + 1, '1'))); }

  vector<ll> sum;
  rep(i, m) rep(j, m) rep(k, m) {
    sum.emplace_back(numbers[i] + numbers[j] + numbers[k]);
  }
  ranges::sort(sum);
  auto uq = ranges::unique(sum);
  sum.erase(uq.begin(), uq.end());

  cout << sum[N - 1] << '\n';
}
