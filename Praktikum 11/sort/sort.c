#include "sort.h"

Address findMiddle(List l){
    int len = length(l);
    int middle;

    if (len % 2 == 0){
        middle = len/2 - 1;
    } else {
        middle = len /2;
    }

    Address p = l;

    while (middle > 0)
    {
        p = NEXT(p);
        middle--;
    }
    return p;
}

List merge(List l1, List l2){
    if (isEmpty(l1)){
        return l2;
    }

    if (isEmpty(l2)){
        return l1;
    }

    List l = NULL;

    while (!isEmpty(l2) && !isEmpty(l1))
    {
        if (head(l1) < head(l2)){
            l = konsb(l, head(l1));
            l1 = NEXT(l1);
        } else {
            l = konsb(l, head(l2));
            l2 = NEXT(l2);
        }
    }

    while (!isEmpty(l2))
    {
        l = konsb(l, head(l2));
        l2 = tail(l2);
    }
    
    while (!isEmpty(l1))
    {
        l = konsb(l, head(l1));
        l1 = tail(l1);
    }   
    return l;
}

List mergeSort(List l){
    if (isEmpty(l) || isOneElmt(l)){
        return l;
    } else {
        List left = l;
        List right = NEXT(findMiddle(l));
        NEXT(findMiddle(l))= NULL;

        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }
}

List zigZagSort(List l){
    List new = mergeSort(l);
    List loc = NULL;

    while (!isEmpty(new))
    {
        if (!isEmpty(new)){
            loc = konsb(loc, head(new));
            new = tail(new);
        }

        if (!isEmpty(new)){
            Address p = new;
            Address prev = p;
            while (NEXT(p) != NULL)
            {
                prev = p;
                p = NEXT(p);
            }

            loc = konsb(loc, head(p));
            if (p == prev){
                new = NULL;
            } else {
                NEXT(prev) = NULL;
            }
        }
    }
    return loc;
}