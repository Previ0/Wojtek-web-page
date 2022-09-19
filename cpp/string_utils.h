#ifndef STRING_UTILS_H
#define STRING_UTILS_H

class StrUtils {
public:

  /*!
  @brief Extracts a string between defined delimiter.

  @param[in] inputString - String from which we want to extract text.
  @param delimiter - character that we want to use as a extraction range of a string.

  @return Extracted string.
  */
  static std::string ExtractBeetweenDelimiter(const std::string& inputString, char delimiter);
};


#endif // !STRING_UTILS_H