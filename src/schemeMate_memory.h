#ifndef MEMORY_HEADER
#define MEMORY_HEADER

#include "schemeMate_objects.h"

#define USE_REAL_HASH
#define INITIAL_SYMBOLTABLE_SIZE 1009
#define _INIT_BUFFER_SIZE 32

enum streamformat
{
	FILE_STREAM,
	STRING_STREAM
};

struct sm_stream_type
{
	enum streamformat type;
	FILE* file;
	char* string;
	int index;
	int peek;
};

typedef struct sm_stream_type* sm_stream;

typedef struct buffer_struct {
	char *memory;
	int size;
	int filled;
} buffer;

static sm_obj eof_singleton;
static sm_obj *symbolTable = NULL;
static int numKnownSymbols = 0;
static int symbolTableSize = 0;

void init_memory(int running_mode);
void shutdown_memory();
sm_obj new_int(int value);
sm_obj new_symbol(char* chars);
sm_obj new_string(char* chars);
sm_obj new_cons(sm_obj car, sm_obj cdr);
sm_obj sm_eof();
sm_obj sm_nil();
sm_obj sm_false();
sm_obj sm_true();
sm_obj sm_void();
sm_obj really_new_symbol(char* chars);
sm_stream new_file_stream(FILE* inFile);
sm_stream new_string_stream(char* string);
static sm_obj create_singleton(sm_tag tag);
static sm_obj get_symbol_or_null(char* chars);
static void remember_symbol(sm_obj obj);
static void grow_symbol_table();
static void check_table_size();

// Hash function
static inline long str_hash(char *cp) {
    long hVal = 0;
    char c;
	#ifdef USE_REAL_HASH
    	while ((c = *cp++) != '\0') {
		hVal = (hVal*63)+(c & 0xFF);
    	}
	#endif
    return(hVal);
}

#endif // MEMORY_HEADER