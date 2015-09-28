#define Print_Bytes(A, B) (printf("\t%-17s\t0x%02X 0x%02X\n", A, (B & 0xff), ((B >> 8) & 0xff)));
