#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <sstream>

#include "math.h"
#include "point.h"


/*!
  @Vector class represents mathematical definition of vector.
  
  @param DIM - dimention in which vector is placed.
*/
template <int DIM>
class Vector{
public:
  /*!
    @brief Class constructor.
    
    @param[in] i - tail of the vector.
    @param[in] j - head of the vector.
  */
  Vector(Point<DIM> i, Point<DIM> j);
  
  /*!
    @brief Returns string representation of a vector.
	
	@return String representation of a vector.
  */
  std::string ToString() const;
  
private:

  Point<DIM> i_; /** < Tail of the vector. */
  Point<DIM> j_; /** < Head of the vector. */
};

template<int DIM>
Vector<DIM>::Vector(Point<DIM> i, Point<DIM> j) :
  i_{ i },
  j_{ j }
{
    std::cout << "Vector created" << std::endl;
}

template<int DIM>
std::string Vector<DIM>::ToString() const {
    std::stringstream ss;
    
    ss << "vec = [i=" << i_.ToString() << ", j=" << j_.ToString() << "]";
    
    return ss.str();
}

#endif // !VECTOR_H