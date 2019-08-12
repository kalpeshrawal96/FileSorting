#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int arr[100];
int result[20],temp[20];
int num,total,numCoin,min,size,max = 20;
bool flag = false;

typedef struct Data{
    int id;
    char fname[20];
    char lname[20];
    char address[40];
    char area[30];
    char city[30];
    char cityCode[7];
    char pinCode[10];
    char contact1[20];
    char contact2[20];
    char email[40];
}Data;

struct Data readData(FILE *f);
void writeData(FILE *f,Data d);
void markAndDistribute(FILE *s,FILE *d1,FILE *d2);
bool mergeSources(FILE *s1,FILE *s2,FILE *d);
bool mergeSourcesFor2s2d(FILE *s1,FILE *s2,FILE *des1,FILE *des2);
void distributeRuns(FILE *s,FILE *d1,FILE *d2);
void fileSorting2s1d(FILE *f1, FILE *f2, FILE *f3);
void fileSorting2s2d(FILE *f1, FILE *f2, FILE *f3,FILE *f4);

void sortData();
void createData();
void printData();
void processData();
void printResult();

void polyPhaseProcessing(char fileName[11],int fibo);
int markData(FILE *s,FILE *d);
void fileSortingPolyPhase(FILE *f1, FILE *f2, FILE *f3);
int algo,file;

