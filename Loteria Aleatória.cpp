//Lot�ria aleat�ria. Ela cria valores aleat�rios para os seus numeros que podem ser apostados, e dentro desses, escolhe aleat�riamente quais s�o os vit�riosos.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL,"Portuguese");
	int num_lot[32];
	int num_escolha[6];
	int num_premio[6];
	int i=0,k,l,aux=0,com=0;
	srand(time(NULL));
	
	while(i!=2)
	{
		system("cls");                                                 
		printf("\t\t\t\t\t+______________________________________+\n"); //menu de op��es
		printf("\t\t\t\t\t|                                      |\n");
		printf("\t\t\t\t\t|             1-Jogar                  |\n");
		printf("\t\t\t\t\t|             2-Sair                   |\n");
		printf("\t\t\t\t\t|                                      |\n");
		printf("\t\t\t\t\t+--------------------------------------+\n");
		scanf("%d",&i); //captura da op��o pelo switch/case
		
		
		switch(i)
		{
			case 1:
				system("cls");
				printf("\t\t\t\tQuadro de Apostas\n\n");
				for(k=0;k<32;k++)          //la�o para gerar os 32 n�meros aleat�rios da loteria
				{
					num_lot[k]=rand() % 99;
					if(k==0)
					printf("%d",num_lot[k]);
					else
					printf("\t\t\t\t%d",num_lot[k]);
				}
				printf("\n\nDigite os seis n�meros dos que est�o ali encima em que voc� ir� apostar:\n\n");
	            for(k=0;k<6;k++) //la�o para receber os 6 n�meros que o usu�rio quer apostar, e tamb�m para gerar os 6 n�meros vencedores.
                {
                    scanf("%d",&num_escolha[k]);
                    for(l=0;l<k;l++)
                    {
                    	if(k==0)
						{}
						else
                    	if(num_escolha[k]==num_escolha[l]&&k!=l)
                    	{
                    		while(num_escolha[k]==num_escolha[l]&&k!=l)
                    		{
                    		printf("Esse n�mero j� foi usado. Digite outro: ");
                    		scanf("%d",&num_escolha[k]);
                    	    }
						}
					}
                	num_premio[k]=num_lot[rand()%32];
				}
				
				for (k=1;k<6;k++)  //la�o em bolha, para verificar se o usu�rio/apostador ganhou alguma coisa ou se errou todos os valores
				{
                    for (l=0;l<5;l++) 
					{
                        if (num_escolha[k]==num_premio[l]&&k!=l) 
						{
                            aux++;
                        }
                    }
                }
//condi��es de determina��o de vit�ria ou derrota
                if(aux==6)
                	printf("\nParab�ns, vc acertou todos os n�meros!");
                else
				if(aux==5)
				    printf("\nBom, pelo menos vc acertou cinco deles.");
				else
				if(aux==4)
				    printf("\nBom, pelo menos vc acertou quatro deles.");
				else
				if(aux==3)
                	printf("\nBom, pelo menos vc acertou tr�s deles.");
                else
				if(aux==2)
				    printf("\nBom, pelo menos vc acertou dois deles.");
				else
				if(aux==1)
				    printf("\nBom, um � melhor que nada.");
			    else
			        {
			            com=rand()%5; //comando para gerar um valor aleat�rio, e a seguinte, frases de derrota aleat�rias ao usu�rio
			            if(com==1)
			            {
			                printf("\nErrou tudo...�, o sol n�o brilha pra todos!");
			            }
			            else
			            if(com==2)
			            {
			                printf("\nCaramba, nem eu sou t�o azarado!");
			            }
			            else
			            if(com==3)
			            {
			                printf("\nTudo errado...Pelo menos voc� tem sa�de!");
			            }
			            else
			            if(com==4)
			            {
			                printf("\nAlgu�m deve estar de olho gordo em voc�, pra voc� ter tanto azar!");
			            }
			            else
			            if(com==5)
			            {
			            	printf("\nSua cota de sorte acabou, eu acho :(");
						}
			        }
			    getch();
				break;
			case 2:
				exit(0); //sa�da do c�digo
		}
	}
	
}
