#include "includes.h"

namespace fancy {
  namespace bootstrap {

    /**
     * Number instance methods
     */
    METHOD(method_Number_plus);
    METHOD(method_Number_minus);
    METHOD(method_Number_multiply);
    METHOD(method_Number_divide);
    METHOD(method_Number_lt);
    METHOD(method_Number_lt_eq);
    METHOD(method_Number_gt);
    METHOD(method_Number_gt_eq);
    METHOD(method_Number_eq);
    METHOD(method_Number_times);
    METHOD(method_Number_modulo);

    void init_number_class()
    {
      NumberClass->def_method("+", new NativeMethod("+", method_Number_plus));
      NumberClass->def_method("-", new NativeMethod("-", method_Number_minus));
      NumberClass->def_method("*", new NativeMethod("*", method_Number_multiply));
      NumberClass->def_method("/", new NativeMethod("/", method_Number_divide));
      NumberClass->def_method("<", new NativeMethod("<", method_Number_lt));
      NumberClass->def_method("<=", new NativeMethod("<=", method_Number_lt_eq));
      NumberClass->def_method(">", new NativeMethod(">", method_Number_gt));
      NumberClass->def_method(">=", new NativeMethod(">=", method_Number_gt_eq));
      NumberClass->def_method("==", new NativeMethod("==", method_Number_eq));
      NumberClass->def_method("times:", new NativeMethod("times:", method_Number_times));
      NumberClass->def_method("modulo:", new NativeMethod("modulo:", method_Number_modulo));
      NumberClass->def_method("%", new NativeMethod("%", method_Number_modulo));
    }

    /**
     * Number instance methods
     */
    FancyObject_p method_Number_plus(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#+", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        if(num1->is_double() || num2->is_double()) {
          return Number::from_double(num1->doubleval() + num2->doubleval());
        } else {
          return Number::from_int(num1->intval() + num2->intval());
        }
      } else {
        return Number::from_int(0);
      }
      return self;
    }

    FancyObject_p method_Number_minus(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#-", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        if(num1->is_double() || num2->is_double()) {
          return Number::from_double(num1->doubleval() - num2->doubleval());
        } else {
          return Number::from_int(num1->intval() - num2->intval());
        }
      } else {
        return Number::from_int(0);
      }
      return self;
    }

    FancyObject_p method_Number_multiply(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#*", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        if(num1->is_double() || num2->is_double()) {
          return Number::from_double(num1->doubleval() * num2->doubleval());
        } else {
          return Number::from_int(num1->intval() * num2->intval());
        }
      } else {
        return Number::from_int(0);
      }
      return self;
    }

    FancyObject_p method_Number_divide(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#/", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        // always return double number for division
        return Number::from_double(num1->doubleval() / num2->doubleval());
      } else {
        return Number::from_int(0);
      }
      return self;
    }

    FancyObject_p method_Number_lt(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#<", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        if(num1->doubleval() < num2->doubleval()) {
          return t;
        } else {
          return nil;
        }
      } else {
        errorln("Number#< only works on Number objects!");
      }
      return nil;
    }

    FancyObject_p method_Number_lt_eq(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#<=", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        if(num1->doubleval() <= num2->doubleval()) {
          return t;
        } else {
          return nil;
        }
      } else {
        errorln("Number#<= only works on Number objects!");
      }
      return nil;
    }


    FancyObject_p method_Number_gt(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#>", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        if(num1->doubleval() > num2->doubleval()) {
          return t;
        } else {
          return nil;
        }
      } else {
        errorln("Number#> only works on Number objects!");
      }
      return nil;
    }

    FancyObject_p method_Number_gt_eq(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#>=", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        if(num1->doubleval() >= num2->doubleval()) {
          return t;
        } else {
          return nil;
        }
      } else {
        errorln("Number#>= only works on Number objects!");
      }
      return nil;
    }

    FancyObject_p method_Number_eq(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#==", 1);
      FancyObject_p arg = args[0];
      if(IS_NUM(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Number_p num2 = dynamic_cast<Number_p>(arg);
        if(num1->doubleval() == num2->doubleval()) {
          return t;
        } else {
          return nil;
        }
      }
      return nil;
    }

    FancyObject_p method_Number_times(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#times:", 1);
      FancyObject_p arg = args[0];
      if(IS_BLOCK(arg)) {
        Number_p num1 = dynamic_cast<Number_p>(self);
        Block_p block = dynamic_cast<Block_p>(arg);

        // if block is empty (nothing in the blocks body) simply
        // return nil and don't bother wasting any precious time here...
        if(block->is_empty())
          return nil;

        int val = num1->intval();
        if(block->argcount() > 0) {
          FancyObject_p arg[1];
          for(int i = 0; i < val; i++) {
            arg[0] = Number::from_int(i);
            block->call(self, arg, 1, scope);
          }
        } else {
          for(int i = 0; i < val; i++) {
            block->call(self, scope);
          }
        }
      } else {
        errorln("Number#times: expects Block object as parameter!");
      }
      return nil;
    }

    FancyObject_p method_Number_modulo(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope)
    {
      EXPECT_ARGS("Number#modulo:", 1);
      Number_p num1 = dynamic_cast<Number_p>(self);
      Number_p num2 = dynamic_cast<Number_p>(args[0]);
      if(num1 && num2) {
        return Number::from_int(num1->intval() % num2->intval());
      } else {
        errorln("Number#modulo: expects Number argument.");
      }
      return self;
    }

  }
}
