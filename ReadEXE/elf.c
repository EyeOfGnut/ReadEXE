#include <stdio.h>
#include "elf.h"


int printElf(FILE *filePtr)
{	
	struct ELF exeBuffer;
	//FILE *filePtr = fopen(argv, "rb"); // r = Read, b = Bytes
	fseek(filePtr, 0, SEEK_SET);
	fread(&exeBuffer, sizeof(struct ELF),1,filePtr);

	printf("ELF Executable\n");
	Print_ulong("Signature", exeBuffer.signature); //this won't work, because Print_Bytes was made for 2-byte vars. This sig is a 4-byte var.

	if(exeBuffer.proc_class == 1) {
		Print_uchar("32-Bit Processor", exeBuffer.proc_class);
	}
	else {
		Print_uchar("64-Bit Processor", exeBuffer.proc_class);
	}

	Print_uchar("ELF Version", exeBuffer.version);

	Print_uchar(printOS(exeBuffer.os_ident), exeBuffer.os_ident);
	Print_uchar("ABI Version", exeBuffer.abi_version);
	Print_uchar("File Type", exeBuffer.type);

	// Still need machine, version, entry, header and section pointers, flags, etc.
	// https://en.wikipedia.org/wiki/Executable_and_Linkable_Format
	

	return 0;
}

char* printOS(byte osID)
{
	char *osName;
	switch(osID)
	{
	case 0x00:
		osName = "System V";
		break;
	case 0x01:
		osName = "HP-UX";
		break;
	case 0x02:
		osName = "NetBSD";
		break;
	case 0x03:
		osName = "Linux";
		break;
	case 0x06:
		osName = "Solaris";
		break;
	case 0x07:
		osName = "AIX";
		break;
	case 0x08:
		osName = "IRIX";
		break;
	case 0x09:
		osName = "FreeBSD";
		break;
	case 0x0C:
		osName = "OpenBSD";
		break;
	case 0x0D:
		osName = "OpenVMS";
		break;
	default:
		osName = "Unknown";
		break;
	}

	return osName;
}