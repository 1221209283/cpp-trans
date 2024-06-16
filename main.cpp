#include <iostream>
#include <istream>
#include <sstream>
#include <limits>
#include <string>
#include <type_traits>

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

// Zoom 4

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
      input.clear();
      cout << "|  Age                                 : ";
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
          cerr << "\e[1;31mError Age!!\e[0m" << endl;
          error_input = true;
          break;
        }
      }
    }while(error_input);
    age = stoi(input);
  }

  void set_phone() {
    bool input_error = false;
    do{
      input_error = false;
      phone.clear();
      cout << "|  Phone                               : ";
      getline(cin,phone);
      if(phone.size() != 8) input_error = true;
      for(const char& i:phone){
        if((int)i < 33) continue;
      }
      if(input_error) cerr << "\e[1;31mError!! (Make sure enter 8-digits)\e[0m" << endl;
    }while(input_error);
  }

  int set_sex() {
    unsigned short good = 0, bad = 0;
    bool input_error = false;
    string input;
    do{
      good = 0;
      bad = 0;
      input_error = false;
      cout << "|  Gender << F = Female : M = Male >>  : ";
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
            cerr << "\e[1;31mError Input!!\e[0m" << endl;
            input_error = true;
        }
        if(input_error) break;
      }

      if(input_error) continue;

      if((good+bad) == 1);
      else {
        cerr << "\e[1;31mError Sex!!\e[0m" << endl; 
        input_error = true;
      }

    }while(input_error);
    legacy_sex = (good == 0 && bad == 1);
    return 0;
  }

  void input_field() {
    cout << "|  Name                                : ";
    set_name();
    set_age();
    set_sex();
    set_phone();
  }
  
  void display() const {
  }
};

class vehicle {
  protected:
  string name, from_destination , to_destination;
  unsigned int price = 0;
  public:
  unsigned int get_price();
  void display();

  void choose_day();

};

class Ferry : public vehicle {
  public:

  Ferry() = default;

  Ferry(unsigned short age){
    if (age <= 12) price = 10;
    else if (age <= 17) price = 15;
    else if (age <= 60) price = 25;
    else price = 12;
  }

  unsigned int get_price() const { 
    return price; 
  }

  void display() const {
    cout << "Ferry" << endl;
  }
  /*
  void display() const override { // example of AI faulty code
    cout << "Ferry" << endl;
  }
  */
};

//function covert num

template <typename T>
void new_num_input(T& a,string&& out = "input : "){
  bool error_input;
  string input;
  double test;
  do{
    error_input = false;
    input.clear();
    cout << out;
    getline(cin,input);
    input.erase(0,input.find_first_not_of(" \t"));
    input.erase(input.find_last_not_of(" \t")+1);
    istringstream iss(input);
    if(input.empty()){
      error_input = true;
      continue;
    }
    if(!(iss >> test) || !iss.eof()){
      cerr << "\e[1;31mError Input!!\e[0m" << endl;
      error_input = true;
      continue;
    }
    if(is_unsigned_v<T> && test < 0){
      cerr << "\e[1;31mError Input!!\e[0m" << endl;
      error_input = true;
    }
  }while(error_input);
  a = (T)stod(input);
}

// end num convert

void display(const unsigned short& person_num, const customer* const arry_cust) {
  unsigned int total = 0;
  cout
  << ">>===============================================<<" << '\n'
  << "|     |     |     |Order Summary|     |     |     |" << '\n'
  << ">>===============================================<<" << '\n'                
  << "|   Description          QTY     Amount(RM)       |" << '\n'
  << "|================================================<<" << '\n'
  << "|     Ferry              "<< person_num <<"          "<< total <<"            |" << '\n'
  << "|                                                 |" << '\n'
  << ">>===============================================<<" << endl;

}
void display_vic() {
  cout
  << "";
}

int main(int argc, char* argv[]){
  unsigned short person_num = 0; //danger out of range!!
  char vehicle_choose = '\0';
  int b;

  cout << "\e[1J\e[;H";

  cout
  << "Price Overview" << '\n'
  << "/----------------------+--------------------------\\" << '\n'
  << "|++++++++++++++++++++++|  Ferry |  Train |  Bus   |" << '\n'
  << "|_________Age__________|__(RM)__|__(RM)__|__(RM)__|" << '\n'
  << "| 0  - 12 (Children)   |   10   |   8    |   5    |" << '\n'
  << "| 13 - 17 (Teen)       |   15   |   12   |   10   |" << '\n'
  << "| 18 - 60 (Adult)      |   25   |   17   |   15   |" << '\n'
  << "| 60 >    (Senior)     |   12   |   10   |   12   |" << '\n'
  << "\\----------------------+--------------------------/" << endl;

  cout << endl;

  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  new_num_input(person_num,"Please Enter The Number Of Person  ------------------------------->> : ");

  customer* arry_cust = new customer[person_num];

  cout << "Choose Type of Transportation <Bus = B : Train = T : Ferry = F>--->> : ";
  cin >> vehicle_choose;
  cin.ignore(MAX_STREAM_SIZE,'\n');

  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << endl;

  if(vehicle_choose == 'f') Ferry selected_vechicle;

  for(unsigned int i = 0;i < person_num;i++){
    //cout << "\e[1J\e[;H";
    cout
    << "/++++++++++++++++++++++++++++++++++++++++++++++++++++" << '\n'
    << "|              Form For <<Ferry>> #" << i+1 << endl;
    arry_cust[i].input_field();
    cout
    << "\\++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
  }
  cout << "=====================================================================================" << endl;
  cout << endl;
  for(unsigned int i = 0;i < person_num;i++){
    cout
    <<"//===============================\\\\" << '\n'
    <<"| Description Form #" << i+1 << "             |" << '\n'
    <<"|                                 |" << endl;
    arry_cust[i].display();
    cout
    << "\\\\===============================//" << endl;
    cout << endl;
  }
  display(person_num,arry_cust);
  delete [] arry_cust;
  return 0;
}
