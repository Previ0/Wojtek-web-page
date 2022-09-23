#include "string_utils.h"

static std::string StrUtils::ExtractBeetweenDelimiter(const std::string& inputString, char delimiter) {
  std::string temp;
  bool isDelimiterFound = false;

  //iterating through every character
  for (int i = 0; i < inputString.length(); i++) {

    //is delimiter found? switch to true if it is starting delimter
    if(inputString[i] == delimiter) {
      isDelimiterFound = !isDelimiterFound;
      continue;
    }

    //append char when start delimiter is found
    if(isDelimiterFound) {
      temp.append(1, inputString[i]);
    }
  }

  //Set temp as an empty string if an ending delimiter has not been found.
  if(isDelimiterFound) {
    temp.clear();
  }
  return temp;
}


//-----------------------------------------

std::vector<std::string> SplitString(const std::string& input, char spliter = '\n') {
    std::vector<std::string> strings;
    
    strings.emplace_back("");
    
    for(char ch : input) {
        if(ch == spliter) {
            if(strings[strings.size() - 1].size() == 0 || ch == input.back()) continue;
            else strings.emplace_back("");
        }
        else {
            strings[strings.size() - 1].append(1, ch);
        }
    }
    return strings;
}
