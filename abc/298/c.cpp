#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll q;
  cin >> q;

  // カードがどこの箱に入っているか
  map<ll, set<ll>> card;

  // 箱の中のカード
  map<ll, priority_queue<ll, vector<ll>, greater<ll>>> box;
  while (q--) {
    ll t;
    cin >> t;

    if (t == 1) {
      ll i, j;
      cin >> i >> j;
      card[i].emplace(j);
      box[j].emplace(i);
    }
    if (t == 2) {
      ll i;
      cin >> i;
      auto tmp = box[i];
      while (not tmp.empty()) {
        cout << tmp.top() << ' ';
        tmp.pop();
      }
      cout << '\n';
    }
    if (t == 3) {
      ll i;
      cin >> i;
      for (auto x : card[i]) cout << x << " ";
      cout << '\n';
    }
  }
  return 0;
}