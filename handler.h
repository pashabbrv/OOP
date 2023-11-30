#ifndef OOP_HEADERS_HANDLER_H
#define OOP_HEADERS_HANDLER_H

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "operations.h"
#include "input.h"

class Handler {
 public:
   Operations get_operation();
   Handler(Input& input, const std::string& new_file);
    
 private:
   Input& input_;
   std::unordered_map<char, Operations> operations_;

   Operations convert_operation(const std::string& operation);
};

#endif