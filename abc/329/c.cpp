#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  string S;
  cin >> S;

  char now = '.';
  ll length = 0;
  map<char, ll> max_length;
  for (auto c : S) {
    if (c == now) {
      ++length;
    } else {
      max_length[now] = max(max_length[now], length);
      now = c;
      length = 1;
    }
  }
  max_length[now] = max(max_length[now], length);

  ll ans = 0;
  for (auto [_, length] : max_length) {
    ans += length;
  }

  cout << ans << '\n';
}
