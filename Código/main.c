#include <stdio.h>
#include <string.h>

void imprimir(int *vet, int tam, char *prefixo){
	int i;
	for(i=1; i <= tam; i++){
		printf("%s[%d] = %d\n",prefixo,i,vet[i]);
	}
}

void par_impar(int numero, char *tipo){
	if((numero % 2) == 0){
		strcpy(tipo, "par");
	} else {
		strcpy(tipo, "impar");
	}
}

int inserir(int *vet, int num){
	int posicao;
	
	posicao = (vet[0]+1);
	
	if(posicao < 6){
		vet[posicao] = num;
		vet[0]++;
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int total=0, num;
	char tipo[15];
	int par[100]={0}, impar[100]={0};
	
	while(total < 15){
		scanf("%d",&num);
		par_impar(num, tipo);
		
		if(strcmp(tipo, "par") == 0){
			
			if(inserir(par,num) == 0){
				imprimir(par, par[0], tipo);
				par[0] = 1;
				par[1] = num;
			}
		} else {
			if(inserir(impar,num) == 0){
				imprimir(impar, impar[0], tipo);
				impar[0] = 1;
				impar[1] = num;
			}
		}
		total++;
	}
	
	imprimir(par, par[0], "par");
	imprimir(impar, impar[0], "impar");
	
	return 0;
}