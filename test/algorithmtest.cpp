//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

#include <cassert>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <vector>
#include "../algorithm.hh"

int main() {
    using namespace stdx::AlgorithmNs;

    auto up = [](int i) {return i <= 10;};
    auto up2 = [](int i) {return i < 5;};
    auto uf = [](int i) {std::cout << i << " ";};
    auto out = std::ostream_iterator<int>{std::cout, " "};

    std::cout << "WRAPPED ALGORITHMS\n\n";

    std::vector<int> v{3, 5, 8, 2, 10};
    auto v2(v);

    std::cout << "v (ForEach): ";
    ForEach(v, uf); std::cout << "\n";

    assert(Accumulate(v, 0) == 3+5+8+2+10);
    assert(Accumulate(v, 1, std::multiplies<int>()) == 3*5*8*2*10);

    AdjacentDifference(v, std::begin(v2));
    if (v2 != std::vector<int>{3, 2, 3, -6, 8}) assert(!"AdjacentDifference");

    assert(AdjacentFind(v) == std::end(v));
    if (AdjacentFind(v, [](int lhs, int rhs) {return lhs == 8 && rhs == 2;}) != std::begin(v) + 2) assert(!"AdjacentDifference");

    assert(AllOf(v, up));
    assert(AnyOf(v, up));

    v2 = v;
    assert(Equal(v, std::begin(v2)));
    Sort(v2);
    if (v2 != std::vector<int>{2, 3, 5, 8, 10}) assert(!"Sort");

    assert(BinarySearch(v2, 2));
    assert(!BinarySearch(v2, 9));

    v2.resize(Size(v2) + 5);
    assert(v2.size() == 10);
    Fill(v2, 0);
    if (v2 != std::vector<int>(10, 0)) assert(!"Fill");
    CopyBackward(v, std::end(v2));
    if (v2 != std::vector<int>{0, 0, 0, 0, 0, 3, 5, 8, 2, 10}) assert(!"CopyBackward");

    v2.clear();
    CopyIf(v, std::back_inserter(v2), [](int i) {return i > 4;});
    if (v2 != std::vector<int>{5, 8, 10}) assert(!"CopyIf");

    assert(Count(v, 3) == 1);
    assert(CountIf(v, up) == 5);

    assert(!Equal(v2, std::begin(v)));

    v2 = {2, 2, 2, 5, 6};
    auto equalRangePair = EqualRange(v2, 2);
    assert(std::distance(equalRangePair.first, equalRangePair.second) == 3);

    assert(std::distance(std::begin(v), Find(v, 10)) == 4);

    v2 = {8, 2};
    assert(std::distance(std::begin(v), FindEnd(v, v2)) == 2);
    assert(std::distance(std::begin(v), FindFirstOf(v, v2)) == 2);
    assert(FindIf(v, up) == std::begin(v));
    assert(FindIfNot(v, up) == std::end(v));

    v2.resize(5);
    Generate(v2, [] {return 0;});
    if (v2 != std::vector<int>(5, 0)) assert(!"Generate");

    assert(!Includes(v, v2));
    assert(InnerProduct(v, std::begin(v), 0) == 3*3 + 5*5 + 2*2 + 8*8 + 10*10);

    v2 = v;
    auto v3(v);
    Sort(v3);
    assert(IsSortedUntil(v3) == std::end(v3));
    assert(IsSorted(v3));

    PartialSort(v2, std::begin(v2) + 3);
    std::sort(std::begin(v2) + 3, std::end(v2));
    InplaceMerge(v2, std::begin(v2) + 3);
    assert(v2 == v3);

    Iota(v2, 8);
    if (v2 != std::vector<int>{8, 9, 10, 11, 12}) assert(!"Iota");

    assert(!IsHeap(v2));
    MakeHeap(v2);
    assert(IsHeap(v2));
    PopHeap(v2);
    PushHeap(v2);
    assert(IsHeap(v2));
    assert(IsHeapUntil(v2) == std::end(v2));

    v2 = v;
    assert(!IsPartitioned(v2, up2));
    Partition(v2, up2);
    assert(IsPartitioned(v2, up2));

    v2 = v3;
    assert(IsPermutation(v3, std::begin(v)));
    assert(NextPermutation(v2));
    assert(PrevPermutation(v2));
    assert(v2 == v3);

    assert(!LexicographicalCompare(v2, v3));

    v2 = v;
    Sort(v2);
    assert(LowerBound(v2, 3) == std::begin(v2) + 1);
    assert(UpperBound(v2, 3) == std::begin(v2) + 2);

    std::cout << "Merge v with v: ";
    Merge(v2, v2, out); std::cout << "\n";

    assert(*MaxElement(v) == 10);
    assert(*MinElement(v) == 2);

    auto mmPair = MinmaxElement(v);
    assert(*(mmPair.first) == 2 && *(mmPair.second) == 10);

    v2 = v;
    v2[4] = 0;
    assert(*(Mismatch(v2, std::begin(v)).first) == 0);

    auto v4(v);
    Move(v4, std::begin(v2));
    assert(v2 == v);
    auto v5(v);
    MoveBackward(v5, std::end(v2));
    assert(v2 == v);

    assert(!NoneOf(v, up));

    NthElement(v2, std::begin(v2) + 1);
    v3.assign(std::begin(v2), std::begin(v2) + 2);
    assert(MaxElement(v3) == std::end(v3) - 1);
    v3.assign(std::begin(v2) + 1, std::end(v2));
    assert(MinElement(v3) == std::begin(v3));

    v3 = v;
    PartialSort(v3, std::begin(v3) + 3);
    v2.assign(std::begin(v3), std::begin(v3) + 3);
    assert(IsSorted(v2));

    v2.resize(5);
    v3.clear();
    Fill(v2, 1);
    PartialSum(v2, std::back_inserter(v3));
    Iota(v2, 1);
    assert(v3 == v2);

    v2 = v;
    std::cout << "PartitionCopy: ";
    std::vector<int> trues, falses;
    PartitionCopy(v2, std::back_inserter(trues), std::back_inserter(falses), up2);
    Copy(trues, out); std::cout << "vs "; Copy(falses, out); std::cout << "\n";

    Partition(v2, up2);
    assert(PartitionPoint(v2, up2) == LowerBound(v2, 5));

    v2 = v;
    std::cout << "RandomShuffle: ";
    RandomShuffle(v2);
    Copy(v2, out); std::cout << "\n";

    EraseRemove(v2, 2);
    v2.emplace_back(2);
    assert(IsPermutation(v2, std::begin(v)));

    v2 = v;
    Replace(v2, 3, 5.6);
    if (v2 != std::vector<int>{5, 5, 8, 2, 10}) assert(!"Replace");

    Reverse(v2);
    if (v2 != std::vector<int>{10, 2, 8, 5, 5}) assert(!"Reverse");

    Rotate(v2, Find(v2, 8));
    assert(v2.front() == 8);

    v2 = {5, 8};
    assert(Search(v, v2) == std::begin(v) + 1);

    v2 = {3, 4, 6, 5, 7, 8};
    v3 = v;
    Sort(v2);
    Sort(v3);

    std::cout << "\nv2: ";
    Copy(v2, out); std::cout << "\n";

    std::cout << "v3: ";
    Copy(v3, out); std::cout << "\n";

    std::vector<int> v6;
    SetDifference(v2, v3, std::back_inserter(v6));

    std::cout << "SetDifference: ";
    Copy(v6, out); std::cout << "\n";

    v6.clear();
    SetIntersection(v2, v3, std::back_inserter(v6));

    std::cout << "SetIntersection: ";
    Copy(v6, out); std::cout << "\n";

    v6.clear();
    SetSymmetricDifference(v2, v3, std::back_inserter(v6));

    std::cout << "SetSymmetricDifference: ";
    Copy(v6, out); std::cout << "\n";

    v6.clear();
    SetUnion(v2, v3, std::back_inserter(v6));

    std::cout << "SetUnion: ";
    Copy(v6, out); std::cout << "\n";

    v2 = v;
    v3.resize(5);
    Iota(v3, 5);
    SwapRanges(v2, std::begin(v3));

    if (v2 != std::vector<int>{5, 6, 7, 8, 9}) assert(!"SwapRanges");

    Transform(v2, std::begin(v3), [](int i) {return i * 2;});
    if (v3 != std::vector<int>{10, 12, 14, 16, 18}) assert(!"Transform");

    v2 = {2, 2, 3, 6, 4, 2, 7, 7, 4, 5};
    Sort(v2);
    EraseUnique(v2);
    if (v2 != std::vector<int>{2, 3, 4, 5, 6, 7}) assert(!"EraseUnique");

    //NEW ALGORITHMS

    std::cout << "\n\nNEW ALGORITHMS\n\n";

    assert(Contains(v, 8));
    assert(ContainsIf(v, [](int i) {return i < 5;}));
    assert(ContainsIfNot(v, [](int i) {return i < 5;}));

    std::cout << "Iota: ";
    Copy(Iota<std::vector>(5, 24), out); std::cout << "\n";

    int maxArr[Max(1, 3, 2)];
    static_assert(sizeof(maxArr)/sizeof(maxArr[0]) == 3, "");

    int minArr[Min(1, 3, 2)];
    static_assert(sizeof(minArr)/sizeof(minArr[0]) == 1, "");

    constexpr auto minmaxPair = MinMax(5, 1, 2, 9);

    int minmaxArr1[minmaxPair.first];
    static_assert(sizeof(minmaxArr1)/sizeof(minmaxArr1[0]) == 1, "");

    int minmaxArr2[minmaxPair.second];
    static_assert(sizeof(minmaxArr2)/sizeof(minmaxArr2[0]) == 9, "");

    std::vector<int> toSplit{2, 5, 4, 2, 3, 9, 2};
    auto split = Split(toSplit, 2);
    std::vector<std::vector<int>> rightSplit{{}, {5, 4}, {3, 9}, {}};
    assert(split == rightSplit);

    toSplit = {2, 2, 5, 4, 2, 3, 2, 2, 1, 2, 9};
    v2 = {2, 2};
    split = Split(toSplit, v2);
    rightSplit = {{}, {5, 4, 2, 3}, {1, 2, 9}};
    assert(split == rightSplit);

    assert(Size({1, 2}) == 2);
}
