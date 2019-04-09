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
        		printf("Digite o número de telefone de(a) %s: ",pessoa.nome);
        		scanf("%d",&pessoa.tele);
        		fflush(stdin);
        		printf("Digite a rua onde mora %s: ",pessoa.nome);
        		gets(pessoa.lugar.rua);
        		printf("Digite o número da residencia de(a)%s: ",pessoa.nome);
        		scanf("%d",&pessoa.lugar.num);
        		fflush(stdin);
        		printf("Digite o nome do bairro onde mora %s: ",pessoa.nome);
        		gets(pessoa.lugar.bairro);
        		printf("Digite o nome da cidade onde mora %s: ",pessoa.nome);
        		gets(pessoa.lugar.cidade);
        		printf("\n");
        		
        		//manipulação de arquivos, inserindo os dados digitados em um arquivo .txt.
        		
        		arquivo=fopen("Agenda.txt","a");
        		fprintf(arquivo,"%s\n",pessoa.nome);
        		fprintf(arquivo,"%d\n",pessoa.tele);
        		fprintf(arquivo,"%s,%d,%s,%s\n\n",pessoa.lugar.rua, pessoa.lugar.num, pessoa.lugar.bairro, pessoa.lugar.cidade);
                fclose(arquivo);
                break;
                
            case 2: //pesquisa de usuários cadastrados
            	system("cls");
            	arquivo=fopen("Agenda.txt","r");
            	if(arquivo==NULL)                                //verificação se o arquivo existe ou se há algum problema com ele.
            	{
            		printf("O arquivo não pode ser aberto.");
            		getch();
				}
				else
				{
            	printf("Digite o nome do contato que deseja procurar: ");
            	fflush(stdin);
            	gets(nome_temp);
            	while((fscanf(arquivo,"%s\n", &palavra_temp))!= EOF) //utilização de um laço while utilizando a comparação da linha lida para definir o fim do laço.
                {                                                    //Caso seja o fim, o laço termina, caso não, ele continua. Além de que, a definição do laço já cuida do armazenamento da linha que esta sendo lida.
                	if(strcmp(nome_temp,palavra_temp)==0)            //se achar o nome, através da comparação, avisa ao usuário e aumenta em 1 o contador
                	{
                	printf("Nome %s encontrado!\n",palavra_temp);
                	j++;
                    }
					else
					if(j==1)                                          //se o nome já foi encontrado, será exibido na próxima linha o número de telefone
					{
					    printf("Número de telefone: %s\n",palavra_temp);
					    j++;
			     	}
			     	else
					if(j==2)                                          //e por fim, na terceira execução do laço, será mostrado o endereço da pessoa.
					{
					    printf("Endereço: %s\n",palavra_temp);
					    break;
			     	}
                    else                                               
                    if(feof(arquivo))                                 //caso o nome não esteja no arquivo, uma mensagem será enviada ao usuário avisando isso.
                    {
                    	printf("Nome não encontrado.");
                    	break;
					}
			    }
			    getch();
			    j=0;
			    fclose(arquivo);
			    }
			    break;
            case 3:
            	exit(0);                                              //saída do arquivo.
		}
	}
}
