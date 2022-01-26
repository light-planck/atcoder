#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int H, W;
vector<string> field;
vector<vector<bool>> seen(510, vector<bool>(510, false));

void dfs(int h, int w) {
  seen[h][w] = true;

  for (int dir = 0; dir < 4; dir++) {
    int dh = h + dx[dir];
    int dw = w + dy[dir];

    if (dh < 0 || dh >= H || dw < 0 || dw >= W) continue;
    if (field[dh][dw] == '#') continue;

    if (seen[dh][dw]) continue;
    dfs(dh, dw);
  }
}

int main() {
  cin >> H >> W;
  field.resize(H);
  rep(i, H) cin >> field[i];

  int sh, sw, gh, gw;
  rep(i, H)rep(j, W) {
    if (field[i][j] == 's') {
      sh = i;
      sw = j;
    }
    if (field[i][j] == 'g') {
      gh = i;
      gw = j;
    }
  }

  dfs(sh, sw);
  if (seen[gh][gw]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}