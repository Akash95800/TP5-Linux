
#include <stdio.h>
#include <pthread.h>


//Question 1 Il permet d’exécuter du code dans un thread différent du thread principal. On crée d’abord ce nouveau thread, puis on le rejoint. Ensuite, grâce au pointeur `fonction_thread`, on peut afficher un texte depuis la coroutine associée à ce thread.


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


 pthread_t sommeThread, soustractionThread, divisionThread, produitThread;

 pthread_create(&sommeThread, NULL, Somme, &args);
 pthread_create(&soustractionThread, NULL, Soustraction, &args);
 pthread_create(&divisionThread, NULL, Division, &args);
 pthread_create(&produitThread, NULL, Produit, &args);

 pthread_join(sommeThread, NULL);
 pthread_join(soustractionThread, NULL);
 pthread_join(divisionThread, NULL);
 pthread_join(produitThread, NULL);

  return 0;
}
