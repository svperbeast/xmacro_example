#ifndef ENUM_UTILITY_INCLUDED
#define ENUM_UTILITY_INCLUDED

#include <type_traits>

// to get underlying type explicitly.
template <typename E>
typename std::underlying_type<E>::type enum_value(E e)
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}

#endif // ! ENUM_UTILITY_INCLUDED
