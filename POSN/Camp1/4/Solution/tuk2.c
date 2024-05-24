#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int h[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < h[i]; j++) {
      for (int k = 0; k < h[i]; k++) {
        printf("*");
      }
      printf("\n");
    }
  }
  return 0;
}