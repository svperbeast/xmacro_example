#include "msgcode.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    uint32_t msg1 = enum_value(MsgCode::MSG1);
    MsgCode  msg2 = MsgCode::MSG2;

    std::cout << "size of MsgCode is " << sizeof(MsgCode) << "\n";
    std::cout << "msg1 = " << strmsgcode(msg1) << "\n";
    std::cout << "msg2 = " << strmsgcode(msg2) << "\n";

    return 0;
}
