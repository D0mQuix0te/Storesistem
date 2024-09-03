#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct produto{
	int codi;
	int qtd_esto;
	char descri[50];	
	float preco;
}Produto, *PProduto, **PPProduto;

typedef struct carrinho{
	int codi;
	int qtd_esto;
	char descri[50];
	float preco;
	int receita;
}Carrinho, *PCarrinho, **PPCarrinho;


void inicializa_vetor(PPProduto ppp){
	int i;
	for(i=0; i<MAX; i++){     
    	ppp[i] = NULL; 
  	}   
}

void inicializa_carrinho(PPCarrinho ppc){
	int i;
	for(i = 0; i<MAX; i++){
		ppc[i] = NULL;
	}
}


int incluir_produtos_inicial(PPProduto ppp){
    int num_produtos, i; 
    printf("\nInforme o numero de produtos a serem incluidos na loja: ");
    scanf("%d",&num_produtos);
    for(i=0; i<num_produtos; i++){     
      ppp[i] = (PProduto) malloc(sizeof(Produto));
      if (ppp[i] == NULL){
         printf("\n\nMemoria insuficiente\n\n");
         exit(1);  
      }
		printf("\n\nInforme o codigo do produto: ");
		scanf("%d", &ppp[i]->codi);
		printf("\nInforme a descricao do produto: ");
		scanf(" %[^\n]", ppp[i]->descri);		
		printf("\nInforme a quantidade do produto em estoque: ");
		scanf("%d", &ppp[i]->qtd_esto);
		printf("\nInforme o preco do produto: ");
		scanf("%f", &ppp[i]->preco);
	}                
   return num_produtos;
}

int incluir_produtos(PPProduto ppp, int aux){
	int num_produtos, i; 
    printf("\nInforme o numero de produtos a serem incluidos na loja: ");
    scanf("%d",&num_produtos);
    for(i=aux; i<num_produtos + aux; i++){     
      ppp[i] = (PProduto) malloc(sizeof(Produto));
      if (ppp[i] == NULL){
         printf("\n\nMemoria insuficiente\n\n");
         exit(1);           
      }
		printf("\n\nInforme o codigo do produto: ");
		scanf("%d", &ppp[i]->codi);
		printf("\nInforme a descricao do produto: ");
		scanf(" %[^\n]", ppp[i]->descri);		
		printf("\nInforme a quantidade do produto em estoque: ");
		scanf("%d", &ppp[i]->qtd_esto);
		printf("\nInforme o preco do produto: ");
		scanf("%f", &ppp[i]->preco);
	}
    aux += num_produtos;               
   return aux;  

}

void alterar_produtos(int num_produtos, PPProduto ppp){
	int i;

    listar_produtos(num_produtos, ppp);
    printf("\n\nInforme a posicao do produto a ser alterado: ");
    scanf("%d", &i);
    printf("\nInforme o codigo do produto: ");
    scanf("%d", &ppp[i]->codi);
    printf("\nInforme a descricao do produto: ");
    scanf(" %[^\n]", ppp[i]->descri);
    printf("\nInforme a quantidade do produto em estoque: ");
    scanf("%d", &ppp[i]->qtd_esto);
    printf("\nInforme o preco do produto: ");
    scanf("%f", &ppp[i]->preco);
    printf("\nProduto alterado com sucesso!");
}

int excluir_produtos(PPProduto ppp, int num_produtos){
	int i, j;

    printf("\nInforme o indice do produto a ser excluido: ");
    scanf("%d", &i);
    if(num_produtos == 2 && i == 1){
		return (num_produtos - 1);
	}else if(num_produtos == 2 && i == 0){
		for(j = i; j < num_produtos; j++){
			ppp[j] = ppp[j+1];
		}
		return (num_produtos - 1);
	}else if(i == num_produtos - 1 && i != 0){
		return (num_produtos - 1);
	}else if(i == num_produtos - 1 && i == 0){
		return (num_produtos - 1);
	}else{
		for(j = i; j < num_produtos - 1; j++){
    		ppp[j] = ppp[j+1];
		}
		return (num_produtos - 1);
	}
	
}

