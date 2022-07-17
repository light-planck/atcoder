#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll k;
  cin >> k;

  // deqに1-9を追加
  deque<ll> deq;
  rep(i, 9) deq.push_back(i + 1);

  // k-1回操作をしたあとのdeqの左端が答え
  for (ll i = 0; i < k -1; ++i) {
    ll left = deq.front();
    deq.pop_front();

    for (ll j = -1; j <= 1; ++j) {
      ll d = left % 10;
      d += j;
      if (d >= 0 && d <= 9) {
        deq.push_back(10 * left + d);
      }
    }
  }

  cout << deq.front() << "\n";
  return 0;
}