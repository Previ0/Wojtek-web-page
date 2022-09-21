#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <cmath>
#include <limits>
#include "math.h"

// Floating point comparisment - https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/

namespace eMath {

  FL_TYPE nth_root(FL_TYPE number, FL_TYPE root, epsilon) {

  }
  
  /* FLOAT COMPARISMENT -----------------------------------------------------*/
  
  /*!
    @brief Compares floating point number (epsilon is an absolute value).
    
    @description Epsilon has an absolute value. This comparison is not recommended for floating point numbers that are big.
    
    @param[in] a - floating point number.
    @param[in] b - floating point number.
    @param[in] epsilon - tolerance in which floating point numbers can differ, to be able to assume they are equal.
    
    @return True: If compared floats are nearly equal.
            False: if compared floats are not equal.
  */
  bool nearly_equal_abs(float a,
                        float b,
                        float epsilon = std::numeric_limits<float>::epsilon())
  {
    return fabs(a - b) <= epsilon
  }

  /*!
    @brief Compares floating point number (epsilon is an relative value).
    
    @description Epsilon value changes accordingly to floating point numbers. This comparison is not recommended for floating point numbers that are approaching 0.
    
    @param[in] a - floating point number.
    @param[in] b - floating point number.
    @param[in] epsilon - tolerance in which floating point numbers can differ, to be able to assume they are equal.
    
    @return True: If compared floats are nearly equal.
            False: if compared floats are not equal.
  */
  bool nearly_equal_rel(float a,
                        float b,
                        float epsilon = std::numeric_limits<float>::epsilon())
  {
    return fabs(a - b) <= epsilon * std::max(fabs(a), fabs(b));
  }
  
  /*!
    @brief Compares floating point number (combines relative and absolute epsilon comparisment).
    
    @description Cobines comparisment of floating point numbers with relative and absolute epsion value. It is preferable function to use when we do not know if the compared floats are nearly 0 or bigger.
    
    @param[in] a - floating point number.
    @param[in] b - floating point number.
    @param[in] absTolerance - absolute tolerance .
    @param[in] relTolerance - relative tolerance scalar. 
    
    @return True: If compared floats are nearly equal.
            False: if compared floats are not equal.
  */
  bool nearly_equal(float a, float b, float absTolerance, float relTolerance) {
    return fabs(a - b) <= max(absTolerance, relTolerance * std::max(fabs(a), fabs(b)));
  }
  
  /*!
    @brief Compares floating point number (combines relative and absolute epsilon comparisment).
    
    @description Cobines comparisment of floating point numbers with relative and absolute epsion value. It is preferable function to use when we do not know if the compared floats are nearly 0 or bigger.
    
    @param[in] a - floating point number.
    @param[in] b - floating point number.
    @param[in] epsilon - tolerance in which floating point numbers can differ, to be able to assume they are equal.
    
    @return True: If compared floats are nearly equal.
            False: if compared floats are not equal.
  */
  bool nearly_equal(float a,
                    float b,
                    float epsilon = std::numeric_limits<float>::epsilon())
  {
    return fabs(a - b) <= epsilon * std::max(1, std::max(fabs(a), fabs(b)));
  }
  
} // !namespace eMath

  
  
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
