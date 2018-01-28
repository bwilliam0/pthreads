#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

pthread_mutex_t mutex;

enum response{Rock = 0, Paper = 1, Scissors = 2};

int printInt(int num) {
    int err = pthread_mutex_lock(&mutex);
    if (err)
        return 0;
    else {
        printf("%d", num);
        return 1;
        pthread_mutex_unlock(&mutex);
    }

}

void *execute (void* playerNum) {

    enum response selection = rand() % 3;
    printInt(selection);

}

int main() {
    srand((unsigned int)time(NULL));
    printf("Hello, World!\n");
    return 0;
}

