#include <stdio.h>
#include "utils.h"
#include "exe.h"

int printExe(FILE *filePtr)
{
	struct EXE exeBuffer;
	//FILE *filePtr = fopen(argv, "rb"); // r = Read, b = Bytes
	fseek(filePtr, 0, SEEK_SET);
	fread(&exeBuffer, sizeof(struct EXE),1,filePtr);

	printf("DOS Executable (exe)\n");
	Print_Bytes("Signature", exeBuffer.signature);
	Print_Bytes("Bytes in Last Block", exeBuffer.bytes_in_last_block);
	Print_Bytes("Blocks", exeBuffer.blocks_in_file);
	Print_Bytes("Relocation Entries", exeBuffer.num_relocs);
	Print_Bytes("Header Paragraphs", exeBuffer.header_paragraphs);
	Print_Bytes("Minimum Paragraphs", exeBuffer.min_extra_paragraphs);
	Print_Bytes("Maximum Paragraphs", exeBuffer.max_extra_paragraphs);
	Print_Bytes("Stack Segment", exeBuffer.ss);
	Print_Bytes("SP Register", exeBuffer.sp);
	Print_Bytes("Checksum", exeBuffer.checksum);
	Print_Bytes("IP Register", exeBuffer.ip);
	Print_Bytes("CS Register", exeBuffer.cs);
	Print_Bytes("First Relocation", exeBuffer.reloc_table_offset);
	Print_Bytes("Overlay Number", exeBuffer.overlay_number);

	getchar();
	return 0;
}