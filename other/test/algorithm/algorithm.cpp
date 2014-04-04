#include <cassert>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include <stdx/algorithm/algorithm.hh>

int main() {
    using namespace stdx::algo;

    auto up = [](int i) {return i <= 10;};
    auto up2 = [](int i) {return i < 5;};
    auto uf = [](int i) {std::cout << i << " ";};
    auto out = std::ostream_iterator<int>{std::cout, " "};

    std::cout << "WRAPPED ALGORITHMS\n\n";

    std::vector<int> v{3, 5, 8, 2, 10};
    auto v2(v);

    std::cout << "v (ForEach): ";
    forEach(v, uf); std::cout << "\n";

    int acc[] = {3, 5, 8, 2, 10};
    assert(accumulate(acc, 0) == 3+5+8+2+10);
    assert(accumulate(v, 1, std::multiplies<int>()) == 3*5*8*2*10);

    adjacentDifference(v, std::begin(v2));
    if (v2 != std::vector<int>{3, 2, 3, -6, 8}) assert(!"AdjacentDifference");

    assert(adjacentFind(v) == std::end(v));
    if (adjacentFind(v, [](int lhs, int rhs) {return lhs == 8 && rhs == 2;}) != std::begin(v) + 2) assert(!"AdjacentDifference");

    assert(allOf(v, up));
    assert(anyOf(v, up));

    v2 = v;
    assert(equal(v, std::begin(v2)));
    sort(v2);
    if (v2 != std::vector<int>{2, 3, 5, 8, 10}) assert(!"Sort");

    assert(binarySearch(v2, 2));
    assert(!binarySearch(v2, 9));

    v2.resize(size(v2) + 5);
    assert(v2.size() == 10);
    fill(v2, 0);
    if (v2 != std::vector<int>(10, 0)) assert(!"Fill");
    copyBackward(v, std::end(v2));
    if (v2 != std::vector<int>{0, 0, 0, 0, 0, 3, 5, 8, 2, 10}) assert(!"CopyBackward");

    v2.clear();
    copyIf(v, std::back_inserter(v2), [](int i) {return i > 4;});
    if (v2 != std::vector<int>{5, 8, 10}) assert(!"CopyIf");

    assert(count(v, 3) == 1);
    assert(countIf(v, up) == 5);

    assert(!equal(v2, std::begin(v)));

    v2 = {2, 2, 2, 5, 6};
    auto equalRangePair = equalRange(v2, 2);
    assert(std::distance(equalRangePair.first, equalRangePair.second) == 3);

    assert(std::distance(std::begin(v), find(v, 10)) == 4);

    v2 = {8, 2};
    assert(std::distance(std::begin(v), findEnd(v, v2)) == 2);
    assert(std::distance(std::begin(v), findFirstOf(v, v2)) == 2);
    assert(findIf(v, up) == std::begin(v));
    assert(findIfNot(v, up) == std::end(v));

    v2.resize(5);
    generate(v2, [] {return 0;});
    if (v2 != std::vector<int>(5, 0)) assert(!"Generate");

    assert(!includes(v, v2));
    assert(innerProduct(v, std::begin(v), 0) == 3*3 + 5*5 + 2*2 + 8*8 + 10*10);

    v2 = v;
    auto v3(v);
    sort(v3);
    assert(isSortedUntil(v3) == std::end(v3));
    assert(isSorted(v3));

    partialSort(v2, std::begin(v2) + 3);
    std::sort(std::begin(v2) + 3, std::end(v2));
    inplaceMerge(v2, std::begin(v2) + 3);
    assert(v2 == v3);

    iota(v2, 8);
    if (v2 != std::vector<int>{8, 9, 10, 11, 12}) assert(!"Iota");

    assert(!isHeap(v2));
    makeHeap(v2);
    assert(isHeap(v2));
    popHeap(v2);
    pushHeap(v2);
    assert(isHeap(v2));
    assert(isHeapUntil(v2) == std::end(v2));

    v2 = v;
    assert(!isPartitioned(v2, up2));
    partition(v2, up2);
    assert(isPartitioned(v2, up2));

    v2 = v3;
    assert(isPermutation(v3, std::begin(v)));
    assert(nextPermutation(v2));
    assert(prevPermutation(v2));
    assert(v2 == v3);

    assert(!lexicographicalCompare(v2, v3));

    v2 = v;
    sort(v2);
    assert(lowerBound(v2, 3) == std::begin(v2) + 1);
    assert(upperBound(v2, 3) == std::begin(v2) + 2);

    std::cout << "Merge v with v: ";
    merge(v2, v2, out); std::cout << "\n";

    assert(*maxElement(v) == 10);
    assert(*minElement(v) == 2);

    auto mmPair = minmaxElement(v);
    assert(*(mmPair.first) == 2 && *(mmPair.second) == 10);

    v2 = v;
    v2[4] = 0;
    assert(*(mismatch(v2, std::begin(v)).first) == 0);

    auto v4(v);
    move(v4, std::begin(v2));
    assert(v2 == v);
    auto v5(v);
    moveBackward(v5, std::end(v2));
    assert(v2 == v);

    assert(!noneOf(v, up));

    nthElement(v2, std::begin(v2) + 1);
    v3.assign(std::begin(v2), std::begin(v2) + 2);
    assert(maxElement(v3) == std::end(v3) - 1);
    v3.assign(std::begin(v2) + 1, std::end(v2));
    assert(minElement(v3) == std::begin(v3));

    v3 = v;
    partialSort(v3, std::begin(v3) + 3);
    v2.assign(std::begin(v3), std::begin(v3) + 3);
    assert(isSorted(v2));

    v2.resize(5);
    v3.clear();
    fill(v2, 1);
    partialSum(v2, std::back_inserter(v3));
    iota(v2, 1);
    assert(v3 == v2);

    v2 = v;
    std::cout << "PartitionCopy: ";
    std::vector<int> trues, falses;
    partitionCopy(v2, std::back_inserter(trues), std::back_inserter(falses), up2);
    copy(trues, out); std::cout << "vs "; copy(falses, out); std::cout << "\n";

    partition(v2, up2);
    assert(partitionPoint(v2, up2) == lowerBound(v2, 5));

    v2 = v;
    std::cout << "RandomShuffle: ";
    randomShuffle(v2);
    copy(v2, out); std::cout << "\n";

    eraseRemove(v2, 2);
    v2.emplace_back(2);
    assert(isPermutation(v2, std::begin(v)));

    v2 = v;
    replace(v2, 3, 5.6);
    if (v2 != std::vector<int>{5, 5, 8, 2, 10}) assert(!"Replace");

    reverse(v2);
    if (v2 != std::vector<int>{10, 2, 8, 5, 5}) assert(!"Reverse");

    rotate(v2, find(v2, 8));
    assert(v2.front() == 8);

    v2 = {5, 8};
    assert(search(v, v2) == std::begin(v) + 1);

    v2 = {3, 4, 6, 5, 7, 8};
    v3 = v;
    sort(v2);
    sort(v3);

    std::cout << "\nv2: ";
    copy(v2, out); std::cout << "\n";

    std::cout << "v3: ";
    copy(v3, out); std::cout << "\n";

    std::vector<int> v6;
    setDifference(v2, v3, std::back_inserter(v6));

    std::cout << "SetDifference: ";
    copy(v6, out); std::cout << "\n";

    v6.clear();
    setIntersection(v2, v3, std::back_inserter(v6));

    std::cout << "SetIntersection: ";
    copy(v6, out); std::cout << "\n";

    v6.clear();
    setSymmetricDifference(v2, v3, std::back_inserter(v6));

    std::cout << "SetSymmetricDifference: ";
    copy(v6, out); std::cout << "\n";

    v6.clear();
    setUnion(v2, v3, std::back_inserter(v6));

    std::cout << "SetUnion: ";
    copy(v6, out); std::cout << "\n";

    v2 = v;
    v3.resize(5);
    iota(v3, 5);
    swapRanges(v2, std::begin(v3));

    if (v2 != std::vector<int>{5, 6, 7, 8, 9}) assert(!"SwapRanges");

    transform(v2, std::begin(v3), [](int i) {return i * 2;});
    if (v3 != std::vector<int>{10, 12, 14, 16, 18}) assert(!"Transform");

    v2 = {2, 2, 3, 6, 4, 2, 7, 7, 4, 5};
    sort(v2);
    eraseUnique(v2);
    if (v2 != std::vector<int>{2, 3, 4, 5, 6, 7}) assert(!"EraseUnique");

    //NEW ALGORITHMS

    std::cout << "\n\nNEW ALGORITHMS\n\n";

    assert(contains(v, 8));
    assert(containsIf(v, [](int i) {return i < 5;}));
    assert(containsIfNot(v, [](int i) {return i < 5;}));

    std::cout << "Iota: ";
    copy(iota<std::vector>(5, 24), out); std::cout << "\n";

    int maxArr[max(1, 3, 2)];
    static_assert(sizeof(maxArr)/sizeof(maxArr[0]) == 3, "");

    int minArr[min(1, 3, 2)];
    static_assert(sizeof(minArr)/sizeof(minArr[0]) == 1, "");

    constexpr auto minmaxPair = minMax(5, 1, 2, 9);

    int minmaxArr1[minmaxPair.first];
    static_assert(sizeof(minmaxArr1)/sizeof(minmaxArr1[0]) == 1, "");

    int minmaxArr2[minmaxPair.second];
    static_assert(sizeof(minmaxArr2)/sizeof(minmaxArr2[0]) == 9, "");

    std::vector<int> toSplit{2, 5, 4, 2, 3, 9, 2};
    auto splitList = split<std::list>(toSplit, 2);
    std::list<std::vector<int>> rightSplit{{}, {5, 4}, {3, 9}, {}};
    assert(splitList == rightSplit);

    toSplit = {2, 2, 5, 4, 2, 3, 2, 2, 1, 2, 9};
    v2 = {2, 2};
    splitList = split<std::list>(toSplit, v2);
    rightSplit = {{}, {5, 4, 2, 3}, {1, 2, 9}};
    assert(splitList == rightSplit);

    assert(size(std::vector<int>{1, 2}) == 2);
}
