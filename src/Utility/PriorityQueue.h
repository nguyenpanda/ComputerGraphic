//
// Created by Hà Tường Nguyên on 5/26/24.
//

#ifndef COMPUTERGRAPHIC_PRIORITYQUEUE_H
#define COMPUTERGRAPHIC_PRIORITYQUEUE_H

#include <iostream>
#include <queue>

template<class T, class S, class C>
S& Container(std::priority_queue<T, S, C>& q) {
    struct HackedQueue : private std::priority_queue<T, S, C> {
        static S& Container(std::priority_queue<T, S, C>& q) {
            return q.*&HackedQueue::c;
        }
    };
    return HackedQueue::Container(q);
}

#endif //COMPUTERGRAPHIC_PRIORITYQUEUE_H
