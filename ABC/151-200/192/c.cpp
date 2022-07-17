#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int f(int x) {
  string s = to_string(x);
  sort(all(s), greater<char>());
  int g1 = stoi(s);
  sort(all(s));
  int g2 = stoi(s);
  return g1 - g2;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k+1);
  a[0] = n;

  for (int i = 0; i < k; i++) {
    a[i + 1] = f(a[i]);
  }

  cout << a[k] << endl;
  return 0;
}