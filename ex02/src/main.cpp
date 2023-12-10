//
// Created by k.t. on 2023/12/10.
//

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *Generate() {
  int mod = rand() % 3;
  std::cout << "Generating ";
  if (mod == 0) {
    std::cout << "A class..." << std::endl;
    return new A();
  } else if (mod == 1) {
    std::cout << "B class..." << std::endl;
    return new B();
  } else {
    std::cout << "C class..." << std::endl;
    return new C();
  }
}

void Identify(Base *p) {
  A *a_ptr = dynamic_cast<A *>(p);
  if (a_ptr) {
    std::cout << "This is a A class pointer" << std::endl;
    return;
  }
  B *b_ptr = dynamic_cast<B *>(p);
  if (b_ptr) {
    std::cout << "This is a B class pointer" << std::endl;
    return;
  }
  C *c_ptr = dynamic_cast<C *>(p);
  if (c_ptr) {
    std::cout << "This is a C class pointer" << std::endl;
    return;
  }
  std::cout << "Nonsense pointer!" << std::endl;
}

void Identify(Base &p) {
  try {
    A a_ref = dynamic_cast<A &>(p);
    std::cout << "This is a A class reference" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }
  try {
    B b_ref = dynamic_cast<B &>(p);
    std::cout << "This is a B class reference" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }
  try {
    C c_ref = dynamic_cast<C &>(p);
    std::cout << "This is a C class reference" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }
  std::cout << "Nonsense reference!" << std::endl;
}

int main() {
  srand(time(NULL));
  Base *ptr = Generate();
  Identify(ptr);
  Identify(*ptr);
  delete ptr;
  return 0;
}