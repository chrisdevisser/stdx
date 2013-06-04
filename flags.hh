//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

#ifndef SDTX_FLAGS_H
#define STDX_FLAGS_H

#include <bitset>
#include <cstddef>
#include <type_traits>

namespace stdx {

template<typename Enum, std::size_t Size>
struct Flags {
	using enum_type = typename std::underlying_type<Enum>::type;

	Flags();
	Flags(Enum);
	explicit operator Enum() const;
	explicit operator bool() const;
	std::bitset<Size> bits() const;

private:
	std::bitset<Size> bits_;
};

template<typename Enum, std::size_t Size> Flags<Enum, Size> operator|(Flags<Enum, Size>, const Flags<Enum, Size> &);
template<typename Enum, std::size_t Size> Flags<Enum, Size> &operator|=(Flags<Enum, Size> &, const Flags<Enum, Size> &);
template<typename Enum, std::size_t Size> Flags<Enum, Size> operator&(Flags<Enum, Size>, const Flags<Enum, Size> &);
template<typename Enum, std::size_t Size> Flags<Enum, Size> &operator&=(Flags<Enum, Size> &, const Flags<Enum, Size> &);
template<typename Enum, std::size_t Size> Flags<Enum, Size> operator~(const Flags<Enum, Size> &);

template<typename Enum, std::size_t Size> bool all(const Flags<Enum, Size> &);
template<typename Enum, std::size_t Size> bool any(const Flags<Enum, Size> &);
template<typename Enum, std::size_t Size> bool none(const Flags<Enum, Size> &);
template<typename Enum, std::size_t Size> Flags<Enum, Size> &set(Flags<Enum, Size> &, Flags<Enum, Size> = static_cast<Enum>(Size - 1 + Size));
template<typename Enum, std::size_t Size> Flags<Enum, Size> &flip(Flags<Enum, Size> &, const Flags<Enum, Size> & = static_cast<Enum>(Size - 1 + Size));
template<typename Enum, std::size_t Size> Flags<Enum, Size> &reset(Flags<Enum, Size> &, const Flags<Enum, Size> & = static_cast<Enum>(Size - 1 + Size));

#define MAKE_ENUM_FLAGS(Enum, Size, Name) \
	using Name = stdx::Flags<Enum, Size>; \
	\
	Name operator|(Enum lhs, Enum rhs) { \
		return static_cast<Name>(lhs) | static_cast<Name>(rhs); \
	} \
	\
    Name operator&(Name lhs, Enum rhs) { \
		return lhs & static_cast<Name>(rhs); \
	} \
	\
	Name operator~(Enum e) { \
		return ~static_cast<Name>(e); \
	}


template<typename Enum, std::size_t Size>
Flags<Enum, Size>::Flags() : Flags{static_cast<Enum>(0)} {}

template<typename Enum, std::size_t Size>
Flags<Enum, Size>::Flags(Enum value) : bits_(static_cast<enum_type>(value)) {}

template<typename Enum, std::size_t Size>
Flags<Enum, Size>::operator Enum() const {
	return static_cast<Enum>(bits_.toullong());
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size>::operator bool() const {
	return any(*this);
}

template<typename Enum, std::size_t Size>
std::bitset<Size> Flags<Enum, Size>::bits() const {
	return bits_;
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size> operator|(Flags<Enum, Size> lhs, const Flags<Enum, Size> &rhs) {
	return lhs |= rhs;
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size> &operator|=(Flags<Enum, Size> &lhs, const Flags<Enum, Size> &rhs) {
	return lhs = static_cast<Enum>(lhs.bits().to_ullong() | rhs.bits().to_ullong());
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size> operator&(Flags<Enum, Size> lhs, const Flags<Enum, Size> &rhs) {
	return lhs &= rhs;
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size> &operator&=(Flags<Enum, Size> &lhs, const Flags<Enum, Size> &rhs) {
	return lhs = static_cast<Enum>(lhs.bits().to_ullong() & rhs.bits().to_ullong());
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size> operator~(const Flags<Enum, Size> &e) {
	return ~static_cast<Enum>(e.bits().to_ullong());
}

template<typename Enum, std::size_t Size>
bool all(const Flags<Enum, Size> &e) {
	return e.bits().all();
}

template<typename Enum, std::size_t Size>
bool any(const Flags<Enum, Size> &e) {
	return e.bits().any();
}

template<typename Enum, std::size_t Size>
bool none(const Flags<Enum, Size> &e) {
	return e.bits().none();
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size> &set(Flags<Enum, Size> &e, Flags<Enum, Size> bits) {
	return e |= bits;
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size> &flip(Flags<Enum, Size> &e, const Flags<Enum, Size> &bits) {
	std::bitset<Size> b = e.bits();
	b.flip(static_cast<typename Flags<Enum, Size>::enum_type>(bits));
	return e = Flags<Enum, Size>(static_cast<Enum>(b.to_ullong()));
}

template<typename Enum, std::size_t Size>
Flags<Enum, Size> &reset(Flags<Enum, Size> &e, const Flags<Enum, Size> &bits) {
	return e &= ~bits;
}

}

#endif
