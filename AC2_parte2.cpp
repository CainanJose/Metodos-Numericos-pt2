// Nome:Cainã Jose de Arruda Pinto RA: 210626
// Nome:Nelson Stropa Junior RA: 211916
// Nome:João Paulo Modanez Morais RA: 223346

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <cmath>

typedef struct mmq {
	float y[20];
	float x[20];
	float aux_1[20];
   	float aux_2[20];
   	float aux_3[20];
	int qtde;
	float teste[12];
}mmq; // estrutura para MMQ


typedef struct trapezio {
	float coeficiente[10];
	float variavel[100];
	int grau;
	float intervalos[2];
	int div;
	
}trap;  // estrutura trapezio

//MMQ
 void aloca_mmq(mmq **c,int j);
 void info_mmq(mmq *c);
 void calc_mmq_reta(mmq *c);
 void calc_mmq_parabola(mmq *c);
 
 // Funções trapezio
  void aloca_trap(trap **c,int j);
  void informacoes(trap *c);
  void calc_trapezio(trap *c);
 
 int main()
 {
 	mmq *minimo= NULL;
 	trapezio *trapezio = NULL;
 	
 	aloca_mmq(&minimo,1);
 	aloca_trap(&trapezio,1);
 	
	int op,a;
 	do{ 
 		system("cls");
 		printf("\n\tMenu");
 		printf("\n\n[1] MMQ \n[2] Trapezio \n[3] Sair\n\n ");
 		scanf("%i",&op);
 		fflush(stdin);

 		switch(op){
 			case 1:
	 				info_mmq(minimo);
	 				do{
	 					system("cls");
		 				printf("\n\n[1] Reta \n[2] Parabola \n[3] Voltar \n\n ");
		 				scanf("%i",&a);
		 				fflush(stdin);
		 				switch(a)
						 {
			 				case 1:
			 					system("cls");
			 					calc_mmq_reta(minimo);
			 				break;
			 				
			 				case 2:
			 					system("cls");
			 					calc_mmq_parabola(minimo);
			 				break;
		 				}
		 			}while(a!=3);
			break;	
							  			
 			case 2:
 				informacoes(trapezio);
 				calc_trapezio(trapezio);

 			break;
					
 		}
	 }while(op!=3);
	system("cls");
	printf("\n\t\t Obrigado por utilizar a calculadora para metodos numericos!\n");
 }
 
 // começo funções MMQ
void aloca_mmq(mmq **c,int j)
 {
	if((*c=(mmq*)realloc(*c,j*sizeof(mmq)))==NULL) // aqui estamos alocando um espaço na memoria para a estrutura de mmq
  		exit(1);	
 }
 
void info_mmq(mmq *c) // recebendo informações
  {
  	
  	int i;
  	
  	printf("\nDigite a quantidade de colunas da tabela:\n ");
	scanf("%i", &c->qtde);
//	printf("valor: %i\n", c->qtde); //teste
	
 	for (i = 0; i < c->qtde ; i++)
	{
	    printf("\nDigite o valores da tabela em x[%i]:\n ",i+1);
	    scanf("%f", c->x+i);
//	    printf("valor: %f\n", *(c->x+i)); //teste
	    getchar(); //limpa o buffer de entrada
	}
	
	
	 	for (i = 0; i < c->qtde ; i++)
	{
	    printf("\nDigite o valores da tabela em y[%i]:\n ",i+1);
	    scanf("%f", c->y+i);
//	    printf("valor: %f\n", *(c->y+i)); //teste
	    getchar(); //limpa o buffer de entrada
	}
  }
  
