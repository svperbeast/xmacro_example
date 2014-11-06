#include "msgcode.hpp"

#define SELECT_STRING(a) #a,
static const char* msgcode_strings[] =
    { FOR_ALL_MSGCODES(SELECT_STRING) };
#undef SELECT_STRING

const char* strmsgcode(MsgCode code)
{
    std::uint16_t c = enum_value(code);
    return msgcode_strings[c];
}

const char* strmsgcode(std::uint16_t code)
{
    return msgcode_strings[code];
}
