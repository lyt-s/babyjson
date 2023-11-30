#include <iostream>
#include <variant>

int main() {
  std::variant<std::nullptr_t  // null
               ,
               bool  // true
               ,
               int  // 42
               ,
               double  // 3.14
               ,
               std::string  // "hello"

               >
      inner;

  inner = 1;
  std::cout << "inner - " << inner.index() << std::endl;
  int i = std::get<2>(inner);
  std::cout << "i - " << i << std::endl;

  inner = 1.1;  // overwrite value
  std::cout << "inner - " << inner.index() << std::endl;
  double dou = std::get<3>(inner);
  std::cout << "dou - " << dou << std::endl;

  inner = false;  // overwrite value
  std::cout << "inner - " << inner.index() << std::endl;
  bool boo = std::get<bool>(inner);
  std::cout << "boo - " << boo << "\n";

  inner = "lyt";  // overwrite value
  std::cout << "inner - " << inner.index() << std::endl;
  std::string str = std::get<std::string>(inner);
  std::cout << "str - " << str << "\n";

  return 0;
}