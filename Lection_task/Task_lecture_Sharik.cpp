#include<iostream>
#include<string>
using namespace std;
void drawRectangle(int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      cout << "*";
    cout << endl;
  }
  cout << endl;
}

void drawPyramid(int n){
  for (int i = 0; i < n; i+=2)
    {
        for (int j = 1; j*2 < n - i; j++)
            cout << ' ';
        for (int j = n - i; j <= n; j++)
            cout << '*';
        cout << endl << endl;
    }
  cout << endl;
}
int variant1(int numberInList, int numberOfVariants) {
	return numberInList % numberOfVariants;
}

int variant2(string name, int numberOfVariants) {
	int pos = name.find(' ') + 1;
  return (int)name[pos] % numberOfVariants; 
}

int variant3(string name, int numberOfVariants) {
	return (int)name[0] % numberOfVariants;
}

int	main() {
  cout << "Task 1" << endl;
	cout << variant1(7, 4) << endl;
	cout << variant2("Nabor bukv", 4) << endl;
	cout << variant3("Nabor bukv", 4) << endl;

  cout << "Task 2" << endl;
  drawRectangle(5, 10);
  drawPyramid(5);
}