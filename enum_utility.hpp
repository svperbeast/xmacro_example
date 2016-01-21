#ifndef ENUM_UTILITY_INCLUDED
#define ENUM_UTILITY_INCLUDED

#include <type_traits>

// to get underlying type explicitly.
template <typename E>
inline
typename std::underlying_type<E>::type enum_value(E e)
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}

// underlying type to enum
template <typename E, typename T>
inline
E to_enum(T x)
{
    static_assert(
            std::is_same<typename std::underlying_type<E>::type, T>::value,
            "requires 'x' is underlying type of enum.");
    return static_cast<E>(x);
}

#endif // ! ENUM_UTILITY_INCLUDED
