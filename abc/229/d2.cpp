#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll k;
  cin >> k;

  deque<char> deq;
  ll replaced = 0;
  ll ans = 0;
  for (char c : s) {
    deq.emplace_back(c);
    if (c == '.') ++replaced;

    while (not deq.empty() and replaced > k) {
      if (deq[0] == '.') --replaced;
      deq.pop_front();
    }

    ans = max(ans, (ll)deq.size());
  }

  cout << ans << '\n';
  return 0;
}