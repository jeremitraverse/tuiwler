#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max) {
    srand(time(NULL));

    return rand() % (max - min + 1) + min;
}