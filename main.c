#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define filename "database.txt"

struct artikulli
{
	char ID;
	char emri[20];
	int nr_tel;
}database[MAX];

int nr_qytetari=0;
FILE *f;

int gjej_qytetarin(int ID);
void menu(void);
void shto(void);
void kerko(void);
void update(void);
void printo(void);
void ruaj(void);
void lexo(void);

int main()
{
	int opsioni;
	
	menu();
	
	f=fopen(filename,"r");
	if(f==NULL)
	{
		f=fopen(filename,"w");  
		int nr=0;
		fprintf(f,"%d\n",nr);
		fclose(f);
	}
	
	lexo();
	
	printf("\nZgjidhini nje opsion:");
	scanf("%d",&opsioni);
	
	while(1)
	{
		switch(opsioni)
		{
			case 1:
				system("cls");
				menu();
				shto();
				break;
			case 2:
				system("cls");
				menu();
				kerko();
				break;
			case 3:
				system("cls");
				menu();
				update();
				break;
			case 4:
				system("cls");
				menu();
				printo();
				break;
			case 5:
				ruaj();
				break;
			case 6:
				return 0;
			default:
				printf("ERROR!.");
				break;	
		}
		
		printf("\n\nZgjidhni nje opsion tjeter:");
		scanf("%d",&opsioni);
	}	
}

void menu(void)
{
	printf("MENUJA");
	printf("\n------------------------------");
	printf("\n1.Shto nje qytetar.\n");
	printf("\n2.Kerko nje qytetar.\n");
	printf("\n3.Modifiko te dhenat e qytetarit.\n");
	printf("\n4.Printo .\n");
	printf("\n5.Ruaj te dhenat ne file.\n");
	printf("\n6.Dil.\n");
}

int gjej_qytetarin(int ID)
{
	int i;
	for(i=0;i<nr_qytetari;i++)
	{
		if(database[i].ID==ID)
		{
			return i;
		}
	}
	
	return -1;
}

void shto(void)
{
	printf("\n\nSHTIMI I TE DHENAVE TE QYTETARIT");
	printf("\n------------------------------\n");
	if(nr_qytetari==MAX)
	{
		printf("Zgjidhini nje ID tjeter.");
		return;
	}
	
	int nr;
	printf("ID:\n");
	scanf("%d",&nr);
	
	int index=gjej_qytetarin(nr);
	if(index>=0)
	{
		printf("Kjo ID egziston.");
		return;
	}
	else
	{
		database[nr_qytetari].ID=nr;
		
		printf("\nEmer/Mbiemer (pa hapsira):\n");
		scanf("%s",database[nr_qytetari].emri);
		printf("\nNumir i Telefonit:\n");
		scanf("%d",&database[nr_qytetari].nr_tel);
		
		nr_qytetari++;
		
		printf("\nQytetari u shtua!");
	}	
}

void kerko(void)
{
	printf("\n\nKerko te dhenat per nje qytetar");
	printf("\n------------------------------\n");
	int ID;
	printf("\nID:\n");
	scanf("%d",&ID);
	
	int index=gjej_qytetarin(ID);
	if(index>=0)
	{
		printf("\nTe dhenat jane:\n");
		printf("ID: %d\n",database[index].ID);
		printf("EMRI/MBIEMRI: %s\n",database[index].emri);
		printf("NR I TELEFONIT: %d\n",database[index].nr_tel);
	}
	else
	{
		printf("QYTEATRI ME ID %d NUK EGZISTON.\n",ID);
	}
	return;
}

void update(void)
{
	printf("\n\nMODIFIKIMI TE DHENAT E QYTETAREIT");
	printf("\n------------------------------\n");
	int ID;
	printf("\nID:\n");
	scanf("%d",&ID);
	
	int i=gjej_qytetarin(ID);
	if(i>=0)
	{
		int ndryshimi;
		printf("NEW ID:\n");
		scanf("%d",&ndryshimi);
		
		database[i].nr_tel=ndryshimi;
		printf("\nQYTETARI U PERDITSUA!");
	}
	else
	{
		printf("KJO ID NUK EGZISTON!\n");
		return;
	}	
}
void printo(void)
{
	printf("\n\nPRINTO TE DHENAT");
	printf("\n------------------------------\n");
	int i;
	for(i=0;i<nr_qytetari;i++)
	{
		printf("\n_____________________________\n");
		printf("QYTETARI %d ka te dhenat:\n",i);
		printf("ID: %d\n",database[i].ID);
		printf("Emri/MBIEMER: %s\n",database[i].emri);
		printf("NR TEL: %d\n",database[i].nr_tel);
		printf("_____________________________\n\n");
	}
}

void ruaj(void)
{
	f=fopen(filename,"w");
	
	fprintf(f,"%d\n",nr_qytetari);
	for(int i=0;i<nr_qytetari;i++)
	{
		fprintf(f,"%d %s %d\n",database[i].ID,database[i].emri,database[i].nr_tel);
	}
	fclose(f);	
}

void lexo(void)
{
	f=fopen(filename,"r");
	
	fscanf(f,"%d\n",&nr_qytetari);
	for(int i=0;i<nr_qytetari;i++)
	{
		fscanf(f,"%d %s %d\n",&database[i].ID,database[i].emri,&database[i].nr_tel);
	}
	
}
