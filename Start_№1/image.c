#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Image
 {
  int mx, my;
  int *mg;
 } Image;

void create(Image *im, int mx, int my)
 {
  im -> mx = mx;
  im -> my = my;
  im -> mg = malloc(mx*my*sizeof(int));
 } 

void show(Image *im)
 {
  int i, j;
   for (j = 0; j < im->my; j++)  // потом спускаемся по столбцу 
    {
     for (i = 0; i < im->mx; i++) // сначала идем по строчке 
      {
       printf("%c", im -> mg[i + j*(im->mx)]); // заполнили массив символами
      } 
     printf("\n"); 
    }
 }

void set(Image *im, int x, int y, int colour)
 {
  if(x < im->mx && y < im->my && x >= 0 && y >= 0) // если не вышли за границы изображения  
	  im -> mg[x + y*(im->mx)] = colour; // заливаем цветом (символ)
 }

int get (Image *im, int x, int y)
 {
 	if(x < im->mx && y < im->my && x >= 0 && y >= 0)	
		return im -> mg[x + y*(im->mx)];
 }

int load(char *filename, Image *im)
 {
  int i, j;
  char mas;

  FILE *file;
  
  file = fopen(filename, "r+"); // открыть файл для чтения и записи (файл должен существовать);
   if (file == NULL)
    {
     printf ("Файл не найден\n");
     return 0;
    }
   
   fscanf(file,"%d %d", &i, &j);
   printf("Размер файла %d х %d\n", i, j);

   create (im, i, j);
   
    for (j = 0; j < im->my; j++)  // потом спускаемся по столбцу 
     {
      for (i = 0; i < im->mx; i++) // сначала идем по строчке 
       {
        mas = fgetc(file); // сохраняем данные в массив
        im -> mg[i + j*(im->mx)] = mas; // передаем массив в структуру
       }
      
      if(mas != '\n')
       {
        while(mas = fgetc(file) != '\n')
         {
          if(feof(file)!= 0) 
          break;
         }
       }
     }
  fclose(file);
 }

int main(int argc, char *mas[])
 {
  Image test; 
  
  load("primer.pht", &test); 
  show(&test); 
  
  set(&test, 76, 11, '*');
  show(&test);
  
  printf("%c\n",get(&test, 76, 11));
  
  free(test.mg);
  return 0;
 }
