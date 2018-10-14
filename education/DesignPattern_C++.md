# Design Pattern C++
----------

* Author : CODENURI lecture book
* Date : 2017.7.7

# Separation of between things to be changed and not changed

1.  Template method

    ````C++
    class EditBox
    {
    public:
      virtual bool validate(char c){return isdigit(c);} //~ virtual function
      string getData()
      {
          ...
          if( validate(c)) //~ things to be changed
            ~~~
      }
    };
    class AddressEdit : public EditBox
    {
    public:
      virtual bool validate(char c) //~ re definition
      {
        if( 'b'<c && c<'m' )
          return true;
        else 
          return false;
      }    
    }
    int main()
    {
      AddressEdit edit;
      string s = edit.getData();
      cout << s << endl;    
    }
    ````
You should set validate (that can be changed) to virtual function  
and redefine it in derived class  
It is the chanse of class itself not object

2.	Strategy

   ````c++
   struct IValidator
   {
     virtual bool validate(string s, char c)=0;
     virtual ~IValidator(){}
   }
   class EditBox
   {
     IValidator* pVal = 0;
   public:
     void setValidator(IValidator* p) {pVal = p;} //~ Things to be changed (validate function) 
   }
   class LimitDigitValidator : public IValidator //~ policy class including validation policy
   {
     int value;
   public:
     LimitDigitValidator(int v) : value(v){}
     if(s.size() < value && isdigit(c)) //~ set limitValue
       return true;
     return false;
   }
   int main()
   {
     EditBox edit;
     LimitDigitValidator v(5);
     edit.setValidator(&v);
     
     string s = edit.getData();
     cout << s << endl;
   }
   ````

Change of policy about object is possible  
It is called Strategy pattern


​	

