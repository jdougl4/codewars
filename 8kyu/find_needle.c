#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*
 * Write a function find_needle() that takes an array full of junk but 
 * containing one "needle"
 *
 * After your function finds the needle, it should return a message (as a 
 * string) that says:
 *
 * "found the needle at position" plus the index it found the needle, so:
 *
 * ["hay", "junk", "hay", "hay", "moreJunk", "needle", "randomJunk"] -->
 *
 * found the needle at position 5
*/
char *find_needle(const char **haystack, size_t count)
{
	for (int i = 0; i < count; ++i)
	{
		if (!strcmp(haystack[i], "needle")) // strncmp returns 0 if 
						     // true
		{
			char *buff;
			asprintf(&buff, "found the needle at position %d", i);
			return buff;
		}
	}
	// Every control path must return a value
	return NULL;
}

void run_test(const char **haystack, size_t count, const char *expected)
{
	char *result = find_needle(haystack, count);
	assert(result != NULL);
	assert(strcmp(result, expected) == 0);
	free(result);
}

int main(void) {
	// Needle in the middle
	const char *test1[] = {
		"hay", "junk", "hay", "hay", "moreJunk", "needle", "randomJunk"
	};
	run_test(test1, 7, "found the needle at position 5");

	// Needle at index 0
	const char *test2[] = {
		"needle", "hay", "hay", "junk"
	};
	run_test(test2, 4, "found the needle at position 0");

	printf("All tests passed.\n");

	return 0;
}
