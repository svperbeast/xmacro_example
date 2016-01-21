#include "msgcode.hpp"
#include <iostream>
#include <assert.h>

int main(int argc, char* argv[])
{
    std::uint16_t msg1 = enum_value(MsgCode::MSG1);
    MsgCode  msg2 = MsgCode::MSG2;

    std::cout << "size of MsgCode is " << sizeof(MsgCode) << "\n";
    std::cout << "msg1 = " << strmsgcode(msg1) << "\n";
    std::cout << "msg2 = " << strmsgcode(msg2) << "\n";

    MsgCode mc = to_enum<MsgCode>(msg1);
    assert(mc == MsgCode::MSG1);

    // static assertion failure.
#if 0
    std::uint32_t val = 0;
    mc = to_enum<MsgCode>(val);
#endif

    return 0;
}
