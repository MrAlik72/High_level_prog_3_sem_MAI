#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Item
{		
 string wrd;

 Item *next;		
 Item (string twrd) 
    { 
	 next = NULL;	
	 wrd = twrd;     
	};
};

class List 
{ 
 Item *head; 
 Item *np;

 public: 

List () 
{
 head = NULL; 
}

~List () 
{
 if (head != NULL) 
  { 
   while (head -> next != NULL) 
       { 
		Item *tmp; 
		
		tmp = head -> next; 
		delete(head); 
		head = tmp; 
	   }
  }
}

void push (Item *p) 
{
 /*if (p != NULL) 
  {
   p -> next = head; 
   head = p; 
  }*/

  Item *tmp;
  char c = 1;

  string tmp_s;
   for(int i = 0; i < p.wrd.size() + 1; i++)
    {
	 c = p.wrd[i];      
	  if (c == '\0'|| c == ' ')
	   {
		tmp = new Item(tmp_s);	
		 if (head == NULL)
		  { 
		   head = tmp;
		   np = tmp;	
		  }
		 else 
		  {
		   np->next = tmp;
		   np = tmp;
		  }
		tmp_s.clear();		
	   }
	  else
	   {
		tmp_s += c;
	   }
	}
}
	
int find (string key)
{
 Item *tmp = head;
 int counter = 0;

  for (; tmp != NULL; tmp = tmp -> next)
	{
	 counter++;
	  if (tmp -> wrd == key) return counter;
	}
 return -1;
}
	
int count (string key)
{
 Item *tmp = head;
 int cnt = 0;
		
  while (tmp != NULL)
	  {
	   if (tmp -> wrd == key) cnt++;
	   tmp = tmp -> next;
	  }
 return cnt;
}
	
void show ()
{
 if (head != NULL)
  {
   Item *tmp = head;
   
   while (tmp != NULL)
	   {
		cout << tmp -> wrd << endl;
		tmp = tmp -> next;
	   }
  }
 else cout << "Empty list" << endl;
}

};

int main()
{
 List a;
 Item *p1 = new Item("MAI");
 Item *p2 = new Item("MAI");
 Item *p3 = new Item("MAI");
 Item *p4 = new Item("MAI");
 Item *v = new Item("С++");
 Item *b = new Item("С#");
 a.push(p1);
 a.push(p2);
 a.push(v);
 a.push(p3);
 a.push(p4);
 a.push(b);
 a.show();
 cout << endl;
 cout << "Слово MAI первый раз встретилось в строчке " << a.find("MAI") << endl;
 cout << "Всего слово MAI встечается " << a.count("MAI") << " раз(а)" << endl;
 cout << endl;
 cout << "Слово C++ первый раз встретилось в строчке " << a.find("С++") << endl;
 cout << "Всего слово C++ встечается " << a.count("С++") << " раз(а)" << endl;
 cout << endl;
 cout << "Слово С# первый раз встретилось в строчке " << a.find("С#") << endl;
 cout << "Всего слово С# встечается " << a.count("С#") << " раз(а)" << endl;
 cout << endl;
 cout << "Слово Test первый раз встретилось в строчке " << a.find("Test") << endl;
 cout << "Всего слово Test встечается " << a.count("Test") << " раз(а)" << endl;

Item *p =  new Item("Test do do do me bro now do it bb");
a.push(p);
a.show();
}