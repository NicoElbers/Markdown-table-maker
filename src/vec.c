#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vec.h"

// TODO: Implement void vec
// TODO: Create getters and deletion
// TODO: Consider implementing all vecs using void vec (slight overhead but
// easier more general implementation)

void charVecPushBack(CharVec *charVec, char ch) {
  if (charVec->size >= charVec->capacity) {
    charVec->capacity *= 2;
    charVec->array =
        (char *)realloc(charVec->array, charVec->capacity * sizeof(char));
  }

  if (charVec->array != NULL) {
    charVec->array[charVec->size++] = ch;
  } else {
    perror("Memory allocation failed");
    exit(-1);
  }
}

void charVecPushMany(CharVec *charVec, char *ptr, size_t count) {
  if (charVec->size + count > charVec->capacity) {
    charVec->capacity =
        (charVec->capacity < count) ? count * 2 : charVec->capacity * 2;
    charVec->array =
        (char *)realloc(charVec->array, charVec->capacity * sizeof(char));
  }

  if (charVec->array != NULL) {
    memcpy(charVec->array + charVec->size * sizeof(char), ptr,
           count * sizeof(char));

    charVec->size += count;
  } else {
    perror("Memory allocation failed");
    exit(-1);
  }
}

CharVec createCharVec(size_t initCap) {
  CharVec charVec;
  charVec.array = (char *)malloc(initCap * sizeof(char));
  charVec.size = 0;
  charVec.capacity = (charVec.array != NULL) ? initCap : 0;
  return charVec;
}

// ----

IntVec createIntVec(size_t initCap) {
  IntVec intVec;
  intVec.array = (int *)malloc(initCap * sizeof(int));
  intVec.size = 0;
  intVec.capacity = (intVec.array != NULL) ? initCap : 0;
  return intVec;
}

void intVecPushBack(IntVec *intVec, int i) {
  if (intVec->size >= intVec->capacity) {
    intVec->capacity *= 2;
    intVec->array =
        (int *)realloc(intVec->array, intVec->capacity * sizeof(int));
  }

  if (intVec->array != NULL) {
    intVec->array[intVec->size++] = i;
  } else {
    perror("IntVec allocation failed");
    exit(-1);
  }
}
void intVecPushMany(IntVec *intVec, int *ptr, size_t count) {
  if (intVec->size + count > intVec->capacity) {
    intVec->capacity =
        (intVec->capacity < count) ? count * 2 : intVec->capacity * 2;
    intVec->array =
        (int *)realloc(intVec->array, intVec->capacity * sizeof(int));
  }

  if (intVec->array != NULL) {
    memcpy(intVec->array + intVec->size * sizeof(int), ptr,
           count * sizeof(int));

    intVec->size += count;
  } else {
    perror("Memory allocation failed");
    exit(-1);
  }
}
