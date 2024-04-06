#include <stdio.h>
void change(int a);
int input;
int main (){
    printf("Enter the number of day : ");
    scanf("%d",&input);
    change(input);
}
void change(int a){
    int year,month,day;
    year = a/365;
    month = (a-(365*year))/30;
    day = (a-(365*year))-(30*month);
    printf("Year = %d\nMonth = %d\nDay = %d",year,month,day);
} 

