#ifndef ELF_HEADER // prevent headers from being included twice
#define ELF_HEADER

struct ELF {
	unsigned long signature;
	unsigned char proc_class;
	unsigned char endianness;
	unsigned char version;
	unsigned char os_ident;
	unsigned char abi_version;
	unsigned char padding[7];
	unsigned short type;
	unsigned short arch;
	unsigned long other_version;
	unsigned long proc_entry;
	unsigned long prog_header_table;
	unsigned long sec_header_table;
	unsigned long flags;
	unsigned short header_size;
	unsigned short pht_entry_size;
	unsigned short pht_entry_count;
	unsigned short sht_entry_size;
	unsigned short sht_entry_count;
	unsigned short sht_names_index;
};

int printElf(FILE *filePtr);


#endif