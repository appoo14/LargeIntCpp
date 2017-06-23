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
        
        ABLInt operator+(const ABLInt& x);
        
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

ABLInt ABLInt::operator+(const ABLInt &x){
            ABLInt y;
            int ans[MAX_SIZE];
            int minlen = x.len < this->len ? x.len : this->len;
            int maxlen = x.len > this->len ? x.len : this->len;
            int carry = 0;
            int i;
            int length = maxlen;
            for(i=0; i<minlen;i++){
                ans[i] = x.value[i]+this->value[i]+carry;
                if(ans[i]/10==0)
                    carry = 0;
                else{
                    carry = ans[i]/10;
                    ans[i] = ans[i]%10;
                }
            }
            for(;i<x.len;i++){
                ans[i] = x.value[i]+carry;
                if(ans[i]/10==0)
                    carry = 0;
                else
                    carry = ans[i]/10;                    
            }
            for(;i<this->len;i++){
                ans[i] = this->value[i]+carry;
                if(ans[i]/10==0)
                    carry = 0;
                else
                    carry = ans[i]/10;                    
            }
            if(carry!=0){
                ans[i] = carry;
                length = maxlen+1;
            }
            y.len = length;
            for(i=0;i<length;i++){
                y.value[i] = ans[i];
            }
    return y;        
}

int main()
{
    ABLInt x,y,z;
    cin >> x;
    cin >> y;
    z = x+y;
    cout << z;
   
   
   return 0;
}

