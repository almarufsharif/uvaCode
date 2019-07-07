#include <stdio.h>
#include <math.h>

int main() {
    int tc, L;
    double l, r, w, center, rect;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &L);
        l = static_cast<double>(L);
        r = l * 0.2;
        w = l * 0.6;
        center = acos(-1) * r * r;
        rect = (w * l) - center;
        printf("%.2f %.2f\n", center, rect);
    }

    return 0;
}
