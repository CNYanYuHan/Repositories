#include <stdio.h>

int main() {
    int count = 0;
    int numbers[] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (i != j && i != k && j != k) {
                    count++;
                    printf("%d%d%d\n", numbers[i], numbers[j], numbers[k]);
                }
            }
        }
    }

    printf("总共有 %d 个互不相同且无重复数字的三位数。\n", count);

    return 0;
}
