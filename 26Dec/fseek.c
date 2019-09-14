#include<stdio.h>
int main()
{
	FILE *fp;
	fp = fopen("inp.txt","r");
	int n;
	printf("enter the value of n to read last n characters of file: ");
	scanf("%d",&n);
	char ch;
	fseek(fp,-n,2);
	int fl = 0;
	while(fscanf(fp,"%c",&ch)!=EOF)
	{
		fl=1;
		printf("%c",ch);
	}
	if(fl==0)
	{
		printf("Insufficient number of characters in file\n");
	}
	fclose(fp);
	return 0;
}
