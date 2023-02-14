#include <iostream>
#include <string>
using namespace std;

#include <cstdlib> // atoi

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
  cout << "Programmer: Mario Salinas\n";
  cout << "Programmer's ID: 1517899\n";
  cout << "File: " << "/Users/mario/VS-Code/COMSC-210/Assignment2" << endl;
  
  Array a; // store the value
  Array b; //keep tracking value index 
  string buf1, buf2;

  // Take user input and store corresponding input into Array a and Array b
  cout << "Input an index and a value [Q to quit]: ";
  cin >> buf1; 
  while (buf1 != "Q" && buf1 != "q") {
    int index = atoi(buf1.c_str());
    cin >> buf2;
    int value = atoi(buf2.c_str());
    a[index] = value;  // assign values
    b[index] = 1;      // keep track of the used index // WHAT DOES THIS DO 
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buf1; 
  } 

  // Count how many values are stored in array b
  int count = 0;
  for (int i=0; i<100; i++) {
    if (b[i] != 0)
      count++;
  }

  cout << "You stored this many values: " << count << endl;
  cout << "The index-value pairs are: " << endl;
  // Output the index-value pairs
  for (int i = 0; i < 100; i++) {
    if(a[i] != 0 && b[i] != 0)
      cout << b[i] << " => " << a[i] << endl;
  }

  // Take user input for index and search array for the given index
  string buf3;
  cout << "Input an index for me to look up [Q to quit]: ";
  cin >> buf3;
  while (buf3 != "Q" && buf3 != "q") {
    int indexSearcher = atoi(buf3.c_str());
    // Traverse array b to find the value stored at indexSearcher
    for (int i=0; i<100; i++) {
      if (b[i] == indexSearcher) {
        cout << "Found it -- the value stored at " << indexSearcher << " is " << a[i] << endl;
      } else if (b[i] != indexSearcher)
        cout << "I didn't find it" << endl;
    }
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> buf3;
  }

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
  if (index < 0 || index >= 10)
    return dummy;
  return values[index];
} 

int& Array::operator[] (int index) {
  if (index < 0 || index >= 10)
    return dummy;
  return values[index];
}