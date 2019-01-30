//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_STRINGCONVERTER_H
#define ARTIFICIAL_TRAINER_STRINGCONVERTER_H

#include <string>
#include "../pokemon/speciesnames.h"
#include "../stat/statnames.h"
#include "../move/movenames.h"
#include "../type/type.h"

namespace artificialtrainer {
class StringConverter {
 public:
  static auto SpeciesToString(const SpeciesNames &species_name) -> std::string;
  static auto StatToString(const StatNames &stat_name) -> std::string;
  static auto MoveToString(const MoveNames &move_name) -> std::string;
  static auto TypeToString(const TypeNames &type_name) -> std::string;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STRINGCONVERTER_H
