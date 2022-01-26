#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  string s;
  cin >> s;
  int a = stoi(s.substr(0, 2));
  int b = stoi(s.substr(2, 2));

  bool yymm = false;
  if (1 <= b && b <= 12) yymm = true;

  bool mmyy = false;
  if (1 <= a && a <= 12) mmyy = true;

  if (yymm && mmyy) cout << "AMBIGUOUS" << endl;
  else if (yymm) cout << "YYMM" << endl;
  else if (mmyy) cout << "MMYY" << endl;
  else cout << "NA" << endl;
  return 0;
}