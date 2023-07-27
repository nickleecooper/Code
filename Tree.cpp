#include "stdio.h"
#include "stdlib.h"

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
    int ltag,rtag;
}BiTNode,*BiTree;

BiTNode *p,*final;
BiTNode *pre=NULL;


void Visit(BiTNode *node){
    p=node;
    if (p->lchild==NULL){
        p->lchild=pre;
        p->ltag=1;
    } else{
        p->ltag=0;
    }
    if (pre!=NULL&&pre->rchild==NULL){
        pre->rchild=p;
        pre->rtag=1;
    } else{
        if (pre!=NULL) {
            pre->rtag=0;
        }
    }

    pre=p;
    //printf("%d",node->data);
}

void InitTree(BiTree &T){
    T= (BiTNode*)malloc(sizeof(BiTNode));
    T->data=1;
    BiTNode *node2=(BiTNode*)malloc(sizeof(BiTNode));
    node2->data=2;
    T->lchild=node2;
    BiTNode *node3=(BiTNode*)malloc(sizeof(BiTNode));
    node3->data=3;
    T->rchild=node3;
    BiTNode *node4=(BiTNode*)malloc(sizeof(BiTNode));
    node4->data=4;
    node2->lchild=node4;
    BiTNode *node5=(BiTNode*)malloc(sizeof(BiTNode));
    node5->data=5;
    node2->rchild=node5;
    BiTNode *node6=(BiTNode*)malloc(sizeof(BiTNode));
    node6->data=6;
    node3->lchild=node6;
    BiTNode *node7=(BiTNode*)malloc(sizeof(BiTNode));
    node7->data=7;
    node3->rchild=node7;
    BiTNode *node8=(BiTNode*)malloc(sizeof(BiTNode));
    node8->data=8;
    node6->lchild=node8;
    BiTNode *node9=(BiTNode*)malloc(sizeof(BiTNode));
    node9->data=9;
    node6->rchild=node9;
    node4->rchild=node4->lchild=NULL;
    node5->rchild=node5->lchild=NULL;
    node8->rchild=node8->lchild=NULL;
    node9->rchild=node9->lchild=NULL;
    node7->rchild=node7->lchild=NULL;

}

void InOrder(BiTree T){
    if (T!=NULL){
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
}


void pr(BiTree T){
    if (T->lchild==NULL || T->rchild==NULL) {
        if (T->lchild==NULL) {
            printf("节点号：%d两边都是线索，没有前驱，后继是：%d\n",T->data,T->rchild->data);
        }else{
            printf("节点号：%d两边都是线索，前驱是：%d，没有后继\n",T->data,T->lchild->data);
        }
    }else{
        if (T->ltag==1&&T->rtag==1){
            printf("节点号：%d两边都是线索，前驱是：%d，后继是：%d\n",T->data,T->lchild->data,T->rchild->data);
        }
        if (T->ltag==1&&T->rtag==0){
            printf("节点号：%d左边是线索右边不是\n",T->data);
        }
        if(T->ltag==0&&T->rtag==1){
            printf("节点号：%d右边是线索左边不是\n",T->data);
        }
        if(T->ltag==0&&T->rtag==0){
            printf("节点号：%d两边都不是线索\n",T->data);
        }
    }
}

void print(BiTree T){

    if (T->ltag==0||T->rtag==0) {
        print(T->lchild);
        pr(T);
        print(T->rchild);
    } else {
        pr(T);
    }

}


int main(){
    BiTree T;
    InitTree(T);
    InOrder(T);
    if (pre->rchild==NULL) {
        pre->rtag=1;
    }
    print(T);
    int i;
    return 0;
}

//do