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
            //no more to read
			if(strndup(aux,100)== NULL){
                break;
            }
			//add to array
            arr[i] = strndup(aux,100);
        
        i++;
        }
    }while(!feof(in));
	
	fclose(in);
	
	

}




int main() {
	
    
	char *arr[100] = {0};
	readFile(arr);
    int num_elem = i;
    long int res[num_elem];
    
    


    //differentiate between int and string
    for(int x=0;x<num_elem;x++){
        res[x] = strtol(arr[x],NULL,10);
    }
    //printIntegers(res,num_elem);
	
    //print array
	for(int j = 0;j<i;j++){
        
        printf("En array de ints, el Numero es:  %ld\n", res[j]);
        printf("Palabra/Numero: %d es %s\n", j,arr[j]);
         
     }
	return 0;
	
}
