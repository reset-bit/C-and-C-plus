//˼·������������mallocN���ڵ㣬�������ϵ����ָ�븳ֵ����˫�׺��ӱ�ʾ��
//�ж���٣�3������洢�ж���䣬�ֱ���name1/relationship/name2���ڼ�����2/1������

//��ô���ַ���������ֵ����strcpy��ô�жϿո������Ӷ�ȷ�����ʹ�ϵ����������
//������gets�������Կո�������ַ�������Ϊgets���Իس���EOFΪ������־��
//strcpy��ͬ����0

//ע�⣺�ṹ�������ÿ����Ա����ֵ��N>=2,M<=100,name<=10
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define OK 0
#define OVERFLOW -1
#define ERROR -2
typedef int Status;
typedef char Elem;
typedef struct BiTNode{
    Elem data[10];//���ֳ��Ȳ�����10
    int parent, lchild, rchild;
}BiTNode, * BiTree;
Status Createfamilytree(int n, BiTree &T){
    char mid = 0;//��Ϊ�м�����ȡ�ַ�
    int *spacenum;
    spacenum = (int *)malloc(n * sizeof(int));//n����С�����飬���name�ո�������
    if(!spacenum)exit(OVERFLOW);
    T = (BiTree)malloc(n * sizeof(BiTNode));//��ͬ��Huffman������n���ڵ㣬ÿ����������
    if(!T)exit(OVERFLOW);
    for(int i = 0; i < n; ++i){//��ʼ���ڵ�
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
    for(int j = 0; j < n - 1; ++j){//���������������ĸ��ڵ㣬���ո���������С����
        if(spacenum[j] < spacenum[j + 1]){//���
            T[j].lchild = j + 1;
            T[j + 1].parent = j;
        }
        else if(spacenum[j] = spacenum[j + 1]){//ͬ��
            T[j - 1].rchild = j + 1;
            T[j + 1].parent = j - 1;
        }
        else if(spacenum[j] > spacenum[j + 1]){//ǰ��
            int i = 0;
            do{
                if(spacenum[i] < spacenum[j + 1] && spacenum[i + 1] == spacenum[j + 1]){//��ͬ����˫��
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
        int cur1 = 11, cur2 = 11;//cur1��һ������λ�ã�cur2�ڶ�������λ��
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
            case 'c':if(T[cur1].parent == cur2)//�жϣ�cur1�Ƿ�cur2����
                        printf("True");
                     else
                        printf("False");
                     break;
            case 'p':if(T[cur2].parent == cur1)//�жϣ�cur1�Ƿ�cur2˫��
                        printf("True");
                     else
                        printf("False");
                     break;
            case 's':if(T[cur2].parent == T[cur1].parent)//�жϣ�cur1�Ƿ�cur2�ֵ�
                        printf("True");
                     else
                        printf("False");
                     break;
            case 'd':for(int i = 0; T[cur1].parent != 0 && i < n; ++i){//�жϣ�cur1�Ƿ�cur2���
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
            case 'a':for(int i = 0; T[cur2].parent != 0 &&i < n; ++i){//�жϣ�cur1�Ƿ�cur2����
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
