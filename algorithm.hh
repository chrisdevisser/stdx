//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

//Wraps standard algorithms to take a container and assume begin() and end().
//Wraps those found in <numeric> as well.
//Overloads provided for built-in arrays.
//Also adds new algorithms.
//Algorithms overloaded with non-const/const versions of the container return Container::iterator and Container::const_iterator respectively.

#ifndef STDX_ALGORITHM_H
#define STDX_ALGORITHM_H

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

//TO ADD ARRAY VERSIONS, NOTEPAD++ REGEX

//Single container:
//template<template<typename...> class Cont, typename... ContArgs(.*)\r\n(.*)Cont<ContArgs...> &cont(.*)
//template<template<typename...> class Cont, typename... ContArgs\1\r\n\2Cont<ContArgs...> &cont\3\r\n\r\ntemplate<typename Type, std::size_t N\1\r\n\2Type\(&cont\)[N]\3
//
//In C::B, no regex
//[N], typename Cont<ContArgs...>::iterator
//[N], Type *
//
//Double container:
//template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args(.*)\r\n(.*)Cont<ContArgs...> &cont, (.*)Cont2<Cont2Args...> &cont2(.*)
//template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args\1\r\n\2Cont<ContArgs...> &cont, \3Cont2<Cont2Args...> &cont2\4\r\n\r\ntemplate<typename Type1, std::size_t N1, typename Type2, std::size_t N2\1\r\n\2Type1\(&cont\)[N1], \3Type2\(&cont2\)[N2]\4
//
//Cleanup:
//Remove non-const overloads of array versions when const exists.
//Remove half-array, half-container overloads