void consultar_produtos(PPProduto ppp, int num_produtos){
	int i, j, k, sair;
	printf("\nNumero  Descricao\n");
	for(i=0; i<num_produtos; i++){    
    	printf("\n%d	%s			 \n", i,	ppp[i]->descri);
  	}
  	printf("\nInforme o indice do produto a ser consultado: ");
  	scanf("%d", &j);
  	do{
  		system("cls");
  		printf("\nCodigo                (1)\n");		
		printf("\nQuantidade em estoque (2)\n");	
		printf("\nValor                 (3)\n");
		printf("\nSair                  (4)\n");
  		printf("\n\nEscolha a alternativa para detalhes: ");
  		scanf("%d", &k);
	  	switch(k){
	  		case 1:
	  			printf("\nCodigo: %d", ppp[j]->codi);
	  			getch();
	  			system("cls");
	  			break;
	  		case 2:
	  			printf("\nQuantidade: %d", ppp[j]->qtd_esto);
	  			getch();
	  			system("cls");
	  			break;
	  		case 3:
	  			printf("\nValor: %.2f", ppp[j]->preco);
	  			getch();
	  			system("cls");
	  			break;
	  		case 4:
	  			sair = 1;
	  			break;
		}
  	}while(sair == 0);	
}

void listar_produtos(int num_produtos, PPProduto ppp, int qtd_produtos_c){
  printf("\nNumero	Codigo	Descricao	Quantidade em estoque	Valor\n");
  int i, j;
  for(i=0; i<num_produtos; i++){    
    printf("\n%d	%d	%s			%d		%.2f \n", i,	ppp[i]->codi, ppp[i]->descri, ppp[i]->qtd_esto, ppp[i]->preco);
  }                                         

}
int adicionar_carrinho(PPCarrinho ppc, PPProduto ppp, int qtd_produtos_c){
	int i, escolha, escolha2, aux, aux2; 
	int aux_c = 0;
	int j = 0;
	printf("\nInforme o indice do produto a ser adicionado ao carrinho: ");
	scanf("%d", &escolha);
	printf("\nInforme a quantidade deste produto a ser adicionado: ");
	scanf("%d", &escolha2);
	
	int x = 0;
	for(i=0;i<qtd_produtos_c;i++){
		if(ppc[i]->codi==ppp[escolha]->codi){
			x = x + 1;
		}
	}

	if(ppp[escolha]->qtd_esto >= (escolha2+x)){
		escolha2 = escolha2 + qtd_produtos_c;
		if(qtd_produtos_c == 1){
			for(i = 0; i < escolha2; i++){
				ppc[i] = (PCarrinho) malloc(sizeof(Carrinho));
				ppc[i]->codi = ppp[escolha]->codi;
				strcpy(ppc[i]->descri, ppp[escolha]->descri);
				ppc[i]->qtd_esto = ppp[escolha]->qtd_esto;
				ppc[i]->preco = ppp[escolha]->preco;
			}
		}else{
			for(i = qtd_produtos_c; i < escolha2; i++){
				ppc[i] = (PCarrinho) malloc(sizeof(Carrinho));
				ppc[i]->codi = ppp[escolha]->codi;
				strcpy(ppc[i]->descri, ppp[escolha]->descri);
				ppc[i]->qtd_esto = ppp[escolha]->qtd_esto;
				ppc[i]->preco = ppp[escolha]->preco;
			}
		}
	}else{
		printf("Acabou o estoque!!!");
	}
	getch();
	return escolha2;
}

