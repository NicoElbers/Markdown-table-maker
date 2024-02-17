#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "util.h"
#include "vec.h"

#define BUFFER_SIZE 1024

char *print_buffer(char *buffer, size_t count);
char *print_full_char_vec(CharVec cv);

void print_table(Item headers, Item data);
void print_header(Item headers);

void print_seperator(int *buffer, size_t count);

Item get_headers();
Item get_data(Item headers);

// TODO: Get the alignment right for the data columns right / Grow header space
// when data is larger than header
// TODO: Pass around a table struct instead of Items
int main(int argc, char *argv[]) {
  Item headers = get_headers();
  Item data = get_data(headers);

  print_table(headers, data);

  return 0;
}

Item get_headers() {
  printf("Create headers below:\n");

  char buffer[BUFFER_SIZE] = {0};

  // TODO: Loop this if an invalid value is given
  enum Alignment al = 0;
  printf("What alignment do you want? (L)eft, (R)ight, (C)enter\n > ");
  fgets(buffer, BUFFER_SIZE, stdin);
  char ch = *buffer;
  char ch_lower = tolower(ch);
  if (ch_lower == 'l') {
    al = Left;
  } else if (ch_lower == 'r') {
    al = Right;
  } else if (ch_lower == 'c') {
    al = Center;
  }

  printf("Type q to quit\n");
  Item headers = create_item(al, 10);

  // TODO: Look into the spec again to see how I should handle alignment
  // https://github.github.com/gfm/#tables-extension-
  int quit = 0;
  while (!quit) {
    printf("Header %zu\n > ", headers.count);

    fgets(buffer, BUFFER_SIZE, stdin);

    int str_len = strlen(buffer);
    buffer[str_len - 1] = '\0';

    if (*buffer == 'q' && str_len <= 2) {
      quit = 1;
    } else {
      headers.count++;
      charVecPushMany(&headers.items, buffer, str_len);
      intVecPushBack(&headers.lengths, str_len - 1);
      print_header(headers);
    }
  }
  return headers;
}

Item get_data(Item headers) {
  Item data = create_item(Left, 10);

  char buffer[BUFFER_SIZE] = {0};

  size_t row = 1;
  int quit = 0;
  while (!quit) {
    for (size_t i = 0; i < headers.count; i++) {
      printf("Row %zu, column %zu\n > ", row, i);

      fgets(buffer, BUFFER_SIZE, stdin);

      int str_len = strlen(buffer);

      // NOTE: replace the newline with a null byte
      buffer[str_len - 1] = '\0';

      if (*buffer == 'q' && str_len <= 2) {
        quit = 1;
        break;
      } else {
        data.count++;
        charVecPushMany(&data.items, buffer, str_len);
        intVecPushBack(&data.lengths, str_len);
        print_table(headers, data);
      }
    }
  }

  return data;
}

// TODO: Implement this less dumb
char *print_buffer(char *buffer, size_t count) {
  if (count == 0)
    return NULL;

  char *ptr_buffer[count];

  int counter = 0;
  char *buf_ptr = buffer;
  char *return_ptr;
  while (counter < count) {
    ptr_buffer[counter] = buf_ptr;

    while (*buf_ptr != 0) {
      buf_ptr++;
    }
    buf_ptr++;
    return_ptr = buf_ptr;

    counter++;
  }

  for (int i = 0; i < count; i++) {
    printf("| %s ", ptr_buffer[i]);
  }
  printf("|\n");

  return return_ptr;
}

void print_seperator(int *buffer, size_t count) {
  if (count == 0)
    return;

  printf("| ");
  for (int i = 0; i < count; i++) {
    int len = *buffer;

    for (int j = 0; j < len; j++) {
      printf("-");
    }
    printf(" | ");

    buffer++;
  }

  printf("\n");
}

void print_header(Item headers) {
  print_buffer(headers.items.array, headers.count);
  print_seperator(headers.lengths.array, headers.count);
}

void print_table(Item headers, Item data) {
  print_header(headers);

  int full_lines = data.count / headers.count;
  char *data_ptr = data.items.array;

  for (int i = 0; i < full_lines; i++) {
    data_ptr = print_buffer(data_ptr, headers.count);
  }

  int remaining_items = data.count % headers.count;
  print_buffer(data_ptr, remaining_items);
}
