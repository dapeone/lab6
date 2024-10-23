#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Phone {
  string manufacturer;
  string number;
  int veight;
  int cost;
  
  Phone (string man, string num, int vei, int _cost): manufacturer(man), number(num), veight(vei), cost(_cost) {}
 
};

void read (string path, vector<Phone> phons) {
  fstream file (path);
  if (file.is_open()) {
    string manufacturer, number;
    int veight, cost;
    while (file >> manufacturer >> number >> veight >> cost) {
      phons.push_back(Phone{manufacturer, number, veight, cost});
    }
  }
}

void print (string manufacturer, vector<Phone> phons) {
  int quantity = 0;
  int summa = 0;
  int light = 0;
  
  for (Phone ph: phons) {
    if (ph.manufacturer == manufacturer) {
      cout << ph.number << " " << ph.veight << " грамм " << ph.cost << " рублей" << endl;
      quantity = quantity + 1;
      summa = summa + ph.cost;
      
      light = 0;
      if (light > ph.veight) {
        light = ph.veight;
      }
      if (ph.veight = light) {
        cout << "самый лёгкий телефон " << ph.number << " " << ph.veight << " " << ph.cost;
      }
    
    }
    
    cout << "средняя стоимость телефонов " << summa/quantity << " рублей" << endl;
    
    int big_cost = 0;
    int lou_cost = 0;
    if (big_cost < ph.cost) {
      big_cost = ph.cost;
    }
    if (lou_cost > ph.cost) {
      lou_cost = ph.cost;
    }  
    
  cout << "самый лёгкий телефон " << ph.number << " " << ph.veight << " " << ph.cost;
  cout << "самая маленькая цена " << lou_cost << endl;
  cout << "самая большая цена " << big_cost << endl;
  }
}
  

int main() {
  setlocale(LC_ALL, "russian");
  
  vector<Phone> phons;
  string path = "phone.txt";
  
  read (path, phons);
  
  string manufacturer;
  cout << "Введите название производителя: ";
  cin >> manufacturer;
  
  print (manufacturer, phons);
}