void listar_carrinho(int qtd_produtos_c, PPCarrinho ppc){
	printf("\nNumero	Codigo	Descricao	Valor\n");
	int i, j; 
	float soma = 0;         
	for(i=0; i<qtd_produtos_c; i++){
		if(ppc[i]->preco )    
    printf("\n%d	%d	%s	        %.2f \n", i,	ppc[i]->codi, ppc[i]->descri, ppc[i]->preco);
    	soma = soma + ppc[i]->preco;
	}
	printf("\n\nPRECO DO CARRINHO: %.2f", soma);
}

int excluir_carrinho(PPCarrinho ppc, int qtd_produtos_c){
	int i, j;

    printf("\nInforme o indice do produto a ser excluido: ");
    scanf("%d", &i);
    if(qtd_produtos_c == 2 && i == 1){
		return (qtd_produtos_c - 1);
	}else if(qtd_produtos_c == 2 && i == 0){
		for(j = i; j < qtd_produtos_c; j++){
			ppc[j] = ppc[j+1];
		}
		return (qtd_produtos_c - 1);
	}else if(i == qtd_produtos_c - 1){
		return (qtd_produtos_c - 1);
	}else{
		for(j = i; j < qtd_produtos_c; j++){
    		ppc[j] = ppc[j+1];
		}
		return (qtd_produtos_c - 1);
	}
}

int alterar_carrinho(PPCarrinho ppc, int qtd_produtos_c){
	int i, j, opcao, qtd, opcao2;

    printf("\n\nInforme a posicao do produto a ser alterado: ");
    scanf("%d", &i);
    printf("\nDeseja aumentar ou diminuir a quantidade do produto (1) - Aumentar / (2) - Diminuir: ");
    scanf("%d", &opcao);
    if(opcao == 1){
    	printf("\nInforme a quantidade que deseja aumentar: ");
    	scanf("%d", &opcao2);
    	opcao2 += qtd_produtos_c;
    	printf("%d", qtd_produtos_c);
    	getch();
	    for(j = qtd_produtos_c; j < opcao2; j++){
	    	ppc[j] = (PCarrinho) malloc(sizeof(Carrinho));
			ppc[j]->codi = ppc[i]->codi;
			strcpy(ppc[j]->descri, ppc[i]->descri);
			ppc[j]->qtd_esto = ppc[i]->qtd_esto;
			ppc[j]->preco = ppc[i]->preco;
		}
		return opcao2;
	}else{
		printf("\nInforme a quantidade que deseja diminuir: ");
		scanf("%d", &opcao2);
			if(qtd_produtos_c == 2 && j == 1){
				return (qtd_produtos_c - opcao2);
			}else if(qtd_produtos_c == 2 && j == 0){
				for(j = i; j < qtd_produtos_c; j++){
					ppc[j] = ppc[j+1];
				}
			}else if(qtd == qtd_produtos_c - 1){
				return (qtd_produtos_c - opcao2);
			}else{
				for(j = i; j < qtd_produtos_c - 1; j++){
    				ppc[j] = ppc[j+1];
				}
				return (qtd_produtos_c - opcao2);
			}
		}
	}


