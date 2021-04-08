#include "Simple_window.h"
#include "Graph.h"

struct Person {
  Person(): name1(), name2(),age1(0) {};
  Person(string n, string n1, int a) :name1(n),name2(), age1(a) {
    const string nr = ";:'[]*&^%$#@!";
    for(int i = 0; i < n.size(); ++i)
      for(int j = 0; j < nr.size(); ++j)
        if(n[i] == nr[j]) error("Rossz karakter: ",string(1,n[i]));
    for(int i = 0; i < n1.size(); ++i)
      for(int j = 0; j < nr.size(); ++j)
        if(n1[i] == nr[j]) error("Rossz karakter: ",string(1,n1[i]));
    if(a < 0 || a > 150) error("Rossz eletkor: ",a);
  }
  string name() const {return name1;}
  string name_2() const {return name2;}
  int age() const {return age1;}

private:
  string name1;
  string name2;
  int age1;
};

istream& operator>>(istream& is,Person& p)
{
  string name;
  string name_2;
  int age;
  is >> name >> name_2 >> age;
  if (!is) return is;
  p = Person(name,name_2,age);
  return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
  return os << "Name: " << p.name() << " " << p.name_2() <<
    "Age: " << p.age();
}

int main(){

  /*
  Person p;
  p.name = "Goofy";
  p.age = 63;
  */
  //Person p;
  //p.name() = "";
  //p.age() = 0;

  vector<Person> person;
  Person p;
  while(cin >> p)
    person.push_back(p);
  for (int i = 0; i < person.size(); ++i)
    cout << person[i] << endl;

  return 0;
}
