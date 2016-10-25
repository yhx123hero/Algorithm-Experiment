#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<string.h>

int main(void)
{
	long int n = pow(3,13);
	long int i;
	int j;
	
	FILE *fp;  
	
	if ((fp = fopen("F:\\PB14011025-project1\\ex1\\input\\input_strings.txt.txt", "wb")) == NULL)  
	{  
   	 exit(0);  
	} 
	
	for(i = 0;i < n; i++)
	{
		int num; 
		num = rand()%16 + 1;
		char str[17];
		for(j = 0;j < num;j++)
		 {  
			str[j] = 'a' + rand()%24;
		}
		str[j] = '\0';
	    fseek(fp, 0, SEEK_END); 
		fprintf(fp,"%s",str);
		fprintf(fp,"%c",'\n');
	 } 
	 fclose(fp);
}
