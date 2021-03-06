# X MACRO Example

This example demonstrates strongly typed enum[1] using X Macro[2].
I think that specifying the underlying integral type is useful,
when the enum value is copied to communication protocol messages.

If we have messages which include unsigned 2 bytes `message code`:

```
+------------+---
|message code|...
+------------+---
```

we can specify the underlying type to `std::uint16_t` 

```c++
#include <cstdint>
  
#define FOR_ALL_MSGCODES(apply) \
    apply(MSG1) \
    apply(MSG2) \
  
#define MAKE_ENUM_CLASS(a) a,
enum class MsgCode : std::uint16_t { FOR_ALL_MSGCODES(MAKE_ENUM_CLASS) };
#undef MAKE_ENUM_CLASS
```

and get the value whose type is the underlying type like this:

```c++
std::uint16_t msg1 = enum_value(MsgCode::MSG1);
```

get the enum value from the value whose type is the underlying type:

```c++
MsgCode mc = to_enum<MsgCode>(msg1);
```

## Compile

run the following commands:

    mkdir build
    cd build
    cmake ..
    make

## Expected output

`xmacro_example` will print:

    size of MsgCode is 2
    msg1 = MSG1
    msg2 = MSG2

## `to_enum`

If the type of argument and the underlying type don't match, a message is
printed similar to the one below:

```
...
enum_utility.hpp:19:5: error: static assertion failed: the argument type and the underlying type of enum don't match. 
...
```

## References

[1] [Better types in C++11 - nullptr, enum classes (strongly typed enumerations) and cstdint](http://www.cprogramming.com/c++11/c++11-nullptr-strongly-typed-enum-class.html)

[2] [The X Macro](http://www.drdobbs.com/cpp/the-x-macro/228700289)
