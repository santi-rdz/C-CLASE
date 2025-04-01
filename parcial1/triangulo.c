#include <stdio.h>
#include <math.h>
#define RADIAN_TO_DEGREE 57.2958

int main(){

	float base, altura, hipo, area, per, teta, beta;
	printf("Ingrese la base -> ");
	scanf("%f", &base);
	
	printf("Ingrese la altura -> ");
	scanf("%f", &altura);

	hipo = sqrt(pow(base,2) + pow(altura,2));
	area = (base*altura)/2;
	per = 	base+altura+hipo;
	teta = atan(altura/base) * RADIAN_TO_DEGREE;
	beta = atan(base/altura) * RADIAN_TO_DEGREE;

		
	printf("\n------\n" "Beta -> %.3f\n", beta);
	printf("Teta -> %.3f\n", teta);
	printf("Hipotenusa -> %.3f\n", hipo);
	printf("Area -> %.3f\n", area);	
	printf("Perimetro -> %.3f\n", per);
	
	

	return 0;
}