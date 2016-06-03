#include <stdio.h>
#include <math.h>
#include 'iqa.h'

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

		scanf("%lf", &o2);
		scanf("%lf", &cf);
		scanf("%lf", &ph);
		scanf("%lf", &dbo);
		scanf("%lf", &ft);
		scanf("%lf", &nt);
		scanf("%lf", &tu);
		scanf("%lf", &dt);
		scanf("%lf", &st);

		qo2 = pow(e_o2(o2), peso_o2);
		qcf = pow(e_cf(cf), peso_cf);
		qph = pow(e_ph(ph), peso_ph);
		qdbo = pow(e_dbo(dbo), peso_dbo);
		qvt = pow(e_dt(dt), peso_dt);
		qnt = pow(e_nt(nt), peso_nt);
		qft = pow(e_ft(ft), peso_ft);
		qtu = pow(e_tu(tu), peso_tu);
		qdt = powe_st(st), peso_st);

		media = qo2 * qcf * qph *; 




		return 0;
	}

