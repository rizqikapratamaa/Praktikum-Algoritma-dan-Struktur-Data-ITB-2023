#include "listrec.h"

List inverseList (List l){
    if (isOneElmt(l) || isEmpty(l)){
        return l;
    }

    return konsb(inverseList(tail(l)), head(l));
}

void splitOnIdx(List l, List *l1, List *l2, int num){
    if (num == 0){
        *l2 = l;
    } else {
        *l1 = konsb(*l1, head(l));
        l = tail(l);

        splitOnIdx(l, l1, l2, num - 1);
    }
}

int main(){
    int n; scanf("%d",&n);

    List l = NULL;

    while (n > 0)
    {
        int x; scanf("%d", &x);
        l = konsb(l, x);
        n--;
    }

    int nq; scanf("%d", &nq);
    while (nq > 0)
    {
        int query; scanf("%d", &query);
        List l1 = NULL;
        List l2 = NULL;

        splitOnIdx(l, &l1, &l2, query);

        l1 = inverseList(l1);
        l2 = inverseList(l2);

        l = concat(l1, l2);

        nq--;
    }

    displayList(l);
    
}