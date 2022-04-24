//思路：创建树，先mallocN个节点，后根据联系进行指针赋值。用双亲孩子表示法
//判断真假：3个数组存储判断语句，分别是name1/relationship/name2，期间跳过2/1个不读

//怎么把字符串整个赋值？？strcpy怎么判断空格缩进从而确定代际关系？？用数组
//不能用gets来接受以空格结束的字符串，因为gets是以回车或EOF为结束标志的
//strcpy相同返回0

//注意：结构体变量的每个成员赋初值，N>=2,M<=100,name<=10
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define OK 0
#define OVERFLOW -1
#define ERROR -2
typedef int Status;
typedef char Elem;
typedef struct BiTNode{
    Elem data[10];//名字长度不超过10
    int parent, lchild, rchild;
}BiTNode, * BiTree;
Status Createfamilytree(int n, BiTree &T){
    char mid = 0;//作为中间量读取字符
    int *spacenum;
    spacenum = (int *)malloc(n * sizeof(int));//n个大小的数组，存放name空格缩进量
    if(!spacenum)exit(OVERFLOW);
    T = (BiTree)malloc(n * sizeof(BiTNode));//不同于Huffman树，有n个节点，每个都存数据
    if(!T)exit(OVERFLOW);
    for(int i = 0; i < n; ++i){//初始化节点
        int j = 0, cou = 0;
        scanf("%c", &mid);
        do{
            if(mid == ' ' && mid != '\n')
                ++cou;
            else
                T[i].data[j++] = mid;
            scanf("%c", &mid);
        }while(mid != '\n');
        spacenum[i] = cou;

        //printf("%d",cou);

        T[i].parent = 0;
        T[i].lchild = 0;
        T[i].rchild = 0;
    }
    for(int j = 0; j < n - 1; ++j){//从上向下连接树的各节点，即空格缩进数由小到大
        if(spacenum[j] < spacenum[j + 1]){//后代
            T[j].lchild = j + 1;
            T[j + 1].parent = j;
        }
        else if(spacenum[j] = spacenum[j + 1]){//同代
            T[j - 1].rchild = j + 1;
            T[j + 1].parent = j - 1;
        }
        else if(spacenum[j] > spacenum[j + 1]){//前代
            int i = 0;
            do{
                if(spacenum[i] < spacenum[j + 1] && spacenum[i + 1] == spacenum[j + 1]){//找同代的双亲
                    T[i].rchild = j + 1;
                    break;
                }
            }while(++i);
        }//else if
    }//for(int j = 0; j < n - 1; ++j)

    //printf("%d",T[0].lchild);

    return OK;
}
Status Judge(int m, int n, BiTree T){
    for(int i = 0; i < m; ++i){
        char name1[10], rel[20], name2[10], mid[20];
        int cur1 = 11, cur2 = 11;//cur1第一个名字位置，cur2第二个名字位置
        scanf("%s", mid);//name1
        strcpy(name1, mid);

        scanf("%s", mid);//is
        scanf("%s", mid);//a or the

        scanf("%s", mid);//rel
        strcpy(rel, mid);

        scanf("%s", mid);//of

        scanf("%s", mid);//name2
        strcpy(name2, mid);
        for(int j = 0; j < n; ++j){
			 if(strcmp(T[j].data, name1) == 0)cur1 = j;
			 if(strcmp(T[j].data, name2) == 0)cur2 = j;
		}//for
        switch(*rel){
            case 'c':if(T[cur1].parent == cur2)//判断：cur1是否cur2孩子
                        printf("True");
                     else
                        printf("False");
                     break;
            case 'p':if(T[cur2].parent == cur1)//判断：cur1是否cur2双亲
                        printf("True");
                     else
                        printf("False");
                     break;
            case 's':if(T[cur2].parent == T[cur1].parent)//判断：cur1是否cur2兄弟
                        printf("True");
                     else
                        printf("False");
                     break;
            case 'd':for(int i = 0; T[cur1].parent != 0 && i < n; ++i){//判断：cur1是否cur2后代
                        if(T[cur1].parent == cur2){
                            printf("True");
                            break;
                        }
                        else
                            T[cur1].parent = T[T[cur1].parent].parent;
                     }
                     break;
                     printf("False");
                     break;
            case 'a':for(int i = 0; T[cur2].parent != 0 &&i < n; ++i){//判断：cur1是否cur2祖先
                        if(T[cur2].parent == cur1){
                            printf("True");
                            break;
                        }
                        else
                            T[cur2].parent = T[T[cur1].parent].parent;
                     }
                     break;
                     printf("False");
                     break;
            default :printf("ERROR");
        }//switch
    }//for(int i = 0; i < m; ++i)
    return OK;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    BiTree T = NULL;
    Createfamilytree(n, T);
    Judge(m, n, T);
    return 0;
}
