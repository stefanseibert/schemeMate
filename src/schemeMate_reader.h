#ifndef READER_HEADER
#define READER_HEADER

#include "schemeMate_objects.h"
#include "schemeMate_memory.h"

#define EOF_CHAR ((sm_char)-1)
#define INIT_BUFFER_SIZE 32

static void alloc_buffer(buffer *b, int initialSize);
static void grow_buffer(buffer *b);
static void put_buffer(buffer *b, sm_char ch);
static int skipSeparators(sm_stream inStream);
static int readCharacter(sm_stream inStream);
static void unreadCharacter(sm_stream inStream, sm_char char_to_unread);
static sm_bool isSeparator(int aChar);
static sm_obj sm_readList(sm_stream inStream);
long long a2l(char* cp);
sm_obj sm_readString(sm_stream inStream);
sm_obj sm_readCString(char* input);
sm_obj sm_read(sm_stream input);

#endif // READER_HEADER