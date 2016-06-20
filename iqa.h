#ifndef iqa_h
#define iqa_h

#include <math.h>


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



//notas indice da água ótimo
#define otimo_a 100
#define otimo_b 80

//notas indice da agua bom
#define bom_a 79
#define bom_b 51

//notas indice da agua aceitavel
#define ok_a 50
#define ok_b 37

//notas indice da agua ruim
#define ruim_a 36
#define ruim_b 20

//notas indice da agua pessimo
#define pess_a 19
#define pess_b 0



// pesos
#define peso_o2 	0.17
#define peso_cf 	0.15
#define peso_ph 	0.12
#define peso_dbo 	0.10
#define peso_dt 	0.10
#define peso_nt 	0.10
#define peso_ft 	0.10
#define peso_tu 	0.08
#define peso_st 	0.08

//pessos equacao O2
#define ep_o2_a 100.8
#define ep_o2_b -106
#define ep_o2_c -3745

//pessos equacao cf
#define ep_cf_a 98.03
#define ep_cf_b -36.45
#define ep_cf_c 3.138
#define ep_cf_d 0.06776

//pesos equacao ph
#define ep_ph_a 0.05421
#define ep_ph_b 1.23
#define ep_ph_c -0.09873

//pesos equacao dbo
#define ep_dbo_a 102.6
#define ep_dbo_b -0.1101

//pesos equacao ft
#define ep_ft_a 213.7
#define ep_ft_b -1.680
#define ep_ft_c 0.3325

//pesos equacao nt
#define ep_nt_a 98.96
#define ep_nt_b -0.2232
#define ep_nt_c -0.006457

//pesos equacao tu
#define ep_tu_a 97.34
#define ep_tu_b -0.01139
#define ep_tu_c -0.04917

//pesos equacao vt
#define ep_dt_a 0.0003869
#define ep_dt_b 0.1815
#define ep_dt_c 0.01081

//pesos equacao st
#define ep_st_a 80.26
#define ep_st_b -0.00107
#define ep_st_c 0.03009
#define ep_st_d -0.1185



//equacao de O2
double e_o2(double o2){

	if(o2 == 140)
		return 47;
	else
    {

		double a;

		a = pow(o2 + ep_o2_b, 2);
		return ep_o2_a * exp(a/ ep_o2_c);
    }
}

//equacao de DBO
double e_cf(double cf){

	if(cf> 100000)
		return 3.0;
	else {
		double a, b, c, lg;

		lg=log10(cf);

		a= ep_cf_b*lg;
		b= ep_cf_c*pow(lg, 2);
		c= ep_cf_d*pow(lg, 3);

		return ep_cf_a + a + b + c;
	}
}

// equacao ph
double e_ph(double ph){

	if(ph > 12){
		return 3.0;
	}else {
		if(ph < 2 ){
			return 2.0;
        }else {
			double a;
			a = (ep_ph_b * ph) + (ep_ph_c * pow(ph, 2));
			return (ep_ph_a * pow(ph, a)) + 5.213;
		}
	}
}

//equacao de DBO
double e_dbo(double dbo){


	if(dbo> 30)
		return 2.0;
	else {
		double a = ep_dbo_a*exp(ep_dbo_b*dbo);
		return a;
	}

}
//equcao ft
double e_ft(double ft){

	if(ft> 10)
		return 1.0;
	else{

		double a = ep_ft_b * pow(ft, ep_ft_c);

		return ep_ft_a * exp(a);
	}
}

//equaco nt
double e_nt(double nt){

	if(nt>100)
		return 1.0;
	else {
		double a = pow(nt, ep_nt_b + ep_nt_c * nt);
		return ep_nt_a * a;
	}
}


//equacao tu
double e_tu(double tu){

	if(tu>100)
		return 5.0;
	else {
		double a = ep_tu_b* tu;
		double b = ep_tu_c* sqrt(tu);
		double c = a + b;
		return ep_tu_a * exp(c);
	}
}

//equacao dt
double e_dt(double dt){

	if(dt>15)
		return 9;
	else {
		double a = ep_dt_a * pow(dt + ep_dt_b, 2);
		double b = a + ep_dt_c;

		return 1 / b;
	}

}

//equacao de ST
double e_st(double st){

	if(st>500)
		return 32;
	else{
		double a = ep_st_b * st;
		double b = ep_st_c * sqrt(st);
		double c = ep_st_a * exp(a + b);
		double d = ep_st_d * st;
		return c + d;

	}

}

void qualidade(double media){


	if(media <= 19)
	{
	printf("Qualidade Péssima\n");
	}
	if (media > 19 && media <=36)
	{
	printf("Qualidade Ruim\n");
	}
	if (media > 36 && media <= 50)
	{
	printf("Qualidade Aceitável\n");
	}
	if (media > 50 && media <= 79)
	{
	printf("Qualidade Boa\n");
	}
	if (media > 79)
	{
	printf("Qualidade Ótima\n");
	}

	//caso a média seja maior que 100 ou nenor que 0
	if(media > 100){
		printf("Ocorreu o erro 0100M\n");
	}
	if(meida<0){
		printf("Ocorreu o erro 0<00M\n");
	}

}



#endif
