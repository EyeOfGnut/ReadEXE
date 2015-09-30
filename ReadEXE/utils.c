#include <stdio.h>
#include "utils.h"

int printTitle(char *Title){
	printf("\t%-17s\t", Title);
	return 0;
}

int Print_ushort(char *Title, unsigned short buffer)
{
	int len = sizeof(unsigned short), i;

	printTitle(Title);

	for(i=0; i<len; i++)
		printf("0x%02X ", ((buffer >> i*8) & 0xFF));

	printf("\n");
	return 0;
}

int Print_uchar(char *Title, unsigned char buffer)
{
	int len = sizeof(unsigned char), i;
	
	printTitle(Title);

	for(i=0; i<len; i++)
		printf("0x%02X ", ((buffer >> i*8) & 0xFF));

	printf("\n");
	return 0;
}

int Print_ulong(char *Title, unsigned long buffer)
{
	int len = sizeof(unsigned long), i;
	
	printTitle(Title);

	for(i=0; i<len; i++)
		printf("0x%02X ", ((buffer >> i*8) & 0xFF));

	printf("\n");
	return 0;
}

int Print_bArray(char *Title, byte *buffer, int count){	
	int i;
	
	printTitle(Title);

	for(i = 0; i < count; i++) {
		printf("0x%02X ", buffer[i]);
	}

	printf("\n");
	return 0;
}