// MMQ Reta
void calc_mmq_reta(mmq *c) 
{
   	int i,j,p;
   	float a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,qw,r1,r2,aux;
   	p = c->qtde;
//	printf("valor: %i\n", p); //teste
   	
   	for(i=0;i<p;i++)
   	{
   		*(c->aux_1+i)= pow(*(c->x+i),0);
//   		printf("valor: %f\n", *(c->aux_1+i)); //teste
   		
   		*(c->aux_2+i ) = pow(*(c->x+i),1);
//   		printf("valor 2: %f\n", *(c->aux_2+i)); //teste

	}
	
	printf("\n---------Construindo p---------\n\n \tVetores\n ");
	printf("\n\ty\tu0\tu1");
	for(i=0;i<c->qtde;i++)
	{
		printf("\n\t%.3f\t%.3f\t%.3f",*(c->y+i),*(c->aux_1+i),*(c->aux_2+i));
	}

	printf("\n\n---------Sistema escalar---------\n\n Sistema obtido pelo produto escalar\n");
	for (i = 0; i < 1; i++) {
	    for (j = 0; j < p; j++) {
	        *(c->teste + i*p + 0) = (a1 += (*(c->aux_1 + j)) * (*(c->aux_1 + j))); // (u0,u0)
	        *(c->teste + i*p + 1) = (a2 += (*(c->aux_1 + j)) * (*(c->aux_2 + j))); // (u1,u0 = u0,u1)
	        *(c->teste + i*p + 2) = (a3 += (*(c->aux_1 + j)) * (*(c->aux_2 + j))); // (u1,u0 = u0,u1)
	        *(c->teste + i*p + 3) = (a4 += (*(c->aux_2 + j)) * (*(c->aux_2 + j))); // (u1,u1)
	        *(c->teste + i*p + 4) = (a5 += (*(c->y + j)) * (*(c->aux_1 + j))); // (y,u0)
	        *(c->teste + i*p + 5) = (a6 += (*(c->y + j)) * (*(c->aux_2 + j))); // (y,u1)
	    }
	}

	
	

//	printf("\n teste valor: %f", *(c->teste + 0*p + 0)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 1)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 2)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 3)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 4)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 5)); //teste
//	system("pause"); //teste
	
	printf("\n\t%.3f\t%.3f\t%.3f\n\t%.3f\t%.3f\t%.3f\n",*(c->teste + 0*p + 0),*(c->teste + 0*p + 1),*(c->teste + 0*p + 4),*(c->teste + 0*p + 2),*(c->teste + 0*p + 3),*(c->teste + 0*p + 5));
	
	
	printf("\n\n---------Eliminacao Gauss---------\n\n Sistema linear equivalente\n\ ");
	qw = (*(c->teste + 0*p + 2)) / (*(c->teste + 0*p + 0));



//	printf("\nvalor %f",qw); //teste
//	system("pause"); //teste
	
	
	*(c->teste + 0*p + 2) = *(c->teste + 0*p + 2) - ((*(c->teste + 0*p + 0)) * qw);
	*(c->teste + 0*p + 3) = *(c->teste + 0*p + 3) - ((*(c->teste + 0*p + 1)) * qw);
	*(c->teste + 0*p + 5) = *(c->teste + 0*p + 5) - ((*(c->teste + 0*p + 4)) * qw);
	
//	printf("\n teste valor: %f", *(c->teste + 0*p + 2)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 3)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 5)); //teste
//	system("pause"); //teste
	
	printf("\n\t%.3f\t%.3f\t%.3f\n\t%.3f\t%.3f\t%.3f\n",*(c->teste + 0*p + 0),*(c->teste + 0*p + 1),*(c->teste + 0*p + 4),*(c->teste + 0*p + 2),*(c->teste + 0*p + 3),*(c->teste + 0*p + 5));
	
	printf("\n\n\---------Resposta---------\n\n ");
	
	r2 = (*(c->teste + 0*p + 5)) / (*(c->teste + 0*p + 3));
//	printf("\nvalor %f", r2); //teste
	
	aux = (*(c->teste + 0*p + 1)) * r2;
//	printf("\nvalor %f", aux); //teste
	r1 = ((*(c->teste + 0*p + 4)) - aux) / (*(c->teste + 0*p + 0));
	
	printf("\n\ta0=%.3f\n\ta1=%.3f\n", r1, r2);
	printf("\n\tA reta que melhor se aproxima a funcao tabelada é p(x)=%.3f+%.3fx\n", r1, r2);
	system("pause");
}
   
   
// MMQ parabola
void calc_mmq_parabola(mmq *c)
{
	
	int i,j,p;
	
   	float a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0,a11=0,a12=0,qw,qe,qa,r1,r2,r3,aux,aux_1,aux_2;
   	p = c->qtde;
//	printf("valor: %i\n", p); //teste
   	
   	
   	for(i=0;i<p;i++)
   	{
   		*(c->aux_1+i)= pow(*(c->x+i),0);
//   		printf("valor: %f\n", *(c->aux_1+i)); //teste
   		
   		*(c->aux_2+i ) = pow(*(c->x+i),1);
//   		printf("valor 2: %f\n", *(c->aux_2+i)); //teste

   		*(c->aux_3+i ) = pow(*(c->x+i),2);
//   		printf("valor 2: %f\n", *(c->aux_2+i)); //teste

	}
	
	
	
	printf("\n---------Construindo p---------\n\n \tVetores\n ");
	printf("\n\ty\tu0\tu1\tu2");
	for(i=0;i<c->qtde;i++)
	{
		printf("\n\t%.3f\t%.3f\t%.3f\t%.3f",*(c->y+i),*(c->aux_1+i),*(c->aux_2+i),*(c->aux_3+i));
	}



	printf("\n\n---------Sistema escalar---------\n\n Sistema obtido pelo produto escalar\n");
	for (i = 0; i < 1; i++) {
	    for (j = 0; j < p; j++) {
	        *(c->teste + i*p + 0) = (a1 += (*(c->aux_1 + j)) * (*(c->aux_1 + j))); // (u0,u0)
	        *(c->teste + i*p + 1) = (a2 += (*(c->aux_1 + j)) * (*(c->aux_2 + j))); // (u1,u0 = u0,u1)
	        *(c->teste + i*p + 2) = (a3 += (*(c->aux_1 + j)) * (*(c->aux_3 + j))); // (u2,u0 = u0,u2)
	        
	        
	        *(c->teste + i*p + 3) = (a4 += (*(c->aux_2 + j)) * (*(c->aux_1 + j))); // (u1,u0 = u0,u1)
	        *(c->teste + i*p + 4) = (a5 += (*(c->aux_2 + j)) * (*(c->aux_2 + j))); // (u1,u1)
	        *(c->teste + i*p + 5) = (a6 += (*(c->aux_2 + j)) * (*(c->aux_3 + j))); // (u2,u1 = u1,u2) 
	        
	        *(c->teste + i*p + 6) = (a7 += (*(c->aux_3 + j)) * (*(c->aux_1 + j))); // (u2,u0 = u0,u2)
	        *(c->teste + i*p + 7) = (a8 += (*(c->aux_3 + j)) * (*(c->aux_2 + j))); // (u2,u1 = u1,u2) 
	        *(c->teste + i*p + 8) = (a9 += (*(c->aux_3 + j)) * (*(c->aux_3 + j))); // (u2,u2)
	        
	        
	        *(c->teste + i*p + 9) = (a10 += (*(c->y + j)) * (*(c->aux_1 + j))); // (y,u0)
	        *(c->teste + i*p + 10) = (a11 += (*(c->y + j)) * (*(c->aux_2 + j))); // (y,u1)
	        *(c->teste + i*p + 11) = (a12 += (*(c->y + j)) * (*(c->aux_3 + j))); // (y,u2)
	    }
	}
	
//	printf("\n teste valor: %f", *(c->teste + 0*p + 0)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 1)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 2)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 3)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 4)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 6)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 7)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 8)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 9)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 10)); //teste
//	printf("\n teste valor: %f", *(c->teste + 0*p + 11)); //teste
//	system("pause"); //teste
	
	printf("\n\t%.3f\t%.3f\t%.3f\t%.3f",*(c->teste + 0*p + 0),*(c->teste + 0*p + 1),*(c->teste + 0*p + 2),*(c->teste + 0*p + 9));
	printf("\n\t%.3f\t%.3f\t%.3f\t%.3f",*(c->teste + 0*p + 3),*(c->teste + 0*p + 4),*(c->teste + 0*p + 5),*(c->teste + 0*p + 10));
	printf("\n\t%.3f\t%.3f\t%.3f\t%.3f",*(c->teste + 0*p + 6),*(c->teste + 0*p + 7),*(c->teste + 0*p + 8),*(c->teste + 0*p + 11));
//	system("pause"); //teste
	
	
	printf("\n\n---------Eliminacao Gauss---------\n\n Sistema linear equivalente\n\ ");
	qw = (*(c->teste + 0*p + 3)) / (*(c->teste + 0*p + 0));
	qe = (*(c->teste + 0*p + 6)) / (*(c->teste + 0*p + 0));
//	printf("\nvalor %f",qw); //teste
//	printf("\nvalor %f",qe); //teste
//	system("pause"); //teste
	
	
	*(c->teste + 0*p + 3) = *(c->teste + 0*p + 3) - ((*(c->teste + 0*p + 0)) * qw);
	*(c->teste + 0*p + 4) = *(c->teste + 0*p + 4) - ((*(c->teste + 0*p + 1)) * qw);
	*(c->teste + 0*p + 5) = *(c->teste + 0*p + 5) - ((*(c->teste + 0*p + 2)) * qw);
	*(c->teste + 0*p + 10) = *(c->teste + 0*p + 10) - ((*(c->teste + 0*p + 9)) * qw);
	
	*(c->teste + 0*p + 6) = *(c->teste + 0*p + 6) - ((*(c->teste + 0*p + 0)) * qe);
	*(c->teste + 0*p + 7) = *(c->teste + 0*p + 7) - ((*(c->teste + 0*p + 1)) * qe);
	*(c->teste + 0*p + 8) = *(c->teste + 0*p + 8) - ((*(c->teste + 0*p + 2)) * qe);
	*(c->teste + 0*p + 11) = *(c->teste + 0*p + 11) - ((*(c->teste + 0*p + 9)) * qe);
	
	
	qa = (*(c->teste + 0*p + 7)) / (*(c->teste + 0*p + 4));
	
	*(c->teste + 0*p + 7) = *(c->teste + 0*p + 7) - ((*(c->teste + 0*p + 4)) * qa);
	*(c->teste + 0*p + 8) = *(c->teste + 0*p + 8) - ((*(c->teste + 0*p + 5)) * qa);
	*(c->teste + 0*p + 11) = *(c->teste + 0*p + 11) - ((*(c->teste + 0*p + 10)) * qa);
	
	printf("\n\t%.3f\t%.3f\t%.3f\t%.3f",*(c->teste + 0*p + 0),*(c->teste + 0*p + 1),*(c->teste + 0*p + 2),*(c->teste + 0*p + 9));
	printf("\n\t%.3f\t%.3f\t%.3f\t%.3f",*(c->teste + 0*p + 3),*(c->teste + 0*p + 4),*(c->teste + 0*p + 5),*(c->teste + 0*p + 10));
	printf("\n\t%.3f\t%.3f\t%.3f\t%.3f",*(c->teste + 0*p + 6),*(c->teste + 0*p + 7),*(c->teste + 0*p + 8),*(c->teste + 0*p + 11));
//	system("pause"); //teste
//	
	
	printf("\n\n\---------Resposta---------\n\n ");
	
	r3 = (*(c->teste + 0*p + 11)) / (*(c->teste + 0*p + 8));
//	printf("\nvalor %f", r2); //teste

	aux = (*(c->teste + 0*p + 5)) * r3;
//	printf("\nvalor %f", aux); //teste

	r2 = ((*(c->teste + 0*p + 10)) - aux) / (*(c->teste + 0*p + 4));
	
	aux = (*(c->teste + 0*p + 2)) * r3;
	
	aux_1 = (*(c->teste + 0*p + 1)) * r2;
	
//	printf("\nvalor %f", aux_1); //teste
//	printf("\nvalor %f", aux); //teste
//	printf("\nvalor %f", r2); //teste
//	printf("\nvalor %f", r3); //teste
//	system("pause");
	aux_2 = aux + aux_1;	
//	printf("\nvalor %f", aux_2); //teste
//	system("pause");


	r1 = ((*(c->teste + 0*p + 9)) - aux_1 - aux) / (*(c->teste + 0*p + 0));
	
	printf("\n\ta0=%.3f\n\ta1=%.3f\n\ta2=%.3f\n", r1, r2, r3);
	printf("\n\tA parabola que melhor se aproxima a funcao tabelada e p(x)=%.3f+%.3fx+%.3f^2\n", r1, r2, r3);
	system("pause");
  	
}  
   
  // fim funções MMQ
  
  
  
  // começo funções trapezio
  
