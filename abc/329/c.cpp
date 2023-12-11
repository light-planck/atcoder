#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

vector<pair<char, ll>> encode(string s) {
  vector<pair<char, ll>> cnt;
  deque<char> deq;

  for (auto c : s) {
    if (ssize(deq) == 0 || deq.back() == c)
      deq.emplace_back(c);
    else {
      cnt.emplace_back(deq.back(), ssize(deq));
      deq.clear();
      deq.emplace_back(c);
    }
  }
  cnt.emplace_back(deq.back(), ssize(deq));

  return cnt;
}

int main() {
  ll N;
  cin >> N;

  string S;
  cin >> S;

  auto cnt = encode(S);
  map<char, ll> max_cnt;
  for (auto [c, n] : cnt) {
    max_cnt[c] = max(max_cnt[c], n);
  }

  ll ans = std::accumulate(
      max_cnt.begin(), max_cnt.end(), 0LL,
      [](ll acc, const auto pair) { return acc + pair.second; });

  cout << ans << '\n';
}
