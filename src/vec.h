#ifndef VECTOR
#define VECTOR

#include <stdio.h>

typedef struct {
  void *array;
  size_t size;
  size_t capacity;
} VoidVec;
VoidVec createVoidVec(size_t initCap);

void voidVecPushBack(void *voidVec, void *el, size_t type_size);
void voidVecPushMany(void *voidVec, void *ptr, size_t count, size_t type_size);

// -----

typedef struct {
  char *array;
  size_t size;
  size_t capacity;
} CharVec;

CharVec createCharVec(size_t initCap);

void charVecPushBack(CharVec *charVec, char ch);
void charVecPushMany(CharVec *charVec, char *ptr, size_t count);

// -----

typedef struct {
  int *array;
  size_t size;
  size_t capacity;
} IntVec;

IntVec createIntVec(size_t initCap);

void intVecPushBack(IntVec *intVec, int i);
void intVecPushMany(IntVec *intVec, int *ptr, size_t count);

#endif // !VECTOR
