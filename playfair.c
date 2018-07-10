#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	int main()
	{
		char a[5][5], key[26],msg[100];
		int i,j,n,stlen,k;
		printf("Enter the key");
		gets(key);
		stlen=strlen(key);
		i=0;
		j=0;
		k=0;
		while(key[k]!='\0')
		{
		for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		a[i][j]=key[k];
		k++;
		}
		printf("Key matrix is=");
		for(i=0;i<5;i++)
		{
		
			for(j=0;j<5;j++)
			{
		
			printf("%d  ",a[i][j]);
			}
			
			printf("\n");
			}
	return 0;
	}
	
		
