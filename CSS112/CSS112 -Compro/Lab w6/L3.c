#include <stdio.h>
int main(){
    int m,n;
    printf("input order of matrix A m,n = ");
    scanf("%d %d",&m,&n);
    printf("input element of matrix A\n");
    int a[m][n];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        int sum = 0;
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
            sum += a[i][j];
        }
        printf("sum of row = %d\n",sum);
    }
}