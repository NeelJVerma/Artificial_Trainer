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
  static std::string SpeciesToString(const SpeciesNames &species_name);
  static std::string StatToString(const StatNames &stat_name);
  static std::string MoveToString(const MoveNames &move_name);
  static std::string TypeToString(const TypeNames &type_name);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STRINGCONVERTER_H
