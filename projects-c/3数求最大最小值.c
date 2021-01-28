#include<stdio.h>
int comptwo(int a, int b, int t){
    if(t == 1){
        return a > b ? a : b;
    }
    if(t == 0){
        return a > b ? b : a;
    }
}
int main(){
    int a, b, c, max, min;
    scanf("%d%d%d", &a, &b, &c);
    max = comptwo(comtwo(a, b, 1), c, 1);
    min = comptwo(comtwo(a, b, 0), c, 0);
    printf("max = %d\tmin = %d\n", max, min);
}

//第一种
//int max_three(int x, int y, int z){
//    int r = x > y ? x : y;
//    return r > z ? r : z;
//}
//int min_three(int x, int y, int z){
//    int r = x > y ? y : x;
//    return r > z ? z : r;
//}
//int main(){
//    int a, b, c, max, min;
//    scanf("%d%d%d", &a, &b, &c);
//    max = max_three(a, b, c);
//    min = min_three(a, b, c);
//    printf("max = %d\tmin = %d\n", max, min);
//}

//第二种
//int max_two(int x, int y){
//    return x > y ? x : y;
//}
//int min_two(int x, int y){
//    return x > y ? y : x;
//}
//int main(){
//    int a, b, c, max, min;
//    scanf("%d%d%d", &a, &b, &c);
//    max = max_two(a, b);
//    if(max < c){
//        max = c;
//    }
//    min = min_two(a, b);
//    if(min > c){
//        min = c;
//    }
//    printf("max = %d\tmin = %d\n", max, min);
//}
