#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i, k) pq.push(p[i]);

  cout << pq.top() << "\n";
  for (int i = k; i < n; ++i) {
    if (pq.top() < p[i]) {
      pq.pop();
      pq.push(p[i]);
    }

    cout << pq.top() << "\n";
  }
  return 0;
}