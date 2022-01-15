#include <stdint.h>
#include <stdio.h>
#ifdef GENERATE
#include <inttypes.h>
#include <limits.h>
#include <string.h>

#define CHR_MAX CHAR_MAX + 1
#endif

int
main()
{
#ifndef GENERATE
	uint64_t dx = 0357620655417;
	while (dx) putchar(0x726f6c6564574820 >> (((dx >>= 0x3) & 07) << 0x3));
	return 0;
#else
	char freq[CHR_MAX], uniq[CHR_MAX], idx[CHR_MAX];
	uint64_t uniq64, idx64;
	const char *msg;
	size_t msg_len, i, j;

	msg = "Hello World";
	msg_len = strlen(msg);
	memset(freq, 0, sizeof freq);

	for(i = 0; msg[i]; i++)
		freq[(int)msg[i]]++;
	
	for(i = 0, j = 0; i < CHR_MAX; i++)
		if(freq[i]) uniq[j++] = i;
	uniq[j] = '\0';

	for(i = 0; msg[i]; i++)
		for(j = 0; uniq[j]; j++)
			if(msg[i] == uniq[j]) idx[i] = j;

	uniq64 = *(uint64_t *)uniq;

	for(i = 0; i < msg_len; i++)
		idx64 = (idx64 << 3) | idx[msg_len - i - 1];

	printf("   msg: \"%s\"\n", msg);
	printf("  uniq: \"%s\"\n", uniq);
	printf("   idx: {");
	for(i = 0; i < msg_len; i++) {
		if(i > 0) printf(", ");
		printf("%d", idx[i]);
	}
	printf("}\n");
	printf("uniq64: 0x%"PRIx64"\n", uniq64);
	printf(" idx64: 0%"PRIo64"\n", idx64);
	return 0;
#endif
}
