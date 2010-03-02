#include "includes.h"

Symbol::Symbol(const string &name) : Object(OBJ_SYMBOL), _name(name)
{
}

Symbol::~Symbol()
{
}

Object_p Symbol::equal(const Object_p other) const
{
  if(!IS_SYMBOL(other))
    return nil;
  
  Symbol_p other_sym = (Symbol_p)other;
  if(this->_name == other_sym->_name)
    return t;
  return nil;
}

Object_p Symbol::eval(Scope *scope)
{
  return this;
}

string Symbol::to_s() const
{
  return this->_name;
}

string Symbol::name() const
{
  return this->_name;
}

map<string, Symbol_p> Symbol::sym_cache;
Symbol_p Symbol::from_string(const string &name)
{
  if(sym_cache.find(name) != sym_cache.end()) {
    return sym_cache[name];
  } else {
    // insert new name into sym_cache & return new number name
    Symbol_p new_sym = new Symbol(name);
    sym_cache[name] = new_sym;
    return new_sym;
  }
}