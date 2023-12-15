#include <stdio.h>
#include "time.h"

int main() {
	boolean pertama = true;
	TIME t1, t2, awal, akhir;
	int jlh, i;
	scanf("%d", &jlh);
	for (i = 1; i<=jlh; i++) {
		printf("[%d]\n", i);
		scanf("%d %d %d", &Hour(t1), &Minute(t1), &Second(t1));
		while (IsTIMEValid(Hour(t1), Minute(t1), Second(t1)) == false) {
			printf("Jam tidak valid\n");
			scanf("%d %d %d", &Hour(t1), &Minute(t1), &Second(t1));		
		}	
		scanf("%d %d %d", &Hour(t2), &Minute(t2), &Second(t2));
		while (IsTIMEValid(Hour(t2), Minute(t2), Second(t2)) == false) {
			printf("Jam tidak valid\n");		
			scanf("%d %d %d", &Hour(t2), &Minute(t2), &Second(t2));
		}		
		if (TGT(t1, t2) == true) {
			// t1 = akhir
			// t2 = awal
			printf("%ld\n", TIMEToDetik(t1)-TIMEToDetik(t2));
			if (pertama == true){
				awal = t2;
				akhir = t1;
				pertama = false;
			}
			else {
				if (TGT(t1, akhir) == true) {
					akhir = t1;
				}
				if (TLT(t2, awal) == true) {
					awal = t2;
				}
			}
		}
		else {
			// t2 = akhir
			// t1 = awal
			printf("%ld\n", TIMEToDetik(t2)-TIMEToDetik(t1));
			if (pertama == true){
				awal = t1;
				akhir = t2;
				pertama = false;
			}
			else {
				if (TGT(t2, akhir) == true) {
					akhir = t2;
				}
				if (TLT(t1, awal) == true) {
					awal = t1;
				}
			}
		}
	}
	printf("%d:%d:%d\n", Hour(awal), Minute(awal), Second(awal));
	printf("%d:%d:%d\n", Hour(akhir), Minute(akhir), Second(akhir));	
}