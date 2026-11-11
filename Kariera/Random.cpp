#include "Random.h"
#include <time.h>	// rand()
#include <stdlib.h> // rand()

//srand(time(NULL));//predat srand() time bez ulozeni do promenne = NULL
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}