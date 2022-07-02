#include "ura.hpp"
#include <string.h>
#include <iostream>

bool palindrome(const char* s, int n) {
  if(strlen(s)==0) return true;
  if(s[0]!=s[n-1]) return false;
  if(&s[0]!=&s[n-1]) return palindrome(s+1,n-2);
  return true;
}
