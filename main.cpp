#include <iostream>
#include <iomanip>
#include <limits>
#include <array> // I like vector bcs it not fixed

using namespace std; //Since we can only use std only, i allow for using namespace;

/* OS specified call */
#if _WIN32
//#include <window.h>
#warning "Window is Bad Bad."
#elif (__linux__||__unix__)
//#include <unistd.h>
//#include <stdio_ext.h>
#warning "Gay Linux is Good Linux!!"
#else 
#warning "Mac, Haiku? Is that you?"
#endif

constexpr auto MAX_STREAM_SIZE = std::numeric_limits<std::streamsize>::max();


namespace Kawaii {
  /* include your inside custom namespace for safety reason;
   * Do not create function outside the namespace then include inside; (why would you do that!?)
   * void Kawaii::function(){} is a big no no when you can put it inside!! (don't make stuff complex)
   * Valid function will pull out of namespace.
  */
  bool choice(string choice = "\0"){
    unsigned short good = 0, bad = 0;
    if(choice == "\0") {
      choice.erase();
      getline(cin,choice);
    }
    for(const char& i:choice){
      switch(i){
        case '\n':
        case ' ':
        case '\t':
        case '\r':
        case '\f':
        case '\v':
          break;
        case 'y':
        case 'Y':
          good++;
          break;
        case 'n':
        case 'N':
        default:
          bad++;
      }
    }
    if(good == 0) good++;
    return (good == 1 && bad == 0);
  }

  class Person {
    protected:
      bool legacy_sex = false;
      string name;
      unsigned short age = 0;

      void change_name();

    public:
      Person()
      :legacy_sex(false)
      ,age(0)
      {}

      ~Person() = default;

      /*accessor*/

      bool Sex() const {
        return legacy_sex;
      }

      string Name() const {
        return name;
      }

      unsigned short Age() const {
        return age;
      }

  };

  class Customer : public Person {
    public:
      friend class Admin;
  };

  class Admin : public Person {
      char status = '\0';
    public:

      Admin(const bool x) {
        if(!x) return;
        change_sex();
        change_name();
        change_age();
      }
      Admin(const bool& legacy_sex,const string& name,const unsigned short& age,const char& status) { // init list to modify local class not inherited class
        this->legacy_sex = legacy_sex;
        this->name = name;
        this->age = age;
        this->status = status;
      }
      ~Admin() {
        cout << "Admin : " << name << " Destroyed !" << endl;
      }

      int change_name(){
        cout << "Insert Name : "; //user input flow will be revised!!
        getline(cin,name);
        return 0;
      }

      int change_age() {
        cout << "Insert Age : ";
        if(!(cin >> age)){ // revise here very very important!!!
          cerr << "Error Input!!" << endl;
          cin.clear();
          cin.ignore(MAX_STREAM_SIZE,'\n');
          return -1;
        } else cin.ignore(MAX_STREAM_SIZE,'\n');
        return 0;
      }

      int change_sex() {
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
          cerr << "Error Gender!!" << endl;
          return -1;
        }
        if((good + bad) == 0) good++;
        legacy_sex = (good == 0 && bad == 1);
        return 0;
      }

      int change_status() {
        cout << "Insert Status : ";
        return 0;
      } 

      void change_sex(const bool& legacy_sex){
        this->legacy_sex = legacy_sex;
      }
      void change_name(const string& name){
        this->name = name;
      }
      void change_age(const unsigned short& age){
        this->age = age;
      }
      void change_status(const char& status){
        this->status = status;
      }

      /*accessor*/

      char Status() const {
        return status;
      }

      void Details() const {
        cout << "=Admin=" << '\n'
          << "Name : " << name << '\n'
          << "Sex  : " << ((legacy_sex == false) ? "Female" : "Male") << '\n'
          << "Age  : " << age << '\n'
          << "Status " << status << endl;
      }

  };
}

int main(int argc, char* argv[]){
  Kawaii::Admin a(true);
  a.Details();
  return 0;
}
