#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
class const_iterator {
    vector<int>::const_iterator iter;

public:
    const_iterator(vector<int>::const_iterator iter) : iter(iter) {}

    const_iterator operator--(int) {
        const_iterator prev = *this;
        iter--;
        return prev;
    }

    const_iterator& operator--() {
        --iter;
        return *this;
    }

    int operator*() const {
        return *iter;
    }

    bool operator!=(const const_iterator& other) const {
        return iter != other.iter;
    }
};