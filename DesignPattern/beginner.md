디자인패턴
----------

-	출처 : CODENURI 강의교재
  -날짜 : 2017.7.7

#### 변하는 것과 변하지 않는 것의 분리

1.  Template method

    ````C++
    class EditBox
    {
    public:
      virtual bool validate(char c){return isdigit(c);} //~ 가상함수
      string getData()
      {
          ...
          if( validate(c)) //~ 변하는 부분
            ~~~
      }
    };
    class AddressEdit : public EditBox
    {
    public:
      virtual bool validate(char c) //~ 재정의
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

    이와 같이 변하는 부분 validate를 가상함수로 선언하고,

    파생클래스에서 재정의하면 됨

    객체가 아닌 클래스 자체에 대한 변경임

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
     void setValidator(IValidator* p) {pVal = p;} //~ 변하는 부분(validate함수) 설정해줌
   }
   class LimitDigitValidator : public IValidator //~ Validation 정책 담은 정책 class
   {
     int value;
   public:
     LimitDigitValidator(int v) : value(v){}
     if(s.size() < value && isdigit(c)) //~ limitValue를 설정
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

   객체에 대한 정책의 변경이 가능함.

   전략 패턴이라고 부름.

​	