void aloca_trap(trap **c,int j)
{
	if((*c=(trap*)realloc(*c,j*sizeof(trap)))==NULL) // aqui estamos alocando um espaço na memoria para a estrutura de trapezio
		exit(1);
}


 void informacoes(trap *c) // recebendo informações
 {
 	int i;
 	float aux,a,b;
 	
 	
 	printf("\nDigite o grau do polinomio:(1 ou 2):\n");
 	scanf("%i",&c->grau);
  	fflush(stdin);

	for(i=0;i<((c->grau) + 1);i++)
	{
	 	printf("\nDigite o coeficiente :\n");
		scanf("%f",c->coeficiente+i);
        fflush(stdin);
    }
	printf("\n----------------------------------------\n");
    printf("\nDigite os intervalos:\n");
 	scanf("%f %f",c->intervalos, c->intervalos+1);
  	fflush(stdin);
  	
  	//arrumando ordem correta
	if (*(c->intervalos) > *(c->intervalos+1))
	{
	    aux = *(c->intervalos);
	    
	    *(c->intervalos) = *(c->intervalos+1);
	    
	    *(c->intervalos+1) = aux;
	    
	}
	
//	printf("\nvalor %.3f",*(c->intervalos));  // teste
//	printf("\nvalor %.3f",*(c->intervalos+1));  // teste
//	system("pause");  // teste


 }