namespace stdx {
inline namespace AlgorithmNs {

//STANDARD ALGORITHM WRAPPERS

//C++14 std::cbegin and std::cend
//C++14 Constraints

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Accumulate(const Cont<ContArgs...> &cont, T &&init) {return std::accumulate(std::begin(cont), std::end(cont), std::move(init));}

template<typename Type, std::size_t N, typename T>
auto Accumulate(const Type(&cont)[N], T &&init) {return std::accumulate(std::begin(cont), std::end(cont), std::move(init));}

template<template<typename...> class Cont, typename... ContArgs, typename T, typename BinaryOperation>
auto Accumulate(const Cont<ContArgs...> &cont, T &&init, BinaryOperation op) {return std::accumulate(std::begin(cont), std::end(cont), std::move(init), op);}

template<typename Type, std::size_t N, typename T, typename BinaryOperation>
auto Accumulate(const Type(&cont)[N], T &&init, BinaryOperation op) {return std::accumulate(std::begin(cont), std::end(cont), std::move(init), op);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator>
auto AdjacentDifference(const Cont<ContArgs...> &cont, OutputIterator first) {return std::adjacent_difference(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename OutputIterator>
auto AdjacentDifference(const Type(&cont)[N], OutputIterator first) {return std::adjacent_difference(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename BinaryOperation>
auto AdjacentDifference(const Cont<ContArgs...> &cont, OutputIterator first, BinaryOperation op) {return std::adjacent_difference(std::begin(cont), std::end(cont), first, op);}

template<typename Type, std::size_t N, typename OutputIterator, typename BinaryOperation>
auto AdjacentDifference(const Type(&cont)[N], OutputIterator first, BinaryOperation op) {return std::adjacent_difference(std::begin(cont), std::end(cont), first, op);}

template<template<typename...> class Cont, typename... ContArgs>
auto AdjacentFind(Cont<ContArgs...> &cont) {return std::adjacent_find(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs>
auto AdjacentFind(const Cont<ContArgs...> &cont) {return std::adjacent_find(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto AdjacentFind(const Type(&cont)[N]) {return std::adjacent_find(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename BinaryPredicate>
auto AdjacentFind(Cont<ContArgs...> &cont, BinaryPredicate p) {return std::adjacent_find(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename BinaryPredicate>
auto AdjacentFind(const Cont<ContArgs...> &cont, BinaryPredicate p) {return std::adjacent_find(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename BinaryPredicate>
auto AdjacentFind(const Type(&cont)[N], BinaryPredicate p) {return std::adjacent_find(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto AllOf(const Cont<ContArgs...> &cont, UnaryPredicate p) {return std::all_of(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto AllOf(const Type(&cont)[N], UnaryPredicate p) {return std::all_of(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto AnyOf(const Cont<ContArgs...> &cont, UnaryPredicate p) {return std::any_of(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto AnyOf(const Type(&cont)[N], UnaryPredicate p) {return std::any_of(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto BinarySearch(const Cont<ContArgs...> &cont, const T &value) {return std::binary_search(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto BinarySearch(const Type(&cont)[N], const T &value) {return std::binary_search(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T, typename Compare>
auto BinarySearch(const Cont<ContArgs...> &cont, const T &value, Compare comp) {return std::binary_search(std::begin(cont), std::end(cont), value, comp);}

template<typename Type, std::size_t N, typename T, typename Compare>
auto BinarySearch(const Type(&cont)[N], const T &value, Compare comp) {return std::binary_search(std::begin(cont), std::end(cont), value, comp);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator>
auto Copy(const Cont<ContArgs...> &cont, OutputIterator first) {return std::copy(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename OutputIterator>
auto Copy(const Type(&cont)[N], OutputIterator first) {return std::copy(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename BidirectionalIterator>
auto CopyBackward(const Cont<ContArgs...> &cont, BidirectionalIterator last) {return std::copy_backward(std::begin(cont), std::end(cont), last);}

template<typename Type, std::size_t N, typename BidirectionalIterator>
auto CopyBackward(const Type(&cont)[N], BidirectionalIterator last) {return std::copy_backward(std::begin(cont), std::end(cont), last);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename UnaryPredicate>
auto CopyIf(const Cont<ContArgs...> &cont, OutputIterator first, UnaryPredicate p) {return std::copy_if(std::begin(cont), std::end(cont), first, p);}

template<typename Type, std::size_t N, typename OutputIterator, typename UnaryPredicate>
auto CopyIf(const Type(&cont)[N], OutputIterator first, UnaryPredicate p) {return std::copy_if(std::begin(cont), std::end(cont), first, p);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Count(const Cont<ContArgs...> &cont, const T &value) {return std::count(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto Count(const Type(&cont)[N], const T &value) {return std::count(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto CountIf(const Cont<ContArgs...> &cont, UnaryPredicate p) {return std::count_if(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto CountIf(const Type(&cont)[N], UnaryPredicate p) {return std::count_if(std::begin(cont), std::end(cont), p);}

//C++14 2 new overloads
template<template<typename...> class Cont, typename... ContArgs, typename InputIterator>
auto Equal(const Cont<ContArgs...> &cont, InputIterator first) {return std::equal(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename InputIterator>
auto Equal(const Type(&cont)[N], InputIterator first) {return std::equal(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename InputIterator, typename BinaryPredicate>
auto Equal(const Cont<ContArgs...> &cont, InputIterator first, BinaryPredicate p) {return std::equal(std::begin(cont), std::end(cont), first, p);}

template<typename Type, std::size_t N, typename InputIterator, typename BinaryPredicate>
auto Equal(const Type(&cont)[N], InputIterator first, BinaryPredicate p) {return std::equal(std::begin(cont), std::end(cont), first, p);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto EqualRange(Cont<ContArgs...> &cont, const T &value) {return std::equal_range(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto EqualRange(const Cont<ContArgs...> &cont, const T &value) {return std::equal_range(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto EqualRange(const Type(&cont)[N], const T &value) {return std::equal_range(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T, typename Compare>
auto EqualRange(Cont<ContArgs...> &cont, const T &value, Compare comp) {return std::equal_range(std::begin(cont), std::end(cont), value, comp);}

template<template<typename...> class Cont, typename... ContArgs, typename T, typename Compare>
auto EqualRange(const Cont<ContArgs...> &cont, const T &value, Compare comp) {return std::equal_range(std::begin(cont), std::end(cont), value, comp);}

template<typename Type, std::size_t N, typename T, typename Compare>
auto EqualRange(const Type(&cont)[N], const T &value, Compare comp) {return std::equal_range(std::begin(cont), std::end(cont), value, comp);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Fill(Cont<ContArgs...> &cont, const T &value) {return std::fill(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto Fill(Type(&cont)[N], const T &value) {return std::fill(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Find(Cont<ContArgs...> &cont, const T &value) {return std::find(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Find(const Cont<ContArgs...> &cont, const T &value) {return std::find(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto Find(const Type(&cont)[N], const T &value) {return std::find(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto FindEnd(Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return std::find_end(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto FindEnd(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return std::find_end(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2>
auto FindEnd(const Type1(&cont)[N1], const Type2(&cont2)[N2]) {return std::find_end(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto FindFirstOf(Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto FindFirstOf(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2>
auto FindFirstOf(const Type1(&cont)[N1], const Type2(&cont2)[N2]) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename BinaryPredicate>
auto FindFirstOf(Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, BinaryPredicate p) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename BinaryPredicate>
auto FindFirstOf(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, BinaryPredicate p) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename BinaryPredicate>
auto FindFirstOf(const Type1(&cont)[N1], const Type2(&cont2)[N2], BinaryPredicate p) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto FindIf(Cont<ContArgs...> &cont, UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto FindIf(const Cont<ContArgs...> &cont, UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto FindIf(const Type(&cont)[N], UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto FindIfNot(Cont<ContArgs...> &cont, UnaryPredicate p) {return std::find_if_not(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto FindIfNot(const Cont<ContArgs...> &cont, UnaryPredicate p) {return std::find_if_not(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto FindIfNot(const Type(&cont)[N], UnaryPredicate p) {return std::find_if_not(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryFunction>
auto ForEach(Cont<ContArgs...> &cont, UnaryFunction f) {return std::for_each(std::begin(cont), std::end(cont), f);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryFunction>
auto ForEach(const Cont<ContArgs...> &cont, UnaryFunction f) {return std::for_each(std::begin(cont), std::end(cont), f);}

template<typename Type, std::size_t N, typename UnaryFunction>
auto ForEach(const Type(&cont)[N], UnaryFunction f) {return std::for_each(std::begin(cont), std::end(cont), f);}

template<template<typename...> class Cont, typename... ContArgs, typename Generator>
auto Generate(Cont<ContArgs...> &cont, Generator g) {return std::generate(std::begin(cont), std::end(cont), g);}

template<typename Type, std::size_t N, typename Generator>
auto Generate(Type(&cont)[N], Generator g) {return std::generate(std::begin(cont), std::end(cont), g);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto Includes(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return std::includes(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2>
auto Includes(const Type1(&cont)[N1], const Type2(&cont2)[N2]) {return std::includes(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename Compare>
auto Includes(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, Compare comp) {return std::includes(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename Compare>
auto Includes(const Type1(&cont)[N1], const Type2(&cont2)[N2], Compare comp) {return std::includes(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename InputIterator, typename T>
auto InnerProduct(const Cont<ContArgs...> &cont, InputIterator first, T &&value) {return std::inner_product(std::begin(cont), std::end(cont), first, std::move(value));}

template<typename Type, std::size_t N, typename InputIterator, typename T>
auto InnerProduct(const Type(&cont)[N], InputIterator first, T &&value) {return std::inner_product(std::begin(cont), std::end(cont), first, std::move(value));}

template<template<typename...> class Cont, typename... ContArgs, typename InputIterator, typename T, typename BinaryOperation1, typename BinaryOperation2>
auto InnerProduct(const Cont<ContArgs...> &cont, InputIterator first, T &&value, BinaryOperation1 op1, BinaryOperation2 op2) {return std::inner_product(std::begin(cont), std::end(cont), first, std::move(value), op1, op2);}

template<typename Type, std::size_t N, typename InputIterator, typename T, typename BinaryOperation1, typename BinaryOperation2>
auto InnerProduct(const Type(&cont)[N], InputIterator first, T &&value, BinaryOperation1 op1, BinaryOperation2 op2) {return std::inner_product(std::begin(cont), std::end(cont), first, std::move(value), op1, op2);}

template<template<typename...> class Cont, typename... ContArgs>
auto InplaceMerge(Cont<ContArgs...> &cont, typename Cont<ContArgs...>::iterator middle) {return std::inplace_merge(std::begin(cont), middle, std::end(cont));}

template<typename Type, std::size_t N>
auto InplaceMerge(Type(&cont)[N], Type *middle) {return std::inplace_merge(std::begin(cont), middle, std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto InplaceMerge(Cont<ContArgs...> &cont, typename Cont<ContArgs...>::iterator middle, Compare comp) {return std::inplace_merge(std::begin(cont), middle, std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto InplaceMerge(Type(&cont)[N], Type *middle, Compare comp) {return std::inplace_merge(std::begin(cont), middle, std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Iota(Cont<ContArgs...> &cont, T &&value) {return std::iota(std::begin(cont), std::end(cont), std::move(value));}

template<typename Type, std::size_t N, typename T>
auto Iota(Type(&cont)[N], T &&value) {return std::iota(std::begin(cont), std::end(cont), std::move(value));}

template<template<typename...> class Cont, typename... ContArgs>
auto IsHeap(const Cont<ContArgs...> &cont) {return std::is_heap(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto IsHeap(const Type(&cont)[N]) {return std::is_heap(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto IsHeap(const Cont<ContArgs...> &cont, Compare comp) {return std::is_heap(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto IsHeap(const Type(&cont)[N], Compare comp) {return std::is_heap(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto IsHeapUntil(Cont<ContArgs...> &cont) {return std::is_heap_until(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs>
auto IsHeapUntil(const Cont<ContArgs...> &cont) {return std::is_heap_until(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto IsHeapUntil(const Type(&cont)[N]) {return std::is_heap_until(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto IsHeapUntil(Cont<ContArgs...> &cont, Compare comp) {return std::is_heap_until(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto IsHeapUntil(const Cont<ContArgs...> &cont, Compare comp) {return std::is_heap_until(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto IsHeapUntil(const Type(&cont)[N], Compare comp) {return std::is_heap_until(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto IsPartitioned(const Cont<ContArgs...> &cont, UnaryPredicate p) {return std::is_partitioned(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto IsPartitioned(const Type(&cont)[N], UnaryPredicate p) {return std::is_partitioned(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename ForwardIterator>
auto IsPermutation(const Cont<ContArgs...> &cont, ForwardIterator first) {return std::is_permutation(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename ForwardIterator>
auto IsPermutation(const Type(&cont)[N], ForwardIterator first) {return std::is_permutation(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename ForwardIterator, typename BinaryPredicate>
auto IsPermutation(const Cont<ContArgs...> &cont, ForwardIterator first, BinaryPredicate p) {return std::is_permutation(std::begin(cont), std::end(cont), first, p);}

template<typename Type, std::size_t N, typename ForwardIterator, typename BinaryPredicate>
auto IsPermutation(const Type(&cont)[N], ForwardIterator first, BinaryPredicate p) {return std::is_permutation(std::begin(cont), std::end(cont), first, p);}

template<template<typename...> class Cont, typename... ContArgs>
auto IsSorted(const Cont<ContArgs...> &cont) {return std::is_sorted(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto IsSorted(const Type(&cont)[N]) {return std::is_sorted(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto IsSorted(const Cont<ContArgs...> &cont, Compare comp) {return std::is_sorted(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto IsSorted(const Type(&cont)[N], Compare comp) {return std::is_sorted(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto IsSortedUntil(Cont<ContArgs...> &cont) {return std::is_sorted_until(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs>
auto IsSortedUntil(const Cont<ContArgs...> &cont) {return std::is_sorted_until(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto IsSortedUntil(const Type(&cont)[N]) {return std::is_sorted_until(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto IsSortedUntil(Cont<ContArgs...> &cont, Compare comp) {return std::is_sorted_until(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto IsSortedUntil(const Cont<ContArgs...> &cont, Compare comp) {return std::is_sorted_until(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto IsSortedUntil(const Type(&cont)[N], Compare comp) {return std::is_sorted_until(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto LexicographicalCompare(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return std::lexicographical_compare(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2>
auto LexicographicalCompare(const Type1(&cont)[N1], const Type2(&cont2)[N2]) {return std::lexicographical_compare(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename Compare>
auto LexicographicalCompare(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, Compare comp) {return std::lexicographical_compare(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename Compare>
auto LexicographicalCompare(const Type1(&cont)[N1], const Type2(&cont2)[N2], Compare comp) {return std::lexicographical_compare(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto LowerBound(Cont<ContArgs...> &cont, const T &value) {return std::lower_bound(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto LowerBound(const Cont<ContArgs...> &cont, const T &value) {return std::lower_bound(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto LowerBound(const Type(&cont)[N], const T &value) {return std::lower_bound(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T, typename Compare>
auto LowerBound(Cont<ContArgs...> &cont, const T &value, Compare comp) {return std::lower_bound(std::begin(cont), std::end(cont), value, comp);}

template<template<typename...> class Cont, typename... ContArgs, typename T, typename Compare>
auto LowerBound(const Cont<ContArgs...> &cont, const T &value, Compare comp) {return std::lower_bound(std::begin(cont), std::end(cont), value, comp);}

template<typename Type, std::size_t N, typename T, typename Compare>
auto LowerBound(const Type(&cont)[N], const T &value, Compare comp) {return std::lower_bound(std::begin(cont), std::end(cont), value, comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto MakeHeap(Cont<ContArgs...> &cont) {return std::make_heap(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto MakeHeap(Type(&cont)[N]) {return std::make_heap(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto MakeHeap(Cont<ContArgs...> &cont, Compare comp) {return std::make_heap(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto MakeHeap(Type(&cont)[N], Compare comp) {return std::make_heap(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto MaxElement(Cont<ContArgs...> &cont) {return std::max_element(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs>
auto MaxElement(const Cont<ContArgs...> &cont) {return std::max_element(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto MaxElement(const Type(&cont)[N]) {return std::max_element(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto MaxElement(Cont<ContArgs...> &cont, Compare comp) {return std::max_element(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto MaxElement(const Cont<ContArgs...> &cont, Compare comp) {return std::max_element(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto MaxElement(const Type(&cont)[N], Compare comp) {return std::max_element(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator>
auto Merge(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first) {return std::merge(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator>
auto Merge(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first) {return std::merge(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator, typename Compare>
auto Merge(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first, Compare comp) {return std::merge(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator, typename Compare>
auto Merge(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first, Compare comp) {return std::merge(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto MinElement(Cont<ContArgs...> &cont) {return std::min_element(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs>
auto MinElement(const Cont<ContArgs...> &cont) {return std::min_element(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto MinElement(const Type(&cont)[N]) {return std::min_element(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto MinElement(Cont<ContArgs...> &cont, Compare comp) {return std::min_element(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto MinElement(const Cont<ContArgs...> &cont, Compare comp) {return std::min_element(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto MinElement(const Type(&cont)[N], Compare comp) {return std::min_element(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto MinmaxElement(Cont<ContArgs...> &cont) {return std::minmax_element(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs>
auto MinmaxElement(const Cont<ContArgs...> &cont) {return std::minmax_element(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto MinmaxElement(const Type(&cont)[N]) {return std::minmax_element(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto MinmaxElement(Cont<ContArgs...> &cont, Compare comp) {return std::minmax_element(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto MinmaxElement(const Cont<ContArgs...> &cont, Compare comp) {return std::minmax_element(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto MinmaxElement(const Type(&cont)[N], Compare comp) {return std::minmax_element(std::begin(cont), std::end(cont), comp);}

//C++14 2 new overloads
template<template<typename...> class Cont, typename... ContArgs, typename InputIterator>
auto Mismatch(Cont<ContArgs...> &cont, InputIterator first) {return std::mismatch(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename InputIterator>
auto Mismatch(const Cont<ContArgs...> &cont, InputIterator first) {return std::mismatch(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename InputIterator>
auto Mismatch(const Type(&cont)[N], InputIterator first) {return std::mismatch(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename InputIterator, typename BinaryPredicate>
auto Mismatch(Cont<ContArgs...> &cont, InputIterator first, BinaryPredicate p) {return std::mismatch(std::begin(cont), std::end(cont), first, p);}

template<template<typename...> class Cont, typename... ContArgs, typename InputIterator, typename BinaryPredicate>
auto Mismatch(const Cont<ContArgs...> &cont, InputIterator first, BinaryPredicate p) {return std::mismatch(std::begin(cont), std::end(cont), first, p);}

template<typename Type, std::size_t N, typename InputIterator, typename BinaryPredicate>
auto Mismatch(const Type(&cont)[N], InputIterator first, BinaryPredicate p) {return std::mismatch(std::begin(cont), std::end(cont), first, p);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator>
auto Move(const Cont<ContArgs...> &cont, OutputIterator first) {return std::move(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename OutputIterator>
auto Move(const Type(&cont)[N], OutputIterator first) {return std::move(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename BidirectionalIterator>
auto MoveBackward(const Cont<ContArgs...> &cont, BidirectionalIterator last) {return std::move_backward(std::begin(cont), std::end(cont), last);}

template<typename Type, std::size_t N, typename BidirectionalIterator>
auto MoveBackward(const Type(&cont)[N], BidirectionalIterator last) {return std::move_backward(std::begin(cont), std::end(cont), last);}

template<template<typename...> class Cont, typename... ContArgs>
auto NextPermutation(Cont<ContArgs...> &cont) {return std::next_permutation(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto NextPermutation(Type(&cont)[N]) {return std::next_permutation(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto NextPermutation(Cont<ContArgs...> &cont, Compare comp) {return std::next_permutation(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto NextPermutation(Type(&cont)[N], Compare comp) {return std::next_permutation(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto NoneOf(const Cont<ContArgs...> &cont, UnaryPredicate p) {return std::none_of(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto NoneOf(const Type(&cont)[N], UnaryPredicate p) {return std::none_of(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs>
auto NthElement(Cont<ContArgs...> &cont, typename Cont<ContArgs...>::iterator nth) {return std::nth_element(std::begin(cont), nth, std::end(cont));}

template<typename Type, std::size_t N>
auto NthElement(Type(&cont)[N], Type *nth) {return std::nth_element(std::begin(cont), nth, std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto NthElement(Cont<ContArgs...> &cont, typename Cont<ContArgs...>::iterator nth, Compare comp) {return std::nth_element(std::begin(cont), nth, std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto NthElement(Type(&cont)[N], Type *nth, Compare comp) {return std::nth_element(std::begin(cont), nth, std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto PartialSort(Cont<ContArgs...> &cont, typename Cont<ContArgs...>::iterator middle) {return std::partial_sort(std::begin(cont), middle, std::end(cont));}

template<typename Type, std::size_t N>
auto PartialSort(Type(&cont)[N], Type *middle) {return std::partial_sort(std::begin(cont), middle, std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto PartialSort(Cont<ContArgs...> &cont, typename Cont<ContArgs...>::iterator middle, Compare comp) {return std::partial_sort(std::begin(cont), middle, std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto PartialSort(Type(&cont)[N], Type *middle, Compare comp) {return std::partial_sort(std::begin(cont), middle, std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto PartialSortCopy(const Cont<ContArgs...> &cont, Cont2<Cont2Args...> &cont2) {return std::partial_sort_copy(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2>
auto PartialSortCopy(const Type1(&cont)[N1], Type2(&cont2)[N2]) {return std::partial_sort_copy(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename Compare>
auto PartialSortCopy(const Cont<ContArgs...> &cont, Cont2<Cont2Args...> &cont2, Compare comp) {return std::partial_sort_copy(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename Compare>
auto PartialSortCopy(const Type1(&cont)[N1], Type2(&cont2)[N2], Compare comp) {return std::partial_sort_copy(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator>
auto PartialSum(const Cont<ContArgs...> &cont, OutputIterator first) {return std::partial_sum(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename OutputIterator>
auto PartialSum(const Type(&cont)[N], OutputIterator first) {return std::partial_sum(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename BinaryOperation>
auto PartialSum(const Cont<ContArgs...> &cont, OutputIterator first, BinaryOperation op) {return std::partial_sum(std::begin(cont), std::end(cont), first, op);}

template<typename Type, std::size_t N, typename OutputIterator, typename BinaryOperation>
auto PartialSum(const Type(&cont)[N], OutputIterator first, BinaryOperation op) {return std::partial_sum(std::begin(cont), std::end(cont), first, op);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto Partition(Cont<ContArgs...> &cont, UnaryPredicate p) {return std::partition(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto Partition(Type(&cont)[N], UnaryPredicate p) {return std::partition(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator1, typename OutputIterator2, typename UnaryPredicate>
auto PartitionCopy(Cont<ContArgs...> &cont, OutputIterator1 first_true, OutputIterator2 first_false, UnaryPredicate p) {return std::partition_copy(std::begin(cont), std::end(cont), first_true, first_false, p);}

template<typename Type, std::size_t N, typename OutputIterator1, typename OutputIterator2, typename UnaryPredicate>
auto PartitionCopy(Type(&cont)[N], OutputIterator1 first_true, OutputIterator2 first_false, UnaryPredicate p) {return std::partition_copy(std::begin(cont), std::end(cont), first_true, first_false, p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto PartitionPoint(Cont<ContArgs...> &cont, UnaryPredicate p) {return std::partition_point(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto PartitionPoint(Type(&cont)[N], UnaryPredicate p) {return std::partition_point(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto PartitionPoint(const Cont<ContArgs...> &cont, UnaryPredicate p) {return std::partition_point(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto PartitionPoint(const Type(&cont)[N], UnaryPredicate p) {return std::partition_point(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs>
auto PopHeap(Cont<ContArgs...> &cont) {return std::pop_heap(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto PopHeap(Type(&cont)[N]) {return std::pop_heap(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto PopHeap(Cont<ContArgs...> &cont, Compare comp) {return std::pop_heap(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto PopHeap(Type(&cont)[N], Compare comp) {return std::pop_heap(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto PrevPermutation(Cont<ContArgs...> &cont) {return std::prev_permutation(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto PrevPermutation(Type(&cont)[N]) {return std::prev_permutation(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto PrevPermutation(Cont<ContArgs...> &cont, Compare comp) {return std::prev_permutation(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto PrevPermutation(Type(&cont)[N], Compare comp) {return std::prev_permutation(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto PushHeap(Cont<ContArgs...> &cont) {return std::push_heap(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto PushHeap(Type(&cont)[N]) {return std::push_heap(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto PushHeap(Cont<ContArgs...> &cont, Compare comp) {return std::push_heap(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto PushHeap(Type(&cont)[N], Compare comp) {return std::push_heap(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto RandomShuffle(Cont<ContArgs...> &cont) {return std::random_shuffle(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto RandomShuffle(Type(&cont)[N]) {return std::random_shuffle(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename RandomNumberGenerator>
auto RandomShuffle(Cont<ContArgs...> &cont, RandomNumberGenerator &&r) {return std::random_shuffle(std::begin(cont), std::end(cont), r);}

template<typename Type, std::size_t N, typename RandomNumberGenerator>
auto RandomShuffle(Type(&cont)[N], RandomNumberGenerator &&r) {return std::random_shuffle(std::begin(cont), std::end(cont), r);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Remove(Cont<ContArgs...> &cont, const T &value) {return std::remove(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto Remove(Type(&cont)[N], const T &value) {return std::remove(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename T>
auto RemoveCopy(Cont<ContArgs...> &cont, OutputIterator first, const T &value) {return std::remove_copy(std::begin(cont), std::end(cont), first, value);}

template<typename Type, std::size_t N, typename OutputIterator, typename T>
auto RemoveCopy(Type(&cont)[N], OutputIterator first, const T &value) {return std::remove_copy(std::begin(cont), std::end(cont), first, value);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename UnaryPredicate>
auto RemoveCopyIf(Cont<ContArgs...> &cont, OutputIterator first, UnaryPredicate p) {return std::remove_copy_if(std::begin(cont), std::end(cont), first, p);}

template<typename Type, std::size_t N, typename OutputIterator, typename UnaryPredicate>
auto RemoveCopyIf(Type(&cont)[N], OutputIterator first, UnaryPredicate p) {return std::remove_copy_if(std::begin(cont), std::end(cont), first, p);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto RemoveIf(Cont<ContArgs...> &cont, UnaryPredicate p) {return std::remove_if(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto RemoveIf(Type(&cont)[N], UnaryPredicate p) {return std::remove_if(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Replace(Cont<ContArgs...> &cont, const T &old_value, const T &new_value) {return std::replace(std::begin(cont), std::end(cont), old_value, new_value);}

template<typename Type, std::size_t N, typename T>
auto Replace(Type(&cont)[N], const T &old_value, const T &new_value) {return std::replace(std::begin(cont), std::end(cont), old_value, new_value);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename T>
auto ReplaceCopy(Cont<ContArgs...> &cont, OutputIterator first, const T &old_value, const T &new_value) {return std::replace_copy(std::begin(cont), std::end(cont), first, old_value, new_value);}

template<typename Type, std::size_t N, typename OutputIterator, typename T>
auto ReplaceCopy(Type(&cont)[N], OutputIterator first, const T &old_value, const T &new_value) {return std::replace_copy(std::begin(cont), std::end(cont), first, old_value, new_value);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename UnaryPredicate, typename T>
auto ReplaceCopyIf(Cont<ContArgs...> &cont, OutputIterator first, UnaryPredicate p, const T &new_value) {return std::replace_copy(std::begin(cont), std::end(cont), first, p, new_value);}

template<typename Type, std::size_t N, typename OutputIterator, typename UnaryPredicate, typename T>
auto ReplaceCopyIf(Type(&cont)[N], OutputIterator first, UnaryPredicate p, const T &new_value) {return std::replace_copy(std::begin(cont), std::end(cont), first, p, new_value);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate, typename T>
auto ReplaceIf(Cont<ContArgs...> &cont, UnaryPredicate p, const T &new_value) {return std::replace_if(std::begin(cont), std::end(cont), p, new_value);}

template<typename Type, std::size_t N, typename UnaryPredicate, typename T>
auto ReplaceIf(Type(&cont)[N], UnaryPredicate p, const T &new_value) {return std::replace_if(std::begin(cont), std::end(cont), p, new_value);}

template<template<typename...> class Cont, typename... ContArgs>
auto Reverse(Cont<ContArgs...> &cont) {return std::reverse(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto Reverse(Type(&cont)[N]) {return std::reverse(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator>
auto ReverseCopy(Cont<ContArgs...> &cont, OutputIterator first) {return std::reverse_copy(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename OutputIterator>
auto ReverseCopy(Type(&cont)[N], OutputIterator first) {return std::reverse_copy(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename ForwardIterator>
auto Rotate(Cont<ContArgs...> &cont, ForwardIterator new_first) {return std::rotate(std::begin(cont), new_first, std::end(cont));}

template<typename Type, std::size_t N, typename ForwardIterator>
auto Rotate(Type(&cont)[N], ForwardIterator new_first) {return std::rotate(std::begin(cont), new_first, std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename ForwardIterator, typename OutputIterator>
auto RotateCopy(Cont<ContArgs...> &cont, ForwardIterator new_first, OutputIterator first) {return std::rotate_copy(std::begin(cont), new_first, std::end(cont), first);}

template<typename Type, std::size_t N, typename ForwardIterator, typename OutputIterator>
auto RotateCopy(Type(&cont)[N], ForwardIterator new_first, OutputIterator first) {return std::rotate_copy(std::begin(cont), new_first, std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto Search(Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto Search(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2>
auto Search(const Type1(&cont)[N1], const Type2(&cont2)[N2]) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename BinaryPredicate>
auto Search(Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, BinaryPredicate p) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename BinaryPredicate>
auto Search(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, BinaryPredicate p) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename BinaryPredicate>
auto Search(const Type1(&cont)[N1], const Type2(&cont2)[N2], BinaryPredicate p) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<template<typename...> class Cont, typename... ContArgs, typename Size, typename T>
auto SearchN(Cont<ContArgs...> &cont, Size count, const T &value) {return std::search_n(std::begin(cont), std::end(cont), count, value);}

template<template<typename...> class Cont, typename... ContArgs, typename Size, typename T>
auto SearchN(const Cont<ContArgs...> &cont, Size count, const T &value) {return std::search_n(std::begin(cont), std::end(cont), count, value);}

template<typename Type, std::size_t N, typename Size, typename T>
auto SearchN(const Type(&cont)[N], Size count, const T &value) {return std::search_n(std::begin(cont), std::end(cont), count, value);}

template<template<typename...> class Cont, typename... ContArgs, typename Size, typename T, typename BinaryPredicate>
auto SearchN(Cont<ContArgs...> &cont, Size count, const T &value, BinaryPredicate p) {return std::search_n(std::begin(cont), std::end(cont), count, value, p);}

template<template<typename...> class Cont, typename... ContArgs, typename Size, typename T, typename BinaryPredicate>
auto SearchN(const Cont<ContArgs...> &cont, Size count, const T &value, BinaryPredicate p) {return std::search_n(std::begin(cont), std::end(cont), count, value, p);}

template<typename Type, std::size_t N, typename Size, typename T, typename BinaryPredicate>
auto SearchN(const Type(&cont)[N], Size count, const T &value, BinaryPredicate p) {return std::search_n(std::begin(cont), std::end(cont), count, value, p);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator>
auto SetDifference(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first) {return std::set_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator>
auto SetDifference(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first) {return std::set_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator, typename Compare>
auto SetDifference(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first, Compare comp) {return std::set_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator, typename Compare>
auto SetDifference(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first, Compare comp) {return std::set_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator>
auto SetIntersection(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first) {return std::set_intersection(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator>
auto SetIntersection(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first) {return std::set_intersection(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator, typename Compare>
auto SetIntersection(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first, Compare comp) {return std::set_intersection(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator, typename Compare>
auto SetIntersection(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first, Compare comp) {return std::set_intersection(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator>
auto SetSymmetricDifference(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first) {return std::set_symmetric_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator>
auto SetSymmetricDifference(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first) {return std::set_symmetric_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator, typename Compare>
auto SetSymmetricDifference(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first, Compare comp) {return std::set_symmetric_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator, typename Compare>
auto SetSymmetricDifference(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first, Compare comp) {return std::set_symmetric_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator>
auto SetUnion(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first) {return std::set_union(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator>
auto SetUnion(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first) {return std::set_union(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename OutputIterator, typename Compare>
auto SetUnion(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, OutputIterator first, Compare comp) {return std::set_union(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename OutputIterator, typename Compare>
auto SetUnion(const Type1(&cont)[N1], const Type2(&cont2)[N2], OutputIterator first, Compare comp) {return std::set_union(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<template<typename...> class Cont, typename... ContArgs, typename UniformRandomNumberGenerator>
auto Shuffle(Cont<ContArgs...> &cont, UniformRandomNumberGenerator &&g) {return std::shuffle(std::begin(cont), std::end(cont), g);}

template<typename Type, std::size_t N, typename UniformRandomNumberGenerator>
auto Shuffle(Type(&cont)[N], UniformRandomNumberGenerator &&g) {return std::shuffle(std::begin(cont), std::end(cont), g);}

template<template<typename...> class Cont, typename... ContArgs>
auto Sort(Cont<ContArgs...> &cont) {return std::sort(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto Sort(Type(&cont)[N]) {return std::sort(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto Sort(Cont<ContArgs...> &cont, Compare comp) {return std::sort(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto Sort(Type(&cont)[N], Compare comp) {return std::sort(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs>
auto SortHeap(Cont<ContArgs...> &cont) {return std::sort_heap(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto SortHeap(Type(&cont)[N]) {return std::sort_heap(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto SortHeap(Cont<ContArgs...> &cont, Compare comp) {return std::sort_heap(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto SortHeap(Type(&cont)[N], Compare comp) {return std::sort_heap(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto StablePartition(Cont<ContArgs...> &cont, UnaryPredicate p) {return std::stable_partition(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto StablePartition(Type(&cont)[N], UnaryPredicate p) {return std::stable_partition(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs>
auto StableSort(Cont<ContArgs...> &cont) {return std::stable_sort(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto StableSort(Type(&cont)[N]) {return std::stable_sort(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename Compare>
auto StableSort(Cont<ContArgs...> &cont, Compare comp) {return std::stable_sort(std::begin(cont), std::end(cont), comp);}

template<typename Type, std::size_t N, typename Compare>
auto StableSort(Type(&cont)[N], Compare comp) {return std::stable_sort(std::begin(cont), std::end(cont), comp);}

template<template<typename...> class Cont, typename... ContArgs, typename ForwardIterator>
auto SwapRanges(Cont<ContArgs...> &cont, ForwardIterator first) {return std::swap_ranges(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename ForwardIterator>
auto SwapRanges(Type(&cont)[N], ForwardIterator first) {return std::swap_ranges(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename UnaryOperation>
auto Transform(const Cont<ContArgs...> &cont, OutputIterator first, UnaryOperation op) {return std::transform(std::begin(cont), std::end(cont), first, op);}

template<typename Type, std::size_t N, typename OutputIterator, typename UnaryOperation>
auto Transform(const Type(&cont)[N], OutputIterator first, UnaryOperation op) {return std::transform(std::begin(cont), std::end(cont), first, op);}

template<template<typename...> class Cont, typename... ContArgs, typename InputIterator, typename OutputIterator, typename BinaryOperation>
auto Transform(const Cont<ContArgs...> &cont, InputIterator firstIn, OutputIterator firstOut, BinaryOperation op) {return std::transform(std::begin(cont), std::end(cont), firstIn, firstOut, op);}

template<typename Type, std::size_t N, typename InputIterator, typename OutputIterator, typename BinaryOperation>
auto Transform(const Type(&cont)[N], InputIterator firstIn, OutputIterator firstOut, BinaryOperation op) {return std::transform(std::begin(cont), std::end(cont), firstIn, firstOut, op);}

template<template<typename...> class Cont, typename... ContArgs>
auto Unique(Cont<ContArgs...> &cont) {return std::unique(std::begin(cont), std::end(cont));}

template<typename Type, std::size_t N>
auto Unique(Type(&cont)[N]) {return std::unique(std::begin(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename BinaryPredicate>
auto Unique(Cont<ContArgs...> &cont, BinaryPredicate p) {return std::unique(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename BinaryPredicate>
auto Unique(Type(&cont)[N], BinaryPredicate p) {return std::unique(std::begin(cont), std::end(cont), p);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator>
auto UniqueCopy(Cont<ContArgs...> &cont, OutputIterator first) {return std::unique_copy(std::begin(cont), std::end(cont), first);}

template<typename Type, std::size_t N, typename OutputIterator>
auto UniqueCopy(Type(&cont)[N], OutputIterator first) {return std::unique_copy(std::begin(cont), std::end(cont), first);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename BinaryPredicate>
auto UniqueCopy(Cont<ContArgs...> &cont, OutputIterator first, BinaryPredicate p) {return std::unique_copy(std::begin(cont), std::end(cont), first, p);}

template<typename Type, std::size_t N, typename OutputIterator, typename BinaryPredicate>
auto UniqueCopy(Type(&cont)[N], OutputIterator first, BinaryPredicate p) {return std::unique_copy(std::begin(cont), std::end(cont), first, p);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto UpperBound(Cont<ContArgs...> &cont, const T &value) {return std::upper_bound(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T>
auto UpperBound(const Cont<ContArgs...> &cont, const T &value) {return std::upper_bound(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto UpperBound(const Type(&cont)[N], const T &value) {return std::upper_bound(std::begin(cont), std::end(cont), value);}

template<template<typename...> class Cont, typename... ContArgs, typename T, typename Compare>
auto UpperBound(Cont<ContArgs...> &cont, const T &value, Compare comp) {return std::upper_bound(std::begin(cont), std::end(cont), value, comp);}

template<template<typename...> class Cont, typename... ContArgs, typename T, typename Compare>
auto UpperBound(const Cont<ContArgs...> &cont, const T &value, Compare comp) {return std::upper_bound(std::begin(cont), std::end(cont), value, comp);}

template<typename Type, std::size_t N, typename T, typename Compare>
auto UpperBound(const Type(&cont)[N], const T &value, Compare comp) {return std::upper_bound(std::begin(cont), std::end(cont), value, comp);}


//NEW OR REFINED ALGORITHMS

//returns true if container has the element or sequence
template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Contains(const Cont<ContArgs...> &cont, const T &value) {return Find(cont, value) != std::end(cont);}

template<typename Type, std::size_t N, typename T>
auto Contains(const Type(&cont)[N], const T &value) {return Find(cont, value) != std::end(cont);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto Contains(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2) {return Search(cont, cont2) != std::end(cont);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2>
auto Contains(const Type1(&cont)[N1], const Type2(&cont2)[N2]) {return Search(cont, cont2) != std::end(cont);}

template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args, typename BinaryPredicate>
auto Contains(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &cont2, BinaryPredicate p) {return Search(cont, cont2, p) != std::end(cont);}

template<typename Type1, std::size_t N1, typename Type2, std::size_t N2, typename BinaryPredicate>
auto Contains(const Type1(&cont)[N1], const Type2(&cont2)[N2], BinaryPredicate p) {return Search(cont, cont2, p) != std::end(cont);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto ContainsIf(const Cont<ContArgs...> &cont, UnaryPredicate p) {return FindIf(cont, p) != std::end(cont);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto ContainsIf(const Type(&cont)[N], UnaryPredicate p) {return FindIf(cont, p) != std::end(cont);}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto ContainsIfNot(const Cont<ContArgs...> &cont, UnaryPredicate p) {return FindIfNot(cont, p) != std::end(cont);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto ContainsIfNot(const Type(&cont)[N], UnaryPredicate p) {return FindIfNot(cont, p) != std::end(cont);}

//employs the erase-remove idiom
template<template<typename...> class Cont, typename... ContArgs, typename T>
auto EraseRemove(Cont<ContArgs...> &cont, const T &value) {return cont.erase(Remove(cont, value), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename T>
auto EraseRemoveCopy(Cont<ContArgs...> &cont, OutputIterator first, const T &value) {return cont.erase(RemoveCopy(cont, first, value), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename UnaryPredicate>
auto EraseRemoveCopyIf(Cont<ContArgs...> &cont, OutputIterator first, UnaryPredicate p) {return cont.erase(RemoveCopyIf(cont, first, p), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename UnaryPredicate>
auto EraseRemoveIf(Cont<ContArgs...> &cont, UnaryPredicate p) {return cont.erase(RemoveIf(cont, p), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs>
auto EraseUnique(Cont<ContArgs...> &cont) {return cont.erase(Unique(cont), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename BinaryPredicate>
auto EraseUnique(Cont<ContArgs...> &cont, BinaryPredicate p) {return cont.erase(Unique(cont, p), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator>
auto EraseUniqueCopy(Cont<ContArgs...> &cont, OutputIterator first) {return cont.erase(UniqueCopy(cont, first), std::end(cont));}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename BinaryPredicate>
auto EraseUniqueCopy(Cont<ContArgs...> &cont, OutputIterator first, BinaryPredicate p) {return cont.erase(UniqueCopy(cont, first, p), std::end(cont));}

//returns specified container with increasing values
template<template<typename...> class Cont, typename T>
auto Iota(std::size_t N, T &&value) {Cont<T> temp(N); Iota(temp, std::move(value)); return temp;}

//returns maximum of two objects of any type at compile time
template<typename T, typename U>
constexpr auto Max(T &&t, U &&u) noexcept {return t > u ? t : u;}

//returns maximum of two or more objects of any type at compile time
template<typename Head, typename Head2, typename... Tail>
constexpr auto Max(Head &&head, Head2 &&head2, Tail&&... tail) noexcept {return Max(std::forward<Head>(head), Max(std::forward<Head2>(head2), std::forward<Tail>(tail)...));}

//returns minimum of two objects of any type at compile time
template<typename T, typename U>
constexpr auto Min(T &&t, U &&u) noexcept {return t < u ? t : u;}

//returns minimum of two or more objects of any type at compile time
template<typename Head, typename Head2, typename... Tail>
constexpr auto Min(Head &&head, Head2 &&head2, Tail&&... tail) noexcept {return Min(std::forward<Head>(head), Min(std::forward<Head2>(head2), std::forward<Tail>(tail)...));}

//returns minimum and maximum of two objects of any type at compile time
template<typename T, typename U>
constexpr auto MinMax(T &&t, U &&u) noexcept {return std::make_pair(Min(t, u), Max(t, u));}

//returns minimum and maximum of an object and a pair of minimum and maximum
template<typename T, typename P1, typename P2>
constexpr auto MinMax(T &&t, std::pair<P1, P2> &&p) noexcept {return std::make_pair(Min(t, p.first), p.second);}

//returns minimum and maximum of two or more objects of any type at compile time
template<typename Head, typename Head2, typename... Tail>
constexpr auto MinMax(Head &&head, Head2 &&head2, Tail&&... tail) noexcept {return MinMax(std::forward<Head>(head), MinMax(std::forward<Head2>(head2), std::forward<Tail>(tail)...));}

//replaces all values in a container with a value of a different type
template<template<typename...> class Cont, typename... ContArgs, typename T, typename U>
auto Replace(Cont<ContArgs...> &cont, const T &old_value, const U &new_value) {return std::replace_if(std::begin(cont), std::end(cont), [&](const T &elem) {return elem == old_value;}, new_value);}

template<typename Type, std::size_t N, typename T, typename U>
auto Replace(Type(&cont)[N], const T &old_value, const U &new_value) {return std::replace_if(std::begin(cont), std::end(cont), [&](const T &elem) {return elem == old_value;}, new_value);}

template<template<typename...> class Cont, typename... ContArgs, typename OutputIterator, typename T, typename U>
auto ReplaceCopy(Cont<ContArgs...> &cont, OutputIterator first, const T &old_value, const U &new_value) {return std::replace_copy_if(std::begin(cont), std::end(cont), first, [&](const T &elem) {return elem == old_value;}, new_value);}

template<typename Type, std::size_t N, typename OutputIterator, typename T, typename U>
auto ReplaceCopy(Type(&cont)[N], OutputIterator first, const T &old_value, const U &new_value) {return std::replace_copy_if(std::begin(cont), std::end(cont), first, [&](const T &elem) {return elem == old_value;}, new_value);}

//returns the size of a container
template<template<typename...> class Cont, typename... ContArgs>
auto Size(const Cont<ContArgs...> &cont) noexcept {return cont.size();}

//returns the size of an array
template<typename Type, std::size_t N>
constexpr auto Size(const Type(&)[N]) noexcept {return N;}

//returns a vector of sub-containers made from parts in between the split element
template<template<typename...> class Cont, typename... ContArgs, typename T>
auto Split(const Cont<ContArgs...> &cont, const T &value) {
    std::vector<Cont<ContArgs...>> temp;

    for (auto it(std::begin(cont)), last(it);; std::advance(it, 1), last = it) {
        it = std::find(it, std::end(cont), value);
        temp.emplace_back(last, it);
        if (it == std::end(cont)) break;
    }

    return temp;
}

//Split with the split element being a sequence
template<template<typename...> class Cont, typename... ContArgs, template<typename...> class Cont2, typename... Cont2Args>
auto Split(const Cont<ContArgs...> &cont, const Cont2<Cont2Args...> &values) {
    std::vector<Cont<ContArgs...>> temp;

    for (auto it(std::begin(cont)), last(it);; std::advance(it, Size(values)), last = it) {
        it = std::search(it, std::end(cont), std::begin(values), std::end(values));
        temp.emplace_back(last, it);
        if (it == std::end(cont)) break;
    }

    return temp;
}

}
}

#endif
