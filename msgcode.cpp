#include "msgcode.hpp"

#define SELECT_STRING(a) #a,
static const char* msgcode_strings[] =
    { FOR_ALL_MSGCODES(SELECT_STRING) };
#undef SELECT_STRING

const char* strmsgcode(MsgCode code)
{
    uint32_t c = enum_value(code);
    return msgcode_strings[c];
}

const char* strmsgcode(uint32_t code)
{
    return msgcode_strings[code];
}
