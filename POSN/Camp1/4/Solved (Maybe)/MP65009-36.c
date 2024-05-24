#include <stdio.h>

int main() {
  int real, fake, val, check=1;
  char password[4], enter[7];
  printf("Real Expense : ");
  scanf("%d", &real);
  printf("Fake Expense : ");
  scanf("%d", &fake);
  printf("Password : ");
  scanf("%s", password);
  printf("\nPassword : ");
  scanf("%s", enter);
  for (int i = 0; i < 6; i+=2) {
    val = (enter[i]-'0')*10+enter[i+1]-'0';
    if (val >= 1 && val <= 26) {
      val += 64;
    }
    else if (val >= 30 && val <= 55) {
      val += 67;
    }
    if (val != password[i/2]) {
      check = 0;
    }
  }
  if (check) {
    printf("Unlocked!!!\n");
    printf("Expense = %d\n", real);
  }
  else {
    printf("Uncorrect!!!\n");
    printf("Expense = %d\n", fake);
  }
  return 0;
}
  