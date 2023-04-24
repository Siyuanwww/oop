#pragma once
#include "abstract_compare.h"
#include <vector>

template<class T> class PriorityQueue {
    std::vector<T> vec_;
    AbstractCompare<T> *cmp_;
public:
    PriorityQueue(AbstractCompare<T> *_cmp);
    ~PriorityQueue();
    bool empty();
    int size();
    void push(T element);
    void pop();
    T top();
};

template <class T>
PriorityQueue<T>::PriorityQueue(AbstractCompare<T> *_cmp) : cmp_(_cmp) {}
template <class T>
PriorityQueue<T>::~PriorityQueue() {
    vec_.clear();
    delete cmp_;
}
template <class T>
bool PriorityQueue<T>::empty() {
    return vec_.empty();
}
template <class T>
int PriorityQueue<T>::size() {
    return vec_.size();
}
template <class T>
void PriorityQueue<T>::push(T element) {
    for (auto it = vec_.begin(); it != vec_.end(); ++it) {
        if (cmp_->compare(*it, element)) {
            vec_.insert(it, element);
            return;
        }
    }
    vec_.push_back(element);
}
template <class T>
void PriorityQueue<T>::pop() {
    vec_.pop_back();
}
template <class T>
T PriorityQueue<T>::top() {
    return vec_.back();
}