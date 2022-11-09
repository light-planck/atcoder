#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;

  vector<deque<char>> deq(n);
  rep(i, n) {
    string s;
    cin >> s;
    for (auto c : s) deq[i].emplace_back(c);
  }

  ll now = 0;
  while (true) {
    if (deq[now].empty()) {
      cout << char(now+'A') << '\n';
      break;
    }
    char c = deq[now].front(); deq[now].pop_front();
    now = c - 'a';
  }
  return 0;
}