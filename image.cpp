#include <iostream> 
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Image
 {
  int mx, my;
  int *mas;

 public:

Image ()
   {
 	mx = 0;
 	my = 0;
 	mas = (int*) malloc(sizeof(int) * mx * my);
   }

~Image ()
 	{
 	 free (mas);
 	}

Image (int tmx, int tmy)
   {
 	  mx = tmx;
  	my = tmy;
    mas = (int*) malloc(sizeof(int) * mx * my);
   }

void set (int x, int y, int colour)
   {
   	if (x < mx && y < my && x >= 0 && y >= 0)
 	 mas[x + y*mx] = colour;
   }

void show ()
   {
   	for (int j = 0; j < my; j++)
   	 {
   	   for (int i = 0; i < mx; i++)
	     {
	    	cout << mas[i + j*mx];
	     }
	    cout << endl;
	    }
	  cout << endl;
   }
 	
int get (int x, int y)
 {
 	if (x < mx && y < my && x >= 0 && y >= 0)
 	 return mas[x + y*mx];
 }

int getMx ()
   {
   	return mx;
   }

int getMy ()
   {
   	return my;
   }
 
 };

int init (Image *im, int x, int y, int colour)
 {
  for (int j = 0; j < y; j++)
  		{
  			for (int i = 0; i < x; i++)  				
  	        {
  	        	if (j == i)
  	        	im -> set(j, i, colour);
  	    		else im -> set(j, i, colour + 2);}
        }
        im -> show();
 }

int main ()
 {
  Image a;
  cout << "Image a" << endl;
  a.show();
  cout << "x = " << a.getMx() << endl; 
  cout << "y = " << a.getMy() << endl;  
  cout << "Значение в точке (0,0) - ";
  cout << a.get(0, 0) << endl;
  a.show();

  Image b(5, 10);
  cout << "Image b" << endl;
  b.show();
  cout << "x = " << b.getMx() << endl; 
  cout << "y = " << b.getMy() << endl; 
  cout << "Значение в точке (0,0) - ";
  cout << b.get(0, 0) << endl;
  init (&b, 5, 10, 5);

  Image *arr = new Image[15];
  cout << "Image arr" << endl;
  for (int count = 0; count < 15; count++)
    arr[count].show();
  cout << "x = " << arr[0].getMx() << endl; 
  cout << "y = " << arr[0].getMy() << endl;  
  cout << "Значение в точке (0,0) - ";
  cout << arr[0].get(0, 0) << endl;
  delete[] arr;
 }