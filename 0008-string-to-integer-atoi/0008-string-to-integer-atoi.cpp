class Solution {
public:



// done by me hehe XD




    int myAtoi(string s) 
    {
      int max = INT_MAX/10;
      int min = INT_MIN/10;
      int i = 0;
      int l = s.length();
      int digit = 0;
      long long value = 0;
      bool positive = true;
      

      //removing whitespace
      while(i < l && isspace(s[i])){
        i++;
      }

      //empty string
      if(i == l){
        return 0;
      }

      //checking sign
      if(s[i] == '-'){
        positive = false;
        i++;
      }
      else if(s[i] == '+'){
        i++;
      }

      //cases like -aeffdsa
      if(i == l || !isdigit(s[i])){
        return 0;
      }

      while(i < l && isdigit(s[i])){
        
        digit = s[i] - '0';

        //overflow handling
        if(value > INT_MAX/10 || 
          (value == INT_MAX/10 && digit > 7)){
            
            return positive ? INT_MAX : INT_MIN;
        }

        value = value * 10 + digit;
        i++;
      }

      if(!positive){
        value = value * (-1);
      }

      return value;

    }
      
};