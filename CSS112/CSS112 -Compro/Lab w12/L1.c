#include <stdio.h>
int main(){
    int d,m,y,i,totalday=0,k=0;
    char mounth[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int dayinmounth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("Input dd,mm,yyyy : ");
    scanf("%d %d %d",&d,&m,&y);
    if(y % 4 == 0){
        dayinmounth[1] = 29;
    }
    for(i=0;i<=m-2;i++){
        totalday += dayinmounth[i];
    }
    totalday += d + 75;
    if(totalday <= 365){
        for(i=0;;i++){
            totalday -= dayinmounth[i];
            k++;
            if(totalday <= 31) break;
        }
    }
    else{
        totalday -= 365;
        for(i=0;;i++){
            totalday -= dayinmounth[i];
            k++;
            if(totalday <= 31) break;
        }
        y++;
    }
    printf("%d %s %d",totalday,mounth[k],y);
}