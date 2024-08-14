#include <stdio.h>
void swap(int x[100][100],int m ,int n,int a,int b);
int main(){
    int a[100][100],m,n,i,j,c1,c2;
    printf("input order of matrix m,n : ");
    scanf("%d %d",&m,&n);
    printf("input matrix A\n");
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("input column number for swapping(c1,c2) : ");
    scanf("%d %d",&c1,&c2);
    printf("\noutput matrix a\n");
    swap(a,m,n,c1,c2);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
void swap(int a[100][100],int m ,int n,int c1,int c2){
    int temp,i,j;
    for(i=1;i<=m;i++){
        temp = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = temp;
    }
}