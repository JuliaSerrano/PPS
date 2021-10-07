#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//counter of number elements we add to array
int i = 0;

//reads 'numeros.txt' file and adds text to an array
void readFile(char *arr[]){

	//variables
    char aux[30];
    FILE *in = fopen("numeros.txt","r");

	//problem opening 'numeros.txt'
	if(in == NULL) {
      perror("Error opening file");
      
   }
    
    do{

		//reads a line
        if (fgets(aux,100,in)!= NULL){
            if(strndup(aux,100)== NULL){
                break;
            }
            arr[i] = strndup(aux,100);
        
        i++;
        }
    }while(!feof(in));
	
	fclose(in);
	
	

}




int main() {
	
	char *arr[100] = {0};
	readFile(arr);
	//print array
	for(int j = 0;j<i;j++){
        
         printf("%s\n", arr[j]);
         
     }
	return 0;
	
}
