/**
 * @project Artificial Trainer
 * @brief The implementation for the TypeSum function.
 *
 * @file typesum.cc
 * @author Neel Verma
 * @date 4/6/19
 */

#include "typesum.h"
#include "../type/effectiveness.h"

namespace artificialtrainer {
namespace {

/**
  * @brief: Translate the effectiveness of one type against another into an
  * integer. This isn't really necessary to do, it just made results a bit
  * easier to read.
  * @param const TypeNames &type_one: The first type.
  * @param const TypeNames &type_two: The second type.
  * @return: The integer conversion of effectiveness.
  */

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

/**
  * @brief: Adds up all type conversion results to a single value. This is
  * used in the ai picking forced switches or leading Pokemon.
  * @param const std::shared_ptr<Pokemon> &pokemon_one: The first Pokmeon in
  * the type effectiveness checking process.
  * @param const std::shared_ptr<Pokemon> &pokemon_two: The second Pokmeon in
  * the type effectiveness checking process.
  * @return int: The result of adding all type effectiveness results.
  */

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