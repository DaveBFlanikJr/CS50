#include <cs50.h>
#include <stdio.h>


int main(void)
{
  int height, r, s, c;
  do
  {
    height = get_int("please pick a number between 1-8: ");
  }
  while(height < 1 || height > 8);
  for(r = 0; r < height; r++) {
    for(s = 0; s < height - r -1 ; s++)
    {
      printf(" ");
    }
    for(c = 0; c <= r; c++) {
      printf("#");
    }
    printf("\n");
  }
}
