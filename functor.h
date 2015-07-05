#ifndef _ETL_FUNCTOR_H_INCLUDED
#define _ETL_FUNCTOR_H_INCLUDED

/*
 * Common functor classes.
 *
 * I'm using the term 'functor' here in the informal C++ sense, not the sense
 * used in category theory.  A functor in C++ is something that can be called.
 *
 * These functors are useful because C++ is willing to work with them in
 * constexpr contexts.  Lambdas -- even lambdas without capture -- cannot
 * appear in constant expressions.  Sigh.
 */

namespace etl {
namespace functor {

/*******************************************************************************
 * Unary arithmetic operators
 */

template <typename A>
struct Negate {
  constexpr auto operator()(A const & a) const -> decltype(-a) {
    return -a;
  }
};

/*******************************************************************************
 * Binary arithmetic operators
 */

template <typename A, typename B>
struct Add {
  constexpr auto operator()(A const & a, B const & b) const -> decltype(a + b) {
    return a + b;
  }
};

template <typename A, typename B>
struct Subtract {
  constexpr auto operator()(A const & a, B const & b) const -> decltype(a - b) {
    return a - b;
  }
};

template <typename A, typename B>
struct Multiply {
  constexpr auto operator()(A const & a, B const & b) const -> decltype(a * b) {
    return a * b;
  }
};

template <typename A, typename B>
struct Divide {
  constexpr auto operator()(A const & a, B const & b) const -> decltype(a / b) {
    return a / b;
  }
};

template <typename A, typename B>
struct Equal {
  constexpr auto operator()(A const & a, B const & b) const
      -> decltype(a == b) {
    return a == b;
  }
};

template <typename A, typename B>
struct NotEqual {
  constexpr auto operator()(A const & a, B const & b) const
      -> decltype(a != b) {
    return a != b;
  }
};

template <typename A, typename B>
struct LogicalAnd {
  constexpr auto operator()(A const & a, B const & b) const
      -> decltype(a && b) {
    return a && b;
  }
};

template <typename A, typename B>
struct LogicalOr {
  constexpr auto operator()(A const & a, B const & b) const
      -> decltype(a || b) {
    return a || b;
  }
};

}  // namespace functor
}  // namespace etl

#endif  // _ETL_FUNCTOR_H_INCLUDED