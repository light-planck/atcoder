#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// a, bの最大公約数
ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << a * b / gcd(a, b) << endl;
  return 0;
}