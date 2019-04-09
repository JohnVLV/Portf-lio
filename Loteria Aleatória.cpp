//Lotéria aleatória. Ela cria valores aleatórios para os seus numeros que podem ser apostados, e dentro desses, escolhe aleatóriamente quais são os vitóriosos.


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
		printf("\t\t\t\t\t+______________________________________+\n"); //menu de opções
		printf("\t\t\t\t\t|                                      |\n");
		printf("\t\t\t\t\t|             1-Jogar                  |\n");
		printf("\t\t\t\t\t|             2-Sair                   |\n");
		printf("\t\t\t\t\t|                                      |\n");
		printf("\t\t\t\t\t+--------------------------------------+\n");
		scanf("%d",&i); //captura da opção pelo switch/case
		
		
		switch(i)
		{
			case 1:
				system("cls");
				printf("\t\t\t\tQuadro de Apostas\n\n");
				for(k=0;k<32;k++)          //laço para gerar os 32 números aleatórios da loteria
				{
					num_lot[k]=rand() % 99;
					if(k==0)
					printf("%d",num_lot[k]);
					else
					printf("\t\t\t\t%d",num_lot[k]);
				}
				printf("\n\nDigite os seis números dos que estão ali encima em que você irá apostar:\n\n");
	            for(k=0;k<6;k++) //laço para receber os 6 números que o usuário quer apostar, e também para gerar os 6 números vencedores.
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
                    		printf("Esse número já foi usado. Digite outro: ");
                    		scanf("%d",&num_escolha[k]);
                    	    }
						}
					}
                	num_premio[k]=num_lot[rand()%32];
				}
				
				for (k=1;k<6;k++)  //laço em bolha, para verificar se o usuário/apostador ganhou alguma coisa ou se errou todos os valores
				{
                    for (l=0;l<5;l++) 
					{
                        if (num_escolha[k]==num_premio[l]&&k!=l) 
						{
                            aux++;
                        }
                    }
                }
//condições de determinação de vitória ou derrota
                if(aux==6)
                	printf("\nParabéns, vc acertou todos os números!");
                else
				if(aux==5)
				    printf("\nBom, pelo menos vc acertou cinco deles.");
				else
				if(aux==4)
				    printf("\nBom, pelo menos vc acertou quatro deles.");
				else
				if(aux==3)
                	printf("\nBom, pelo menos vc acertou três deles.");
                else
				if(aux==2)
				    printf("\nBom, pelo menos vc acertou dois deles.");
				else
				if(aux==1)
				    printf("\nBom, um é melhor que nada.");
			    else
			        {
			            com=rand()%5; //comando para gerar um valor aleatório, e a seguinte, frases de derrota aleatórias ao usuário
			            if(com==1)
			            {
			                printf("\nErrou tudo...É, o sol não brilha pra todos!");
			            }
			            else
			            if(com==2)
			            {
			                printf("\nCaramba, nem eu sou tão azarado!");
			            }
			            else
			            if(com==3)
			            {
			                printf("\nTudo errado...Pelo menos você tem saúde!");
			            }
			            else
			            if(com==4)
			            {
			                printf("\nAlguém deve estar de olho gordo em você, pra você ter tanto azar!");
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
				exit(0); //saída do código
		}
	}
	
}
