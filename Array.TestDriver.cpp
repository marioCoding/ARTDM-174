#include <iostream>
#include <cassert>
using namespace std;

class Array {
  private: 
    int values[100]; // initialize to 0
    int dummy;
  public:
    Array();
    int capacity() const;
    int operator[ ] (int) const; // getter version
    int& operator [ ] (int); // setter version
};

int main() {
  Array a;
  cout << "Programmer: Mario Salinas\n";
  cout << "Programmer's ID: 1517899\n";
  cout << "File: " << "/Users/mario/VS-Code/COMSC-210/Assignment2" << endl;

  // Array::capacity
  cout << "\nTesting Array::capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << a.capacity( ) << endl;
  assert(100 == a.capacity( ));

   // Array::Array
  cout << "\nTesting Array::Array\n";
  for (int i = 0; i < a.capacity( ); i++)
    assert(a[i] == 0);

  // Array::operator[ ] setter
  cout << "\nTesting the Array::operator[ ] setter\n";
  a[26] = 12356;
  a[48] = 7654321;
  cout << "\nTesting Array::operator[ ] setter\n";
  cout << "EXPECTED: 12356 for a[26]\n";
  cout << "ACTUAL: " << a[26] << endl;
  assert(12356 == a[26]);
  cout << "EXPECTED: 7654321 for a[48]\n";
  cout << "ACTUAL: " << a[48] << endl;
  assert(7654321 == a[48]);
  a[-1000] = 123123;
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(12356 == a[26]);
  assert(7654321 == a[48]);
  assert(123123 == a[-6]); // any out-of-range uses dummy
  assert(123123 == a[100]); // checks upper end of range
  assert(123123 != a[90]); // checks upper end of range
  assert(123123 != a[0]); // checks lower end of range

  // Array::operator[ ] getter
  cout << "\nTesting the Array::operator[ ] getter\n";
  const Array b = a;
  for (int i = 0; i < 10; i++)
    assert(a[i] == b[i]);

  cout << "\nConst object test\n";
  const Array c; 
  assert(c.capacity( ) == 100); 
  assert(c[0] == c[0]); 
  assert(c[-1] == c[-1]); 

  return 0;
}

Array::Array() {
  dummy = 0;
  for (int i = 0; i < 100; i++) {
    values[i] = 0;
  }
}

int Array::capacity() const {
  return 100;
}

int Array::operator[] (int index) const {
  if (index < 0 || index >= 100)
    return dummy;
  return values[index];
} 

int& Array::operator[] (int index) {
  if (index < 0 || index >= 100)
    return dummy;
  return values[index];
}