int main()
{
    FILE *f1,*f2,*f3,*f4;
    char ch;
	/*
    f1 = fopen("Random.csv", "r");
    f2 = fopen("temp1.csv", "w");
    f3 = fopen("temp2.csv", "w");
    f4 = fopen("temp3.csv", "w");
    markAndDistributr(f1,f2,f3);
    fclose(f1);
    fclose(f2);
	fclose(f3);
	fclose(f4);
	//one step
	f1 = fopen("temp1.csv", "r");
    f2 = fopen("temp2.csv", "r");
    f3 = fopen("temp3.csv", "w");
	mergeSources(f1,f2,f3);
	fclose(f1);
    fclose(f2);
	fclose(f3);
	f1 = fopen("temp1.csv", "w");
    f2 = fopen("temp2.csv", "w");
    f3 = fopen("temp3.csv", "r");
	distributeRuns(f3,f1,f2);
    fclose(f1);
    fclose(f2);
	fclose(f3);
	//two step
	f1 = fopen("temp1.csv", "r");
    f2 = fopen("temp2.csv", "r");
    f3 = fopen("temp4.csv", "w");
	mergeSources(f1,f2,f3);
	fclose(f1);
    fclose(f2);
	fclose(f3);
	f1 = fopen("temp1.csv", "w");
    f2 = fopen("temp2.csv", "w");
    f3 = fopen("temp4.csv", "r");
	distributeRuns(f3,f1,f2);
    fclose(f1);
    fclose(f2);
	fclose(f3);
	//three step
	f1 = fopen("temp1.csv", "r");
    f2 = fopen("temp2.csv", "r");
    f3 = fopen("temp5.csv", "w");
	mergeSources(f1,f2,f3);
	fclose(f1);
    fclose(f2);
	fclose(f3);
	f1 = fopen("temp1.csv", "w");
    f2 = fopen("temp2.csv", "w");
    f3 = fopen("temp5.csv", "r");
	distributeRuns(f3,f1,f2);
    fclose(f1);
    fclose(f2);
	fclose(f3);
	//four step
	f1 = fopen("temp1.csv", "r");
    f2 = fopen("temp2.csv", "r");
    f3 = fopen("temp6.csv", "w");
	mergeSources(f1,f2,f3);
	fclose(f1);
    fclose(f2);
	fclose(f3);
	f1 = fopen("temp1.csv", "w");
    f2 = fopen("temp2.csv", "w");
    f3 = fopen("temp6.csv", "r");
	distributeRuns(f3,f1,f2);
    fclose(f1);
    fclose(f2);
	fclose(f3);
	//five step
	f1 = fopen("temp1.csv", "r");
    f2 = fopen("temp2.csv", "r");
    f3 = fopen("temp7.csv", "w");
	mergeSources(f1,f2,f3);
	fclose(f1);
    fclose(f2);
	fclose(f3);
	f1 = fopen("temp1.csv", "w");
    f2 = fopen("temp2.csv", "w");
    f3 = fopen("temp7.csv", "r");
	distributeRuns(f3,f1,f2);
    fclose(f1);
    fclose(f2);
	fclose(f3);
	//six step
	f1 = fopen("temp1.csv", "r");
    f2 = fopen("temp2.csv", "r");
    f3 = fopen("temp8.csv", "w");
	mergeSources(f1,f2,f3);
	fclose(f1);
    fclose(f2);
	fclose(f3);
	f1 = fopen("temp1.csv", "w");
    f2 = fopen("temp2.csv", "w");
    f3 = fopen("temp8.csv", "r");
	distributeRuns(f3,f1,f2);
    fclose(f1);
    fclose(f2);
	fclose(f3);
	*/
	/*
	//following is valid code
    //fileSorting2s1d(f1,f2,f3);
    */
    do
    {
	    printf("\nWhich algorithm you would like to use:");
		printf("\n0. for exit");
	    printf("\n1. for 2s 1d");
	    printf("\n2. for 2s 2d");
	    printf("\n3. for Poly Phase\nYour choice:");
	    scanf("%d",&algo);
	    if(algo != 0)
	    {
		    printf("\nWhich file you would like to use:");
		    printf("\n1. for Sorted");
		    printf("\n2. for Sorted but 1 misplaced");
		    printf("\n3. for Reverse");
		    printf("\n4. for Reverse but 1 misplaced");
		    printf("\n5. for Random\nYour choice:");
		    scanf("%d",&file);
		    switch(file)
		    {
		    	case 1:
		    		f1 = fopen("Sorted","r");
		    		f2 = fopen("temp1","w");
		    		ch = fgetc(f1);
		    		while(ch != EOF)
		    		{
		    			fputc(ch,f2);
		    			ch = fgetc(f1);
					}
					fclose(f1);
					fclose(f2);
					break;
				case 2:
					f1 = fopen("Sorted But One","r");
		    		f2 = fopen("temp1","w");
		    		ch = fgetc(f1);
		    		while(ch != EOF)
		    		{
		    			fputc(ch,f2);
		    			ch = fgetc(f1);
					}
					fclose(f1);
					fclose(f2);
					break;
				case 3:
					f1 = fopen("Reverse","r");
		    		f2 = fopen("temp1","w");
		    		ch = fgetc(f1);
		    		while(ch != EOF)
		    		{
		    			fputc(ch,f2);
		    			ch = fgetc(f1);
					}
					fclose(f1);
					fclose(f2);
					break;
				case 4:
					f1 = fopen("Reverse But One","r");
		    		f2 = fopen("temp1","w");
		    		ch = fgetc(f1);
		    		while(ch != EOF)
		    		{
		    			fputc(ch,f2);
		    			ch = fgetc(f1);
					}
					fclose(f1);
					fclose(f2);
					break;
				case 5:
					f1 = fopen("Random","r");
		    		f2 = fopen("temp1","w");
		    		ch = fgetc(f1);
		    		while(ch != EOF)
		    		{
		    			fputc(ch,f2);
		    			ch = fgetc(f1);
					}
					fclose(f1);
					fclose(f2);
					break;
				default:
					printf("\n Please enter some valid number!!!");
			}
			switch(algo)
			{
				case 1:
					fileSorting2s1d(f1,f2,f3);
					break;
				case 2:
					fileSorting2s2d(f1,f2,f3,f4);
					break;
				case 3:
					fileSortingPolyPhase(f1,f2,f3);
					break;
				case 0:
					printf("\nGood Bye!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
				default:
					printf("\n Please enter some valid number!!!");
			}
		}
	}while(algo != 0);
	return 0;
}

void polyPhaseProcessing(char fileName[11],int fibo)
{
	struct Data d1,d2;
	char c1,c2,ch;
	int counter = 0;
	bool data1 = false,data2 = false;
	int fibo1,fibo2,t,i,j,n = 0,c = 0;
	FILE *f1,*f2,*f3,*s1,*s2,*d;
	f1 = fopen(fileName,"r");
	f2 = fopen("ptemp1","w");
	f3 = fopen("ptemp2","w");
	i = 0;
	while(arr[i] != 0)
	{
		if(arr[i] == fibo)
		{
			break;
		}
		i++;
	}
	i++;
	fibo1 = arr[i];/*//big number*/
	i++;
	fibo2 = arr[i];/*//small number*/
	i--;i--;
	while(arr[i] != 0)
	{
		n++;
		i++;
	}
	ch = fgetc(f1);
	while(c < fibo2)
	{
		fputc(ch,f2);
		if(ch == '$')
		{
			printf("\nincrement\n");
			c++;
		}
		ch = fgetc(f1);
	}
	while(ch != EOF)
	{
		fputc(ch,f3);
		ch = fgetc(f1);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	for(i = 0 ; i <= n ; i++)
	{
		if(i == 0)
		{
			s1 = fopen("ptemp1","r");/*//small file*/
			s2 = fopen("ptemp2","r");/*//big file*/
			d = fopen(fileName,"w");/*//destination file*/
		}
		else
		{
			switch( i % 3)
			{
				case 0:
					s1 = fopen("ptemp1","r");/*//small file*/
					s2 = fopen("ptemp2","r");/*//big file*/
					d = fopen(fileName,"w");/*//destination file*/
					break;
				case 1:
					s1 = fopen("ptemp2","r");/*//small file*/
					s2 = fopen(fileName,"r");/*//big file*/
					d = fopen("ptemp1","w");/*//destination file*/
					break;
				case 2:
					s1 = fopen(fileName,"r");/*//small file*/
					s2 = fopen("ptemp1","r");/*//big file*/
					d = fopen("ptemp2","w");/*//destination file*/
					break;
			}
		}
		/*//merging logic goes here-------------------------------------------------------------------------------------------*/
		d1 = readData(s1);
		data1 =true;
		d2 = readData(s2);
		data2 = true;
		printf("\nData is %d,%d ---------------------------------------Merge Started------------------------\n",d1.id,d2.id);
		c1 = fgetc(s1);
		c2 = fgetc(s2);
		printf("\n--------------------%c of s1 run this loop till end of file %c of s2------------------------",c1,c2);
		/*//Merge runs till end of any one run*/
		for(j = 0 ; j < fibo2 ; j++)
		{
			while(c1 != '$' && c2 != '$')
			{
				fseek(s1, -1, SEEK_CUR);
				fseek(s2, -1, SEEK_CUR);
				printf("\n--------------------%c of s1 run this loop till end of run %c of s2------------------------",c1,c2);
				if(d1.id > d2.id)
				{
					printf("\n%d of file s1 is greater than %d of file s2 therefore put %d in d",d1.id,d2.id,d2.id);
					writeData(d,d2);
					d2 = readData(s2);
				}
				else
				{
					printf("\n%d of file s2 is greater than %d of file s1 therefore put %d in d",d2.id,d1.id,d1.id);
					writeData(d,d1);
					d1 = readData(s1);
				}
				c1 = fgetc(s1);
				c2 = fgetc(s2);
			}
			if(c1 == '$')
			{
				fseek(s2, -1, SEEK_CUR);
				printf("\nEnd of run encountered in s1 via '%c' therefore copy till end of run of s2",c1);
				c2 = fgetc(s2);
				while(c2 != '$' && !feof(s2))
				{
					fseek(s2, -1, SEEK_CUR);
					if(data1)
					{
						if(d1.id < d2.id)
						{
							writeData(d,d1);
							data1 = false;
							writeData(d,d2);
							d2 = readData(s2);
						}
						else
						{
							writeData(d,d2);
							d2 = readData(s2);
						}
					}
					else
					{
						writeData(d,d2);
						d2 = readData(s2);
					}
					c2 = fgetc(s2);
				}
				if(data1)
				{
					if(d1.id < d2.id)
					{
						writeData(d,d1);
						data1 = false;
						writeData(d,d2);
					}
					else
					{
						writeData(d,d2);
						writeData(d,d1);
						data1 = false;
					}
				}
				else
				{
					writeData(d,d2);
				}
				printf("\nEnd of run encountered in s2 via '%c' therefore end this iteration",c2);
				fputc(c2,d);
				counter++;
			}
			else
			{
				fseek(s1, -1, SEEK_CUR);
				printf("\nEnd of run encountered in s2 via '%c' therefore copy till end of run of s1",c2);
				c1 = fgetc(s1);
				while(c1 != '$' && !feof(s1))
				{
					fseek(s1, -1, SEEK_CUR);
					if(data2)
					{
						if(d2.id < d1.id)
						{
							writeData(d,d2);
							data2 = false;
							writeData(d,d1);
							d1 = readData(s1);

						}
						else
						{
							writeData(d,d1);
							d1 = readData(s1);
						}
					}
					else
					{
						writeData(d,d1);
						d1 = readData(s1);
					}
					c1 = fgetc(s1);
				}
				if(data2)
				{
					if(d2.id < d1.id)
					{
						writeData(d,d2);
						data2 = false;
						writeData(d,d1);
					}
					else
					{
						writeData(d,d1);
						writeData(d,d2);
						data2 = false;
					}
				}
				else
				{
					writeData(d,d1);
				}
				printf("\nEnd of run encountered in s1 via '%c' therefore end this iteration\n",c1);
				fputc(c1,d);
				counter++;
			}
		}
		t = fibo2;
		fibo2 = fibo1 - fibo2;/*//new small number*/
		fibo1 = t;
		/*//merging logic ends here---------------------------------------------------------------------------------------------*/
		fclose(s1);
		fclose(d);
	}
	fclose(s2);
	printf("\nthis is test input:\n");
	scanf("%d",&t);
}

void fileSortingPolyPhase(FILE *f1, FILE *f2, FILE *f3)
{
	int i,t,counter = 0;
	char ch;
	char fileName[11] = {'p', 'o', 'l', 'y', 'F', 'i', 'l', 'e', '0', '0', '\0'};
	num = markData(f1,f2);
	f1 = fopen("polytemp1.csv","r");
	createData();
	sortData();
	printData();
	processData();
	printResult();
	FILE *fileArray[min];
	for(i = 0 ; i <= min ; i++)
	{
		counter = 0;
		if(i % 10 == 0)
		{
			t = i / 10;
			t += 48;
			fileName[8] = t;
			fileName[9] = '0';
		}
		else
		{
			t = i + 48;
			fileName[9] = t;
		}
		fileArray[i] = fopen(fileName,"w");
		printf("\ntest:%d fileName:%s\n",i,fileName);
		ch = fgetc(f1);
		while(counter < result[i])
		{
			fputc(ch,fileArray[i]);
			if(ch == '$')
			{
				printf("\nincrement\n");
				counter++;
			}
			ch = fgetc(f1);
		}
		fseek(f1,-1,SEEK_CUR);
		fclose(fileArray[i]);
		polyPhaseProcessing(fileName,result[i]);
		printf("\ntest:%d fileName:%s\n",i,fileName);
	}
	fclose(f1);
}

int markData(FILE *s,FILE *d)
{
	char ch;
	int counter = 0;
	struct Data current,next;
	s = fopen("temp1","r");
	d = fopen("polytemp1.csv","w");
	current = readData(s);
	next = readData(s);
	ch = getc(s);
	while(ch != EOF)
	{
		fseek(s,-1,SEEK_CUR);
		if(current.id < next.id)
		{
			writeData(d,current);

		}
		else
		{
			writeData(d,current);
			fputc('$',d);
			counter++;
		}
		current = next;
		next = readData(s);
		ch = getc(s);
	}
	if(current.id < next.id)
	{
		writeData(d,current);
		writeData(d,next);
	}
	else
	{
		writeData(d,current);
		fputc('$',d);
		counter++;
		writeData(d,next);
	}
	fseek(d,-1,SEEK_CUR);
	ch = fgetc(d);
	if(ch != '$')
	{
		fseek(d,1,SEEK_CUR);
		fputc('$',d);
		counter++;
	}
	fclose(s);
	fclose(d);
	return counter;
}

void processData()
{
	int i,j;
	for(i = 0; i < size ; i++)
	{
		/*printf("\nfor i:%d depth:%d",i,numCoin);*/
		if(numCoin == 0)
		{
			/*printf("\nset total to zero as num coin is zero");*/
			total = 0;
		}
		if(total+arr[i] < num)
		{
			/*printf("\ntotal is less than amount");*/
			/*printf("\nPrevious total:%d\nnew data to be added:%d\nnew total:%d",total,arr[i],total+arr[i]);*/
			temp[numCoin] = arr[i];
			numCoin++;
			/*printf("\nnumcoin value after incr:%d",numCoin);*/
			total += arr[i];
			if(flag && numCoin > min)
			{
				/*printf("\nsince we have got result shorter than this,\n therefor continue");*/
				continue;
			}
			else
			{
				/*printf("\nwe would like to go more deep for result");*/
				processData();
				/*printf("\ndecrement value of num count on backward jounery");*/
				numCoin--;
				/*printf("\nnumcoin value after decr:%d",numCoin);*/
			}
		}
		else if(total+arr[i] == num )
		{
			/*printf("\nwe have got a new answer-------yeah!!");*/
			temp[numCoin] = arr[i];
			total += arr[i];
			if(flag)
			{
				/*
				printf("\nSince we have got answer before as well lets check with previous one");
				printf("\nSize of previous answer:%d",min);
				printf("\nSize of new answer:%d",numCoin);
				printf("\nNew answer is:");
				for(j = 0 ; j < max ; j++)
				{
					if(temp[j]!=0)
					printf(" %d ",temp[j]);
				}
				*/
				if(numCoin < min)
				{
					/*printf("\nNew answer is great!!");*/
					min = numCoin;
					for(j = 0 ; j < max ; j++)
					{
						result[j] = 0;
					}
					/*printf("\nStore New result");*/
					for(j = 0 ; j < max ; j++)
					{
						result[j] = temp[j];
						temp[j] = 0;
					}
					/*
					printf("\nNew result is:");
					for(j = 0 ; j < max ; j++)
					{
						if(result[j]!=0)
						printf(" %d ",result[j]);
					}
					*/
				}
				return;
			}
			else
			{
				/*printf("\nSet flag to true as we have got first answer");*/
				flag = true;
				/*printf("\nSize of first answer is:%d",numCoin);*/
				min = numCoin;
				for(j = 0 ; j < max ; j++)
				{
					result[j] = 0;
				}
				for(j = 0 ; j < max ; j++)
				{
					result[j] = temp[j];
					temp[j] = 0;
				}
				/*
				printf("\nNew result is:");
				for(j = 0 ; j < max ; j++)
				{
					if(result[j]!=0)
					printf(" %d ",result[j]);
				}
				*/
				return;
			}
		}
		else
		{
			/*printf("\nTotal is more than given amount!!!");*/
			continue;
		}
	}
}


void createData()
{
	int f1 = 0, f2 = 1 , i,t;
	size = 0;
	for(i = 0 ; f2 < num ; i++)
	{
		t = f2;
		f2 += f1;
		f1 = t;
		arr[i] = f2;
		size++;
	}
}

void printData()
{
	int i;
	printf("Data is as follows:");
	for(i = 0 ; i < size ; i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");
}

void sortData()
{
	int i,j,s,temp,c = 0,m = 0,cost;
	for(i = 0 ; i < size ; i++)
	{
		s = i;
		for(j = i + 1  ; j < size  ; j++)
		{
			c++;
			if(arr[j] > arr[s])
			{
				s = j;
			}
		}
		if(i!=s)
		{
			temp = arr[i];
			m++;
			arr[i] = arr[s];
			m++;
			arr[s] = temp;
			m++;
		}
	}
}

void printResult()
{
	int i;
	printf("\nResult is:");
	for(i = 0 ; i < max ; i++)
	{
		if(result[i]!=0)
		{
			printf(" %d ",result[i]);
		}
		else
		{
			break;
		}
	}
}

void fileSorting2s2d(FILE *f1, FILE *f2, FILE *f3,FILE *f4)
{
	int counter = 0,done;
	printf("\nMark and distribute started\n");
	markAndDistribute(f1,f2,f3);
	printf("\nMark and distribute done\n");
	while(mergeSourcesFor2s2d(f1,f2,f3,f4))
	{
		counter++;
		printf("\nlets continue with 2s2d----------------------------------------------------------------------------------------------------------------------------------------------------------------counter:%d\n",counter);
	}
	if(counter % 2 == 0)
	{
		switch(file)
		{
			case 1:
	    		done = rename("temp1","Sorted2s2d_Sorted");
				break;
			case 2:
				done = rename("temp1","Sorted2s2d_Sorted But One");
				break;
			case 3:
				done = rename("temp1","Sorted2s2d_Reverse");
				break;
			case 4:
				done = rename("temp1","Sorted2s2d_Reverse But One");
				break;
			case 5:
				done = rename("temp1","Sorted2s2d_Random");
				break;
		}
		if(!done)
		{
			printf("\nName change successfully of temp1\n");
		}
		else
		{
			printf("\nName  not changed of temp1");
			if (remove("temp1") == 0)
			{
				printf("\nDeleted temp1successfully");
			}
			else
			{
				printf("\nUnable to delete temp1");
			}
		}
		if (remove("temp2") == 0)
		{
			printf("Deleted temp2 successfully");
		}
		else
		{
			printf("Unable to delete temp2");
		}
		if (remove("temp3") == 0)
		{
			printf("Deleted temp3 successfully");
		}
	    else
	    {
	    	printf("Unable to delete temp3");
		}
		if (remove("temp4") == 0)
		{
			printf("Deleted temp4 successfully");
		}
	    else
	    {
	    	printf("Unable to delete temp4");
		}
	}
	else
	{
		switch(file)
		{
			case 1:
	    		done = rename("temp2","Sorted2s2d_Sorted");
				break;
			case 2:
				done = rename("temp2","Sorted2s2d_Sorted But One");
				break;
			case 3:
				done = rename("temp2","Sorted2s2d_Reverse");
				break;
			case 4:
				done = rename("temp2","Sorted2s2d_Reverse But One");
				break;
			case 5:
				done = rename("temp2","Sorted2s2d_Random");
				break;
		}
		if(!done)
		{
			printf("\nName change successfully of temp2\n");
		}
		/*
		else
		{
			printf("\nName  not changed of temp2");
			if (remove("temp2") == 0)
			{
				printf("\nDeleted temp2successfully");
			}
			else
			{
				printf("\nUnable to delete temp2");
			}
		}
		*/
		if (remove("temp1") == 0)
		{
			printf("\nDeleted temp1 successfully");
		}
		else
		{
			printf("\nUnable to delete temp1");
		}
		if (remove("temp3") == 0)
		{
			printf("\nDeleted temp3 successfully");
		}
	    else
	    {
	    	printf("\nUnable to delete temp3");
		}
		if (remove("temp4") == 0)
		{
			printf("\nDeleted temp4 successfully");
		}
	    else
	    {
	    	printf("\nUnable to delete temp4");
		}
	}
}

void fileSorting2s1d(FILE *f1, FILE *f2, FILE *f3)
{
	int done;
	printf("\n---------------------------------Mark and distribute start----------------------------------------\n");
	markAndDistribute(f1,f2,f3);
	printf("\n---------------------------------Mark and distribute done----------------------------------------\n");
	while(mergeSources(f2,f3,f1))
	{
		printf("\n---------------------------------Merging done----------------------------------------\n");
		printf("\n---------------------------------distribute start----------------------------------------\n");
		distributeRuns(f1,f2,f3);
		printf("\n---------------------------------distribute done----------------------------------------\n");
	}
	printf("\n---------------------------------Sorting done----------------------------------------\n");
	switch(file)
	{
		case 1:
    		done = rename("temp1","Sorted2s1d_Sorted");
			break;
		case 2:
			done = rename("temp1","Sorted2s1d_Sorted But One");
			break;
		case 3:
			done = rename("temp1","Sorted2s1d_Reverse");
			break;
		case 4:
			done = rename("temp1","Sorted2s1d_Reverse But One");
			break;
		case 5:
			done = rename("temp1","Sorted2s1d_Random");
			break;
	}
	if(!done)
	{
		printf("\nName change successful");
	}
	if (remove("temp2") == 0)
	{
		printf("\nDeleted temp2 successfully");
	}
	else
	{
		printf("\nUnable to delete temp2");
	}
	if (remove("temp3") == 0)
	{
		printf("\nDeleted temp3 successfully");
	}
    else
    {
    	printf("\nUnable to delete temp3");
	}
}

void distributeRuns(FILE *s,FILE *d1,FILE *d2)
{
	bool f = true;
	struct Data current;
	char ch;
	s = fopen("temp1","r");
	d1 = fopen("temp2","w");
	d2 = fopen("temp3","w");
	ch = fgetc(s);
    while (ch != EOF)
    {
		fseek(s, -1, SEEK_CUR);
        if(f)
        {
        	ch = fgetc(s);
			while(ch != '$')
        	{
        		fseek(s, -1, SEEK_CUR);
				current = readData(s);
        		writeData(d1,current);
        		ch = fgetc(s);
			}
			fputc(ch,d1);
			f = false;
		}
		else
		{
			ch = fgetc(s);
			while(ch != '$')
        	{
        		fseek(s, -1, SEEK_CUR);
				current = readData(s);
        		writeData(d2,current);
        		ch = fgetc(s);
			}
			fputc(ch,d2);
			f = true;
		}
        ch = fgetc(s);
    }
    fclose(s);
    fclose(d1);
    fclose(d2);
}

bool mergeSourcesFor2s2d(FILE *s1,FILE *s2,FILE *des1,FILE *des2)
{
	struct Data d1,d2;
	char c1,c2;
	int counter = 0;
	bool data1 = false,data2 = false,f = true;
	static bool file = true;
	if(file)
	{
		s1 = fopen("temp2","r");
		s2 = fopen("temp3","r");
		des1 = fopen("temp1","w");
		des2 = fopen("temp4","w");
		file = false;
	}
	else
	{
		s1 = fopen("temp1","r");
		s2 = fopen("temp4","r");
		des1 = fopen("temp2","w");
		des2 = fopen("temp3","w");
		file = true;
	}

	fseek(s1, 0, SEEK_SET);
	fseek(s2, 0, SEEK_SET);
	c1 = fgetc(s1);
	c2 = fgetc(s2);
	/*//Merge runs till end of any one file*/
	while(c1 != EOF && c2 != EOF)
	{
		fseek(s1, -1, SEEK_CUR);
		fseek(s2, -1, SEEK_CUR);
		d1 = readData(s1);
		data1 =true;
		d2 = readData(s2);
		data2 = true;
		printf("\nData is %d,%d ---------------------------------------Merge Started------------------------\n",d1.id,d2.id);
		c1 = fgetc(s1);
		c2 = fgetc(s2);
		printf("\n--------------------%c of s1 run this loop till end of file %c of s2------------------------",c1,c2);
		/*//Merge runs till end of any one run*/
		if(f)
		{
			while(c1 != '$' && c2 != '$')
			{
				fseek(s1, -1, SEEK_CUR);
				fseek(s2, -1, SEEK_CUR);
				printf("\n--------------------%c of s1 run this loop till end of run %c of s2------------------------",c1,c2);
				if(d1.id > d2.id)
				{
					printf("\n%d of file s1 is greater than %d of file s2 therefore put %d in d",d1.id,d2.id,d2.id);
					writeData(des1,d2);
					d2 = readData(s2);
				}
				else
				{
					printf("\n%d of file s2 is greater than %d of file s1 therefore put %d in d",d2.id,d1.id,d1.id);
					writeData(des1,d1);
					d1 = readData(s1);
				}
				c1 = fgetc(s1);
				c2 = fgetc(s2);
			}
			/*//Copy till end of left over run*/
			if(c1 == '$')
			{
				fseek(s2, -1, SEEK_CUR);
				printf("\nEnd of run encountered in s1 via '%c' therefore copy till end of run of s2",c1);
				c2 = fgetc(s2);
				while(c2 != '$' && !feof(s2))
				{
					fseek(s2, -1, SEEK_CUR);
					if(data1)
					{
						if(d1.id < d2.id)
						{
							writeData(des1,d1);
							data1 = false;
							writeData(des1,d2);
							d2 = readData(s2);
						}
						else
						{
							writeData(des1,d2);
							d2 = readData(s2);
						}
					}
					else
					{
						writeData(des1,d2);
						d2 = readData(s2);
					}
					c2 = fgetc(s2);
				}
				if(data1)
				{
					if(d1.id < d2.id)
					{
						writeData(des1,d1);
						data1 = false;
						writeData(des1,d2);
					}
					else
					{
						writeData(des1,d2);
						writeData(des1,d1);
						data1 = false;
					}
				}
				else
				{
					writeData(des1,d2);
				}
				printf("\nEnd of run encountered in s2 via '%c' therefore end this iteration",c2);
				fputc(c2,des1);
				/*//counter++;*/
			}
			else
			{
				fseek(s1, -1, SEEK_CUR);
				printf("\nEnd of run encountered in s2 via '%c' therefore copy till end of run of s1",c2);
				c1 = fgetc(s1);
				while(c1 != '$' && !feof(s1))
				{
					fseek(s1, -1, SEEK_CUR);
					if(data2)
					{
						if(d2.id < d1.id)
						{
							writeData(des1,d2);
							data2 = false;
							writeData(des1,d1);
							d1 = readData(s1);

						}
						else
						{
							writeData(des1,d1);
							d1 = readData(s1);
						}
					}
					else
					{
						writeData(des1,d1);
						d1 = readData(s1);
					}
					c1 = fgetc(s1);
				}
				if(data2)
				{
					if(d2.id < d1.id)
					{
						writeData(des1,d2);
						data2 = false;
						writeData(des1,d1);
					}
					else
					{
						writeData(des1,d1);
						writeData(des1,d2);
						data2 = false;
					}
				}
				else
				{
					writeData(des1,d1);
				}
				printf("\nEnd of run encountered in s1 via '%c' therefore end this iteration\n",c1);
				fputc(c1,des1);
				/*//counter++;*/
			}
			f = false;
		}
		else
		{
			while(c1 != '$' && c2 != '$')
			{
				fseek(s1, -1, SEEK_CUR);
				fseek(s2, -1, SEEK_CUR);
				printf("\n--------------------%c of s1 run this loop till end of run %c of s2------------------------",c1,c2);
				if(d1.id > d2.id)
				{
					printf("\n%d of file s1 is greater than %d of file s2 therefore put %d in d",d1.id,d2.id,d2.id);
					writeData(des2,d2);
					d2 = readData(s2);
				}
				else
				{
					printf("\n%d of file s2 is greater than %d of file s1 therefore put %d in d",d2.id,d1.id,d1.id);
					writeData(des2,d1);
					d1 = readData(s1);
				}
				c1 = fgetc(s1);
				c2 = fgetc(s2);
			}
			/*//Copy till end of left over run*/
			if(c1 == '$')
			{
				fseek(s2, -1, SEEK_CUR);
				printf("\nEnd of run encountered in s1 via '%c' therefore copy till end of run of s2",c1);
				c2 = fgetc(s2);
				while(c2 != '$' && !feof(s2))
				{
					fseek(s2, -1, SEEK_CUR);
					if(data1)
					{
						if(d1.id < d2.id)
						{
							writeData(des2,d1);
							data1 = false;
							writeData(des2,d2);
							d2 = readData(s2);
						}
						else
						{
							writeData(des2,d2);
							d2 = readData(s2);
						}
					}
					else
					{
						writeData(des2,d2);
						d2 = readData(s2);
					}
					c2 = fgetc(s2);
				}
				if(data1)
				{
					if(d1.id < d2.id)
					{
						writeData(des2,d1);
						data1 = false;
						writeData(des2,d2);
					}
					else
					{
						writeData(des2,d2);
						writeData(des2,d1);
						data1 = false;
					}
				}
				else
				{
					writeData(des2,d2);
				}
				printf("\nEnd of run encountered in s2 via '%c' therefore end this iteration",c2);
				fputc(c2,des2);
				counter++;
			}
			else
			{
				fseek(s1, -1, SEEK_CUR);
				printf("\nEnd of run encountered in s2 via '%c' therefore copy till end of run of s1",c2);
				c1 = fgetc(s1);
				while(c1 != '$' && !feof(s1))
				{
					fseek(s1, -1, SEEK_CUR);
					if(data2)
					{
						if(d2.id < d1.id)
						{
							writeData(des2,d2);
							data2 = false;
							writeData(des2,d1);
							d1 = readData(s1);

						}
						else
						{
							writeData(des2,d1);
							d1 = readData(s1);
						}
					}
					else
					{
						writeData(des2,d1);
						d1 = readData(s1);
					}
					c1 = fgetc(s1);
				}
				if(data2)
				{
					if(d2.id < d1.id)
					{
						writeData(des2,d2);
						data2 = false;
						writeData(des2,d1);
					}
					else
					{
						writeData(des2,d1);
						writeData(des2,d2);
						data2 = false;
					}
				}
				else
				{
					writeData(des2,d1);
				}
				printf("\nEnd of run encountered in s1 via '%c' therefore end this iteration\n",c1);
				fputc(c1,des2);
				counter++;
			}
			f = true;
		}
		c1 = fgetc(s1);
		c2 = fgetc(s2);
	}
	/*//Copy all left over data as only one file left and other file is empty*/
	if(feof(s1))
	{
		printf("\nFinal Step copy till end of s2 as s1 is empty\n");
		fseek(s2, -1, SEEK_CUR);
		while(c2 != EOF)
		{
			if(f)
			{
				d2 = readData(s2);
				writeData(des1,d2);
				c2 = fgetc(s2);
				if(c2 == '$')
				{
					fputc(c2,des1);
					/*//counter++;*/
					c2 = fgetc(s2);
					if(c2 == EOF)
					{
						break;
					}
					else
					{
						f = false;
						fseek(s2, -1, SEEK_CUR);
					}
				}
				else
				{
					fseek(s2, -1, SEEK_CUR);
				}
			}
			else
			{
				d2 = readData(s2);
				writeData(des2,d2);
				c2 = fgetc(s2);
				if(c2 == '$')
				{
					fputc(c2,des2);
					counter++;
					c2 = fgetc(s2);
					if(c2 == EOF)
					{
						break;
					}
					else
					{
						f = true;
						fseek(s2, -1, SEEK_CUR);
					}
				}
				else
				{
					fseek(s2, -1, SEEK_CUR);
				}
			}
		}
	}
	else
	{
		fseek(s1, -1, SEEK_CUR);
		while(c1 != EOF)
		{
			if(f)
			{
				d1 = readData(s1);
				writeData(des1,d1);
				c1 = fgetc(s1);
				if(c1 == '$')
				{
					fputc(c1,des1);
					/*//counter++;*/
					c1 = fgetc(s1);
					if(c1 == EOF)
					{
						break;
					}
					else
					{
						f = false;
						fseek(s1, -1, SEEK_CUR);
					}
				}
				else
				{
					fseek(s1, -1, SEEK_CUR);
				}
			}
			else
			{
				d1 = readData(s1);
				writeData(des2,d1);
				c1 = fgetc(s1);
				if(c1 == '$')
				{
					fputc(c1,des2);
					counter++;
					c1 = fgetc(s1);
					if(c1 == EOF)
					{
						break;
					}
					else
					{
						f = true;
						fseek(s1, -1, SEEK_CUR);
					}
				}
				else
				{
					fseek(s1, -1, SEEK_CUR);
				}
			}
		}
	}
	fclose(s1);
	fclose(s2);
	fclose(des1);
	fclose(des2);
	if(counter == 0)
	{
		file = true;
		return false;
	}
	else
	{
		return true;
	}
	printf("\n-----------------------end of merge process and counter is : %d-----------------------------\n",counter);
}

bool mergeSources(FILE *s1,FILE *s2,FILE *d)
{
	struct Data d1,d2;
	char c1,c2;
	int counter = 0;
	bool data1 = false,data2 = false;
	s1 = fopen("temp2","r");
	s2 = fopen("temp3","r");
	d = fopen("temp1","w");
	fseek(s1, 0, SEEK_SET);
	fseek(s2, 0, SEEK_SET);
	c1 = fgetc(s1);
	c2 = fgetc(s2);
	/*//Merge runs till end of any one file*/
	while(c1 != EOF && c2 != EOF)
	{
		fseek(s1, -1, SEEK_CUR);
		fseek(s2, -1, SEEK_CUR);
		d1 = readData(s1);
		data1 =true;
		d2 = readData(s2);
		data2 = true;
		printf("\nData is %d,%d ---------------------------------------Merge Started------------------------\n",d1.id,d2.id);
		c1 = fgetc(s1);
		c2 = fgetc(s2);
		printf("\n--------------------%c of s1 run this loop till end of file %c of s2------------------------",c1,c2);
		/*//Merge runs till end of any one run*/
		while(c1 != '$' && c2 != '$')
		{
			fseek(s1, -1, SEEK_CUR);
			fseek(s2, -1, SEEK_CUR);
			printf("\n--------------------%c of s1 run this loop till end of run %c of s2------------------------",c1,c2);
			if(d1.id > d2.id)
			{
				printf("\n%d of file s1 is greater than %d of file s2 therefore put %d in d",d1.id,d2.id,d2.id);
				writeData(d,d2);
				d2 = readData(s2);
			}
			else
			{
				printf("\n%d of file s2 is greater than %d of file s1 therefore put %d in d",d2.id,d1.id,d1.id);
				writeData(d,d1);
				d1 = readData(s1);
			}
			c1 = fgetc(s1);
			c2 = fgetc(s2);
		}
		/*//Copy till end of left over run*/
		if(c1 == '$')
		{
			fseek(s2, -1, SEEK_CUR);
			printf("\nEnd of run encountered in s1 via '%c' therefore copy till end of run of s2",c1);
			c2 = fgetc(s2);
			while(c2 != '$' && !feof(s2))
			{
				fseek(s2, -1, SEEK_CUR);
				if(data1)
				{
					if(d1.id < d2.id)
					{
						writeData(d,d1);
						data1 = false;
						writeData(d,d2);
						d2 = readData(s2);
					}
					else
					{
						writeData(d,d2);
						d2 = readData(s2);
					}
				}
				else
				{
					writeData(d,d2);
					d2 = readData(s2);
				}
				c2 = fgetc(s2);
			}
			if(data1)
			{
				if(d1.id < d2.id)
				{
					writeData(d,d1);
					data1 = false;
					writeData(d,d2);
				}
				else
				{
					writeData(d,d2);
					writeData(d,d1);
					data1 = false;
				}
			}
			else
			{
				writeData(d,d2);
			}
			printf("\nEnd of run encountered in s2 via '%c' therefore end this iteration",c2);
			fputc(c2,d);
			counter++;
		}
		else
		{
			fseek(s1, -1, SEEK_CUR);
			printf("\nEnd of run encountered in s2 via '%c' therefore copy till end of run of s1",c2);
			c1 = fgetc(s1);
			while(c1 != '$' && !feof(s1))
			{
				fseek(s1, -1, SEEK_CUR);
				if(data2)
				{
					if(d2.id < d1.id)
					{
						writeData(d,d2);
						data2 = false;
						writeData(d,d1);
						d1 = readData(s1);

					}
					else
					{
						writeData(d,d1);
						d1 = readData(s1);
					}
				}
				else
				{
					writeData(d,d1);
					d1 = readData(s1);
				}
				c1 = fgetc(s1);
			}
			if(data2)
			{
				if(d2.id < d1.id)
				{
					writeData(d,d2);
					data2 = false;
					writeData(d,d1);
				}
				else
				{
					writeData(d,d1);
					writeData(d,d2);
					data2 = false;
				}
			}
			else
			{
				writeData(d,d1);
			}
			printf("\nEnd of run encountered in s1 via '%c' therefore end this iteration\n",c1);
			fputc(c1,d);
			counter++;
		}
		c1 = fgetc(s1);
		c2 = fgetc(s2);
	}
	/*//Copy all left over data as only one file left and other file is empty*/
	if(feof(s1) && !feof(s2))
	{
		printf("\nFinal Step copy till end of s2 as s1 is empty\n");
		while(c2 != EOF)
		{
			fputc(c2,d);
			c2 = fgetc(s2);
			if(c2 == '$')
			{
				counter++;
			}
		}
	}
	else
	{
		printf("\nFinal Step copy till end of s1 as s2 is empty\n");
		while(c1 != EOF)
		{
			fputc(c1,d);
			c1 = fgetc(s1);
			if(c1 == '$')
			{
				counter++;
			}
		}
	}
	fclose(s1);
	fclose(s2);
	fclose(d);
	if(counter == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
	printf("\n-----------------------end of merge process and counter is : %d-----------------------------\n",counter);
}

/*
bool mergeSources(FILE *s1,FILE *s2,FILE *d)
{
	struct Data d1,d2;
	char c1,c2;
	long int t1,t2,counter = 0;
	bool data1 = false,data2 = false;
	s1 = fopen("temp2","r");
	s2 = fopen("temp3","r");
	d = fopen("temp1","w");
	fseek(s1, 0, SEEK_SET);
	fseek(s2, 0, SEEK_SET);
	c1 = fgetc(s1);
	c2 = fgetc(s2);
	//Merge runs till end of any one file
	while(c1 != EOF && c2 != EOF)
	{
		fseek(s1, -1, SEEK_CUR);
		fseek(s2, -1, SEEK_CUR);
		d1 = readData(s1);
		data1 =true;
		d2 = readData(s2);
		data2 = true;
		printf("\nData is %d,%d ---------------------------------------Merge Started------------------------\n",d1.id,d2.id);
		c1 = fgetc(s1);
		c2 = fgetc(s2);
		t1 = ftell(s1);
		t2 = ftell(s2);
		printf("\n--------------------%c at %ld of s1 run this loop till end of file %c at %ld of s2------------------------\n",c1,t1,c2,t2);
		//Merge runs till end of any one run
		while(c1 != '$' && c2 != '$')
		{
			fseek(s1, -1, SEEK_CUR);
			fseek(s2, -1, SEEK_CUR);
			t1 = ftell(s1);
			t2 = ftell(s2);
			printf("\n--------------------%c at %ld of s1 run this loop till end of run %c at %ld of s2------------------------\n",c1,t1,c2,t2);
			if(d1.id > d2.id)
			{
				printf("\n%d of file s1 is greater than %d of file s2 therefore put %d in d\n",d1.id,d2.id,d2.id);
				writeData(d,d2);
				d2 = readData(s2);
			}
			else
			{
				printf("\n%d of file s2 is greater than %d of file s1 therefore put %d in d\n",d2.id,d1.id,d1.id);
				writeData(d,d1);
				d1 = readData(s1);
			}
			c1 = fgetc(s1);
			c2 = fgetc(s2);
		}
		//Copy till end of left over run
		if(c1 == '$')
		{
			fseek(s2, -1, SEEK_CUR);
			printf("\nEnd of run encountered in s1 via '%c' therefore copy till end of run of s2\n",c1);
			c2 = fgetc(s2);
			while(c2 != '$' && !feof(s2))
			{
				fseek(s2, -1, SEEK_CUR);
				if(data1)
				{
					if(d1.id < d2.id)
					{
						writeData(d,d1);
						data1 = false;
						writeData(d,d2);
						d2 = readData(s2);
					}
					else
					{
						writeData(d,d2);
						d2 = readData(s2);
					}
				}
				else
				{
					writeData(d,d2);
					d2 = readData(s2);
				}
				c2 = fgetc(s2);
			}
			if(data1)
			{
				if(d1.id < d2.id)
				{
					writeData(d,d1);
					data1 = false;
					writeData(d,d2);
				}
				else
				{
					writeData(d,d2);
					writeData(d,d1);
					data1 = false;
				}
			}
			else
			{
				writeData(d,d2);
			}
			printf("\nEnd of run encountered in s2 via '%c' therefore end this iteration\n",c2);
			fprintf(d,"$");
			counter++;
		}
		else
		{
			fseek(s1, -1, SEEK_CUR);
			printf("\nEnd of run encountered in s2 via '%c' therefore copy till end of run of s1\n",c2);
			c1 = fgetc(s1);
			while(c1 != '$' && !feof(s1))
			{
				fseek(s1, -1, SEEK_CUR);
				if(data2)
				{
					if(d1.id < d2.id)
					{
						writeData(d,d1);
						d1 = readData(s1);
						writeData(d,d2);
						data2 = false;
					}
					else
					{
						writeData(d,d1);
						d1 = readData(s1);
					}
				}
				else
				{
					writeData(d,d1);
					d1 = readData(s1);
				}
				c1 = fgetc(s1);
			}
			if(data2)
			{
				if(d1.id < d2.id)
				{
					writeData(d,d1);
					writeData(d,d2);
					data2 = false;
				}
				else
				{
					writeData(d,d2);
					data2 = false;
					writeData(d,d1);
				}
			}
			else
			{
				writeData(d,d1);
			}
			printf("\nEnd of run encountered in s1 via '%c' therefore end this iteration\n",c1);
			fprintf(d,"$");
			counter++;
		}
		c1 = fgetc(s1);
		c2 = fgetc(s2);
	}
	//Copy all left over data as only one file left and other file is empty
	if(feof(s1))
	{
		printf("\nFinal Step copy till end of s2 as s1 is empty\n");
		c2 = fgetc(s2);
		while(c2 != EOF)
		{
			fputc(c2,d);
			c2 = fgetc(s2);
		}
	}
	else
	{
		printf("\nFinal Step copy till end of s1 as s2 is empty\n");
		c1 = fgetc(s1);
		while(c1 != EOF)
		{
			fputc(c1,d);
			c1 = fgetc(s1);
		}
	}
	fclose(s1);
	fclose(s2);
	fclose(d);
	if(counter == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
*/
void markAndDistribute(FILE *s,FILE *d1,FILE *d2)
{
	bool f = true;
	struct Data current,next;
	s = fopen("temp1","r");
	d1 = fopen("temp2","w");
	d2 = fopen("temp3","w");
	current = readData(s);
	next = readData(s);
	while(!feof(s))
	{
		if(f)
		{
			if(current.id < next.id)
			{
				writeData(d1,current);
				current = next;
				next = readData(s);
			}
			else
			{
				writeData(d1,current);
				fprintf(d1,"$");
				current = next;
				next = readData(s);
				/*//printf("\n------------------End of one run------------\n");*/
				f = false;
			}
			if(next.id==0)
			{
				writeData(d1,current);
				fprintf(d1,"$");
				/*//printf("\n------------------End of one run------------\n");*/
				break;
			}
		}
		else
		{
			if(current.id < next.id)
			{
				writeData(d2,current);
				current = next;
				next = readData(s);
			}
			else
			{
				writeData(d2,current);
				fprintf(d2,"$");
				current = next;
				next = readData(s);
				/*//printf("\n------------------End of one run------------\n");*/
				f = true;
			}
			if(next.id==0)
			{
				writeData(d2,current);
				fprintf(d2,"$");
				/*//printf("\n------------------End of one run------------\n");*/
				break;
			}
		}
	}
	fclose(s);
	fclose(d1);
	fclose(d2);
}

struct Data readData(FILE *f)
{
	char ch;
	int i,c;
	struct Data d;
	/*//to read id*/
	ch = fgetc(f);
	d.id = 0;
	while(ch != ',' && ch != EOF)
	{
		if(ch > 47 && ch < 58)
        {
            d.id = d.id * 10 + ((int)ch-48) ;
        }
        ch = fgetc(f);
	}
	/*//to read fname*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.fname[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.fname[i] = '\0';
	/*//to read lname*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.lname[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.lname[i] = '\0';
	/*//to read address;*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.address[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.address[i] = '\0';
	/*//to read area*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.area[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.area[i] = '\0';
	/*//to read city*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.city[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.city[i] = '\0';
	/*//to read cityCode*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.cityCode[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.cityCode[i] = '\0';
	/*//to read pinCode*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.pinCode[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.pinCode[i] = '\0';
	/*//to read contact1*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.contact1[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.contact1[i] = '\0';
	/*//to read contact2*/
	ch = fgetc(f);
	i = 0;
	while(ch != ','  && ch != EOF)
	{
		d.contact2[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.contact2[i] = '\0';
	/*//to read email*/
	ch = fgetc(f);
	i = 0;
	while(ch != ',' && ch !='\n'  && ch != EOF)
	{
		d.email[i] = ch;
		i++;
		ch = fgetc(f);
	}
	d.email[i] = '\0';
	/*//Print data:*/
	/*
	printf("\nData is as follow:\n");
	printf("\nID:%d",d.id);
	printf("\nfname:%s",d.fname);
	printf("\nlname:%s",d.lname);
	printf("\naddress:%s",d.address);
	printf("\narea:%s",d.area);
	printf("\nCity:%s",d.city);
	printf("\nCityCode:%s",d.cityCode);
	printf("\npinCode:%s",d.pinCode);
	printf("\ncontact1:%s",d.contact1);
	printf("\ncontact2:%s",d.contact2);
	printf("\nemail:%s",d.email);
	*/
	return d;
}

void writeData(FILE *f,Data data)
{
	struct Data d = data;
	printf("\nWritten to file:%d----------------\n",d.id);
	fprintf(f,"%d",d.id);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.fname);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.lname);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.address);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.area);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.city);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.cityCode);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.pinCode);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.contact1);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.contact2);
	fprintf(f,"%c",',');
	fprintf(f,"%s",d.email);
	fprintf(f,"%c",'\n');
}

