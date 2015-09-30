//http://www.w3.org/Graphics/GIF/spec-gif89a.txt

#ifndef GIF_HDR // prevent headers from being included twice
#define GIF_HDR

#include "utils.h"
#define GCOLORTABLE	128
#define SORT 8

struct GIF_HEADER {
	byte header[6];
	byte l_screen_desc[7];
};

struct GRAPHIC_CONTROL_EXTENSION {
	byte ext_intro;
	byte type_label;
	byte block_size; // hard-set to 4
	byte flags;
	doublebyte delay_time;
	byte trans_color_index;
	byte terminator;
};

// Data Structure Alignment causes problems with simply using sizeof(); There are padding bytes after both uchar members 
//	to align with the ushort members. So there are bytes read from the stream that are discarded when reading the whole chunk, when they need to be saved.
typedef unsigned char ID_TAG;
typedef unsigned char ID_FLAGS;
struct IMAGE_DESCRIPTOR {
	//unsigned char tag;
	unsigned short left_coord;
	unsigned short top_cord;
	unsigned short width;
	unsigned short height;
	//unsigned char flags;
};

int printGIF(FILE *filePtr);

#endif