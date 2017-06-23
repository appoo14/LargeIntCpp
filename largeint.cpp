#include <iostream>
#include <string.h>

#define MAX_SIZE 50

using namespace std;

class ABLInt {
    int value[MAX_SIZE]; /* Actual value of integer as an array
                            Index 0     -> units place digit   
                            Index len-1 -> msb of the number
                         */
    string svalue;
    int len;
    
    public:
        
        ABLInt operator+(const AbLInt &x);
        
     friend ostream &operator<<( ostream &output, ABLInt &D ) {
         D.svalue.clear();
         for(int i=D.len-1,j=0;i>=0;i--,j++) {
            D.svalue += (char)D.value[i]+'0';
         } 
         output << D.svalue;
         return output;            
      }

      friend istream &operator>>( istream  &input, ABLInt &D ) { 
         input >> D.svalue;
         D.len = D.svalue.size();
         for(int i=D.len-1,j=0;i>=0;i--,j++) {
            D.value[j] = (int)D.svalue[i]-'0';
         }
         
         return input;  
         
      }
};

int main()
{
    ABLInt x;
    cin >> x;
    cout << x;
   
   
   return 0;
}

