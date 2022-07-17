#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int a[3][3];
  rep(i, 3)rep(j, 3) cin >> a[i][j];
  int n;
  cin >> n;
  rep(i, n) {
    int b;
    cin >> b;
    rep(i, 3)rep(j, 3) {
      if (a[i][j] == b) a[i][j] = 0;
    }
  }

  bool bingo = false;
  
  // 横
  rep(i, 3){
    int cnt = 0;
    rep(j, 3) {
      if (a[i][j] == 0) cnt++;
    }
    if (cnt == 3) bingo = true;
  }

  // 縦
  rep(j, 3){
    int cnt = 0;
    rep(i, 3) {
      if (a[i][j] == 0) cnt++;
    }
    if (cnt == 3) bingo = true;
  }

  // ななめ
  if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) bingo = true;
  if (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0) bingo = true;

  if (bingo) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}