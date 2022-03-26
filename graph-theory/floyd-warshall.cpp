#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int N = 1e5+7;
int d[N][N], n, m, p, q, r;

void warshall() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<n; k++) {
        d[j][k] = min(d[j][k], d[i][j], d[i][k]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=n; j++) {
      d[i][j] = inf;
    }
  }
  while(m--) {
    cin >> p >> q >> r; // node node weight
    d[p][q] = r;
    d[q][p] = r;
  }
  warshall();

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << i << '-' << j << ": " << d[i][j] << '\n';
    }
  }
  return 0;
}
