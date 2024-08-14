#include <stdio.h>
void Convert(int a){
    float num;
    if(a==1){
        printf("Enter dimention in Centimeter : ");
        scanf("%f",&num);
        printf("The %.2f Centimeter(s) equal to %.2f inch(es).\n",num,num/2.54);
    }
    else if (a==2){
        printf("Enter weight in Kilogram : ");
        scanf("%f",&num);
        printf("The %.2f Kilogram(s) equal to %.2f Pound(s).\n",num,num*2.2);
    }
    else if (a==3){
        printf("Enter temperature in Celcius : ");
        scanf("%f",&num);
        printf("The %.2f Celcius(es) equal to %.2f Frenheit(s).\n",num,(num*9/5)+32);
    }
    else if (a==4){
        printf("Enter vloume in Litre : ");
        scanf("%f",&num);
        printf("The %.2f Litre(s) equal to %.2f US Gallon(s).\n",num,num/3.785);
    }
    else{
        printf("Invalid Input");
    }
    
}
int main(){
    int choice; 
    char gonext;
    for(int i=1;;i++){
    printf("Select an operation.\n");
    printf("\n1.Convert Centmeter into Inch\n");
    printf("2.Convert kilogram into Pound\n");
    printf("3.Convert Celcius to Farenheit\n");
    printf("4.Convert Litre into US Gallon\n");
    printf("\nEnter choice(1/2/3/4): ");
    scanf("%d",&choice);
    Convert(choice);
    printf("\nLet's do next calculate? (y/n) : ");
    scanf("%s",&gonext);
    if(gonext == 'y'|| gonext == 'Y'){
        Convert(choice);
    }
    else if(gonext == 'n'|| gonext == 'N'){
        break;
    }
    }
}