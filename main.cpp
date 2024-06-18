#include <iomanip>
#include <ios>
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

//function covert num

template <typename T>
void new_num_input(T& a,string&& out = "input : ",string&& err = "Error Input!!"){
  bool error_input;
  double test;
  do{
    string input;
    error_input = false;
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
      cerr << "\e[1;31m"<<err<<"\e[0m" << endl;
      error_input = true;
      continue;
    }
    if(is_unsigned_v<T> && test < 0){
      cerr << "\e[1;31m"<<err<<"\e[0m" << endl;
      error_input = true;
    }
  }while(error_input);
  a = (T)test;
}

// end num convert

class Customer {
  bool legacy_sex = false;
  unsigned short age = 0;
  float cust_price = 0;
  string cust_name, phone;
  public:

  void set_name() {
    getline(cin,cust_name);
      cust_name.erase(0,cust_name.find_first_not_of(" \t"));
      cust_name.erase(cust_name.find_last_not_of(" \t")+1);
  }

  void set_age() {
    new_num_input(age,"|  Age                                 : ","Error Age!!");
  }

  void set_phone() {
    bool input_error = false;
    do{
      input_error = false;
      phone.clear();
      cout << "|  Phone                               : ";
      getline(cin,phone);
      phone.erase(0,phone.find_first_not_of(" \t"));
      phone.erase(phone.find_last_not_of(" \t")+1);
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
      input.clear();
      cout << "|  Gender << F = Female : M = Male >>  : ";
      getline(cin,input);
      input.erase(0,input.find_first_not_of(" \t"));
      input.erase(input.find_last_not_of(" \t")+1);
      for(const char& i:input){
        switch(i) {
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

  string Age_Category() const {
    if(age < 13) return "Children";
    else if(age < 18) return "Teen";
    else if(age < 61) return "Adult";
    else return "Senior";
  }

  void input_field() {
    cout << "|  Name                                : ";
    set_name();
    set_age();
    if(age > 999) cout << "\e[1;93mThis is quite some Great Mage age...\n\e[0m";
    set_sex();
    set_phone();
  }
  
  float price() const {
    return cust_price;
  }

  void price(const float price){
    this->cust_price = price;
  }

  void display() const {
    cout
    <<"| Name           : "<<setw(15)<<cust_name<<"|"<<'\n'
    <<"| Gender         : "<<setw(15)<<((legacy_sex == false) ? "Female" : "Male")<<"|"<<'\n'
    <<"| Age Category   : "<<setw(15)<<Age_Category()<<"|"<<'\n';
  }

  friend class Vehicle;
};

class Vehicle {
  protected:
  string name;
  unsigned int price[4];
  public:
  void get_price(Customer& cust) const { 
    if(cust.age < 13) cust.cust_price = price[0];
    else if(cust.age < 18) cust.cust_price = price[1];
    else if(cust.age < 61) cust.cust_price = price[2];
    else cust.cust_price = price[3];
  }
  string display() const {
    return name;
  }

};

class Ferry : public Vehicle {
  public:

  Ferry(){
    name = "Ferry";
    price[0] = 10;
    price[1] = 15;
    price[2] = 25;
    price[3] = 12;
  }

  /*
  void display() const override { // example of AI faulty code
    cout << "Ferry" << endl;
  }
  */
};

class Bus : public Vehicle {
  public:

  Bus(){
    name = "Bus";
    price[0] = 5;
    price[1] = 10;
    price[2] = 15;
    price[3] = 12;
  }

};

class Train : public Vehicle {
  public:

  Train(){
    name = "Train";
    price[0] = 8;
    price[1] = 12;
    price[2] = 17;
    price[3] = 10;
  }

};

void display(const unsigned short& person_num, const Customer* const arry_cust, const Vehicle* const vec) {
  float total = 0;
  for(int i = 0;i<person_num;i++) total += arry_cust[i].price();
  cout
  << ">>===============================================<<" << '\n'
  << "|     |     |     |Order Summary|     |     |     |" << '\n'
  << ">>===============================================<<" << '\n'                
  << "|   Description          QTY     Amount(RM)       |" << '\n'
  << "|================================================<<" << '\n'
  << "|     "<<setw(19)<<vec->display()<<setw(11)<<person_num<<setw(14)<<total<<"|"<< '\n'
  << "|                                                 |" << '\n'
  << ">>===============================================<<" << endl;

}
void display_vic() {
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
}

Vehicle* choose_vec(){
  Vehicle* selected_vehicle;
  bool error_input = false;
  do{
    string input;
    error_input = false;
    cout << "Choose Type of Transportation <Bus = B : Train = T : Ferry = F>--->> : ";
    getline(cin,input);
    input.erase(0,input.find_first_not_of(" \t"));
    input.erase(input.find_last_not_of(" \t")+1);
    if(input.empty()){
      error_input = true;
      continue;
    }
    if(input.size() != 1){
      error_input = true;
      cerr << "\e[1;31mError Input!!\e[0m" << endl; 
      continue;
    }
    switch (input[0]) {
      case 'B':
      case 'b':
        selected_vehicle = new Bus;
        break;
      case 'T':
      case 't':
        selected_vehicle = new Train;
        break;
      case 'F':
      case 'f':
        selected_vehicle = new Ferry;
        break;
      default:
        error_input = true;
        cerr << "\e[1;31mError Input!!\e[0m" << endl; 
    }
  }while (error_input);
  return selected_vehicle;
}

int main(int argc, char* argv[]){
  unsigned short person_num = 0; //danger out of range!!
  Vehicle* selected_vehicle;

  cout << "\e[2J\e[;H";

  cout << left; // Input manip here

  display_vic();

  cout << endl;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  new_num_input(person_num,"Please Enter The Number Of Person  ------------------------------->> : ");
  Customer* arry_cust = new Customer[person_num];
  selected_vehicle = choose_vec();
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << endl;

  for(unsigned int i = 0;i < person_num;i++){
    //cout << "\e[1J\e[;H";
    cout
    << "/++++++++++++++++++++++++++++++++++++++++++++++++++++" << '\n'
    << "|              Form For <<"<<selected_vehicle->display()<<">> #" << i+1 << endl;
    arry_cust[i].input_field();
    cout
    << "\\++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
    selected_vehicle->get_price(arry_cust[i]);
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
    << "| Transportation : "<<setw(15)<<selected_vehicle->display()<<"|" << '\n'
    << "| Price          : RM "<<setw(12)<<arry_cust[i].price()<<"|"<<'\n'
    << "\\\\===============================//" << endl;
    cout << endl;
  }
  display(person_num,arry_cust,selected_vehicle);
  delete [] arry_cust;
  return 0;
}
