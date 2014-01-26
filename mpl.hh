//Wraps type traits for easier use, plus adds more.

#ifndef STDX_MPL_H
#define STDX_MPL_H

#include <cstddef>
#include <type_traits>

#include "compiler_diagnostics.hh"

namespace stdx {
inline namespace MplNs {

//MPL UTILITIES

namespace detail {
    template<bool B, bool... Bs> struct AllOf : std::integral_constant<bool, B && AllOf<Bs...>::value> {};
    template<> struct AllOf<true> : std::true_type {};
    template<> struct AllOf<false> : std::false_type {};

    template<bool B, bool... Bs> struct AnyOf : std::integral_constant<bool, B || AnyOf<Bs...>::value> {};
    template<> struct AnyOf<true> : std::true_type {};
    template<> struct AnyOf<false> : std::false_type {};

    template<bool B, bool... Bs> struct NoneOf : std::integral_constant<bool, !B && NoneOf<Bs...>::value> {};
    template<> struct NoneOf<true> : std::false_type {};
    template<> struct NoneOf<false> : std::true_type {};
}

template<bool B, bool... Bs> constexpr bool AllOf{detail::AllOf<B, Bs...>::value};
template<bool B, bool B2, bool... Bs> constexpr bool And{detail::AllOf<B, B2, Bs...>::value};
template<bool B, bool... Bs> constexpr bool AnyOf{detail::AnyOf<B, Bs...>::value};
template<bool B, bool B2, bool... Bs> constexpr bool Or{detail::AllOf<B, B2, Bs...>::value};
template<bool B, bool... Bs> constexpr bool NoneOf{detail::NoneOf<B, Bs...>::value};

//BOOLEAN CONSTANT FUNCTIONS

//todo: add other compilers
#if STDX_CLANG
    #define STDX_IS_TRIVIALLY_ASSIGNABLE(to, from) __is_trivially_assignable(to, from)
#elif STDX_GCC
#elif STD_MSVC
#endif

template<typename T> constexpr bool HasVirtualDestructor{std::has_virtual_destructor<T>::value};
template<typename T> constexpr bool IsAbstract{std::is_abstract<T>::value};
template<typename T> constexpr bool IsArithmetic{std::is_arithmetic<T>::value};
template<typename T> constexpr bool IsArray{std::is_array<T>::value};
template<typename T, typename U> constexpr bool IsAssignable{std::is_assignable<T, U>::value};
template<typename T> constexpr bool IsClass{std::is_class<T>::value};
template<typename T> constexpr bool IsCompound{std::is_compound<T>::value};
template<typename T> constexpr bool IsConst{std::is_const<T>::value};
template<typename T, typename... Ts> constexpr bool IsConstructible{std::is_constructible<T, Ts...>::value};
template<typename T> constexpr bool IsCopyAssignable{std::is_copy_assignable<T>::value};
template<typename T> constexpr bool IsCopyConstructible{std::is_copy_constructible<T>::value};
template<typename T> constexpr bool IsDefaultConstructible{std::is_default_constructible<T>::value};
template<typename T> constexpr bool IsDestructible{std::is_destructible<T>::value};
template<typename T> constexpr bool IsEmpty{std::is_empty<T>::value};
template<typename T> constexpr bool IsEnum{std::is_enum<T>::value};
template<typename T> constexpr bool IsFloatingPoint{std::is_floating_point<T>::value};
template<typename T> constexpr bool IsFunction{std::is_function<T>::value};
template<typename T> constexpr bool IsFundamental{std::is_fundamental<T>::value};
template<typename T> constexpr bool IsIntegral{std::is_integral<T>::value};
template<typename T> constexpr bool IsLiteralType{std::is_literal_type<T>::value};
template<typename T> constexpr bool IsLvalueReference{std::is_lvalue_reference<T>::value};
template<typename T> constexpr bool IsMemberFunctionPointer() noexcept {return std::is_member_function_pointer<T>::value;}
template<typename T> constexpr bool IsMemberObjectPointer{std::is_member_object_pointer<T>::value};
template<typename T> constexpr bool IsMemberPointer{std::is_member_pointer<T>::value};
template<typename T> constexpr bool IsMoveAssignable{std::is_move_assignable<T>::value};
template<typename T> constexpr bool IsMoveConstructible{std::is_move_constructible<T>::value};
template<typename T, typename U> constexpr bool IsNothrowAssignable{std::is_nothrow_assignable<T, U>::value};
template<typename T, typename... Ts> constexpr bool IsNothrowConstructible{std::is_nothrow_constructible<T, Ts...>::value};
template<typename T> constexpr bool IsNothrowCopyAssignable{std::is_nothrow_copy_assignable<T>::value};
template<typename T> constexpr bool IsNothrowCopyConstructible{std::is_nothrow_copy_constructible<T>::value};
template<typename T> constexpr bool IsNothrowDefaultConstructible{std::is_nothrow_default_constructible<T>::value};
template<typename T> constexpr bool IsNothrowDestructible{std::is_nothrow_destructible<T>::value};
template<typename T> constexpr bool IsNothrowMoveAssignable{std::is_nothrow_move_assignable<T>::value};
template<typename T> constexpr bool IsNothrowMoveConstructible{std::is_nothrow_move_constructible<T>::value};
template<typename T> constexpr bool IsObject{std::is_object<T>::value};
template<typename T> constexpr bool IsPod{std::is_pod<T>::value};
template<typename T> constexpr bool IsPointer{std::is_pointer<T>::value};
template<typename T> constexpr bool IsPolymorphic{std::is_polymorphic<T>::value};
template<typename T> constexpr bool IsReference{std::is_reference<T>::value};
template<typename T> constexpr bool IsRvalueReference{std::is_rvalue_reference<T>::value};
template<typename T> constexpr bool IsScalar{std::is_scalar<T>::value};
template<typename T> constexpr bool IsSigned{std::is_signed<T>::value};
template<typename T> constexpr bool IsStandardLayout{std::is_standard_layout<T>::value};
template<typename T> constexpr bool IsTrivial{std::is_trivial<T>::value};
template<typename T, typename U> constexpr bool IsTriviallyAssignable{STDX_IS_TRIVIALLY_ASSIGNABLE(T, U)};
//template<typename T, typename... Ts> constexpr bool IsTriviallyConstructible{STDX_IS_TRIVIALLY_CONSTRUCTIBLE(T, Ts...)};
//template<typename T> constexpr bool IsTriviallyCopyAssignable{std::is_trivially_copy_assignable<T>::value};
//template<typename T> constexpr bool IsTriviallyCopyable{std::is_trivially_copyable<T>::value};
//template<typename T> constexpr bool IsTriviallyCopyConstructible{std::is_trivially_copy_constructible<T>::value};
//template<typename T> constexpr bool IsTriviallyDefaultConstructible{std::is_trivially_default_constructible<T>::value};
template<typename T> constexpr bool IsTriviallyDestructible{std::is_trivially_destructible<T>::value};
//template<typename T> constexpr bool IsTriviallyMoveAssignable{std::is_trivially_move_assignable<T>::value};
//template<typename T> constexpr bool IsTriviallyMoveConstructible{std::is_trivially_move_constructible<T>::value};
template<typename T> constexpr bool IsUnion{std::is_union<T>::value};
template<typename T> constexpr bool IsUnsigned{std::is_unsigned<T>::value};
template<typename T> constexpr bool IsVoid{std::is_void<T>::value};
template<typename T> constexpr bool IsVolatile{std::is_volatile<T>::value};


//OTHER GETTERS

//template<std::size_t Len, typename... Types> constexpr auto AlignedUnion() noexcept {return std::aligned_union<Len, Types...>::alignment_value;}
template<typename T> constexpr std::size_t AlignmentOf{std::alignment_of<T>::value};
template<typename T, typename U> constexpr bool IsBaseOf{std::is_base_of<T, U>::value};
template<typename T, typename U> constexpr bool IsConvertible{std::is_convertible<T, U>::value};
template<typename T, unsigned N = 0> constexpr std::size_t Extent{std::extent<T, N>::value};
template<typename T, typename U> constexpr bool IsSame{std::is_same<T, U>::value};
template<typename T> constexpr std::size_t Rank{std::rank<T>::value};


//BASIC TYPES

template<typename T> using AddConst = typename std::add_const<T>::type;
template<typename T> using AddCv = typename std::add_cv<T>::type;
template<typename T> using AddLvalueReference = typename std::add_lvalue_reference<T>::type;
template<typename T> using AddPointer = typename std::add_pointer<T>::type;
template<typename T> using AddRvalueReference = typename std::add_rvalue_reference<T>::type;
template<typename T> using AddVolatile = typename std::add_volatile<T>::type;
template<typename T> using MakeSigned = typename std::make_signed<T>::type;
template<typename T> using MakeUnsigned = typename std::make_unsigned<T>::type;
template<typename T> using RemoveAllExtents = typename std::remove_all_extents<T>::type;
template<typename T> using RemoveConst = typename std::remove_const<T>::type;
template<typename T> using RemoveCv = typename std::remove_cv<T>::type;
template<typename T> using RemoveExtent = typename std::remove_extent<T>::type;
template<typename T> using RemovePointer = typename std::remove_pointer<T>::type;
template<typename T> using RemoveReference = typename std::remove_reference<T>::type;
template<typename T> using RemoveVolatile = typename std::remove_volatile<T>::type;


//OTHER TYPES

template<std::size_t Len> using AlignedStorage = typename std::aligned_storage<Len>::type;
template<typename... T> using CommonType = typename std::common_type<T...>::type;
template<bool B, typename T, typename F> using Conditional = typename std::conditional<B, T, F>::type;
template<typename T> using Decay = typename std::decay<T>::type;
template<bool B, typename T = void> using EnableIf = typename std::enable_if<B, T>::type;
template<typename F, typename... ArgTypes> using ResultOf = decltype(std::declval<F>()(std::declval<ArgTypes>()...));
template<typename T> using UnderlyingType = typename std::underlying_type<T>::type;


//ADDED

namespace detail {
    template<typename T> struct IsBothCv : std::integral_constant<bool, std::is_const<T>::value && std::is_volatile<T>::value> {};
    template<typename T> struct IsEitherCv : std::integral_constant<bool, std::is_const<T>::value || std::is_volatile<T>::value> {};
    template<typename T> struct IsNullPointer : std::integral_constant<bool, std::is_same<RemoveCv<T>, std::nullptr_t>::value> {};
}

template<typename T> constexpr bool IsBothCv{detail::IsBothCv<T>::value};
template<typename T> constexpr bool IsEitherCv{detail::IsEitherCv<T>::value};
template<typename T> constexpr bool IsNullPointer{detail::IsNullPointer<T>::value};
template<bool B, typename T = void> using DisableIf = EnableIf<!B, T>;
template<typename T> using Id = T;

namespace detail {
    template<typename T> struct Bare {using type = T;};
    template<typename T> struct Bare<const T> : Bare<RemoveConst<T>> {};
    template<typename T> struct Bare<volatile T> : Bare<RemoveVolatile<T>> {};
    template<typename T> struct Bare<T *> : Bare<RemovePointer<T>> {};
    template<typename T> struct Bare<const T *> : Bare<RemoveConst<RemovePointer<T>>> {};
    template<typename T> struct Bare<volatile T *> : Bare<RemoveVolatile<RemovePointer<T>>> {};
    template<typename T> struct Bare<T &> : Bare<RemoveReference<T>> {};
    template<typename T> struct Bare<T[]> : Bare<RemoveAllExtents<T>> {};
    template<typename T, std::size_t N> struct Bare<T[N]> : Bare<RemoveAllExtents<T>> {};
}

template<typename T> using Bare = typename detail::Bare<T>::type;

}
}

#if STDX_CLANG
    #undef STDX_IS_TRIVIALLY_ASSIGNABLE
#endif

#endif
