//
// Created by neel on 1/30/19.
//

#ifndef ARTIFICIAL_TRAINER_TYPECONTAINER_H
#define ARTIFICIAL_TRAINER_TYPECONTAINER_H

#include <utility>
#include "type.h"
#include "../pokemon/speciesnames.h"

namespace artificialtrainer {
class TypeContainer {
 public:
  TypeContainer() = default;
  TypeContainer(const TypeContainer &type_container) = default;
  auto operator=(
      const TypeContainer &type_container) -> TypeContainer & = default;
  explicit TypeContainer(const SpeciesNames &species_name);
  auto FirstType() const -> TypeNames;
  auto SecondType() const -> TypeNames;

 private:
  std::pair<TypeNames, TypeNames> types_;
};

// add blocks status

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TYPECONTAINER_H
