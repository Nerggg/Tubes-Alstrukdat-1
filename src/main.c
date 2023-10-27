#include <stdio.h>
#include "feat/bacakata.c"

int main() {
	Word tes;
	printf("masukkan kata\n");
	tes = baca();
	for (int i = 0; i < tes.Length; i++) {
		printf("%c", tes.TabWord[i]);
	}
	printf("\n");
}
