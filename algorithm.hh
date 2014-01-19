//Wraps standard algorithms to take a container and assume begin() and end().
//Wraps those found in <numeric> as well.
//Work with built-in arrays.
//Also adds new algorithms.
//Algorithms overloaded with non-const/const versions of the container return Container::iterator and Container::const_iterator respectively.

#ifndef STDX_ALGORITHM_H
#define STDX_ALGORITHM_H

#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

namespace stdx {
inline namespace AlgorithmNs {

//STANDARD ALGORITHM WRAPPERS

//C++14 std::cbegin and std::cend
//C++14 Constraints

template<typename Cont, typename T>
auto Accumulate(const Cont &cont, T &&init) {return std::accumulate(std::begin(cont), std::end(cont), std::move(init));}

template<typename Cont, typename T, typename BinaryOperation>
auto Accumulate(const Cont &cont, T &&init, BinaryOperation op) {return std::accumulate(std::begin(cont), std::end(cont), std::move(init), op);}

template<typename Cont, typename OutputIterator>
auto AdjacentDifference(const Cont &cont, OutputIterator first) {return std::adjacent_difference(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename OutputIterator, typename BinaryOperation>
auto AdjacentDifference(const Cont &cont, OutputIterator first, BinaryOperation op) {return std::adjacent_difference(std::begin(cont), std::end(cont), first, op);}

template<typename Cont>
auto AdjacentFind(Cont &cont) {return std::adjacent_find(std::begin(cont), std::end(cont));}

template<typename Cont>
auto AdjacentFind(const Cont &cont) {return std::adjacent_find(std::begin(cont), std::end(cont));}

template<typename Cont, typename BinaryPredicate>
auto AdjacentFind(Cont &cont, BinaryPredicate p) {return std::adjacent_find(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename BinaryPredicate>
auto AdjacentFind(const Cont &cont, BinaryPredicate p) {return std::adjacent_find(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto AllOf(const Cont &cont, UnaryPredicate p) {return std::all_of(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto AnyOf(const Cont &cont, UnaryPredicate p) {return std::any_of(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto AnyOf(const Type(&cont)[N], UnaryPredicate p) {return std::any_of(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename T>
auto BinarySearch(const Cont &cont, const T &value) {return std::binary_search(std::begin(cont), std::end(cont), value);}

template<typename Type, std::size_t N, typename T>
auto BinarySearch(const Type(&cont)[N], const T &value) {return std::binary_search(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T, typename Compare>
auto BinarySearch(const Cont &cont, const T &value, Compare comp) {return std::binary_search(std::begin(cont), std::end(cont), value, comp);}

template<typename Type, std::size_t N, typename T, typename Compare>
auto BinarySearch(const Type(&cont)[N], const T &value, Compare comp) {return std::binary_search(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename OutputIterator>
auto Copy(const Cont &cont, OutputIterator first) {return std::copy(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename BidirectionalIterator>
auto CopyBackward(const Cont &cont, BidirectionalIterator last) {return std::copy_backward(std::begin(cont), std::end(cont), last);}

template<typename Cont, typename OutputIterator, typename UnaryPredicate>
auto CopyIf(const Cont &cont, OutputIterator first, UnaryPredicate p) {return std::copy_if(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename T>
auto Count(const Cont &cont, const T &value) {return std::count(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename UnaryPredicate>
auto CountIf(const Cont &cont, UnaryPredicate p) {return std::count_if(std::begin(cont), std::end(cont), p);}

//C++14 2 new overloads
template<typename Cont, typename InputIterator>
auto Equal(const Cont &cont, InputIterator first) {return std::equal(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename InputIterator, typename BinaryPredicate>
auto Equal(const Cont &cont, InputIterator first, BinaryPredicate p) {return std::equal(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename T>
auto EqualRange(Cont &cont, const T &value) {return std::equal_range(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto EqualRange(const Cont &cont, const T &value) {return std::equal_range(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T, typename Compare>
auto EqualRange(Cont &cont, const T &value, Compare comp) {return std::equal_range(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename T, typename Compare>
auto EqualRange(const Cont &cont, const T &value, Compare comp) {return std::equal_range(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename T>
auto Fill(Cont &cont, const T &value) {return std::fill(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto Find(Cont &cont, const T &value) {return std::find(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto Find(const Cont &cont, const T &value) {return std::find(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename Cont2>
auto FindEnd(Cont &cont, const Cont2 &cont2) {return std::find_end(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2>
auto FindEnd(const Cont &cont, const Cont2 &cont2) {return std::find_end(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2>
auto FindFirstOf(Cont &cont, const Cont2 &cont2) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2>
auto FindFirstOf(const Cont &cont, const Cont2 &cont2) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto FindFirstOf(Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto FindFirstOf(const Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return std::find_first_of(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Cont, typename UnaryPredicate>
auto FindIf(Cont &cont, UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto FindIf(const Cont &cont, UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<typename Type, std::size_t N, typename UnaryPredicate>
auto FindIf(const Type(&cont)[N], UnaryPredicate p) {return std::find_if(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto FindIfNot(Cont &cont, UnaryPredicate p) {return std::find_if_not(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto FindIfNot(const Cont &cont, UnaryPredicate p) {return std::find_if_not(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryFunction>
auto ForEach(Cont &cont, UnaryFunction f) {return std::for_each(std::begin(cont), std::end(cont), f);}

template<typename Cont, typename UnaryFunction>
auto ForEach(const Cont &cont, UnaryFunction f) {return std::for_each(std::begin(cont), std::end(cont), f);}

template<typename Cont, typename Generator>
auto Generate(Cont &cont, Generator g) {return std::generate(std::begin(cont), std::end(cont), g);}

template<typename Cont, typename Cont2>
auto Includes(const Cont &cont, const Cont2 &cont2) {return std::includes(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename Compare>
auto Includes(const Cont &cont, const Cont2 &cont2, Compare comp) {return std::includes(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Cont, typename InputIterator, typename T>
auto InnerProduct(const Cont &cont, InputIterator first, T &&value) {return std::inner_product(std::begin(cont), std::end(cont), first, std::move(value));}

template<typename Cont, typename InputIterator, typename T, typename BinaryOperation1, typename BinaryOperation2>
auto InnerProduct(const Cont &cont, InputIterator first, T &&value, BinaryOperation1 op1, BinaryOperation2 op2) {return std::inner_product(std::begin(cont), std::end(cont), first, std::move(value), op1, op2);}

template<typename Cont>
auto InplaceMerge(Cont &cont, typename Cont::iterator middle) {return std::inplace_merge(std::begin(cont), middle, std::end(cont));}

template<typename Cont, typename Compare>
auto InplaceMerge(Cont &cont, typename Cont::iterator middle, Compare comp) {return std::inplace_merge(std::begin(cont), middle, std::end(cont), comp);}

template<typename Cont, typename T>
auto Iota(Cont &cont, T &&value) {return std::iota(std::begin(cont), std::end(cont), std::move(value));}

template<typename Cont>
auto IsHeap(const Cont &cont) {return std::is_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto IsHeap(const Cont &cont, Compare comp) {return std::is_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto IsHeapUntil(Cont &cont) {return std::is_heap_until(std::begin(cont), std::end(cont));}

template<typename Cont>
auto IsHeapUntil(const Cont &cont) {return std::is_heap_until(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto IsHeapUntil(Cont &cont, Compare comp) {return std::is_heap_until(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto IsHeapUntil(const Cont &cont, Compare comp) {return std::is_heap_until(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename UnaryPredicate>
auto IsPartitioned(const Cont &cont, UnaryPredicate p) {return std::is_partitioned(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename ForwardIterator>
auto IsPermutation(const Cont &cont, ForwardIterator first) {return std::is_permutation(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename ForwardIterator, typename BinaryPredicate>
auto IsPermutation(const Cont &cont, ForwardIterator first, BinaryPredicate p) {return std::is_permutation(std::begin(cont), std::end(cont), first, p);}

template<typename Cont>
auto IsSorted(const Cont &cont) {return std::is_sorted(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto IsSorted(const Cont &cont, Compare comp) {return std::is_sorted(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto IsSortedUntil(Cont &cont) {return std::is_sorted_until(std::begin(cont), std::end(cont));}

template<typename Cont>
auto IsSortedUntil(const Cont &cont) {return std::is_sorted_until(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto IsSortedUntil(Cont &cont, Compare comp) {return std::is_sorted_until(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto IsSortedUntil(const Cont &cont, Compare comp) {return std::is_sorted_until(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Cont2>
auto LexicographicalCompare(const Cont &cont, const Cont2 &cont2) {return std::lexicographical_compare(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename Compare>
auto LexicographicalCompare(const Cont &cont, const Cont2 &cont2, Compare comp) {return std::lexicographical_compare(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Cont, typename T>
auto LowerBound(Cont &cont, const T &value) {return std::lower_bound(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto LowerBound(const Cont &cont, const T &value) {return std::lower_bound(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T, typename Compare>
auto LowerBound(Cont &cont, const T &value, Compare comp) {return std::lower_bound(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename T, typename Compare>
auto LowerBound(const Cont &cont, const T &value, Compare comp) {return std::lower_bound(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont>
auto MakeHeap(Cont &cont) {return std::make_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto MakeHeap(Cont &cont, Compare comp) {return std::make_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto MaxElement(Cont &cont) {return std::max_element(std::begin(cont), std::end(cont));}

template<typename Cont>
auto MaxElement(const Cont &cont) {return std::max_element(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto MaxElement(Cont &cont, Compare comp) {return std::max_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto MaxElement(const Cont &cont, Compare comp) {return std::max_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto Merge(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::merge(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto Merge(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::merge(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont>
auto MinElement(Cont &cont) {return std::min_element(std::begin(cont), std::end(cont));}

template<typename Cont>
auto MinElement(const Cont &cont) {return std::min_element(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto MinElement(Cont &cont, Compare comp) {return std::min_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto MinElement(const Cont &cont, Compare comp) {return std::min_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto MinmaxElement(Cont &cont) {return std::minmax_element(std::begin(cont), std::end(cont));}

template<typename Cont>
auto MinmaxElement(const Cont &cont) {return std::minmax_element(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto MinmaxElement(Cont &cont, Compare comp) {return std::minmax_element(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename Compare>
auto MinmaxElement(const Cont &cont, Compare comp) {return std::minmax_element(std::begin(cont), std::end(cont), comp);}

//C++14 2 new overloads
template<typename Cont, typename InputIterator>
auto Mismatch(Cont &cont, InputIterator first) {return std::mismatch(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename InputIterator>
auto Mismatch(const Cont &cont, InputIterator first) {return std::mismatch(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename InputIterator, typename BinaryPredicate>
auto Mismatch(Cont &cont, InputIterator first, BinaryPredicate p) {return std::mismatch(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename InputIterator, typename BinaryPredicate>
auto Mismatch(const Cont &cont, InputIterator first, BinaryPredicate p) {return std::mismatch(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename OutputIterator>
auto Move(const Cont &cont, OutputIterator first) {return std::move(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename BidirectionalIterator>
auto MoveBackward(const Cont &cont, BidirectionalIterator last) {return std::move_backward(std::begin(cont), std::end(cont), last);}

template<typename Cont>
auto NextPermutation(Cont &cont) {return std::next_permutation(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto NextPermutation(Cont &cont, Compare comp) {return std::next_permutation(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename UnaryPredicate>
auto NoneOf(const Cont &cont, UnaryPredicate p) {return std::none_of(std::begin(cont), std::end(cont), p);}

template<typename Cont>
auto NthElement(Cont &cont, typename Cont::iterator nth) {return std::nth_element(std::begin(cont), nth, std::end(cont));}

template<typename Cont, typename Compare>
auto NthElement(Cont &cont, typename Cont::iterator nth, Compare comp) {return std::nth_element(std::begin(cont), nth, std::end(cont), comp);}

template<typename Cont>
auto PartialSort(Cont &cont, typename Cont::iterator middle) {return std::partial_sort(std::begin(cont), middle, std::end(cont));}

template<typename Cont, typename Compare>
auto PartialSort(Cont &cont, typename Cont::iterator middle, Compare comp) {return std::partial_sort(std::begin(cont), middle, std::end(cont), comp);}

template<typename Cont, typename Cont2>
auto PartialSortCopy(const Cont &cont, Cont2 &cont2) {return std::partial_sort_copy(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename Compare>
auto PartialSortCopy(const Cont &cont, Cont2 &cont2, Compare comp) {return std::partial_sort_copy(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), comp);}

template<typename Cont, typename OutputIterator>
auto PartialSum(const Cont &cont, OutputIterator first) {return std::partial_sum(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename OutputIterator, typename BinaryOperation>
auto PartialSum(const Cont &cont, OutputIterator first, BinaryOperation op) {return std::partial_sum(std::begin(cont), std::end(cont), first, op);}

template<typename Cont, typename UnaryPredicate>
auto Partition(Cont &cont, UnaryPredicate p) {return std::partition(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename OutputIterator1, typename OutputIterator2, typename UnaryPredicate>
auto PartitionCopy(Cont &cont, OutputIterator1 first_true, OutputIterator2 first_false, UnaryPredicate p) {return std::partition_copy(std::begin(cont), std::end(cont), first_true, first_false, p);}

template<typename Cont, typename UnaryPredicate>
auto PartitionPoint(Cont &cont, UnaryPredicate p) {return std::partition_point(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename UnaryPredicate>
auto PartitionPoint(const Cont &cont, UnaryPredicate p) {return std::partition_point(std::begin(cont), std::end(cont), p);}

template<typename Cont>
auto PopHeap(Cont &cont) {return std::pop_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto PopHeap(Cont &cont, Compare comp) {return std::pop_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto PrevPermutation(Cont &cont) {return std::prev_permutation(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto PrevPermutation(Cont &cont, Compare comp) {return std::prev_permutation(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto PushHeap(Cont &cont) {return std::push_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto PushHeap(Cont &cont, Compare comp) {return std::push_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto RandomShuffle(Cont &cont) {return std::random_shuffle(std::begin(cont), std::end(cont));}

template<typename Cont, typename RandomNumberGenerator>
auto RandomShuffle(Cont &cont, RandomNumberGenerator &&r) {return std::random_shuffle(std::begin(cont), std::end(cont), r);}

template<typename Cont, typename T>
auto Remove(Cont &cont, const T &value) {return std::remove(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename OutputIterator, typename T>
auto RemoveCopy(Cont &cont, OutputIterator first, const T &value) {return std::remove_copy(std::begin(cont), std::end(cont), first, value);}

template<typename Cont, typename OutputIterator, typename UnaryPredicate>
auto RemoveCopyIf(Cont &cont, OutputIterator first, UnaryPredicate p) {return std::remove_copy_if(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename UnaryPredicate>
auto RemoveIf(Cont &cont, UnaryPredicate p) {return std::remove_if(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename T>
auto Replace(Cont &cont, const T &old_value, const T &new_value) {return std::replace(std::begin(cont), std::end(cont), old_value, new_value);}

template<typename Cont, typename OutputIterator, typename T>
auto ReplaceCopy(Cont &cont, OutputIterator first, const T &old_value, const T &new_value) {return std::replace_copy(std::begin(cont), std::end(cont), first, old_value, new_value);}

template<typename Cont, typename OutputIterator, typename UnaryPredicate, typename T>
auto ReplaceCopyIf(Cont &cont, OutputIterator first, UnaryPredicate p, const T &new_value) {return std::replace_copy(std::begin(cont), std::end(cont), first, p, new_value);}

template<typename Cont, typename UnaryPredicate, typename T>
auto ReplaceIf(Cont &cont, UnaryPredicate p, const T &new_value) {return std::replace_if(std::begin(cont), std::end(cont), p, new_value);}

template<typename Cont>
auto Reverse(Cont &cont) {return std::reverse(std::begin(cont), std::end(cont));}

template<typename Cont, typename OutputIterator>
auto ReverseCopy(Cont &cont, OutputIterator first) {return std::reverse_copy(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename ForwardIterator>
auto Rotate(Cont &cont, ForwardIterator new_first) {return std::rotate(std::begin(cont), new_first, std::end(cont));}

template<typename Cont, typename ForwardIterator, typename OutputIterator>
auto RotateCopy(Cont &cont, ForwardIterator new_first, OutputIterator first) {return std::rotate_copy(std::begin(cont), new_first, std::end(cont), first);}

template<typename Cont, typename Cont2>
auto Search(Cont &cont, const Cont2 &cont2) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2>
auto Search(const Cont &cont, const Cont2 &cont2) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2));}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto Search(Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto Search(const Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return std::search(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), p);}

template<typename Cont, typename Size, typename T>
auto SearchN(Cont &cont, Size count, const T &value) {return std::search_n(std::begin(cont), std::end(cont), count, value);}

template<typename Cont, typename Size, typename T>
auto SearchN(const Cont &cont, Size count, const T &value) {return std::search_n(std::begin(cont), std::end(cont), count, value);}

template<typename Cont, typename Size, typename T, typename BinaryPredicate>
auto SearchN(Cont &cont, Size count, const T &value, BinaryPredicate p) {return std::search_n(std::begin(cont), std::end(cont), count, value, p);}

template<typename Cont, typename Size, typename T, typename BinaryPredicate>
auto SearchN(const Cont &cont, Size count, const T &value, BinaryPredicate p) {return std::search_n(std::begin(cont), std::end(cont), count, value, p);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto SetDifference(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::set_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto SetDifference(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::set_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto SetIntersection(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::set_intersection(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto SetIntersection(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::set_intersection(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto SetSymmetricDifference(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::set_symmetric_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto SetSymmetricDifference(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::set_symmetric_difference(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont, typename Cont2, typename OutputIterator>
auto SetUnion(const Cont &cont, const Cont2 &cont2, OutputIterator first) {return std::set_union(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first);}

template<typename Cont, typename Cont2, typename OutputIterator, typename Compare>
auto SetUnion(const Cont &cont, const Cont2 &cont2, OutputIterator first, Compare comp) {return std::set_union(std::begin(cont), std::end(cont), std::begin(cont2), std::end(cont2), first, comp);}

template<typename Cont, typename UniformRandomNumberGenerator>
auto Shuffle(Cont &cont, UniformRandomNumberGenerator &&g) {return std::shuffle(std::begin(cont), std::end(cont), g);}

template<typename Cont>
auto Sort(Cont &cont) {return std::sort(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto Sort(Cont &cont, Compare comp) {return std::sort(std::begin(cont), std::end(cont), comp);}

template<typename Cont>
auto SortHeap(Cont &cont) {return std::sort_heap(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto SortHeap(Cont &cont, Compare comp) {return std::sort_heap(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename UnaryPredicate>
auto StablePartition(Cont &cont, UnaryPredicate p) {return std::stable_partition(std::begin(cont), std::end(cont), p);}

template<typename Cont>
auto StableSort(Cont &cont) {return std::stable_sort(std::begin(cont), std::end(cont));}

template<typename Cont, typename Compare>
auto StableSort(Cont &cont, Compare comp) {return std::stable_sort(std::begin(cont), std::end(cont), comp);}

template<typename Cont, typename ForwardIterator>
auto SwapRanges(Cont &cont, ForwardIterator first) {return std::swap_ranges(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename OutputIterator, typename UnaryOperation>
auto Transform(const Cont &cont, OutputIterator first, UnaryOperation op) {return std::transform(std::begin(cont), std::end(cont), first, op);}

template<typename Cont, typename InputIterator, typename OutputIterator, typename BinaryOperation>
auto Transform(const Cont &cont, InputIterator firstIn, OutputIterator firstOut, BinaryOperation op) {return std::transform(std::begin(cont), std::end(cont), firstIn, firstOut, op);}

template<typename Cont>
auto Unique(Cont &cont) {return std::unique(std::begin(cont), std::end(cont));}

template<typename Cont, typename BinaryPredicate>
auto Unique(Cont &cont, BinaryPredicate p) {return std::unique(std::begin(cont), std::end(cont), p);}

template<typename Cont, typename OutputIterator>
auto UniqueCopy(Cont &cont, OutputIterator first) {return std::unique_copy(std::begin(cont), std::end(cont), first);}

template<typename Cont, typename OutputIterator, typename BinaryPredicate>
auto UniqueCopy(Cont &cont, OutputIterator first, BinaryPredicate p) {return std::unique_copy(std::begin(cont), std::end(cont), first, p);}

template<typename Cont, typename T>
auto UpperBound(Cont &cont, const T &value) {return std::upper_bound(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T>
auto UpperBound(const Cont &cont, const T &value) {return std::upper_bound(std::begin(cont), std::end(cont), value);}

template<typename Cont, typename T, typename Compare>
auto UpperBound(Cont &cont, const T &value, Compare comp) {return std::upper_bound(std::begin(cont), std::end(cont), value, comp);}

template<typename Cont, typename T, typename Compare>
auto UpperBound(const Cont &cont, const T &value, Compare comp) {return std::upper_bound(std::begin(cont), std::end(cont), value, comp);}


//NEW OR REFINED ALGORITHMS

//returns true if container has the element or sequence
template<typename Cont, typename T>
auto Contains(const Cont &cont, const T &value) {return Find(cont, value) != std::end(cont);}

template<typename Cont, template<typename...> class Cont2, typename... Cont2Args>
auto Contains(const Cont &cont, const Cont2<Cont2Args...> &cont2) {return Search(cont, cont2) != std::end(cont);}

template<typename Cont, typename Cont2, typename BinaryPredicate>
auto Contains(const Cont &cont, const Cont2 &cont2, BinaryPredicate p) {return Search(cont, cont2, p) != std::end(cont);}

template<typename Cont, typename UnaryPredicate>
auto ContainsIf(const Cont &cont, UnaryPredicate p) {return FindIf(cont, p) != std::end(cont);}

template<typename Cont, typename UnaryPredicate>
auto ContainsIfNot(const Cont &cont, UnaryPredicate p) {return FindIfNot(cont, p) != std::end(cont);}

//employs the erase-remove idiom
template<typename Cont, typename T>
auto EraseRemove(Cont &cont, const T &value) {return cont.erase(Remove(cont, value), std::end(cont));}

template<typename Cont, typename OutputIterator, typename T>
auto EraseRemoveCopy(Cont &cont, OutputIterator first, const T &value) {return cont.erase(RemoveCopy(cont, first, value), std::end(cont));}

template<typename Cont, typename OutputIterator, typename UnaryPredicate>
auto EraseRemoveCopyIf(Cont &cont, OutputIterator first, UnaryPredicate p) {return cont.erase(RemoveCopyIf(cont, first, p), std::end(cont));}

template<typename Cont, typename UnaryPredicate>
auto EraseRemoveIf(Cont &cont, UnaryPredicate p) {return cont.erase(RemoveIf(cont, p), std::end(cont));}

template<typename Cont>
auto EraseUnique(Cont &cont) {return cont.erase(Unique(cont), std::end(cont));}

template<typename Cont, typename BinaryPredicate>
auto EraseUnique(Cont &cont, BinaryPredicate p) {return cont.erase(Unique(cont, p), std::end(cont));}

template<typename Cont, typename OutputIterator>
auto EraseUniqueCopy(Cont &cont, OutputIterator first) {return cont.erase(UniqueCopy(cont, first), std::end(cont));}

template<typename Cont, typename OutputIterator, typename BinaryPredicate>
auto EraseUniqueCopy(Cont &cont, OutputIterator first, BinaryPredicate p) {return cont.erase(UniqueCopy(cont, first, p), std::end(cont));}

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
template<typename Cont, typename T, typename U>
auto Replace(Cont &cont, const T &old_value, const U &new_value) {return std::replace_if(std::begin(cont), std::end(cont), [&](const T &elem) {return elem == old_value;}, new_value);}

template<typename Cont, typename OutputIterator, typename T, typename U>
auto ReplaceCopy(Cont &cont, OutputIterator first, const T &old_value, const U &new_value) {return std::replace_copy_if(std::begin(cont), std::end(cont), first, [&](const T &elem) {return elem == old_value;}, new_value);}

//returns the size of a container
template<typename Cont>
auto Size(const Cont &cont) noexcept {return cont.size();}

//returns the size of an array
template<typename Type, std::size_t N>
constexpr auto Size(const Type(&)[N]) noexcept {return N;}

//returns a RetCont of sub-containers made from parts in between the split element
template<template<typename...> class RetCont, typename Cont, typename T>
auto Split(const Cont &cont, const T &value) {
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
auto Split(const Cont &cont, const T &value) {
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
auto Split(const Cont &cont, const Cont2<Cont2Args...> &values) {
    RetCont<Cont> temp;

    for (auto it(std::begin(cont)), last(it);; std::advance(it, Size(values)), last = it) {
        it = std::search(it, std::end(cont), std::begin(values), std::end(values));
        temp.emplace_back(last, it);
        if (it == std::end(cont)) break;
    }

    return temp;
}

//Split with the split element being a sequence
template<typename Cont, template<typename...> class Cont2, typename... Cont2Args>
auto Split(const Cont &cont, const Cont2<Cont2Args...> &values) {
    std::vector<Cont> temp;

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
