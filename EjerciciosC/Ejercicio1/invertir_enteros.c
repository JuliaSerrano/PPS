#include <stdio.h>

#include <stdlib.h>


const char* readFile(){


	/*pointer of type FILE, open for reading*/
	FILE *in = fopen("numeros.txt","r");
	static int arr[10];
	char c;
	int counter = 0;
	int i;
	static char str[60];
	/*file doesn't exist*/
	if (in == NULL){
		perror("Error while opening the file.\n");
		exit(0);
	}

	if(fgets(str,60,in)!=NULL){
		puts(str);
	}
	
	fclose(in);
	return str;
	/* gets the next character until the end of file/error (EOF)  */
/*	while((c=fgetc(in))!=EOF){
		arr[counter]=c;
		counter++;
	fclose(in);
	for(i=0;i<counter;i++)
		printf("%d ", arr[i]);		

*/
}








int main() {
  /*	int *p;
	int i;
	p = readFile();
	for (i = 0;i<10;i++){
	printf( "%d\n",*p);
*/
	printf("%s",readFile());

	return 0;
	
}
