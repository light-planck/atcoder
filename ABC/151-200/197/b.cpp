#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--; y--;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  int cnt = 1;

  //left
  for (int j = y - 1; j >= 0; j--){
    if (s[x][j] != '#') cnt++;
    else break;
  }

  //cout << "left : " << cnt << endl;

  //right
  for (int j = y + 1; j < w; j++){
    if (s[x][j] != '#') cnt++;
    else break;
  }

  //cout << "right : " << cnt << endl;

  //down
  for (int i = x + 1; i < h; i++){
    if (s[i][y] != '#') cnt++;
    else break;
  }

  //cout << "down : " << cnt << endl;

  //up
  for (int i = x - 1; i >= 0; i--){
    if (s[i][y] != '#') cnt++;
    else break;
  }

  //cout << "up : " << cnt << endl;

  cout << cnt << endl;
}