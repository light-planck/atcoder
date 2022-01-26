#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  if (n >= 42) cout<< "AGC" << 0 << n + 1 << endl;
  else if (n >= 10) cout << "AGC" << 0 << n << endl;
  else cout << "AGC" << "00" << n << endl;
  return 0;
}