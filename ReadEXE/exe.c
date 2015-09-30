#include <stdio.h>
#include <string.h>
#include "exe.h"

int printExe(FILE *filePtr)
{
	struct EXE exeBuffer;

	//FILE *filePtr = fopen(argv, "rb"); // r = Read, b = Bytes
	fseek(filePtr, 0, SEEK_SET);
	fread(&exeBuffer, sizeof(struct EXE),1,filePtr);

	printf("DOS Executable (exe)\n");
	Print_ushort("Signature", exeBuffer.signature);
	Print_ushort("Bytes in Last Block", exeBuffer.bytes_in_last_block);
	Print_ushort("Blocks", exeBuffer.blocks_in_file);
	Print_ushort("Relocation Entries", exeBuffer.num_relocs);
	Print_ushort("Header Paragraphs", exeBuffer.header_paragraphs);
	Print_ushort("Minimum Paragraphs", exeBuffer.min_extra_paragraphs);
	Print_ushort("Maximum Paragraphs", exeBuffer.max_extra_paragraphs);
	Print_ushort("Stack Segment", exeBuffer.ss);
	Print_ushort("SP Register", exeBuffer.sp);
	Print_ushort("Checksum", exeBuffer.checksum);
	Print_ushort("IP Register", exeBuffer.ip);
	Print_ushort("CS Register", exeBuffer.cs);
	Print_ushort("First Relocation", exeBuffer.reloc_table_offset);
	Print_ushort("Overlay Number", exeBuffer.overlay_number);

	getchar();
	return 0;
}