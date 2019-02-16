//
// Created by neel on 1/30/19.
//

#ifndef ARTIFICIAL_TRAINER_TYPECONTAINER_H
#define ARTIFICIAL_TRAINER_TYPECONTAINER_H

#include <utility>
#include "../pokemon/speciesnames.h"
#include "typenames.h"
#include "../move/movenames.h"

namespace artificialtrainer {
class TypeContainer {
 public:
  TypeContainer() = default;
  TypeContainer(const TypeContainer &type_container) = default;
  TypeContainer &operator=(const TypeContainer &type_container) = default;
  explicit TypeContainer(const SpeciesNames &species_name);
  TypeNames FirstType() const;
  TypeNames SecondType() const;
  void ResetTypeFromConversion(const TypeNames &type_name);
  bool MoveMatchesType(const MoveNames &move_name) const;

 private:
  std::pair<TypeNames, TypeNames> types_;
};

// add blocks status

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TYPECONTAINER_H
