//˼·�������������һ���Ǹ��ڵ㣬�������и�Ԫ��ǰ���������������������Դ����ƣ��ݹ飩
//����������Ǵ�����ĩ�ҿ�ʼ����ǰ���ǴӸ���ʼ�����ʺ������дӺ���ǰ���������Եõ�ǰ��
//������ƥ����Ϊ���ҵ�ÿ�������ĸ��������ߣ����ڴ���������С���������ڵڶ��������н��У���ʹ����ʱ�ж���������
//������ͬ�����������ķ�Χ�ں�����ǰ���������
//ע�⣺ʲôʱ�򸳿�
#include<stdio.h>
typedef int ElemType;
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void GetPreTraverseBiTree(int *post, int *mid, int pos){
    if(pos < 0)//���Ϸ�
        return ;
    else{
        int i = 0;
        for(i = 0; mid[i] != post[pos]; ++i){}
        printf(" %d", mid[i]);
        GetPreTraverseBiTree(post, mid, i - 1);//i��Ǵ�ʱ���ڵ��ֵ������pos
        //post+i�����������Ӹ���ʼ��pos-i-1�ֹ�post-i��Ԫ�أ�-1�ӵ����ڶ�����ʼ
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

