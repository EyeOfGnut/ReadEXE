#include <stdio.h>
#include "elf.h"
#include "utils.h"



int printElf(FILE *filePtr)
{	
	struct ELF exeBuffer;
	//FILE *filePtr = fopen(argv, "rb"); // r = Read, b = Bytes
	fseek(filePtr, 0, SEEK_SET);
	fread(&exeBuffer, sizeof(struct ELF),1,filePtr);

	printf("ELF Executable\n");
	Print_Bytes("Signature", exeBuffer.signature); //this won't work, because Print_Bytes was made for 2-byte vars. This sig is a 4-byte var.

	if(exeBuffer.proc_class == 1) {
		Print_Bytes("32-Bit Processor", exeBuffer.proc_class);
	}
	else {
		Print_Bytes("64-Bit Processor", exeBuffer.proc_class);
	}

	Print_Bytes("ELF Version", exeBuffer.version);
	Print_Bytes("Target OS", exeBuffer.os_ident);

	return 0;
}