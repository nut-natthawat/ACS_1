#include <stdio.h>
#include <string.h>
int main(){
    char sentence[100],word[100][100];
    int flag=1,i,count[10] = {},n=0,max,position;
    printf("Input the sentence : ");
    gets(sentence);
    for(i=0;sentence[i] != '\0';i++){
        if(sentence[i] != ' ' && sentence[i] != '.'){
            word[flag][n] = sentence[i];
            n++;
        }
        else if(sentence[i] == ' '){
            flag++;
            n=0;
        }
    }
    max = count[1];
    for(i = flag ; i > 0 ; i--){
        count[i] = strlen(word[i]);
        if(max < count[i]){
            max = count[i];
            position = i;
        }
        printf("word[%d] : %s\n",i,word[i]);
    }
    printf("The longest word is consists of %d chatacters.",max);
    printf("\nIt is in the position no. %d of the sentence",position);
    printf("\nThis word is %s.",word[position]);

}