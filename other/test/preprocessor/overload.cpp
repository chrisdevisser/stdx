#include <stdx/preprocessor/overload.hh>

#define M1 1
#define M2 2
#define M3 3
#define M4 4
#define M5 5
#define M65 65

#define N1(a1) 1
#define N2(a1, a2) 2
#define N3(a1, a2, a3) 3
#define N4(a1, a2, a3, a4) 4
#define N5(a1, a2, a3, a4, a5) 5
#define N65(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, a63, a64, a65) 65

int main() {
	static_assert(STDX_PP_OVERLOAD(M, 1) == 1, "M1");
	static_assert(STDX_PP_OVERLOAD(M, 1, 2) == 2, "M2");
	static_assert(STDX_PP_OVERLOAD(M, 1, 2, 3) == 3, "M3");
	static_assert(STDX_PP_OVERLOAD(M, 1, 2, 3, 4) == 4, "M4");
	static_assert(STDX_PP_OVERLOAD(M, 1, 2, 3, 4, 5) == 5, "M5");
	static_assert(STDX_PP_OVERLOAD(M, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65) == 65, "M65");

	static_assert(STDX_PP_CALL_OVERLOAD(N, 1) == 1, "N1");
	static_assert(STDX_PP_CALL_OVERLOAD(N, 1, 2) == 2, "N2");
	static_assert(STDX_PP_CALL_OVERLOAD(N, 1, 2, 3) == 3, "N3");
	static_assert(STDX_PP_CALL_OVERLOAD(N, 1, 2, 3, 4) == 4, "N4");
	static_assert(STDX_PP_CALL_OVERLOAD(N, 1, 2, 3, 4, 5) == 5, "N5");
	static_assert(STDX_PP_CALL_OVERLOAD(N, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65) == 65, "N65");
}