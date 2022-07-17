#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  bitset<8> a1(a);
  bitset<8> b1(b);
  bitset<8> c = a1 ^ b1;
  
  cout << c.to_ullong() << endl;
}