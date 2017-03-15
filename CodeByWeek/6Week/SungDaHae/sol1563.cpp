/* https://www.acmicpc.net/blog/view/31 방법5 복사본 */

#include <iostream>
#include <cstdio>
using namespace std;
int mod = 1000000;
int d[1001][3];
int main() {
    int n;
    cin >> n;
    d[0][0] = 1;
    for (int i=1; i<=n; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1] + d[i-1][2];
        d[i][1] = d[i-1][0];
        d[i][2] = d[i-1][1];
        for (int j=0; j<3; j++) {
            d[i][j] %= mod;
        }
    }
    int ans = 0;
    for (int i=0; i<3; i++) {
        ans += d[n][i];
        ans %= mod;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                long long temp = (long long)d[i-1][j] * d[n-i][k];
                ans += temp % mod;
                ans %= mod;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
