#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
int N, M, pos[100005], FT[200005], offset, top;

int LSOne(int X) {
    return (X&(-X));
}

void update(int X, int val) {
    while(X <= offset) {
        FT[X] += val;
        X += LSOne(X);
    }
}

int rsq(int X) {
    int sum = 0;
    while(X) {
        sum += FT[X];
        X -= LSOne(X);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &N, &M);

        offset = MX + N;
        memset(pos, 0, sizeof(pos));
        memset(FT, 0, sizeof(FT));

        for (int i = 1; i <= N; i++) pos[i] = MX+i;
        for (int i = 2; i <= N; i++) update(MX+i, 1);

        top = 100000;
        while(M--) {
            int x;
            scanf("%d", &x);
            printf("%d", rsq(pos[x]));
            if (M) printf(" ");
            else printf("\n");
            update(pos[x], -1);
            update(top+1, 1);
            pos[x] = top;
            top--;
        }
    }
}
