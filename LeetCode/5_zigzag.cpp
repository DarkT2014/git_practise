#include <iostream>
using namespace std;



string convert(string s, int numRows) {
        int len = s.length();
        if (len <= numRows || numRows == 1) {
            return s;
        }
        if (numRows == 2) {
            string sum = "";
            int isOdd = 0;
            // if (len % 2 == 1) {isOdd = 1;}else{isOdd = 0;}
            for (int n = 0; n < 2; n++) {
                for (int m = 0; m < len - n;m+=2) {
                    if(n + m < len) {
                        sum += s[n+m];
                    }                  
                }
            }
            return sum;
        } else {
            int perlen = 2 * (numRows - 1);
            string sum = "";
            bool zhengchu = (len % perlen == 0);
            int pernum = (zhengchu ? (len / perlen) : (len / perlen + 1));//number of period 
            // int pernum = numRows / perlen + 1;
            for (int i = 0; i < numRows; i++) {//row number = i  , i start from 0
                string tmp = "";
                for (int m = 0; m < pernum; m++) {
                    if (i == 0 || i == numRows - 1) {
                        if (m*perlen + i < len) {
                            tmp += s[m * perlen + i];
                        }                        
                    } else {
                        if (m*perlen + i < len) {
                            tmp +=s[m*perlen + i];
                            if ((m+1)*perlen - i<len && i > 0) {
                                tmp += s[m*perlen + perlen - i];
                            }
                        }
                    }               
                }
                sum += tmp;
            }
            return sum;
        }        
    }

int main() {
    int row = 3;
    string words = "ABCD";
    string output = convert(words, row);
    cout << output <<endl;
}
    