#include <stdio.h>

#define RADIAN_TO_DEGREE 57.2958
#define DEGREE_TO_RADIAN 0.0174
#define KM_TO_MILE	0.6213
#define MILE_TO_KM	1.6093
#define CM_TO_INCH 	0.3937
#define INCH_TO_CM	2.54

int main(void){
	
	float radian, degree,km,mile,cm,inch;
	printf("\nEnter radians ->");
	scanf("%f", &radian);
	
	printf("Enter degrees ->");
	scanf("%f", &degree);
	
	printf("Enter KM ->");
	scanf("%f", &km);

	printf("Enter miles ->");
	scanf("%f", &mile);

	printf("Enter CM ->");
	scanf("%f", &cm);

	printf("Enter Inch ->");
	scanf("%f", &inch);

	printf("\n---------\n" "%.2f Radians in degrees = %.4f\n", radian, 	
	radian*RADIAN_TO_DEGREE);

	printf("%.2f Degrees in radians = %.4f\n", degree, 	
	degree*DEGREE_TO_RADIAN);

	printf("%.2f KM in miles = %.4f\n", km, 	
	km*KM_TO_MILE);

	printf("%.2f Miles in Km = %.4f\n", mile, 	
	mile*MILE_TO_KM);

	printf("%.2f CM in Inch's = %.4f\n", cm, 	
	cm*CM_TO_INCH );

	printf("%.2f Inch's in CM = %.4f\n\n", inch, 	
	inch*INCH_TO_CM);


	
	
	return 0;
}





