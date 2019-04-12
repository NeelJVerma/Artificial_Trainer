//
// Created by neel on 4/6/19.
//

#include "typesum.h"
#include "../type/effectiveness.h"

namespace artificialtrainer {
namespace {
int CheckTypes(const TypeNames &type_one, const TypeNames &type_two) {
  double effectiveness = Effectiveness(type_one, type_two);

  if (effectiveness == 0.0) {
    return 3;
  }

  if (effectiveness == 0.5) {
    return 2;
  }

  if (effectiveness == 1) {
    return 1;
  }

  return 0;
}

} //namespace

int TypeSum(const std::shared_ptr<Pokemon> &pokemon_one,
            const std::shared_ptr<Pokemon> &pokemon_two) {
  TypeContainer type_container_one = pokemon_one->GetTypeContainer();
  TypeContainer type_container_two = pokemon_two->GetTypeContainer();
  return CheckTypes(type_container_one.FirstType(),
                    type_container_two.FirstType()) +
      CheckTypes(type_container_one.FirstType(),
                 type_container_two.SecondType()) +
      CheckTypes(type_container_one.SecondType(),
                 type_container_two.FirstType()) +
      CheckTypes(type_container_one.SecondType(),
                 type_container_two.SecondType());
}

} //namespace artificialtrainer