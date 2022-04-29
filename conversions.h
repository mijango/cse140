#include <string>
#include <cmath>
#include <bitset>

//converting the binary given as string into decimal value
int binaryToDec(std::string str) {
  int binaryVal = 0;
  double decimalVal = 0;
  //converting to decimal
  for(int i = str.size()-1, exponent = 0; i >= 0; i--, exponent++) {
    binaryVal = std::stoi(str.substr(i,1));
    decimalVal += binaryVal*pow(2,exponent);
  }
  int result = decimalVal;
  return result;
}

//converting the binary given as string into decimal value
std::string decToBinary(int i) {
  //converting to decimal
  std::string s = std::__1::bitset<32>(i).to_string();
  return s;
}