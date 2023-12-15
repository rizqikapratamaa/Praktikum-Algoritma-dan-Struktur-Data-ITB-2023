#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
   BinTree t = newTreeNode(root);
   if(t != NULL){
      LEFT(t) = left_tree;
      RIGHT(t) = right_tree;
   }
   return t;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val){
   Address p = (Address) malloc (sizeof(TreeNode));
   if(p != NULL){
      ROOT(p) = val;
      LEFT(p) = NULL;
      RIGHT(p) = NULL;
   } return p;
}

void deallocTreeNode (Address p){
   free(p);
}

boolean isTreeEmpty (BinTree p){
   return p == NULL;
}

boolean isOneElmt (BinTree p){
   if(!isTreeEmpty(p)){
      return (LEFT(p) == NULL && RIGHT(p) == NULL);
   }
   return false;
}

boolean isUnerLeft (BinTree p){
   if(!isTreeEmpty(p)){
      return (LEFT(p) != NULL && RIGHT(p) == NULL);
   }
   return false;
}

boolean isUnerRight (BinTree p){
   if(!isTreeEmpty(p)){
      return (LEFT(p) == NULL && RIGHT(p) != NULL);
   }
   return false;
}

boolean isBinary (BinTree p){
   if(!isTreeEmpty(p)){
      return (LEFT(p) != NULL && RIGHT(p) != NULL);
   }
   return false;
}

void printPreorder(BinTree p){
   printf("(");
   if (!isTreeEmpty(p)) {
      printf("%d", ROOT(p));
      printPreorder(LEFT(p));
      printPreorder(RIGHT(p));
   }
   printf(")");
}

void printInorder(BinTree p){
   printf("(");
   if (!isTreeEmpty(p)) {
      printInorder(LEFT(p));
      printf("%d", ROOT(p));
      printInorder(RIGHT(p));
   }
   printf(")");
}

void printPostorder(BinTree p){
   printf("(");
   if (!isTreeEmpty(p)) {
      printPostorder(LEFT(p));
      printPostorder(RIGHT(p));
      printf("%d", ROOT(p));
   }
   printf(")");
}

void printTreeDepth(BinTree p, int h, int depth){
   if(!isTreeEmpty(p)){
      int i;
      for(i = 0; i < (h*depth); i++){
         printf(" ");
      }
      printf("%d\n", ROOT(p));
      printTreeDepth(LEFT(p), h, depth+1);
      printTreeDepth(RIGHT(p), h, depth+1);
   }
}

void printTree(BinTree p, int h){
   printTreeDepth(p, h, 0);
}

int hitungNode(BinTree p){
   if (isTreeEmpty(p)){
      return 0;
   }
   int sumNode = 0;
   if (isUnerLeft(p) || isUnerRight(p)){
      sumNode++;
   }
   return sumNode + hitungNode(LEFT(p)) + hitungNode(RIGHT(p));
}

int hitungBebek(BinTree p, int n){
   if (ROOT(p) == n && isOneElmt(p)){
      return ROOT(p) % 10000;
   } else if (isTreeEmpty(p)){
      return 0;
   } else if ( ROOT(p) > n){
      return 0;
   } else if (ROOT(p) < n && isOneElmt(p)){
      return 0;
   } else if (ROOT(p) == n && !isOneElmt(p)){
      return 0;
   }

   int ans = 0;

   if (isUnerLeft(p)){
      ans += (ROOT(p) * hitungBebek(LEFT(p), n - ROOT(p))) % 10000;
   } else if (isUnerRight(p)){
      ans += (ROOT(p) * hitungBebek(RIGHT(p), n - ROOT(p))) % 10000;
   } else{
      ans = (ROOT(p) * hitungBebek(LEFT(p), n - ROOT(p)) + ROOT(p) * hitungBebek(RIGHT(p), n - ROOT(p))) % 10000;
   }

   ans %= 10000;

   return ans;
}

int max(int a, int b){
   if (a > b){
      return a;
   }

   return b;
}

int sum(BinTree p, boolean possible){
   if (isTreeEmpty(p)){
      return 0;
   }

   if (!possible){
      if (isBinary(p)){
         return sum(LEFT(p), true) + sum(RIGHT(p), true);

      } else if (isUnerLeft(p)){

         return sum(LEFT(p), true);
      } else{
         return sum(RIGHT(p), true);
      }
   } else {
      if (isBinary(p)){
         return max(ROOT(p) + sum(LEFT(p), false) + sum(RIGHT(p), false), sum(LEFT(p), true) + sum(RIGHT(p), true));

      } else if (isUnerLeft(p)){
         return max(ROOT(p) + sum(LEFT(p), false), sum(LEFT(p), true));
      } else {
         return max(ROOT(p) + sum(RIGHT(p), false), sum(RIGHT(p), true));
      }
   }
}

int hitungUang(BinTree p){
   if (isTreeEmpty(p)){
      return 0;
   }

   return sum(p, true);
}