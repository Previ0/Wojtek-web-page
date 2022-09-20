#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <cmath>
#include <limits>
#include math.h

// ref

namespace eMath {

  FL_TYPE nth_root(FL_TYPE number, FL_TYPE root, epsilon) {

  }
  
  //TO-DO
  //bool nearly_equal(FL_TYPE a, FL_TYPE b, FL_TYPE epsilon = )

}

namespace eMathUtils {
  
   /*!
    @brief Prints bit pattern of floating point number to standard output.
    
    @param a - value of primitive data type.
    
  */
  template<typename T>
  void printBitPattern(T a) {
    T compare = 1;           // setting least sagnificant bit.
    char str[sizeof(T) * 8]; // char array representation of bit pattern.
    
    // scanning bit by bit
    for(int i = sizeof(T) * 8; i> 0; --i) {
      if((a & compare) > 0) str[i-1] = '1';
      else str[i-1] = '0';
      compare <<= 1;
    }
    
    // prints bit pattern - most sagnificant --> least sagnificant.
    std::cout << str <<std::endl;
  }
  
  /*!
    @brief Prints bit pattern of floating point number to standard output.
    
    @description x - sign
                 xxxx'xxxx - Exponent
                 xxx'xxxx'xxxx'xxxx'xxxx'xxxx' - Mantissa
    
  */
  template<>
  void printBitPattern<float>(float a) {
    uint32_t compare = 1;          // setting least sagnificant bit.
    char str[sizeof(float) * 8];   // char array representation of bit pattern.
    
    // casting float to same width bit pattern, remaining the bit order.
    uint32_t* fl_num = reinterpret_cast<uint32_t*>(&a);
    
    // scanning bit by bit
    for(int i = sizeof(float) * 8; i> 0; --i) {
      if((*fl_num & compare) > 0) str[i-1] = '1';
      else str[i-1] = '0';
      compare <<= 1;
    }
    
    // prints bit pattern - most sagnificant --> least sagnificant.
    std::cout << str <<std::endl;
    /*
    std::cout << "sign: " << str[0] << std::endl;
    std::cout << "exponent: ";
    for (int i = 1; i < 9; ++i) { std::cout << str[i]; }
    std::cout << std::endl << "mantissa: ";
    for (int i = 9; i < 32; ++i) { std::cout << str[i]; }
    */
  }
  
  /*!
    @brief Prints bit pattern of double precission floating point number to standard output.
    
    @description x - sign
                 xxxx'xxxx'xxx - Exponent
                 xxxx'xxxx'xxxx'xxxx' xxxx'xxxx'xxxx'xxxx' xxxx'xxxx'xxxx'xxxx' xxxx' - Mantissa
    
  */
  template<>
  void printBitPattern(double a) {
    uint64_t compare = 1;          // setting least sagnificant bit.
    char str[sizeof(double) * 8];  // char array representation of bit pattern.
    
    // casting float to same width bit pattern, remaining the bit order.
    uint64_t* fl_num = reinterpret_cast<uint64_t*>(&a);
    
    // scanning bit by bit
    for(int i = sizeof(double) * 8; i> 0; --i) {
      if((*fl_num & compare) > 0) str[i-1] = '1';
      else str[i-1] = '0';
      compare <<= 1;
    }
    // prints bit pattern - most sagnificant --> least sagnificant.
    std::cout << str <<std::endl;
      
  }
  
}

#endif // !MATH_FUNCTIONS_H
