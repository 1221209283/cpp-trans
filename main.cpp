#include <iostream>
//#include <string>
#include <limits>

/* OS specified call */
#if _WIN32
//#include <window.h>
#warning "Complied in Window"
#elif (__linux__||__unix__)
//#include <unistd.h>
//#include <stdio_ext.h>
#warning "Complied in Linux / Unix"
#else
#warning "Complied in non-Unix system"
#endif

//#error "Comment if you reviewed the code!! \n I dont want faulty code!!"

using namespace std;

constexpr auto MAX_STREAM_SIZE = std::numeric_limits<std::streamsize>::max();

class customer {
  bool legacy_sex = false;
  unsigned short age = 0;
  string name, phone;
  public:

  void set_name() {
    getline(cin,name);
  }

  void set_age() {
    cin >> age;
    cin.ignore(MAX_STREAM_SIZE,'\n');
  }

  void set_phone() {
    getline(cin,phone);
  }

  int set_sex() {
    unsigned short good = 0, bad = 0;
    string input;
    cout << "Insert Sex [F/m] : ";
    getline(cin,input);
    for(const char& i:input){
      switch(i) {
        case '\n':
        case ' ':
        case '\t':
        case '\r':
        case '\f':
        case '\v':
          break;
        case '0':
        case 'F':
        case 'f':
          good++;
          break;
        case '1':
        case 'M':
        case 'm':
          bad++;
          break;
        default:
          cerr << "Error Input!!" << endl;
          return -1;
      }
    }
    if((good + bad) > 1) {
      cerr << "Error Sex!!" << endl;
      return -1;
    }
    if((good + bad) == 0) good++;
    legacy_sex = (good == 0 && bad == 1);
    return 0;
  }

  void input_field() {
    cout << "Name : ";
    set_name();
    cout << "Age  : ";
    set_age();
    set_sex();
    cout << "Phone: ";
    set_phone();
  }
};

class vehicle {
  string name, from_destination , to_destination;
  unsigned int price = 0;
  public:
  
  
};

void display(const unsigned short& person_num,  const customer* const arry_cust) {
  
}

int main(int argc, char* argv[]){
  unsigned short person_num = 0; //danger out of range!!
  char vehicle_choose = '\0';

  cout << "Enter number of person: ";
  cin >> person_num;

  customer* arry_cust = new customer[person_num];

  cout << "Enter a trip-code: ";
  cin >> vehicle_choose;
  cin.ignore(MAX_STREAM_SIZE,'\n');

  for(unsigned int i = 0;i < person_num;i++){
    arry_cust[i].input_field();
  }
  return 0;
}
