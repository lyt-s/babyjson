#include <cstddef>
#include <iostream>
#include <memory>
#include <optional>
#include <regex>
#include <string>
#include <string_view>
#include <unordered_map>
#include <variant>
#include <vector>
#include "print.h"

struct JSONObject;

using JSONDict = std::unordered_map<std::string, JSONObject>;
using JSONList = std::vector<JSONObject>;

struct JSONObject {
  std::variant<std::nullptr_t  // null
               ,
               bool  // true
               ,
               int  // 42
               ,
               double  // 3.14
               ,
               std::string  // "hello"
               ,
               JSONList  // [42, "hello"]
               ,
               JSONDict  // {"hello": 985, "world": 211}
               >
      inner;

  void do_print() const { printnl(inner); }
};

JSONObject parse(std::string_view json) {
  if (json.empty()) {
    return JSONObject{std::nullptr_t{}};
  }
  if ('0' <= json[0] && json[0] <= '9') {
    return JSONObject{int{json[0] - '0'}};
  }
  return JSONObject{std:nullptr_t{}};
}

int main() {
  std::string str1 = "42323333";
  parse(str1);
  print(str1.substr(3));
  return 0;
}