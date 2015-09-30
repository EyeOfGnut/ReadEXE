//#define Print_Bytes(Title, Bytes) (printf("\t%-17s\t0x%02X 0x%02X\n", Title, (Bytes & 0xff), ((Bytes >> 8) & 0xff)));
typedef unsigned char byte;
typedef unsigned short doublebyte;
typedef unsigned long quadbyte;

int Print_uchar(char *Title, unsigned char buffer); //1 Byte
int Print_ushort(char *Title, unsigned short buffer); //2 Bytes
int Print_ulong(char *Title, unsigned long buffer); //3 Bytes
int Print_bArray(char *Title, byte array[], int count);