#include <stdio.h>

int main() {
	typedef struct {
		int sols, p;
	} solutions;
	solutions max;
	max.sols = 0;

	#pragma omp parallel for  
	for (int p = 12; p <= 1000; p++) { 
		solutions sol;
		sol.p = p;
		sol.sols = 0;

		for (int l1 = 3; l1 < p/2; l1++) {
			for (int l2 = 3; l2 < p/2; l2++) {
				int h = p - (l1 + l2);
				if (h > l1 && h > l2 && h*h == (l1*l1) + (l2*l2)) {
					sol.sols += 1;
				}
			}
		}
		//printf("Solutions: %d\n", sol.sols);
		if (sol.sols > max.sols) {
			max.sols = sol.sols;
			max.p = p;
		}
		sol.sols = 0;
	}
	printf("Maximum solution p: %d\n", max.p);
}

