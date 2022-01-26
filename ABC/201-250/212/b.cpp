#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;

int main() {
  string n;
  cin >> n;
  vector<int> x(4);
  rep(i, 4) x.at(i) = n.at(i) - '0';
  bool same = true;
  bool step = true;

  rep(i, 3){
    if (x.at(i) != x.at(i+1)) same = false;
    if ((x.at(i) + 1) % 10 != x.at(i+1)) step = false;
  }

  if (same || step) cout << "Weak" << endl;
  else cout << "Strong" << endl;
}