#include <stdio.h>

int getOption(){

   int option;

   printf("\n[1] Display Binary (Most significant -> Less)\n");
   printf("[2] Display Binary iverted (Less significant -> Highest)\n");
   printf("[3] Exit\n");
   printf("Option -> ");
   scanf("%d", &option);
   return option;
}
int main(){
   int option, number, i,run = 1;
   while (run){
      option = getOption();
      switch (option){
         case 1:
            printf("\nInput a number -> ");
            scanf("%d", &number);
            i = 15;
            while (i>=0){
               if (i % 4 == 0){  
                  printf("%d ", (number & (1<<i--)) > 0);
                  continue;
               }
               printf("%d", (number & (1<<i--)) > 0);
            }
            break;
         case 2:
            printf("\nInput a number -> ");
            scanf("%d", &number);
            i = 0;
            while (i<=15){
               if (i %4==3){  
                  printf("%d ", (number & (1<<i++)) > 0);
                  continue;
               }
               printf("%d", (number & (1<<i++)) > 0);
            }
            break;
         case 3:
            run = 0;
            break;
         default:
            printf("\nInvalid option!!\n");
            break;
      }
   }
   


   return 0;
}