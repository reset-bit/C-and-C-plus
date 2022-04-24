//思路：后序序列最后一个是根节点，中序序列该元素前是左子树后是右子树，以此类推（递归）
//后序和中序是从树的末梢开始读，前序是从根开始读，故后序序列从后向前遍历，可以得到前序
//和中序匹配是为了找到每个子树的根并向左走，至于大左子树的小右子树会在第二个遍历中进行（根使返回时判断右子树）
//右子树同理：在右子树的范围内后序向前，中序向后
//注意：什么时候赋空
#include<stdio.h>
typedef int ElemType;
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void GetPreTraverseBiTree(int *post, int *mid, int pos){
    if(pos < 0)//不合法
        return ;
    else{
        int i = 0;
        for(i = 0; mid[i] != post[pos]; ++i){}
        printf(" %d", mid[i]);
        GetPreTraverseBiTree(post, mid, i - 1);//i标记此时根节点的值，不是pos
        //post+i舍弃左子树从根开始，pos-i-1现共post-i个元素，-1从倒数第二个开始
        GetPreTraverseBiTree(post + i, mid + i + 1, pos - i - 1);
    }
}
int main(){
    int n = 0;
    int post[31], mid[31];
    BiTNode T;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", post + i);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", mid + i);
    }
    printf("Preorder:");
    GetPreTraverseBiTree(post, mid, n - 1);
    return 0;
}

