#include "gtest/gtest.h"
#include "limonp/Closure.hpp"

using namespace limonp;

void Foo0() {
}

void Foo1(int x) {
}

class Obj {
 public:
  void Foo0() {
  }
  void Foo1(int i) {
  }
}; 

TEST(Closure, Test0) {
  ClosureInterface* c;

  c = NewClosure(&Foo0);
  ASSERT_TRUE(c != NULL);
  c->Run();
  delete c;
  c = NULL;

  c = NewClosure(&Foo1, 1);
  ASSERT_TRUE(c != NULL);
  c->Run();
  delete c;
  c = NULL;

  Obj obj;
  c = NewClosure(&obj, &Obj::Foo0);
  ASSERT_TRUE(c != NULL);
  c->Run();
  delete c;
  c = NULL;

  c = NewClosure(&obj, &Obj::Foo1, 1);
  ASSERT_TRUE(c != NULL);
  c->Run();
  delete c;
  c = NULL;
}
