#include <stdio.h>
#include <wchar.h>

#define CHAR_T wchar_t 

static inline CHAR_T *__SN(CHAR_T **str, int offset) {
	return (CHAR_T *) ((*((char **) str)) += offset);
}

int main() {
	CHAR_T *str = (CHAR_T *) "bleee";

	while (* ((char *) str)) {
		__SN(&str, 1);
	}

	return 0;
}