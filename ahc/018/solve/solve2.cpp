// 家と水源のマンハッタン距離が最小となるように掘削
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct Pos {
  ll y, x;
  Pos(ll y=0, ll x=0) : y(y), x(x) {}
};


ll n, w, k, c;
vector<Pos> water;
vector<Pos> house;

vector<vector<bool>> broken;
ll power = 100;
ll cost = 0;


void init_c() {
  if (c < 16) power = 50;
  else if (c < 128) power = 100;
  else power = 200;
}


void init() {
  cin >> n >> w >> k >> c;
  broken = vector(n, vector<bool>(n, false));
  init_c();
  rep(_, w) {
    ll a, b;
    cin >> a >> b;
    water.emplace_back(a, b);
  }
  rep(_, k) {
    ll a, b;
    cin >> a >> b;
    house.emplace_back(a, b);
  }
}


void respond(ll y, ll x) {
  cost += power + c;
  cout << y << " " << x << " " << power << endl;
  ll r;
  cin >> r;
  if (r == -1) {
    cerr << "invalid: y=" << y << " j=" << x << endl;
    exit(1);
  }
  if (r == 2) {
    broken[y][x] = true;
    cerr << "total_cost=" << cost << endl;
    exit(0);
  }
  if (r == 1) {
    broken[y][x] = true;
  }
}


void destruct(ll y, ll x) {
  while (not broken[y][x]) {
    respond(y, x);
  }
}


void move(Pos start, Pos goal) {
  cout << "# move from (" << start.y << "," << start.x << ") to (" << goal.y << "," << goal.x << ")" << endl;

  // down/up
  if (start.y < goal.y) {
    for (int y = start.y; y < goal.y; y++) {
      destruct(y, start.x);
    }
  } else {
    for (int y = start.y; y > goal.y; y--) {
      destruct(y, start.x);
    }
  }

  // right/left
  if (start.x < goal.x) {
    for (int x = start.x; x <= goal.x; x++) {
      destruct(goal.y, x);
    }
  } else {
    for (int x = start.x; x >= goal.x; x--) {
      destruct(goal.y, x);
    }
  }
}


// それぞれの家について、一つ目の水源まで最短距離でまっすぐに掘削を行う
void solve() {
  // 家と水源の最小のマンハッタン距離をとる水源のidx
  vector<ll> near_water(k);
  rep(i, k) {
    ll dist = 1ll << 60;
    ll idx = 0;
    rep(j, w) {
      ll d = abs(house[i].y - water[j].y) + abs(house[i].x - water[j].x);
      if (d < dist) {
        dist = d;
        idx = j;
      }
    }
    near_water[i] = idx;
  }
  rep(i, k) {
    move(house[i], water[near_water[i]]);
  }
}


int main() {
  init();
  solve();
  return 0;
}