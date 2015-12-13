#ifndef LIMONP_CLOSURE_HPP
#define LIMONP_CLOSURE_HPP

namespace limonp {

class ClosureInterface {
 public:
  virtual ~ClosureInterface() {
  }
  virtual void Run() = 0;
};

template <class Funct>
class Closure0: public ClosureInterface {
 public:
  Closure0(Funct fun) {
    fun_ = fun;
  }
  virtual ~Closure0() {
  }
  virtual void Run() {
    (*fun_)();
  }
 private:
  Funct fun_;
}; 

template <class Funct, class Arg1>
class Closure1: public ClosureInterface {
 public:
  Closure1(Funct fun, Arg1 arg1) {
    fun_ = fun;
    arg1_ = arg1;
  }
  virtual ~Closure1() {
  }
  virtual void Run() {
    (*fun_)(arg1_);
  }
 private:
  Funct fun_;
  Arg1 arg1_;
}; 

template <class Obj, class Funct> 
class ObjClosure0: public ClosureInterface {
 public:
  ObjClosure0(Obj* p, Funct fun) {
   p_ = p;
   fun_ = fun;
  }
  virtual ~ObjClosure0() {
  }
  virtual void Run() {
    (p_->*fun_)();
  }
 private:
  Obj* p_;
  Funct fun_;
}; 

template <class Obj, class Funct, class Arg1> 
class ObjClosure1: public ClosureInterface {
 public:
  ObjClosure1(Obj* p, Funct fun, Arg1 arg1) {
   p_ = p;
   fun_ = fun;
   arg1_ = arg1;
  }
  virtual ~ObjClosure1() {
  }
  virtual void Run() {
    (p_->*fun_)(arg1_);
  }
 private:
  Obj* p_;
  Funct fun_;
  Arg1 arg1_;
}; 

template<class R>
ClosureInterface* NewClosure(R (*fun)()) {
  return new Closure0<R (*)()>(fun);
}

template<class R, class Arg1>
ClosureInterface* NewClosure(R (*fun)(Arg1 arg1), Arg1 arg1) {
  return new Closure1<R (*)(Arg1), Arg1>(fun, arg1);
}

template<class R, class Obj>
ClosureInterface* NewClosure(Obj* obj, R (Obj::* fun)()) {
  return new ObjClosure0<Obj, R (Obj::* )()>(obj, fun);
}

template<class R, class Obj, class Arg1>
ClosureInterface* NewClosure(Obj* obj, R (Obj::* fun)(Arg1), Arg1 arg1) {
  return new ObjClosure1<Obj, R (Obj::* )(Arg1), Arg1>(obj, fun, arg1);
}

class ITask {
 public:
  virtual ~ITask() {
  }
  virtual void Run() = 0;
}; // class ITask

template <class TaskType>
ITask* CreateTask() {
  return new TaskType();
}
template <class TaskType, class ArgType>
ITask* CreateTask(ArgType arg) {
  return new TaskType(arg);
}
template <class TaskType, class ArgType0, class ArgType1>
ITask* CreateTask(ArgType0 arg0, ArgType1 arg1) {
  return new TaskType(arg0, arg1);
}
template <class TaskType, class ArgType0, class ArgType1, class ArgType2>
ITask* CreateTask(ArgType0 arg0, ArgType1 arg1, ArgType2 arg2) {
  return new TaskType(arg0, arg1, arg2);
}

} // namespace limonp

#endif // LIMONP_CLOSURE_HPP
