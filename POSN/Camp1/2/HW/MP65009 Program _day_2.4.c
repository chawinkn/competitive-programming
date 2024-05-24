#include <stdio.h>

int main() {
	int s1, s2;
	float m;
	printf("Please enter midterm score : ");
	scanf("%d", &s1);
	printf("Please enter final score : ");
	scanf("%d", &s2);
	if (s1 >= 0 && s1 <= 100 && s2 >= 0 && s2 <= 100) {
		m = (s1+s2)/2;
		printf("Your score = %.0f %%\n", m);
		if (m >= 80 && m <= 100) {
			printf("Grade = G, Good");
		}
		else if (m >= 50 && m < 80) {
			printf("Grade = P, Pass");
		}
		else if (m >= 0 && m < 50) {
			printf("Grade = F, Fail");
		}
	}
	else {
		printf("Error");
	}
}
