#include<stdio.h>
#define MAX_SIZE 100
int get_matrix(int ma[][MAX_SIZE], int m, int n){
    int i = 0, j = 0;
    for(i = 0; i < m; ++i)
        for(j = 0; j < n; ++j)
            scanf("%d", &ma[i][j]);
    return 0;
}
int put_matrix(int ma[][MAX_SIZE], int m, int n){
    int i = 0, j = 0;
    for(i = 0; i < m; ++i){
        for(j = 0; j < n - 1; ++j)
            printf("%d ", ma[i][j]);//�򻯰汾�����
        printf("%d\n", ma[i][j]);
    }
    return 0;
}
int mul_matrix(int pr[][MAX_SIZE], int m1[][MAX_SIZE], int m2[][MAX_SIZE], int m, int n, int q){
    //����ע����ô��˵ģ�
    int i,j,k;
    for(i=0;i<m;i++){
        for(j=0;j<q;j++){
            pr[i][j] = 0;//����գ���
            for(k=0;k<n;k++){
                pr[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    return 0;
}
