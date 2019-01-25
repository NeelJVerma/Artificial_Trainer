#include <iostream>
#include "clientelements/gui.h"
#include "clientelements/sanitizer.h"
#include "stat/ev.h"
#include "stat/iv.h"
#include "stat/hp.h"
#include <cmath>

int main() {
  artificialtrainer::Ev ev(65535);
  artificialtrainer::Iv iv(15);
  artificialtrainer::Hp hp(artificialtrainer::Species::kChansey, 100, ev, iv);
  hp -= 100;
  std::cout << hp.MaxHp() << std::endl;
  std::cout << hp.CurrentHp() << std::endl;
  return 0;
}