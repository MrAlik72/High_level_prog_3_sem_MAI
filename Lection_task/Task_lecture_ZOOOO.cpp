#include <iostream>
#include <cstdlib>
#define SIZE_ZOO 18

using namespace std;

class Animal
 {
 public:
 	virtual void speak ()
 	 {
 	  cout << "....." << endl;
 	 }
 };

 class Wolf : public Animal
  {
   public:
      virtual void speak ()
 	{
 		cout << "Рычууу" << endl;
 	}
  };

 class Zoo
 {
 	Animal **anim;
 	int count;

 	public:
 		Zoo (int size = SIZE_ZOO)
 		 {
 		  anim = new Animal*[size];
 		  count = 0;
 		 }

 		~Zoo ()
 		 {
 		  for (int i = 0; i < count; i++) delete anim[i];
 		 }

 		void speak_all ()
 		 {
 		  for (int i = 0; i < count; i++) anim[i] -> speak();
 		 }

 		void kletka (Animal *an)
 		 {
 		  if (anim != NULL && count < SIZE_ZOO) anim[count++] = an;
 		 }
 };

int main(int argc, char *argv[])
 {
  Animal *an = new Wolf;
  Zoo z(SIZE_ZOO);
   for (int i = 1; i < SIZE_ZOO; i++)
    {
 	 an = new Wolf;
 	 z.kletka(an);
 	}
  z.speak_all();
  return 0;
 }