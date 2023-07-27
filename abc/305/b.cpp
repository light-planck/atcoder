#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  char p, q;
  cin >> p >> q;

  vector<ll> dist = {0, 3, 4, 8, 9, 14, 23};
  ll i = p - 'A';
  ll j = q - 'A';
  if (i > j) swap(i, j);
  cout << dist[j] - dist[i] << '\n';
  return 0;
}