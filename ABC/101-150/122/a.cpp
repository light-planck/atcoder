#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string b;
  cin >> b;
  if (b == "A") cout << "T" << endl;
  if (b == "T") cout << "A" << endl;
  if (b == "C") cout << "G" << endl;
  if (b == "G") cout << "C" << endl;
  return 0;
}