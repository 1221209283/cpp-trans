#include <cstdio>
#include <iostream>
//#include <string>
#include <limits>
#include <string>
//lol
/* OS specified call */
#if _WIN32
//#include <window.h>
#warning "Complied in Window"
#elif (__linux__||__unix__)
//#include <unistd.h>
//#include <st
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
    bool error_input = false;
    string input;
    do{
      error_input = false;
      input.erase();
      cout << "Input Age : ";
      getline(cin,input);
      if(input == ""){
        error_input = true;
        continue;
      }
      for(const char& i:input){
        if((int)i < 33){
          continue;
        }else if((int)i < 58 && (int)i > 47){
          continue;
        }else{
          cerr << "\e[31mError Age!!\e[0m" << endl;
          error_input = true;
          break;
        }
      }
    }while(error_input);
    age = stoi(input);
  }

  void set_phone() {
    getline(cin,phone);
  }

  int set_sex() {
    unsigned short good = 0, bad = 0;
    bool input_error = false;
    string input;
    do{
      good = 0;
      bad = 0;
      input_error = false;
      cout << "Insert Sex [f/m] : ";
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
            cerr << "\e[31mError Input!!\e[0m" << endl;
            input_error = true;
        }
        if(input_error) break;
      }

      if(input_error) continue;

      if((good+bad) == 1);
      else {
        cerr << "\e[31mError Sex!!\e[0m" << endl; 
        input_error = true;
      }

    }while(input_error);
    legacy_sex = (good == 0 && bad == 1);
    return 0;
  }

  void input_field() {
    cout << "Name : ";
    set_name();
    set_age();
    set_sex();
    cout << "Phone: ";
    set_phone();
  }
  
  void display() const {
    cout
  << "Name :" << name << '\n'
  << "Age  :" << age  << '\n'
  << "Sex  :" << ((legacy_sex == 0)? "Female" : "Male") << '\n'
  << "Phone:" << phone << endl;
  }
};

class vehicle {
  string name, from_destination , to_destination;
  unsigned int price = 0;
  public:
  
  
};

void display(const unsigned short& person_num, const customer* const arry_cust) {

}

//function covert num

template <class T>
void int_input(T& a,string&& out = ""){
  bool error_input = false, no_symbol = false;
  string input;
  do{
    error_input = false;
    no_symbol = false;
    input.erase();
    cout << out;
    getline(cin,input);
    if(input == ""){
      error_input = true;
      continue;
    }
    for(const char& i:input){
      if((int)i < 33){
        continue;
      }else if((int)i < 58){
        if((int)i > 47){
          no_symbol = true;
          continue;
        }else if((i == '+' || i == '-') && !no_symbol){
          no_symbol = true;
          continue;
        }else{
          cerr << "\e[31mError Int!!\e[0m" << endl;    
          error_input = true;
          break;
        }
      }else{
        cerr << "\e[31mError Input!!\e[0m" << endl;
        error_input = true;
        break;
      }
    }
  }while(error_input);
  a = (T)stoi(input);
}

template <class T>
void unsign_input(T& a,string&& out = ""){
  bool error_input = false;
  string input;
  do{
    error_input = false;
    input.erase();
    cout << out;
    getline(cin,input);
    if(input == ""){
      error_input = true;
      continue;
    }
    for(const char& i:input){
      if((int)i < 33){
        continue;
      }else if((int)i < 58 && (int)i > 47){
        continue;
      }else{
        cerr << "\e[31mError Input!!\e[0m" << endl;
        error_input = true;
        break;
      }
    }
  }while(error_input);
  a = (T)stoull(input);
}

template <class T>
void float_input(T& a,string&& out = ""){
  bool error_input = false, no_symbol = false, dot_format = false, lock_dot = false;
  string input;
  do{
    error_input = false;
    no_symbol = false;
    dot_format = false;
    lock_dot = false;
    input.erase();
    cout << out;
    getline(cin,input);
    if(input == ""){
      error_input = true;
      continue;
    }
    for(const char& i:input){
      if((int)i < 33){
        continue;
      }else if((int)i < 58){
        if((int)i > 47) {
          no_symbol = true;
          dot_format = true;
          continue;
        }else if((i == '+' || i == '-') && !no_symbol){
          no_symbol = true;
          continue;
        }else if(i == '.' && dot_format && !lock_dot){
          lock_dot = true;
          continue;
        }else{
          cerr << "\e[31mError Input!!\e[0m" << endl;    
          error_input = true;
          break;
        }
      }else{
        cerr << "\e[31mError Input!!\e[0m" << endl;
        error_input = true;
        break;
      }
    }
  }while(error_input);
  a = (T)stod(input);
}

// end num convert

int main(int argc, char* argv[]){
  unsigned short person_num = 0; //danger out of range!!
  char vehicle_choose = '\0';

  unsign_input(person_num,"Enter number of person: ");

  customer* arry_cust = new customer[person_num];

  cout << "Enter a trip-code: ";
  cin >> vehicle_choose;
  cin.ignore(MAX_STREAM_SIZE,'\n');

  for(unsigned int i = 0;i < person_num;i++){
    //cout << "\e[1J\e[;H";
    cout<< "person #" << i+1 <<endl;
    arry_cust[i].input_field();
  }
  cout << endl;
  for(unsigned int i = 0;i < person_num;i++){
    cout << "Display: person #" << i+1 << endl;
    arry_cust[i].display();
  }
  return 0;
}