void finalizar_pedido(PPCarrinho ppc, int qtd_produtos_c){
	
	srand(time(0));
	printf("\nRECEITA DA COMPRA: %d", rand());
	FILE * arq;
	int i;
	arq = fopen("Relatorio_de_vendas.txt","w");
	if(arq == NULL){
		printf("\nErro ao abrir o arquivo");
		exit(1);
	}	
	float cod_pedido = (float)rand()/(float)(RAND_MAX/100.00);
        printf("Pedido %d finalizado",&cod_pedido);
    	for(i=0;i<qtd_produtos_c;i++){
			fprintf(arq,"\nNumero        Codigo        Descricao        Quantidade em estoque        Valor\n");
			fprintf(arq,"\n%d        %d        %s                        %d                %.2f \n", i, ppc[i]->codi, ppc[i]->descri, qtd_produtos_c, ppc[i]->preco);
		}
	fclose(arq);
}
	   
	
int main(int argc, char *argv[]) {	
	int saida = 0, opcao;
	int voltar1 = 0, opcao1;
	int voltar2 = 0, opcao2;
	Produto* produtos[MAX];
	Carrinho* carrinhos[MAX]; 
	int qtd_produtos, aux, aux2, aux3;
	int qtd_produtos_c, aux_c, aux_c2, aux_c3, aux_c4;
	inicializa_vetor(produtos);
	inicializa_carrinho(carrinhos);
	
	aux = incluir_produtos_inicial(produtos);
	aux2 = aux;
	aux3 = aux;
	
	qtd_produtos_c = 0;
	
	
	
	do{
		system("cls");
		printf("\nMercadao varejo:\n");
		printf("\n(1) Gerenciar produtos");
		printf("\n(2) Registrar Pedido de Compra");	
		printf("\n(3) Sair\n");
		printf("\nSelecione a opcao desejada: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
	
				do{					
					system("cls");
					printf("\nGerenciar Produtos:\n");
					printf("\n1) Incluir");
					printf("\n2) Alterar");	
					printf("\n3) Excluir");
					printf("\n4) Consultar");
					printf("\n5) Listar");
					printf("\n6) Voltar\n");
					printf("\nSelecione a opcao desejada: ");
					scanf("%d", &opcao1);
					
					switch(opcao1){
						case 1:
							system("cls");
							qtd_produtos = incluir_produtos(produtos, aux3);
							aux2 = qtd_produtos;
							aux3 = qtd_produtos;
							break;
						case 2:
							system("cls");
							alterar_produtos(aux2, produtos);
							break;
						case 3:
							system("cls");
							listar_produtos(aux3, produtos, qtd_produtos_c);
							aux3 = excluir_produtos(produtos, aux2);
							getch();
							break;
						case 4:
							system("cls");
							consultar_produtos(produtos, aux3);
							getch();
							break;
						case 5:
							system("cls");
							listar_produtos(aux3, produtos, qtd_produtos_c); 
							getch();
						case 6:
							voltar1 = 1;	
							
					}
				}while(!voltar1);			
				break;
				
			case 2:
				system("cls");
				do{					
					system("cls");
					printf("\nRegistrar Pedido de Compra:\n");
					printf("\n1) Adicionar produto");
					printf("\n2) Consultar carrinho de compras");	
					printf("\n3) Remover um produto do carrinho de compras");
					printf("\n4) Alterar a quantidade de um produto do carrinho de compras");
					printf("\n5) Finalizar pedido");
					printf("\n6) Voltar\n");
					printf("\nSelecione a opcao desejada: ");
					scanf("%d", &opcao1);
					
					switch(opcao1){
						case 1:
							system("cls");
							listar_produtos(aux3, produtos, qtd_produtos_c);
							qtd_produtos_c = adicionar_carrinho(carrinhos, produtos, aux_c3);
							aux_c = qtd_produtos_c;
							aux_c2 = qtd_produtos_c;
							aux_c3 = qtd_produtos_c;
							aux_c4 = qtd_produtos_c;
							getch();
							break;
						case 2:
							system("cls");
							listar_carrinho(aux_c4, carrinhos);
							getch();
							break;
						case 3:
							aux_c2 = excluir_carrinho(carrinhos, aux_c4);
							aux_c4 = aux_c2;
							getch();
							break;
						case 4:
							listar_carrinho(aux_c4, carrinhos);
							aux_c3 = alterar_carrinho(carrinhos, aux_c4);
							aux_c4 = aux_c3;
							break;
						case 5:
							system("cls");
							finalizar_pedido(carrinhos, aux_c3);
							getch();
							exit(1);
							break;                        
						case 6:
							voltar2 = 1;	
							
					}
				}while(!voltar2);			
				break;
			
			case 3:
				saida = 1;
				break;
		
			default:
				printf("\nOpcao invalida!");
				getch();			
		}			

	}while(!saida);	
	
	system("PAUSE");
	
	return 0;
}




