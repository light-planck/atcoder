#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string n;
  cin >> n;
  char c = n[n.size() - 1];
  if (c == '2' or c == '4' or c == '5' or c == '7' or c == '9')
    cout << "hon" << endl;
  else if (c == '0' or c == '1' or c == '6' or c == '8')
    cout << "pon" << endl;
  else cout << "bon" << endl;
}