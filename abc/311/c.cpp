#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector edge(N, vector<ll>());
  rep(i, N) {
    ll a;
    cin >> a;
    --a;
    edge[i].emplace_back(a);
  }
}
