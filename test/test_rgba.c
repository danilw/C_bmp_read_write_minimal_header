

// gcc test_rgba.c -o bmp_rw_test


#include "../C_bmp_rw_header.h"

// rgba_gimp.bmp - image from gimp
// rgba_gimp_save.bmp - self image after save load again
int main() {
  
  {
    uint8_t *rgba = NULL;
    int width, height;
    if(read_bmp("rgba_gimp.bmp", &width, &height, &rgba)){
      printf("loaded img width height %d %d\n", width, height);
      
      write_bmp("rgba_gimp_save.bmp", width, height, rgba);
      free(rgba);
    }
  }
  
  {
    uint8_t *rgba = NULL;
    int width, height;
    if(read_bmp("rgba_gimp_save.bmp", &width, &height, &rgba)){
      printf("loaded img width height %d %d\n", width, height);
      
      write_bmp("rgba_self_save.bmp", width, height, rgba);
      free(rgba);
    }
  }
  
  return 0;
}

