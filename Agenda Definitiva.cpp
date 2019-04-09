#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>

struct end
{
	char rua[30];
	char bairro[30];
	int num;
	char cidade[30];
};

struct ficha
{
	char nome[30];
	int tele;
	struct end lugar;
};

int main()
{
	setlocale(LC_ALL,"Portuguese");
	struct ficha pessoa;
	int i=0,j=0;
	char nome_temp[100], palavra_temp[100];
	char *res;
	FILE *arquivo;
	while(i!=3)
	{                     //Menu
		system("cls");
		printf("\t\t\t\t\t+______________________________________+\n");
		printf("\t\t\t\t\t|                                      |\n");
		printf("\t\t\t\t\t|             1-Incuir                 |\n");
		printf("\t\t\t\t\t|             2-Pesquisar              |\n");
		printf("\t\t\t\t\t|             3-Sair                   |\n");
		printf("\t\t\t\t\t|                                      |\n");
		printf("\t\t\t\t\t+--------------------------------------+\n");
		scanf("%d",&i);
		
		switch(i)
        {
        	case 1:              //cadastro de pessoas
        		system("cls"); 
        		printf("Digite o nome do contato da agenda: ");
        		fflush(stdin);
        		gets(pessoa.nome);
        		printf("Digite o n�mero de telefone de(a) %s: ",pessoa.nome);
        		scanf("%d",&pessoa.tele);
        		fflush(stdin);
        		printf("Digite a rua onde mora %s: ",pessoa.nome);
        		gets(pessoa.lugar.rua);
        		printf("Digite o n�mero da residencia de(a)%s: ",pessoa.nome);
        		scanf("%d",&pessoa.lugar.num);
        		fflush(stdin);
        		printf("Digite o nome do bairro onde mora %s: ",pessoa.nome);
        		gets(pessoa.lugar.bairro);
        		printf("Digite o nome da cidade onde mora %s: ",pessoa.nome);
        		gets(pessoa.lugar.cidade);
        		printf("\n");
        		
        		//manipula��o de arquivos, inserindo os dados digitados em um arquivo .txt.
        		
        		arquivo=fopen("Agenda.txt","a");
        		fprintf(arquivo,"%s\n",pessoa.nome);
        		fprintf(arquivo,"%d\n",pessoa.tele);
        		fprintf(arquivo,"%s,%d,%s,%s\n\n",pessoa.lugar.rua, pessoa.lugar.num, pessoa.lugar.bairro, pessoa.lugar.cidade);
                fclose(arquivo);
                break;
                
            case 2: //pesquisa de usu�rios cadastrados
            	system("cls");
            	arquivo=fopen("Agenda.txt","r");
            	if(arquivo==NULL)                                //verifica��o se o arquivo existe ou se h� algum problema com ele.
            	{
            		printf("O arquivo n�o pode ser aberto.");
            		getch();
				}
				else
				{
            	printf("Digite o nome do contato que deseja procurar: ");
            	fflush(stdin);
            	gets(nome_temp);
            	while((fscanf(arquivo,"%s\n", &palavra_temp))!= EOF) //utiliza��o de um la�o while utilizando a compara��o da linha lida para definir o fim do la�o.
                {                                                    //Caso seja o fim, o la�o termina, caso n�o, ele continua. Al�m de que, a defini��o do la�o j� cuida do armazenamento da linha que esta sendo lida.
                	if(strcmp(nome_temp,palavra_temp)==0)            //se achar o nome, atrav�s da compara��o, avisa ao usu�rio e aumenta em 1 o contador
                	{
                	printf("Nome %s encontrado!\n",palavra_temp);
                	j++;
                    }
					else
					if(j==1)                                          //se o nome j� foi encontrado, ser� exibido na pr�xima linha o n�mero de telefone
					{
					    printf("N�mero de telefone: %s\n",palavra_temp);
					    j++;
			     	}
			     	else
					if(j==2)                                          //e por fim, na terceira execu��o do la�o, ser� mostrado o endere�o da pessoa.
					{
					    printf("Endere�o: %s\n",palavra_temp);
					    break;
			     	}
                    else                                               
                    if(feof(arquivo))                                 //caso o nome n�o esteja no arquivo, uma mensagem ser� enviada ao usu�rio avisando isso.
                    {
                    	printf("Nome n�o encontrado.");
                    	break;
					}
			    }
			    getch();
			    j=0;
			    fclose(arquivo);
			    }
			    break;
            case 3:
            	exit(0);                                              //sa�da do arquivo.
		}
	}
}
