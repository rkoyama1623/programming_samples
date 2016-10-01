// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-

#include <stdio.h>
#include <memory>
#include <memory.h>
#include <string>
#include "getch.h"

namespace std {
  using namespace tr1; // std::tr1:: => std::
}

class keyboard_joy : GetCharacter {
public:
  keyboard_joy();
  keyboard_joy(int tm_sec, int tm_usec);
  ~keyboard_joy();
  void read();
private:
  char* key;
  const std::vector<char> KEYCODE_U;
  const std::vector<char> KEYCODE_D;
  const std::vector<char> KEYCODE_R;
  const std::vector<char> KEYCODE_L;
};
// keyboard_joy::keyboard_joy() : GetCharacter() {
//   keyboard_joy(3,0);
// };
keyboard_joy::keyboard_joy(int tm_sec, int tm_usec)
  :GetCharacter(tm_sec, tm_usec),
   KEYCODE_U{0x1b, 0x5b, 0x41},
   KEYCODE_D{0x1b, 0x5b, 0x42},
   KEYCODE_R{0x1b, 0x5b, 0x43},
   KEYCODE_L{0x1b, 0x5b, 0x44}
{
  key = NULL;
};
keyboard_joy::~keyboard_joy() {
  GetCharacter::resetTermios();
};
void keyboard_joy::read() {
  GetCharacter::read(&key, 3);
  const std::vector<char> key_vec(key, key+3);
  if ( key_vec == KEYCODE_U) {
    printf("UP!\n");
  } else if ( key_vec == KEYCODE_D) {
    printf("DOWN!\n");
  } else if ( key_vec == KEYCODE_R) {
    printf("RIGHT!\n");
  } else if ( key_vec == KEYCODE_L) {
    printf("LEFT!\n");
  } else {
    printf("key_vec: %d/%d/%d (%d)\n", key_vec[0], key_vec[1], key_vec[2], (int) key_vec.size());
  }
  // printf("key_vec: %d/%d/%d (%d)\n", key_vec[0], key_vec[1], key_vec[2], key_vec.size());
  // printf("key:     %d/%d/%d\n", key[0], key[1], key[2]);
  // printf("UP:      %d/%d/%d (%d)\n", KEYCODE_U[0], KEYCODE_U[1], KEYCODE_U[2], KEYCODE_U.size());
};

int main(void)
{
  std::shared_ptr<keyboard_joy> kj(new keyboard_joy(3,0));
  kj -> read();
};
