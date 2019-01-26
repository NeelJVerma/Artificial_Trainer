//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_STRINGCONVERTER_H
#define ARTIFICIAL_TRAINER_STRINGCONVERTER_H

#include <string>
#include "../pokemon/species.h"
#include "../stat/statnames.h"

namespace artificialtrainer {
auto SpeciesToString(const Species &species) -> std::string;
auto StatToString(const StatNames &stat_name) -> std::string;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STRINGCONVERTER_H
