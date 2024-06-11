/*
template <typename T>
void int_input(T& a,string&& out = ""){
  static_assert(false, "Use num_input");
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

template <typename  T>
void float_input(T& a,string&& out = ""){
  static_assert(false, "Use num_input");
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
*/