void calc_trapezio(trap *c)
{
	char op;
	do{
		system("cls");
		int i,div;
		float h,x,it,aux;
		aux=0;
		x = *(c->intervalos);
		
		printf("\nDigite o numero de divisoes:\n");
	 	scanf("%i",&div);
	  	fflush(stdin);
	  	
	  	h = (*(c->intervalos+1) - *(c->intervalos)) / div; // calculo h
	  	
	  	printf("\n h = (%.3f - %.3f) / %i",*(c->intervalos+1),*(c->intervalos),div);  
	  	printf("\n h = %.3f\n ",h); 
	//  	system("pause"); //teste
		printf("\n-------------------------------------\n");
		printf("\n\tTabela de valores\n");
		printf("\n\tx\tf(x)");
		for(i=0;i<(div+1);i++)
		{
			if(c->grau == 1) // equação de primeiro grau
			{
				
				*(c->variavel+i) = (*(c->coeficiente) * pow(x, 1)) + *(c->coeficiente+1);
				printf("\n\t%.3f\t%3.f",x,*(c->variavel+i));
				x += h;
			}	
			
			if(c->grau == 2) // equação de segundo grau
			{
				*(c->variavel + i) = (*(c->coeficiente) * pow(x, 2)) + (*(c->coeficiente + 1) * pow(x, 1)) + *(c->coeficiente + 2);
				printf("\n\t%.3f\t%.3f",x,*(c->variavel+i));
				x += h;
			}	
		}
		for(i=0;i<(div+1);i++)
		{
			if(i == 0 || i == div) // somando f(x)
			{
				continue;
			}
			
			aux += *(c->variavel+i);
		}
		
		it = (h/2) * ((*c->variavel + *(c->variavel + div)) + 2 * aux); //calculo final
		if(div == 1)
		{
			printf("\n\tIT = %.3f\n",it);
			system("pause");
		}
		else
		{
			printf("\n\n\tITR = %.3f\n",it);
			system("pause");
		}
		
		printf("\nDeseja digitar novamente com outro numero de divisoes? (s/n) \n");
		scanf("%c",&op);
	}while(op != 'n');
		
}
 // fim funções trapezio
