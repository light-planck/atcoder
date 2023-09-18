#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  set<string> sticks;
  rep(i, N) {
    string s;
    cin >> s;

    string rev_s = s;
    ranges::reverse(rev_s);
    if (not sticks.contains(s) and not sticks.contains(rev_s)) {
      sticks.emplace(s);
    }
  }

  cout << ssize(sticks) << '\n';
  return 0;
}
