#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class String
 {
  char *mas;

 public:

String (char *str)
   {
	 int lenth = 0;
      for (int i = 0; str[i] != '\0'; i++)
		lenth++;
   	 mas = (char*) malloc(sizeof(char) * (lenth + 1));
      for (int i = 0; str[i] != '\0'; i++)
	    mas[i] = str[i];
	 mas[lenth] = 0;
   };
  
~String ()
   {
	free(mas);
   };

int lenth ()
   {
    int lenth = 0;
    for (int i = 0; mas[i] != '\0'; i++)
     lenth++;
    cout << "Длина строки = ";
    cout << lenth << endl;
    return lenth;
   };

void show ()
   {
	for (int i = 0; mas[i] != '\0'; i++)
	  cout << mas[i];
	cout << endl;
   }
 };

int compare (String *str1, String *str2)
 {
  if (str1 -> lenth() != str2 -> lenth())
   {
   	cout << "Строки разной длины" << endl;
   	return 1;
   }
  else 
  	{
     cout << "Строки одинаковой длины" << endl;
  	 return 0;
  	}
 }

int main ()
 {
  String s1("C++");
  String s2("MAI");
  String s3("LK2 19.09.18");
  s1.show();
  s2.show();
  s3.show();
  compare (&s1, &s2);
  compare (&s1, &s3);
 }
