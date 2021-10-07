#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {


    static char *arr[30];
    char aux[30];

    //stores number of elements we add to arr
    int i = 0;

    //open file
    FILE *in = fopen("numeros.txt","r");
    
    do{
        //read the file
        if (fgets(aux,30,in)!= NULL){
            //no more to read
            if(strndup(aux,30)== NULL){
                break;
            }
            //add to array
            arr[i] = strndup(aux,30);
        
            i++;
        }
    }while(!feof(in));
   
   
    
    //print array
    for(int j = 0;j<i;j++){
        
         printf("%s", arr[j]);
         
     }
   

    //close file
    fclose(in);
    return 0;

}