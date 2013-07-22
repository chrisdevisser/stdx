//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

#include "../mpl.hh"

int main() {
    using namespace stdx::MplNs;

    struct AbsVD {virtual ~AbsVD() = 0;};
    struct AssignInt {AssignInt &operator=(int) noexcept;};
    enum Enum : long {};
    struct Functor {void operator()(int);};

    //BOOLEAN CONSTANTS

    static_assert(HasVirtualDestructor<AbsVD>(), "");
    static_assert(IsAbstract<AbsVD>(), "");
    static_assert(IsArithmetic<int>(), "");
    static_assert(IsArray<int[]>(), "");
    static_assert(IsAssignable<AssignInt, int>(), "");
    static_assert(IsClass<AbsVD>(), "");
    static_assert(IsCompound<AbsVD>(), "");
    static_assert(IsConst<const int>(), "");
    static_assert(IsConstructible<AssignInt>(), "");
    static_assert(IsCopyAssignable<AssignInt>(), "");
    static_assert(IsDefaultConstructible<AssignInt>(), "");
    static_assert(IsDestructible<AbsVD>(), "");
    static_assert(!IsEmpty<AbsVD>(), "");
    static_assert(!IsEnum<int>(), "");
    static_assert(IsFloatingPoint<float>(), "");
    static_assert(IsFunction<void()>(), "");
    static_assert(IsFundamental<int>(), "");
    static_assert(IsIntegral<int>(), "");
    static_assert(IsLiteralType<int>(), "");
    static_assert(IsLvalueReference<int&>(), "");
    static_assert(IsMemberFunctionPointer<void(AbsVD::*)()>(), "");
    static_assert(IsMemberObjectPointer<int(AbsVD::*)>(), "");
    static_assert(IsMemberPointer<int(AbsVD::*)>(), "");
    static_assert(IsMoveAssignable<AssignInt>(), "");
    static_assert(IsMoveConstructible<AssignInt>(), "");
    static_assert(IsNothrowAssignable<AssignInt, int>(), "");
    static_assert(IsNothrowConstructible<AssignInt>(), "");
    static_assert(IsNothrowCopyAssignable<AssignInt>(), "");
    static_assert(IsNothrowCopyConstructible<AssignInt>(), "");
    static_assert(IsNothrowDefaultConstructible<AssignInt>(), "");
    static_assert(IsNothrowDestructible<AssignInt>(), "");
    static_assert(IsNothrowMoveAssignable<AssignInt>(), "");
    static_assert(IsNothrowMoveConstructible<AssignInt>(), "");
    static_assert(IsObject<decltype(AssignInt{})>(), "");
    static_assert(IsPod<int>(), "");
    static_assert(IsPointer<int*>(), "");
    static_assert(IsPolymorphic<AbsVD>(), "");
    static_assert(IsReference<int&>(), "");
    static_assert(IsRvalueReference<int&&>(), "");
    static_assert(IsScalar<int>(), "");
    static_assert(IsSigned<int>(), "");
    static_assert(IsStandardLayout<int>(), "");
    static_assert(IsTrivial<int>(), "");
//    static_assert(IsTriviallyAssignable<AssignInt>(), "");
//    static_assert(IsTriviallyConstructible<AssignInt>(), "");
//    static_assert(IsTriviallyCopyAssignable<AssignInt>(), "");
//    static_assert(IsTriviallyCopyConstructible<AssignInt>(), "");
//    static_assert(IsTriviallyDefaultConstructible<AssignInt>(), "");
    static_assert(IsTriviallyDestructible<AssignInt>(), "");
//    static_assert(IsTriviallyMoveAssignable<AssignInt>(), "");
//    static_assert(IsTriviallyMoveConstructible<AssignInt>(), "");
    static_assert(!IsUnion<int>(), "");
    static_assert(IsUnsigned<unsigned>(), "");
    static_assert(IsVoid<void>(), "");
    static_assert(IsVolatile<volatile int>(), "");


    //OTHER GETTERS

    static_assert(AlignmentOf<char>() == 1, "");
    static_assert(!IsBaseOf<int, double>(), "");
    static_assert(IsConvertible<int, double>(), "");
    static_assert(Extent<int[3]>() == 3, "");
    static_assert(IsSame<int, int>(), "");
    static_assert(Rank<int[1][1]>() == 2, "");


    //BASIC TYPES

    static_assert(IsSame<AddConst<int>, const int>(), "");
    static_assert(IsSame<AddCv<int>, const volatile int>(), "");
    static_assert(IsSame<AddLvalueReference<int>, int &>(), "");
    static_assert(IsSame<AddPointer<int>, int *>(), "");
    static_assert(IsSame<AddRvalueReference<int>, int &&>(), "");
    static_assert(IsSame<AddVolatile<int>, volatile int>(), "");
    static_assert(IsSame<MakeSigned<unsigned>, signed>(), "");
    static_assert(IsSame<MakeUnsigned<signed>, unsigned>(), "");
    static_assert(IsSame<RemoveAllExtents<int[1][1]>, int>(), "");
    static_assert(IsSame<RemoveConst<const int>, int>(), "");
    static_assert(IsSame<RemoveCv<const volatile int>, int>(), "");
    static_assert(IsSame<RemoveExtent<int[][2]>, int[2]>(), "");
    static_assert(IsSame<RemovePointer<int *>, int>(), "");
    static_assert(IsSame<RemoveReference<int &>, int>(), "");
    static_assert(IsSame<RemoveVolatile<volatile int>, int>(), "");


    //OTHER TYPES

    static_assert(IsSame<CommonType<int, long, short>, long>(), "");
    static_assert(IsSame<Conditional<true, int, long>, int>(), "");
    static_assert(IsSame<Decay<int[]>, int *>(), "");
    static_assert(IsSame<EnableIf<true, int>, int>(), "");
    static_assert(IsSame<ResultOf<Functor, int>, void>(), "");
    static_assert(IsSame<UnderlyingType<Enum>, long>(), "");


    //ADDED

    static_assert(IsBothCv<const volatile int>(), "");
    static_assert(IsEitherCv<const int>(), "");
    static_assert(IsSame<DisableIf<false, int>, int>(), "");
    static_assert(IsSame<Id<const int[2]>, const int[2]>(), "");

    static_assert(IsSame<Bare<int[]>, int>(), "");
    static_assert(IsSame<Bare<int &>, int>(), "");
    static_assert(IsSame<Bare<int(&)[]>, int>(), "");
    static_assert(IsSame<Bare<const int * const volatile * volatile *(&)[1]>, int>(), "");
}
