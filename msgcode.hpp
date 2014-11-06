#ifndef MSGCODE_INCLUDED
#define MSGCODE_INCLUDED

#include "enum_utility.hpp"
#include <cstdint>

#define FOR_ALL_MSGCODES(apply) \
    apply(MSG1) \
    apply(MSG2) \

// if you want to add prefix:
//  #define MAKE_ENUM_CLASS(a) PREFIX_##a,
#define MAKE_ENUM_CLASS(a) a,
enum class MsgCode : std::uint16_t { FOR_ALL_MSGCODES(MAKE_ENUM_CLASS) };
#undef MAKE_ENUM_CLASS

extern const char* strmsgcode(MsgCode code);
extern const char* strmsgcode(std::uint16_t code);

#endif // !MSGCODE_INCLUDED
