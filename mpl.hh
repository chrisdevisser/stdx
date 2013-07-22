//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

//Wraps type traits for easier use, plus adds more.

#ifndef STDX_MPL_H
#define STDX_MPL_H

#include <cstddef>
#include <type_traits>

namespace stdx {
inline namespace MplNs {

//C++14 variable templates

//BOOLEAN CONSTANTS

template<typename T> constexpr auto HasVirtualDestructor() noexcept {return std::has_virtual_destructor<T>::value;}
template<typename T> constexpr auto IsAbstract() noexcept {return std::is_abstract<T>::value;}
template<typename T> constexpr auto IsArithmetic() noexcept {return std::is_arithmetic<T>::value;}
template<typename T> constexpr auto IsArray() noexcept {return std::is_array<T>::value;}
template<typename T, typename U> constexpr auto IsAssignable() noexcept {return std::is_assignable<T, U>::value;}
template<typename T> constexpr auto IsClass() noexcept {return std::is_class<T>::value;}
template<typename T> constexpr auto IsCompound() noexcept {return std::is_compound<T>::value;}
template<typename T> constexpr auto IsConst() noexcept {return std::is_const<T>::value;}
template<typename T> constexpr auto IsConstructible() noexcept {return std::is_constructible<T>::value;}
template<typename T> constexpr auto IsCopyAssignable() noexcept {return std::is_copy_assignable<T>::value;}
template<typename T> constexpr auto IsCopyConstructible() noexcept {return std::is_copy_constructible<T>::value;}
template<typename T> constexpr auto IsDefaultConstructible() noexcept {return std::is_default_constructible<T>::value;}
template<typename T> constexpr auto IsDestructible() noexcept {return std::is_destructible<T>::value;}
template<typename T> constexpr auto IsEmpty() noexcept {return std::is_empty<T>::value;}
template<typename T> constexpr auto IsEnum() noexcept {return std::is_enum<T>::value;}
template<typename T> constexpr auto IsFloatingPoint() noexcept {return std::is_floating_point<T>::value;}
template<typename T> constexpr auto IsFunction() noexcept {return std::is_function<T>::value;}
template<typename T> constexpr auto IsFundamental() noexcept {return std::is_fundamental<T>::value;}
template<typename T> constexpr auto IsIntegral() noexcept {return std::is_integral<T>::value;}
template<typename T> constexpr auto IsLiteralType() noexcept {return std::is_literal_type<T>::value;}
template<typename T> constexpr auto IsLvalueReference() noexcept {return std::is_lvalue_reference<T>::value;}
template<typename T> constexpr auto IsMemberFunctionPointer() noexcept {return std::is_member_function_pointer<T>::value;}
template<typename T> constexpr auto IsMemberObjectPointer() noexcept {return std::is_member_object_pointer<T>::value;}
template<typename T> constexpr auto IsMemberPointer() noexcept {return std::is_member_pointer<T>::value;}
template<typename T> constexpr auto IsMoveAssignable() noexcept {return std::is_move_assignable<T>::value;}
template<typename T> constexpr auto IsMoveConstructible() noexcept {return std::is_move_constructible<T>::value;}
template<typename T, typename U> constexpr auto IsNothrowAssignable() noexcept {return std::is_nothrow_assignable<T, U>::value;}
template<typename T> constexpr auto IsNothrowConstructible() noexcept {return std::is_nothrow_constructible<T>::value;}
template<typename T> constexpr auto IsNothrowCopyAssignable() noexcept {return std::is_nothrow_copy_assignable<T>::value;}
template<typename T> constexpr auto IsNothrowCopyConstructible() noexcept {return std::is_nothrow_copy_constructible<T>::value;}
template<typename T> constexpr auto IsNothrowDefaultConstructible() noexcept {return std::is_nothrow_default_constructible<T>::value;}
template<typename T> constexpr auto IsNothrowDestructible() noexcept {return std::is_nothrow_destructible<T>::value;}
template<typename T> constexpr auto IsNothrowMoveAssignable() noexcept {return std::is_nothrow_move_assignable<T>::value;}
template<typename T> constexpr auto IsNothrowMoveConstructible() noexcept {return std::is_nothrow_move_constructible<T>::value;}
template<typename T> constexpr auto IsObject() noexcept {return std::is_object<T>::value;}
template<typename T> constexpr auto IsPod() noexcept {return std::is_pod<T>::value;}
template<typename T> constexpr auto IsPointer() noexcept {return std::is_pointer<T>::value;}
template<typename T> constexpr auto IsPolymorphic() noexcept {return std::is_polymorphic<T>::value;}
template<typename T> constexpr auto IsReference() noexcept {return std::is_reference<T>::value;}
template<typename T> constexpr auto IsRvalueReference() noexcept {return std::is_rvalue_reference<T>::value;}
template<typename T> constexpr auto IsScalar() noexcept {return std::is_scalar<T>::value;}
template<typename T> constexpr auto IsSigned() noexcept {return std::is_signed<T>::value;}
template<typename T> constexpr auto IsStandardLayout() noexcept {return std::is_standard_layout<T>::value;}
template<typename T> constexpr auto IsTrivial() noexcept {return std::is_trivial<T>::value;}
//template<typename T, typename U> constexpr auto IsTriviallyAssignable() noexcept {return std::is_trivially_assignable<T, U>::value;}
//template<typename T> constexpr auto IsTriviallyConstructible() noexcept {return std::is_trivially_constructible<T>::value;}
//template<typename T> constexpr auto IsTriviallyCopyAssignable() noexcept {return std::is_trivially_copy_assignable<T>::value;}
//template<typename T> constexpr auto IsTriviallyCopyable() noexcept {return std::is_trivially_copyable<T>::value;}
//template<typename T> constexpr auto IsTriviallyCopyConstructible() noexcept {return std::is_trivially_copy_constructible<T>::value;}
//template<typename T> constexpr auto IsTriviallyDefaultConstructible() noexcept {return std::is_trivially_default_constructible<T>::value;}
template<typename T> constexpr auto IsTriviallyDestructible() noexcept {return std::is_trivially_destructible<T>::value;}
//template<typename T> constexpr auto IsTriviallyMoveAssignable() noexcept {return std::is_trivially_move_assignable<T>::value;}
//template<typename T> constexpr auto IsTriviallyMoveConstructible() noexcept {return std::is_trivially_move_constructible<T>::value;}
template<typename T> constexpr auto IsUnion() noexcept {return std::is_union<T>::value;}
template<typename T> constexpr auto IsUnsigned() noexcept {return std::is_unsigned<T>::value;}
template<typename T> constexpr auto IsVoid() noexcept {return std::is_void<T>::value;}
template<typename T> constexpr auto IsVolatile() noexcept {return std::is_volatile<T>::value;}


//OTHER GETTERS

//template<std::size_t Len, typename... Types> constexpr auto AlignedUnion() noexcept {return std::aligned_union<Len, Types...>::alignment_value;}
template<typename T> constexpr auto AlignmentOf() noexcept {return std::alignment_of<T>::value;}
template<typename T, typename U> constexpr auto IsBaseOf() noexcept {return std::is_base_of<T, U>::value;}
template<typename T, typename U> constexpr auto IsConvertible() noexcept {return std::is_convertible<T, U>::value;}
template<typename T, unsigned N = 0> constexpr auto Extent() noexcept {return std::extent<T, N>::value;}
template<typename T, typename U> constexpr auto IsSame() noexcept {return std::is_same<T, U>::value;}
template<typename T> constexpr auto Rank() noexcept {return std::rank<T>::value;}


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

template<typename T> constexpr auto IsBothCv() noexcept {return IsConst<T>() && IsVolatile<T>();}
template<typename T> constexpr auto IsEitherCv() noexcept {return IsConst<T>() || IsVolatile<T>();}
template<bool B, typename T = void> using DisableIf = EnableIf<!B, T>;
template<typename T> using Id = T;

namespace detail {
    template<typename T> struct Bare {using type = T;};
    template<typename T> struct Bare<const T> {using type = typename Bare<RemoveConst<T>>::type;};
    template<typename T> struct Bare<volatile T> {using type = typename Bare<RemoveVolatile<T>>::type;};
    template<typename T> struct Bare<T *> {using type = typename Bare<RemovePointer<T>>::type;};
    template<typename T> struct Bare<const T *> {using type = typename Bare<RemoveConst<RemovePointer<T>>>::type;};
    template<typename T> struct Bare<volatile T *> {using type = typename Bare<RemoveVolatile<RemovePointer<T>>>::type;};
    template<typename T> struct Bare<T &> {using type = typename Bare<RemoveReference<T>>::type;};
    template<typename T> struct Bare<T[]> {using type = typename Bare<RemoveAllExtents<T>>::type;};
    template<typename T, std::size_t N> struct Bare<T[N]> {using type = typename Bare<RemoveAllExtents<T>>::type;};
}

template<typename T> using Bare = typename detail::Bare<T>::type;

}
}

#endif
