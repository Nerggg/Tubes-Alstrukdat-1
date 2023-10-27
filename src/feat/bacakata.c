#include <stdio.h>
#include "../adt/wordmachine.c"
#include "../adt/charmachine.c"

Word baca() {
	STARTWORD();
	return currentWord;
}
