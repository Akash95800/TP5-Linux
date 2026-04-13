#include <stdio.h>
#include <pthread.h>

char c = 0;

void *lecteur(void *arg) {
    do {
        c = getchar();
    } while (c != 'E');
    return NULL;
}

void *afficheur(void *arg) {
    char last = 0;
    do {
        if (c != last) {
            last = c;
            printf("Caractère : %c\n", c);
        }
    } while (c != 'E');
    return NULL;
}

int main() {
    pthread_t t[2];

    pthread_create(&t[0], NULL, lecteur, NULL);
    pthread_create(&t[1], NULL, afficheur, NULL);

    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    return 0;
}