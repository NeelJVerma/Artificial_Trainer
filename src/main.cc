#include <iostream>
#include "clientelements/gui.h"
#include "clientelements/sanitizer.h"
#include "stat/ev.h"
#include "stat/iv.h"
#include "stat/hp.h"
#include "stat/statscontainer.h"
#include "battle/battle.h"
#include <cmath>

int main() {
  artificialtrainer::Battle battle;
  battle.Play();
  return 0;
}