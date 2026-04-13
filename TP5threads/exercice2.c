#include <stdio.h>
#include <pthread.h>

typedef struct {
   double number1;
   double number2;
} NumberArgs;

void *Somme(void *arg) {
   NumberArgs *a = (NumberArgs *)arg;
   double calc = (a->number1 + a->number2);
   printf("Somme: %lf\n", calc);
   return NULL;
}

void *Soustraction(void *arg) {
  NumberArgs *a = (NumberArgs *)arg;
  double calc = (a->number1 - a->number2);
  printf("Soustraction: %lf\n", calc);
  return NULL;
}

void *Division(void *arg) {
   NumberArgs *a = (NumberArgs *) arg;
   double calc = (a->number1 / a->number2);
   printf("Division: %lf\n", calc);
   return NULL;
}

void *Produit(void *arg) {
    NumberArgs *a = (NumberArgs *)arg;
    if (a->number2 == 0.0) {
        printf("Produit: %lf\n", 1.0);
    }
  double calc = (a->number1 * a->number2);

  printf("Produit: %lf\n", calc);
  return NULL;
}


int main() {
  NumberArgs args;

  printf("1er nombre\n");
  scanf("%lf", &args.number1);

  printf("2ème nombre\n");
  scanf("%lf", &args.number2);


 pthread_t thread[4];

 pthread_create(&thread[0], NULL, Somme, &args);
 pthread_create(&thread[1], NULL, Soustraction, &args);
 pthread_create(&thread[2], NULL, Division, &args);
 pthread_create(&thread[3], NULL, Produit, &args);

 pthread_join(thread[0], NULL);
 pthread_join(thread[1], NULL);
 pthread_join(thread[2], NULL);
 pthread_join(thread[3], NULL);

  return 0;
}