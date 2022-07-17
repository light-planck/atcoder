#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;

  map<int, int> mp;
  ll sum = 0;
  rep(i, n) {
    int a;
    cin >> a;
    sum += a;
    mp[a]++;
  }

  int q;
  cin >> q;
  vector<ll> s;
  rep(i, q) {
    int b, c;
    cin >> b >> c;
    int num = mp[b];
    sum -= (ll)num * b;
    sum += (ll)num * c;
    mp[b] = 0;
    mp[c] += num;
    s.push_back(sum);
  }

  for (auto x : s) {
    cout << x << endl;
  }
  return 0;
}