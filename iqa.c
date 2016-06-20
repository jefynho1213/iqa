#include <stdio.h>
#include <math.h>
#include "iqa.h"

	int main()
	{

		double o2, cf, ph, dbo, ft, nt, tu, dt, st, qo2, qcf, qph, qdbo, qft, qnt, qtu, qst, qdt, media;
		/*
		o2 = percentual de oxigenio
		cf = colifornes fecais
		ph = percentual hidrogenico
		dbo = demanda bioquimica de oxigenio
		ft = fosforo total
		nt = nitrogenio total
		tu = turbidez
		dt = variacao de temperatura
		st = solidos totais
				*/

		printf("   ******************************\n");
		printf("   **                          **\n");
		printf("   **   ***** ******   ******  **\n");
		printf("   **     *   *    *   *    *  **\n");
		printf("   **     *   *    *   ******  **\n");
		printf("   **     *   *   **** *    *  **\n");
		printf("   **   ***** ****** * *    *  **\n");
		printf("   **                          **\n");
		printf("   ******************************\n\n\n");



		printf("Insira valor do percentual de oxigênio: ");
		scanf("%lf", &o2);
		printf("Insira valor de coliformes fecais(Nmp/mL): ");
		scanf("%lf", &cf);
		printf("Insira valor de percentual hidrogênico: ");
		scanf("%lf", &ph);
		printf("Insira valor de demanda bioquimica de oxigênio(Mg/L): ");
		scanf("%lf", &dbo);
		printf("Insira valor de fosforo total(Mg/L): ");
		scanf("%lf", &ft);
		printf("Insira valor de nitrogenio total: ");
		scanf("%lf", &nt);
		printf("Insira valor de turbidez: ");
		scanf("%lf", &tu);
		printf("Insira valor de variacao de temperatura: ");
		scanf("%lf", &dt);
		printf("Insira valor de solidos totais(Mg/L): ");
		scanf("%lf", &st);

		qo2 = pow(e_o2(o2), peso_o2);
		qcf = pow(e_cf(cf), peso_cf);
		qph = pow(e_ph(ph), peso_ph);
		qdbo = pow(e_dbo(dbo), peso_dbo);
		qdt = pow(e_dt(dt), peso_dt);
		qnt = pow(e_nt(nt), peso_nt);
		qft = pow(e_ft(ft), peso_ft);
		qtu = pow(e_tu(tu), peso_tu);
		qst = pow(e_st(st), peso_st);

		media = qo2 * qcf * qph * qdbo * qdt * qnt * qft * qtu * qst;

		printf("Média = %lf\n", media);

		qualidade(media);

		
		return 0;
	}
