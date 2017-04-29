#ifndef OBJECTS_HEADER
#define OBJECTS_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Basic defines
typedef union sm_object* sm_obj;
typedef enum sm_tag_type sm_tag;
typedef int sm_char;
typedef int sm_bool;
typedef sm_obj (*sm_func)();
typedef struct sm_environment* sm_env;
typedef enum { false, true } bool;

// Error reporting

#define ERROR(msg) error(msg, __FILE__, __LINE__)

#define ASSERT(cond, msg) ASSERT2(cond, msg, __FILE__, __LINE__)

#define ASSERT2(cond, msg, fileName, lineNr) \
	if (! (cond)) { \
		fprintf(stderr, "[%s:%d] assertion failed: %s", \
			fileName, lineNr, msg); \
		abort(); \
	}

#define ASSERT_SYMBOL(obj) \
    ASSERT(is_symbol(obj), "Symbol expected but got something else!")

// Basic objects

enum sm_tag_type
{
	TAG_INT = 0,
	TAG_FLOAT,
	TAG_NIL,
	TAG_FALSE,
	TAG_TRUE,
	TAG_SYMBOL,
	TAG_STRING,
	TAG_CONS,
	TAG_EOF,
	TAG_OBJ,
	TAG_VOID,
	TAG_SYS_FUNC,
	TAG_SYS_SYNTAX,
	TAG_USER_FUNC,
	TAG_MAX
};

struct sm_int_type {
	sm_tag tag;
	long iVal;
};

struct sm_float_type {
	sm_tag tag;
	double fVal;
};

struct sm_special_type {
	sm_tag tag;
};

struct sm_symbol_type {
	sm_tag tag;
	char chars[1];
};

struct sm_string_type {
	sm_tag tag;
	char string[1];
};

struct sm_cons_type {
	sm_tag tag;
	sm_obj car;
	sm_obj cdr;
};

struct sm_any_type {
    sm_tag tag;
};

struct sm_sys_func_type {
	sm_tag tag;
	sm_func code;
};

struct sm_user_func_type {
	sm_tag tag;
	sm_obj args;
	sm_obj body;
};

struct sm_sys_syntax_type {
	sm_tag tag;
	sm_func code;
};

struct sm_entry {
    sm_obj key;
    sm_obj value;
};

struct sm_environment {
    struct sm_environment *parent;
    unsigned int used_slots;
    unsigned int allocated_slots;
    struct sm_entry *entries;
};

union sm_object {
	struct sm_any_type sm_any;
	struct sm_int_type sm_int;
	struct sm_float_type sm_float;
	struct sm_special_type sm_special;
	struct sm_symbol_type sm_symbol;
	struct sm_string_type sm_string;
	struct sm_cons_type sm_cons;
	struct sm_sys_func_type sm_sys_func;
	struct sm_sys_syntax_type sm_sys_syntax;
	struct sm_user_func_type sm_user_func;
};

// program wide data
extern sm_env MAIN_ENV;

// Type checks

static inline sm_tag get_tag(sm_obj obj) {
    return (obj->sm_any.tag);
}

static inline sm_bool has_tag(sm_obj obj, sm_tag tag) {
    return (get_tag(obj) == tag);
}

static inline sm_bool is_int(sm_obj obj) {
    return has_tag(obj, TAG_INT);
}

static inline sm_bool is_float(sm_obj obj) {
    return has_tag(obj, TAG_FLOAT);
}

static inline double to_float(sm_obj obj)
{
	ASSERT(is_float(obj), "to_float() function expects a float object.");
	return obj->sm_float.fVal;
}

static inline sm_bool is_nil(sm_obj obj) {
    return has_tag(obj, TAG_NIL);
}

static inline sm_bool is_symbol(sm_obj obj) {
    return has_tag(obj, TAG_SYMBOL);
}

static inline sm_bool is_string(sm_obj obj) {
    return has_tag(obj, TAG_STRING);
}

static inline sm_bool is_cons(sm_obj obj) {
    return has_tag(obj, TAG_CONS);
}

// Data getter

static inline long int_val(sm_obj obj) {
    ASSERT(is_int(obj), "int_val() function expects an integer object.");
    return (obj->sm_int.iVal);
}

static inline double float_val(sm_obj obj) {
    ASSERT(is_float(obj), "float_val() function expects a float object.");
    return (obj->sm_float.fVal);
}

static inline char* symbol_val(sm_obj obj) {
    ASSERT(is_symbol(obj), "symbol_val() function expects a symbol object.");
    return (obj->sm_symbol.chars);
}

static inline char* string_val(sm_obj obj) {
    ASSERT(is_string(obj), "string_val() function expects a string object.");
    return (obj->sm_symbol.chars);
}

static inline sm_obj car(sm_obj obj) {
    ASSERT(is_cons(obj), "car() function expects a cons cell.");
    return (obj->sm_cons.car);
}

static inline sm_obj cdr(sm_obj obj) {
    ASSERT(is_cons(obj), "cdr() function expects a cons cell.");
    return (obj->sm_cons.cdr);
}

#endif // OBJECTS_HEADER