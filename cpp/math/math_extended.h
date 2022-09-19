#ifndef MATH_EXTENDED_H
#define MATH_EXTENDED_H

#include <iostream>
#include <sstream>

#define MATH_NUMERIC_TYPE double
#define DEBUG_MODE_1 1

/*!
  @brief A-dimentional Point.
*/
template <int A>
struct Point{
  MATH_NUMERIC_TYPE coordinates[A]; /** < Point coordinates */
  
  
  /*!
    @brief Point constructor.
  */
  Point();
 
  Point(MATH_NUMERIC_TYPE x, MATH_NUMERIC_TYPE y);
  
  /*!
    @brief Point constructor.
    
    param[in] cords - coordinate list of A-dimentional Point. 
  */
  template<typename... B> Point(B... cords) {
    MATH_NUMERIC_TYPE temp[] = {cords...};
    
    // copying A-number parameters to coordinates.
    for (int i = 0; i < A; i++) {
      coordinates[i] = temp[i];
    }
  }
  
#if DEBUG_MODE_1 
  std::string ToString() const {
    std::stringstream ss;
    ss << "(" << coordinates[0] << ", " << coordinates[1] << ")";
    return ss.str();
  }
#endif
 
};

template<>
Point<2>::Point(MATH_NUMERIC_TYPE x, MATH_NUMERIC_TYPE y) :
  coordinates{x, y} {
    std::cout << "Point<2> init." << std::endl;
  }

#endif // !MATH_EXTENDED_H
