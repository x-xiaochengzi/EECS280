template <typename iter_type>
bool any_of(iter_type begin, iter_type end, bool (*func)(int)) {
    for (iter_type it = begin; it != end; ++it) {
        if (func(*it)) {
            return true;
        }
    }
    return false;
}

template <typename iter_type, typename predicate>
bool any_of(iter_type begin, iter_type end, predicate pred) {
    for (iter_type it = begin; it != end; ++it) {
        if (pred(*it)) {
            return true;
        }
    }
    return false;
}