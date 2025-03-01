#ifndef ANY_OF_HPP
#define ANY_OF_HPP

template <typename iter_type>
bool any_of(iter_type begin, iter_type end, bool (*cond)(int));
bool is_odd(int x);
bool is_even(int x);
bool is_positive(int x);

template <typename iter_type, typename predicate>
bool any_of(iter_type begin, iter_type end, predicate pred);
#include "any_of.tpp"
#endif // ANY_OF_HPP