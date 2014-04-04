//Due for redo using proper ranges and file splitting

//Wraps standard algorithms to take a container and assume begin() and end().
//Wraps those found in <numeric> as well.
//Work with built-in arrays.
//Also adds new algorithms.
//Algorithms overloaded with non-const/const versions of the container return Container::iterator and Container::const_iterator respectively.

#pragma once

#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

namespace stdx {
inline namespace algo {

//STANDARD ALGORITHM WRAPPERS

//C++14 std::cbegin and std::cend
//C++14 Constraints

template<typename Cont, typename T>
auto accumulate(const Cont &cont, T &&init) {return std::accumulate(std::begin(cont), std::end(cont), std::move(init));}

template<typename Cont, typename T, typename BinaryOperation>
auto accumulate(const Cont &cont, T &&init, BinaryOperation op) {return std::accumulate(std::begin(cont), std::end(cont), std::move(init), op);}

template<typename Cont, typename OutputIterator>
auto adjacentDifference(const Cont &cont, OutputIterator first) {return std::adjacent_difference(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename OutputIterator, typename BinaryOperation>
auto adjacentDifference(const Cont &cont, OutputIterator first, BinaryOperation op) {return std::adjacent_difference(std::begin(cont), std::end(cont), first, op);}

template<typename Cont>
auto adjacentFind(Cont &cont) {return std::adjacent_find(std::begin(cont), std::end(cont));}

template<typename Cont>
auto adjacentFind(const Cont &cont) {return std::adjacent_find(std::begin(cont), std::end(cont));}

template<typename Cont, typename BinaryPredicate>
auto adjacentFind(Cont &cont, BinaryPredicate p) {return std::adjacent_find(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename BinaryPredicate>
auto adjacentFind(const Cont &cont, BinaryPredicate p) {return std::adjacent_find(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto allOf(const Cont &cont, UnaryPredicate p) {return std::all_of(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto anyOf(const Cont &cont, UnaryPredicate p) {return std::any_of(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto anyOf(const Type(&cont)[N], UnaryPredicate p) {return std::any_of(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename T>
auto binarySearch(const Cont &cont, const T &value) {return std::binary_search(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto binarySearch(const Type(&cont)[N], const T &value) {return std::binary_search(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T, typename Compare>
auto binarySearch(const Cont &cont, const T &value, Compare comp) {return std::binary_search(std::begin(cont), std::end(cont), value, comp);}

template<typename Type, std::size_t N, typename T, typename Compare>
auto binarySearch(const Type(&cont)[N], const T &value, Compare comp) {return std::binary_search(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename OutputIterator>
auto copy(const Cont &cont, OutputIterator first) {return std::copy(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename BidirectionalIterator>
auto copyBackward(const Cont &cont, BidirectionalIterator last) {return std::copy_backward(std::begin(cont), std::end(cont), last);}

template<typename Cont, typename OutputIterator, typename UnaryPredicate>
auto copyIf(const Cont &cont, OutputIterator first, UnaryPredicate p) {return std::copy_if(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename T>
auto count(const Cont &cont, const T &value) {return std::count(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename UnaryPredicate>
auto countIf(const Cont &cont, UnaryPredicate p) {return std::count_if(std::begin(cont), std::end(cont), p);}

//C++14 2 new overloads
template<typename Cont, typename InputIterator>
auto equal(const Cont &cont, InputIterator first) {return std::equal(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename InputIterator, typename BinaryPredicate>
auto equal(const Cont &cont, InputIterator first, BinaryPredicate p) {return std::equal(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename T>
auto equalRange(Cont &cont, const T &value) {return std::equal_range(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto equalRange(const Cont &cont, const T &value) {return std::equal_range(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T, typename Compare>
auto equalRange(Cont &cont, const T &value, Compare comp) {return std::equal_range(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename T, typename Compare>
auto equalRange(const Cont &cont, const T &value, Compare comp) {return std::equal_range(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename T>
auto fill(Cont &cont, const T &value) {return std::fill(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto find(Cont &cont, const T &value) {return std::find(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto find(const Cont &cont, const T &value) {return std::find(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename Cont2>
auto findEnd(Cont &cont, const Cont2 &cont2) {return std::find_end(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2>
auto findEnd(const Cont &cont, const Cont2 &cont2) {return std::find_end(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2>
auto findFirstOf(Cont &cont, const Cont2 &cont2) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2>
auto findFirstOf(const Cont &cont, const Cont2 &cont2) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto findFirstOf(Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto findFirstOf(const Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Cont, typename UnaryPredicate>
auto findIf(Cont &cont, UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto findIf(const Cont &cont, UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto findIf(const Type(&cont)[N], UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto findIfNot(Cont &cont, UnaryPredicate p) {return std::find_if_not(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto findIfNot(const Cont &cont, UnaryPredicate p) {return std::find_if_not(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryFunction>
auto forEach(Cont &cont, UnaryFunction f) {return std::for_each(std::begin(cont), std::end(cont), f);}

template<typename Cont, typename UnaryFunction>
auto forEach(const Cont &cont, UnaryFunction f) {return std::for_each(std::begin(cont), std::end(cont), f);}

template<typename Cont, typename Generator>
auto generate(Cont &cont, Generator g) {return std::generate(std::begin(cont), std::end(cont), g);}

template<typename Cont, typename Cont2>
auto includes(const Cont &cont, const Cont2 &cont2) {return std::includes(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename Compare>
auto includes(const Cont &cont, const Cont2 &cont2, Compare comp) {return std::includes(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Cont, typename InputIterator, typename T>
auto innerProduct(const Cont &cont, InputIterator first, T &&value) {return std::inner_product(std::begin(cont), std::end(cont), first, std::move(value));}

template<typename Cont, typename InputIterator, typename T, typename BinaryOperation1, typename BinaryOperation2>
auto innerProduct(const Cont &cont, InputIterator first, T &&value, BinaryOperation1 op1, BinaryOperation2 op2) {return std::inner_product(std::begin(cont), std::end(cont), first, std::move(value), op1, op2);}

template<typename Cont>
auto inplaceMerge(Cont &cont, typename Cont::iterator middle) {return std::inplace_merge(std::begin(cont), middle, std::end(cont));}

template<typename Cont, typename Compare>
auto inplaceMerge(Cont &cont, typename Cont::iterator middle, Compare comp) {return std::inplace_merge(std::begin(cont), middle, std::end(cont), comp);}

template<typename Cont, typename T>
auto iota(Cont &cont, T &&value) {return std::iota(std::begin(cont), std::end(cont), std::move(value));}

template<typename Cont>
auto isHeap(const Cont &cont) {return std::is_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto isHeap(const Cont &cont, Compare comp) {return std::is_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto isHeapUntil(Cont &cont) {return std::is_heap_until(std::begin(cont), std::end(cont));}

template<typename Cont>
auto isHeapUntil(const Cont &cont) {return std::is_heap_until(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto isHeapUntil(Cont &cont, Compare comp) {return std::is_heap_until(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto isHeapUntil(const Cont &cont, Compare comp) {return std::is_heap_until(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename UnaryPredicate>
auto isPartitioned(const Cont &cont, UnaryPredicate p) {return std::is_partitioned(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename ForwardIterator>
auto isPermutation(const Cont &cont, ForwardIterator first) {return std::is_permutation(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename ForwardIterator, typename BinaryPredicate>
auto isPermutation(const Cont &cont, ForwardIterator first, BinaryPredicate p) {return std::is_permutation(std::begin(cont), std::end(cont), first, p);}

template<typename Cont>
auto isSorted(const Cont &cont) {return std::is_sorted(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto isSorted(const Cont &cont, Compare comp) {return std::is_sorted(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto isSortedUntil(Cont &cont) {return std::is_sorted_until(std::begin(cont), std::end(cont));}

template<typename Cont>
auto isSortedUntil(const Cont &cont) {return std::is_sorted_until(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto isSortedUntil(Cont &cont, Compare comp) {return std::is_sorted_until(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto isSortedUntil(const Cont &cont, Compare comp) {return std::is_sorted_until(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Cont2>
auto lexicographicalCompare(const Cont &cont, const Cont2 &cont2) {return std::lexicographical_compare(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename Compare>
auto lexicographicalCompare(const Cont &cont, const Cont2 &cont2, Compare comp) {return std::lexicographical_compare(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Cont, typename T>
auto lowerBound(Cont &cont, const T &value) {return std::lower_bound(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto lowerBound(const Cont &cont, const T &value) {return std::lower_bound(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T, typename Compare>
auto lowerBound(Cont &cont, const T &value, Compare comp) {return std::lower_bound(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename T, typename Compare>
auto lowerBound(const Cont &cont, const T &value, Compare comp) {return std::lower_bound(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont>
auto makeHeap(Cont &cont) {return std::make_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto makeHeap(Cont &cont, Compare comp) {return std::make_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto maxElement(Cont &cont) {return std::max_element(std::begin(cont), std::end(cont));}

template<typename Cont>
auto maxElement(const Cont &cont) {return std::max_element(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto maxElement(Cont &cont, Compare comp) {return std::max_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto maxElement(const Cont &cont, Compare comp) {return std::max_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto merge(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::merge(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto merge(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::merge(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont>
auto minElement(Cont &cont) {return std::min_element(std::begin(cont), std::end(cont));}

template<typename Cont>
auto minElement(const Cont &cont) {return std::min_element(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto minElement(Cont &cont, Compare comp) {return std::min_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto minElement(const Cont &cont, Compare comp) {return std::min_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto minmaxElement(Cont &cont) {return std::minmax_element(std::begin(cont), std::end(cont));}

template<typename Cont>
auto minmaxElement(const Cont &cont) {return std::minmax_element(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto minmaxElement(Cont &cont, Compare comp) {return std::minmax_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto minmaxElement(const Cont &cont, Compare comp) {return std::minmax_element(std::begin(cont), std::end(cont), comp);}

//C++14 2 new overloads
template<typename Cont, typename InputIterator>
auto mismatch(Cont &cont, InputIterator first) {return std::mismatch(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename InputIterator>
auto mismatch(const Cont &cont, InputIterator first) {return std::mismatch(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename InputIterator, typename BinaryPredicate>
auto mismatch(Cont &cont, InputIterator first, BinaryPredicate p) {return std::mismatch(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename InputIterator, typename BinaryPredicate>
auto mismatch(const Cont &cont, InputIterator first, BinaryPredicate p) {return std::mismatch(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename OutputIterator>
auto move(const Cont &cont, OutputIterator first) {return std::move(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename BidirectionalIterator>
auto moveBackward(const Cont &cont, BidirectionalIterator last) {return std::move_backward(std::begin(cont), std::end(cont), last);}

template<typename Cont>
auto nextPermutation(Cont &cont) {return std::next_permutation(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto nextPermutation(Cont &cont, Compare comp) {return std::next_permutation(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename UnaryPredicate>
auto noneOf(const Cont &cont, UnaryPredicate p) {return std::none_of(std::begin(cont), std::end(cont), p);}

template<typename Cont>
auto nthElement(Cont &cont, typename Cont::iterator nth) {return std::nth_element(std::begin(cont), nth, std::end(cont));}

template<typename Cont, typename Compare>
auto nthElement(Cont &cont, typename Cont::iterator nth, Compare comp) {return std::nth_element(std::begin(cont), nth, std::end(cont), comp);}

template<typename Cont>
auto partialSort(Cont &cont, typename Cont::iterator middle) {return std::partial_sort(std::begin(cont), middle, std::end(cont));}

template<typename Cont, typename Compare>
auto partialSort(Cont &cont, typename Cont::iterator middle, Compare comp) {return std::partial_sort(std::begin(cont), middle, std::end(cont), comp);}

template<typename Cont, typename Cont2>
auto partialSortCopy(const Cont &cont, Cont2 &cont2) {return std::partial_sort_copy(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename Compare>
auto partialSortCopy(const Cont &cont, Cont2 &cont2, Compare comp) {return std::partial_sort_copy(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Cont, typename OutputIterator>
auto partialSum(const Cont &cont, OutputIterator first) {return std::partial_sum(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename OutputIterator, typename BinaryOperation>
auto partialSum(const Cont &cont, OutputIterator first, BinaryOperation op) {return std::partial_sum(std::begin(cont), std::end(cont), first, op);}

template<typename Cont, typename UnaryPredicate>
auto partition(Cont &cont, UnaryPredicate p) {return std::partition(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename OutputIterator1, typename OutputIterator2, typename UnaryPredicate>
auto partitionCopy(Cont &cont, OutputIterator1 first_true, OutputIterator2 first_false, UnaryPredicate p) {return std::partition_copy(std::begin(cont), std::end(cont), first_true, first_false, p);}

template<typename Cont, typename UnaryPredicate>
auto partitionPoint(Cont &cont, UnaryPredicate p) {return std::partition_point(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto partitionPoint(const Cont &cont, UnaryPredicate p) {return std::partition_point(std::begin(cont), std::end(cont), p);}

template<typename Cont>
auto popHeap(Cont &cont) {return std::pop_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto popHeap(Cont &cont, Compare comp) {return std::pop_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto prevPermutation(Cont &cont) {return std::prev_permutation(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto prevPermutation(Cont &cont, Compare comp) {return std::prev_permutation(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto pushHeap(Cont &cont) {return std::push_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto pushHeap(Cont &cont, Compare comp) {return std::push_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto randomShuffle(Cont &cont) {return std::random_shuffle(std::begin(cont), std::end(cont));}

template<typename Cont, typename RandomNumberGenerator>
auto randomShuffle(Cont &cont, RandomNumberGenerator &&r) {return std::random_shuffle(std::begin(cont), std::end(cont), r);}

template<typename Cont, typename T>
auto remove(Cont &cont, const T &value) {return std::remove(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename OutputIterator, typename T>
auto removeCopy(Cont &cont, OutputIterator first, const T &value) {return std::remove_copy(std::begin(cont), std::end(cont), first, value);}

template<typename Cont, typename OutputIterator, typename UnaryPredicate>
auto removeCopyIf(Cont &cont, OutputIterator first, UnaryPredicate p) {return std::remove_copy_if(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename UnaryPredicate>
auto removeIf(Cont &cont, UnaryPredicate p) {return std::remove_if(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename T>
auto replace(Cont &cont, const T &old_value, const T &new_value) {return std::replace(std::begin(cont), std::end(cont), old_value, new_value);}

template<typename Cont, typename OutputIterator, typename T>
auto replaceCopy(Cont &cont, OutputIterator first, const T &old_value, const T &new_value) {return std::replace_copy(std::begin(cont), std::end(cont), first, old_value, new_value);}

template<typename Cont, typename OutputIterator, typename UnaryPredicate, typename T>
auto replaceCopyIf(Cont &cont, OutputIterator first, UnaryPredicate p, const T &new_value) {return std::replace_copy(std::begin(cont), std::end(cont), first, p, new_value);}

template<typename Cont, typename UnaryPredicate, typename T>
auto replaceIf(Cont &cont, UnaryPredicate p, const T &new_value) {return std::replace_if(std::begin(cont), std::end(cont), p, new_value);}

template<typename Cont>
auto reverse(Cont &cont) {return std::reverse(std::begin(cont), std::end(cont));}

template<typename Cont, typename OutputIterator>
auto reverseCopy(Cont &cont, OutputIterator first) {return std::reverse_copy(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename ForwardIterator>
auto rotate(Cont &cont, ForwardIterator new_first) {return std::rotate(std::begin(cont), new_first, std::end(cont));}

template<typename Cont, typename ForwardIterator, typename OutputIterator>
auto rotateCopy(Cont &cont, ForwardIterator new_first, OutputIterator first) {return std::rotate_copy(std::begin(cont), new_first, std::end(cont), first);}

template<typename Cont, typename Cont2>
auto search(Cont &cont, const Cont2 &cont2) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2>
auto search(const Cont &cont, const Cont2 &cont2) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto search(Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto search(const Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Cont, typename Size, typename T>
auto searchN(Cont &cont, Size count, const T &value) {return std::search_n(std::begin(cont), std::end(cont), count, value);}

template<typename Cont, typename Size, typename T>
auto searchN(const Cont &cont, Size count, const T &value) {return std::search_n(std::begin(cont), std::end(cont), count, value);}

template<typename Cont, typename Size, typename T, typename BinaryPredicate>
auto searchN(Cont &cont, Size count, const T &value, BinaryPredicate p) {return std::search_n(std::begin(cont), std::end(cont), count, value, p);}

template<typename Cont, typename Size, typename T, typename BinaryPredicate>
auto searchN(const Cont &cont, Size count, const T &value, BinaryPredicate p) {return std::search_n(std::begin(cont), std::end(cont), count, value, p);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto setDifference(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::set_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto setDifference(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::set_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto setIntersection(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::set_intersection(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto setIntersection(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::set_intersection(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto setSymmetricDifference(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::set_symmetric_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto setSymmetricDifference(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::set_symmetric_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto setUnion(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::set_union(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto setUnion(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::set_union(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont, typename UniformRandomNumberGenerator>
auto shuffle(Cont &cont, UniformRandomNumberGenerator &&g) {return std::shuffle(std::begin(cont), std::end(cont), g);}

template<typename Cont>
auto sort(Cont &cont) {return std::sort(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto sort(Cont &cont, Compare comp) {return std::sort(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto sortHeap(Cont &cont) {return std::sort_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto sortHeap(Cont &cont, Compare comp) {return std::sort_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename UnaryPredicate>
auto stablePartition(Cont &cont, UnaryPredicate p) {return std::stable_partition(std::begin(cont), std::end(cont), p);}

template<typename Cont>
auto stableSort(Cont &cont) {return std::stable_sort(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto stableSort(Cont &cont, Compare comp) {return std::stable_sort(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename ForwardIterator>
auto swapRanges(Cont &cont, ForwardIterator first) {return std::swap_ranges(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename OutputIterator, typename UnaryOperation>
auto transform(const Cont &cont, OutputIterator first, UnaryOperation op) {return std::transform(std::begin(cont), std::end(cont), first, op);}

template<typename Cont, typename InputIterator, typename OutputIterator, typename BinaryOperation>
auto transform(const Cont &cont, InputIterator firstIn, OutputIterator firstOut, BinaryOperation op) {return std::transform(std::begin(cont), std::end(cont), firstIn, firstOut, op);}

template<typename Cont>
auto unique(Cont &cont) {return std::unique(std::begin(cont), std::end(cont));}

template<typename Cont, typename BinaryPredicate>
auto unique(Cont &cont, BinaryPredicate p) {return std::unique(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename OutputIterator>
auto uniqueCopy(Cont &cont, OutputIterator first) {return std::unique_copy(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename OutputIterator, typename BinaryPredicate>
auto uniqueCopy(Cont &cont, OutputIterator first, BinaryPredicate p) {return std::unique_copy(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename T>
auto upperBound(Cont &cont, const T &value) {return std::upper_bound(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto upperBound(const Cont &cont, const T &value) {return std::upper_bound(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T, typename Compare>
auto upperBound(Cont &cont, const T &value, Compare comp) {return std::upper_bound(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename T, typename Compare>
auto upperBound(const Cont &cont, const T &value, Compare comp) {return std::upper_bound(std::begin(cont), std::end(cont), value, comp);}


//NEW OR REFINED ALGORITHMS

//returns true if container has the element or sequence
template<typename Cont, typename T>
auto contains(const Cont &cont, const T &value) {return find(cont, value) != std::end(cont);}

template<typename Cont, template<typename...> class Cont2, typename... Cont2Args>
auto contains(const Cont &cont, const Cont2<Cont2Args...> &cont2) {return search(cont, cont2) != std::end(cont);}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto contains(const Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return search(cont, cont2, p) != std::end(cont);}

template<typename Cont, typename UnaryPredicate>
auto containsIf(const Cont &cont, UnaryPredicate p) {return findIf(cont, p) != std::end(cont);}

template<typename Cont, typename UnaryPredicate>
auto containsIfNot(const Cont &cont, UnaryPredicate p) {return findIfNot(cont, p) != std::end(cont);}

//employs the erase-remove idiom
template<typename Cont, typename T>
auto eraseRemove(Cont &cont, const T &value) {return cont.erase(remove(cont, value), std::end(cont));}

template<typename Cont, typename OutputIterator, typename T>
auto eraseRemoveCopy(Cont &cont, OutputIterator first, const T &value) {return cont.erase(removeCopy(cont, first, value), std::end(cont));}

template<typename Cont, typename OutputIterator, typename UnaryPredicate>
auto eraseRemoveCopyIf(Cont &cont, OutputIterator first, UnaryPredicate p) {return cont.erase(removeCopyIf(cont, first, p), std::end(cont));}

template<typename Cont, typename UnaryPredicate>
auto eraseRemoveIf(Cont &cont, UnaryPredicate p) {return cont.erase(removeIf(cont, p), std::end(cont));}

template<typename Cont>
auto eraseUnique(Cont &cont) {return cont.erase(unique(cont), std::end(cont));}

template<typename Cont, typename BinaryPredicate>
auto eraseUnique(Cont &cont, BinaryPredicate p) {return cont.erase(unique(cont, p), std::end(cont));}

template<typename Cont, typename OutputIterator>
auto eraseUniqueCopy(Cont &cont, OutputIterator first) {return cont.erase(uniqueCopy(cont, first), std::end(cont));}

template<typename Cont, typename OutputIterator, typename BinaryPredicate>
auto eraseUniqueCopy(Cont &cont, OutputIterator first, BinaryPredicate p) {return cont.erase(uniqueCopy(cont, first, p), std::end(cont));}

//returns specified container with increasing values
template<template<typename...> class Cont, typename T>
auto iota(std::size_t N, T &&value) {Cont<T> temp(N); iota(temp, std::move(value)); return temp;}

//returns maximum of two objects of any type at compile time
template<typename T, typename U>
constexpr auto max(T &&t, U &&u) noexcept {return t > u ? t : u;}

//returns maximum of two or more objects of any type at compile time
template<typename Head, typename Head2, typename... Tail>
constexpr auto max(Head &&head, Head2 &&head2, Tail&&... tail) noexcept {return max(std::forward<Head>(head), max(std::forward<Head2>(head2), std::forward<Tail>(tail)...));}

//returns minimum of two objects of any type at compile time
template<typename T, typename U>
constexpr auto min(T &&t, U &&u) noexcept {return t < u ? t : u;}

//returns minimum of two or more objects of any type at compile time
template<typename Head, typename Head2, typename... Tail>
constexpr auto min(Head &&head, Head2 &&head2, Tail&&... tail) noexcept {return min(std::forward<Head>(head), min(std::forward<Head2>(head2), std::forward<Tail>(tail)...));}

//returns minimum and maximum of two objects of any type at compile time
template<typename T, typename U>
constexpr auto minMax(T &&t, U &&u) noexcept {return std::make_pair(min(t, u), max(t, u));}

//returns minimum and maximum of an object and a pair of minimum and maximum
template<typename T, typename P1, typename P2>
constexpr auto minMax(T &&t, std::pair<P1, P2> &&p) noexcept {return std::make_pair(min(t, p.first), p.second);}

//returns minimum and maximum of two or more objects of any type at compile time
template<typename Head, typename Head2, typename... Tail>
constexpr auto minMax(Head &&head, Head2 &&head2, Tail&&... tail) noexcept {return minMax(std::forward<Head>(head), minMax(std::forward<Head2>(head2), std::forward<Tail>(tail)...));}

//replaces all values in a container with a value of a different type
template<typename Cont, typename T, typename U>
auto replace(Cont &cont, const T &old_value, const U &new_value) {return std::replace_if(std::begin(cont), std::end(cont), [&](const T &elem) {return elem == old_value;}, new_value);}

template<typename Cont, typename OutputIterator, typename T, typename U>
auto replaceCopy(Cont &cont, OutputIterator first, const T &old_value, const U &new_value) {return std::replace_copy_if(std::begin(cont), std::end(cont), first, [&](const T &elem) {return elem == old_value;}, new_value);}

//returns the size of a container
template<typename Cont>
auto size(const Cont &cont) noexcept {return cont.size();}

//returns the size of an array
template<typename Type, std::size_t N>
constexpr auto size(const Type(&)[N]) noexcept {return N;}

//returns a RetCont of sub-containers made from parts in between the split element
template<template<typename...> class RetCont, typename Cont, typename T>
auto split(const Cont &cont, const T &value) {
    RetCont<Cont> temp;

    for (auto it(std::begin(cont)), last(it);; std::advance(it, 1), last = it) {
        it = std::find(it, std::end(cont), value);
        temp.emplace_back(last, it);
        if (it == std::end(cont)) break;
    }

    return temp;
}

//returns a std::vector of sub-containers made from parts in between the split element
template<typename Cont, typename T>
auto split(const Cont &cont, const T &value) {
    std::vector<Cont> temp;

    for (auto it(std::begin(cont)), last(it);; std::advance(it, 1), last = it) {
        it = std::find(it, std::end(cont), value);
        temp.emplace_back(last, it);
        if (it == std::end(cont)) break;
    }

    return temp;
}

//Split with the split element being a sequence
template<template<typename...> class RetCont, typename Cont, template<typename...> class Cont2, typename... Cont2Args>
auto split(const Cont &cont, const Cont2<Cont2Args...> &values) {
    RetCont<Cont> temp;

    for (auto it(std::begin(cont)), last(it);; std::advance(it, size(values)), last = it) {
        it = std::search(it, std::end(cont), std::begin(values), std::end(values));
        temp.emplace_back(last, it);
        if (it == std::end(cont)) break;
    }

    return temp;
}

//Split with the split element being a sequence
template<typename Cont, template<typename...> class Cont2, typename... Cont2Args>
auto split(const Cont &cont, const Cont2<Cont2Args...> &values) {
    std::vector<Cont> temp;

    for (auto it(std::begin(cont)), last(it);; std::advance(it, size(values)), last = it) {
        it = std::search(it, std::end(cont), std::begin(values), std::end(values));
        temp.emplace_back(last, it);
        if (it == std::end(cont)) break;
    }

    return temp;
}

}
}