#include<iostream>
#include<algorithm>

using namespace std;

class fraction
{
private:
        int numerator;
        int denominator;

 public:
         fraction(){

         } 


        fraction(int numerator,int denominator)
        {
          this->numerator=numerator;
          this->denominator=denominator;
        }



    fraction operator+ (fraction const &f2)
    {
      int lcm=denominator * f2.denominator;
      int x=lcm/denominator;
      int y=lcm/f2.denominator;
      int num= numerator * x + f2.numerator * y;

      fraction fnew(num,lcm);
      fnew.simplify();
      return fnew;

    
    }



     fraction operator-(fraction const &f2)
    {
      int lcm=denominator * f2.denominator;
      int x=lcm/denominator;
      int y=lcm/f2.denominator;
      int num= numerator * x - f2.numerator * y;

      fraction fnew(num,lcm);
      fnew.simplify();
      return fnew;

    
    }



    fraction operator* (fraction &f2)
    {
         int num= numerator * f2.numerator;
         int den= denominator * f2.denominator;
       
         fraction fnew(num,den);
         fnew.simplify();
         return fnew;
    }


    fraction operator/ (fraction &f2)
     { 
       int num=numerator * f2.denominator;
       int den=denominator * f2.numerator;

       fraction fnew(num,den);
       fnew.simplify();
       return fnew;
     }



    void simplify()
    {
        int a= __gcd(numerator,denominator);
        numerator=numerator/a;
        denominator=denominator/a;

    }


    void print()
    {
        cout<<numerator<<"/"<<denominator<<endl;
    }

       

};


int main()
{    int num1,den1;
     int num2,den2;

     int choice;
     
     

    cout<<"\nEnter Numerator for the first fraction: "<<endl;
    cin>>num1;
    cout<<"Enter Denominator for the first fraction: "<<endl;
    cin>>den1;
    cout<<"\nEnter Numerator for the second fraction: "<<endl;
    cin>>num2;
    cout<<"Enter Denominator for the second fraction: "<<endl;
    cin>>den2;

    cout<<"\nYour first fraction is: "<<num1<<"/"<<den1<<endl;
    cout<<"Your second fraction is: "<<num2<<"/"<<den2<<endl;

    fraction f1(num1,den1);
    fraction f2(num2,den2);

    fraction f3;

    cout<<"\nWhich operation do you want to perform: "<<endl;
    cout<<"\n1.Addition\n"
          "2.Subtraction\n"
          "3.Multiplication\n"
          "4.Division\n";

    cout<<"\nYour choice: ";
    cin>>choice;

    switch(choice)
    {

       case 1:
            f3=f1+f2;
            cout<<"\noutput:";
            f3.print();
            break;

       case 2: 
             f3=f1-f2; 
             cout<<"\noutput:";
             f3.print();  
             break;

       case 3: 
              f3=f1*f2;
              cout<<"\noutput:"; 
              f3.print();
              break;
      
      case 4:
             f3=f1/f2;
             cout<<"\noutput:";
             f3.print();
             break;

    default : 
             cout<<" please enter a valid choice"<<endl;
               
              
    }
   
    return 0;
}