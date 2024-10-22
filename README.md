# C bmp read write minimal header

BMP format https://en.wikipedia.org/wiki/BMP_file_format

Parts of this code based on https://github.com/vallentin/LoadBMP

BPM rgba image read write in C minimal single header.

# Only RGBA bpm format supported - tested with GIMP 2.10.38

### Example usage:

```c

// gcc test_rgba.c -o bmp_rw_test

#include "C_bmp_rw_header.h"

// rgba_gimp.bmp - image from gimp
int main() {
  uint8_t *rgba = NULL;
  int width, height;
  if(read_bmp("rgba_gimp.bmp", &width, &height, &rgba)){
    printf("loaded img width height %d %d\n", width, height);
    write_bmp("rgba_gimp_save.bmp", width, height, rgba);
    free(rgba);
  }
  return 0;
}

```

### Pixel idexing:

```rgba[(x+y*width)*4 + <0/1/2/3>] where <0/1/2/3> is color and x,y is pixel```
