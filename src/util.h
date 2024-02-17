#include "src/vec.h"

enum Alignment {
  Left,
  Center,
  Right,
};

typedef struct {
  enum Alignment alignment;
  size_t count;
  CharVec items;
  IntVec lengths;
} Item;

Item create_item(enum Alignment alignment, int initCap) {
  Item item;
  item.count = 0;
  item.alignment = alignment;
  item.items = createCharVec(initCap);
  item.lengths = createIntVec(initCap);
  return item;
}

struct Table {
  Item headers;
  Item data;
};
