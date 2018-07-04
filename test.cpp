#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>


typedef struct {
	uint64_t begin_lba;
	uint64_t end_lba;
	uint64_t file_offset;
}lba_range_t;

std::vector<lba_range_t> Ranges ;


extern "C" {
	
	// defined in lba.a 
	extern int do_filemap (const char *file_name) ;

	void add_range(uint64_t begin_lba , uint64_t end_lba , uint64_t byte_offset ){
		Ranges.push_back({ begin_lba , end_lba , byte_offset });
	}

}

int main(int argc , char ** argv ){

	char * file_name = argv[1];

	fprintf(stderr , "\n Get Logical Block Address List of : %s\n\n", file_name );

	do_filemap ( (const char *) file_name);

	// Print the list 
	fprintf(stderr, "%12s %10s %10s \n", "Byte offset", "LBA", "end_LBA");
	// print each LBA Range
	for (auto lba_range : Ranges){
		fprintf(stderr, "%12lu %10lu %10lu \n", lba_range.file_offset , lba_range.begin_lba, lba_range.end_lba);
	}

	return 0 ;
}