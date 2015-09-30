#ifndef EXE_HEADER // prevent headers from being included twice
#define EXE_HEADER

#include "utils.h"

struct EXE {
	unsigned short signature;
	unsigned short bytes_in_last_block;
	unsigned short blocks_in_file;
	unsigned short num_relocs;
	unsigned short header_paragraphs;
	unsigned short min_extra_paragraphs;
	unsigned short max_extra_paragraphs;
	unsigned short ss;
	unsigned short sp;
	unsigned short checksum;
	unsigned short ip;
	unsigned short cs;
	unsigned short reloc_table_offset;
	unsigned short overlay_number;
};

struct EXE_RELOC {
	unsigned short offset;
	unsigned short segment;
};

int printExe(FILE *filePtr);


#endif