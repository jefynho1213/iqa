#include <stdio.h>

	int main(){

		double param[8], peso[9] = {0.17, 0.15, 0.12, 0.10, 0.10, 0.10, 0.10, 0.08, 0.08} , teste[8]; 
		 //oxigenio 0, coliformes 1, potencial 2, demanda 3, temperatura 4, nitrogenio 5, fosforo 6, turbidez 7, r total 8;
		int i;

		for(i=0; i<=8; i++){
			scanf("%lf", &param[i]);

			}

		for(i=0; i<=8; i++){
			param[i]*=peso[i];
			printf("%lf\n", param[i]);
		}

		/*

		%O2 = param[0]
		CF = param[1]
		pH = param[2]
		DBO = param[3]
		FT = param[]

 		*/

	}
