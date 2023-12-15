#include <stdio.h>

int main() {
	int nRumah, nJalan, i, j, waktu = 0;

	scanf("%d", &nRumah);
	int rumah[nRumah];
	for (i = 0; i < nRumah; i++) {
		scanf("%d", &rumah[i]);
	}

	scanf("%d", &nJalan);
	int jalan[nJalan];
	for (i = 0; i < nJalan; i++) {
		scanf("%d", &jalan[i]);
	}

	int cek, last = -1;
	for (cek = 1; cek <= 3; cek++) {
		for (i = 0; i < nRumah; i++) {
			if(rumah[i] == cek) {
				last = i;
			}
		}

		if (last == -1) {
			cek++;
		}
		else {
			for (i = 0; i <= last; i++) {
				if (rumah[i] == cek) {
					waktu++;
				}
				if (i > 0) {
					waktu += 2 * jalan[i - 1];
				}
			}
		}

		last = -1;
	}
	printf("%d\n", waktu);
}
