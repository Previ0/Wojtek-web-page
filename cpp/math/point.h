#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <sstream>
#include "math.h"

/*!
  @brief A-dimentional Point.
*/
template <int A>
class Point{
public:

// Constructors

  /*!
    @brief Point constructor.
  */
  Point();
 
  /*!
    @brief Point constructor.
    
    @param[in] x - x coordinate.
    @param[in] y - y coordinate.
  */
  Point(FL_TYPE x, FL_TYPE y);
  
  /*!
    @brief Point constructor.
    
    @param[in] x - x coordinate.
    @param[in] y - y coordinate.
    @param[in] z - z coordinate.
  */
  Point(FL_TYPE x, FL_TYPE y, FL_TYPE z);
  
  /*!
    @brief Point constructor.
    
    param[in] cords - coordinate list of A-dimentional Point. 
  */
  template<typename... B> Point(B... cords);
  
// Methods 
 
  /*!
    @biref Converts Point into string representation.
    
    @return Point in string representation.
  */
  std::string ToString() const;

// Data members

  MATH_NUMERIC_TYPE coordinates_[A]; /** < Point coordinates */
  
private:

  static const int size_;  /** < Point diementions */
};

template<int A>
const int Point<A>::size_{ A };

template<>
Point<2>::Point(FL_TYPE x, FL_TYPE y) :
  coordinates_{x, y} {
    //std::cout << "Point<" << size_ << "> init." << std::endl;
}

template<>
Point<3>::Point(FL_TYPE x, FL_TYPE y, FL_TYPE z) :
  coordinates_{x, y, z} {
    //std::cout << "Point<" << size_ << "> init." << std::endl;
}

template<int A>
Point<A>::Point(FL_TYPE x, FL_TYPE y) :
  coordinates_{} {
    coordinates_[0] = x;
    coordinates_[1] = y;
    //std::cout << "Point<" << size_ << "> init." << std::endl;
}

template<int A>
Point<A>::Point(FL_TYPE x, FL_TYPE y, FL_TYPE z) :
  coordinates_{} {
    coordinates_[0] = x;
    coordinates_[1] = y;
    coordinates_[3] = y;
    //std::cout << "Point<" << size_ << "> init." << std::endl;
}

template<int A>
template<typename... B>
Point<A>::Point(B... cords) {
  FL_TYPE temp[] = {cords...};
    
  // copying A-number parameters to coordinates.
  for (int i = 0; i < A; i++) {
    coordinates_[i] = temp[i];
  }
}

template<int A>
std::string Point<A>::ToString() const {
  std::stringstream ss;
  
  ss << "(";
  
  // concatenating coordinates_
  for(int i = 0; i < size_-1; i++){
    ss << coordinates_[i] << ", ";
  }
  
  ss << coordinates_[size_-1] << ")";
  
  return ss.str();
}

#endif // !POINT_H
