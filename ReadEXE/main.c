#include <stdio.h>
#include "exe.h"
#include "elf.h"
#include "gif.h"
#include "utils.h"


void check0x00(byte* buffer, FILE *filePtr);
void check0x4D(byte* buffer, FILE *filePtr);
void checkISO(byte* buffer, FILE *filePtr);

int main(int argc, char *argv[])
{	
	byte exeBuffer[12];
	FILE *filePtr; 
	fopen_s(&filePtr, argv[1], "rb"); // r = Read, b = Bytes

	fread(&exeBuffer,12,1,filePtr);

	switch(exeBuffer[0])
	{
	case 0x00:
		check0x00(exeBuffer, filePtr);
		break;
	case 0x05:
		printf("AppleWorks 5 document\n");
		break;
	case 0x06:
		printf("AppleWorks 6 document\n");
		break;
	case 0x1F:
		// Gzip, L-Z-W compressed file, LZH compressed file
		break;
	case 0x20:
		// two types of FITS image file
		break;
	case 0x24:
		printf("MS System Deployment Image");
		break;
	case 0x25:
		// post script or pdf
		break;
	case 0x30:
		printf("Advanced Systems Format");
		break;
	case 0x37:
		printf("7-Zip File");
		break;
	case 0x38:
		printf("Photoshop Document File");
		break;
	case 0x3D:
		printf("Flexible Image Transport System (FITS) file");
		break;
	case 0x41:
		printf("FreeHand 8 Document");
	case 0x42:
		// one of 4 types
		break;
	case 0x43:
		// ISO or Google Chrome extension
		break;
	case 0x44:
		printf("Windows Update BDC");
		break;
	case 0x45:
	case 0x8B:
		printf("Roxio Toast Image");
		break;
	case 0x46:
		//12 types of IFF
		break;
	case 0x47:
		printGIF(filePtr);
		break;
	case 0x49:
		//Could be MP3 or TIFF, or or AmiBack on an Amiga
		break;
	case 0x4B:
		printf("VMDK");
		break;
	case 0x4D:
		check0x4D(exeBuffer, filePtr);
		break;
	case 0x4E:
		printf("Nintendo ROM File");
		break;
	case 0x4F:
		printf("OGG Media File");
		break;
	case 0x50:
		//Could be ZIP or Windows Files and Settings xFer Repo
		break;
	case 0x52:
		// Wav audio file or 2 types of RAR
		break;
	case 0x53:
		// Big Endian DPX image or FITS image file
		break;
	case 0x58:
		printf("Little-Endian format DPX Image");
		break;
	case 0x64:
		printf("Dalvik Executable");
		break;
	case 0x66:
		printf("Free Lossless Audio Codec (FLAC)");
		break;
	case 0x74:
		printf("Portable Voxel File");
		break;
	case 0x75:
		//one of two types of TAR
		break;
	case 0x76:
		printf("OpenEXR Image");
		break;
	case 0x78:
		// Apple disk image, or eXtensible Archive (xar)
		break;
	case 0x7F:
		printf("ELF\n");
		break;
	case 0x80:
		printf("Kodak Cineon Image");
		break;
	case 0x89:
		printf("Portable Network Graphics (PNG) image");
		break;
	case 0xBE:
		printf("Palm Desktop Calendar Archive");
		break;
	case 0xCA:
		printf("Java Class File");
		break;
	case 0xCE:
		printf("32-bit Mach-O binary (reverse byte ordering)");
		break;
	case 0xCF:
		printf("64-bit Mach-O binary (reverse byte ordering)");
		break;
	case 0xD0:
		printf("MS Office Document");
		break;
	case 0xEF:
		printf("UTF-8 Encoded text file");
		break;
	case 0xFE:
		// one of two Mach-O binaries
		break;
	case 0xFF:
		// jpg, mpg, or 2 types of txt
		break;
	default:
		printf("Unknown");
		break;
	};

	getchar();
	return 0;
}

void check0x00(byte* buffer, FILE *filePtr)
{
	switch(buffer[1])
	{
	case 0x01:
		switch(buffer[2])
		{
		case 0x00:
			printf("Palm Desktop Data File");
			break;
		case 0x42:
			printf("Palm Desktop To Do Archive");
			break;
		case 0x44:
			printf("Palm Desktop Calendar Archive");
			break;
		default:
			printf("Uknown Format");
			break;
		};
	case 0x00:
		if(buffer[3] == 0x01) printf("Computer Icon file");
		else if(buffer[4] == 0x66) 
		{
			if(buffer[11] == 0x35) printf("MPEG-4 Video");
			else printf("3rd Generation Partnership Project multimedia file");
		}
		else checkISO(buffer, filePtr);
		break;
	default:
		break;
	};

}

void check0x4D(byte* buffer, FILE *filePtr)
{
	switch(buffer[1])
	{
		case 0x4C:
			printf("Magic Lantern Video");
			break;
		case 0x53:
			printf("MS CAB File");
			break;
		case 0x54:
			printf("MIDI Sound File");
			break;
		case 0x5A:
			printExe(filePtr);
			break;
		default:
			break;
	}
}

void checkISO(byte* buffer, FILE *filePtr){}