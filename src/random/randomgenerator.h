/**
 * @project Artificial Trainer
 * @brief Functions to get random int and real numbers from a distribution.
 *
 * @file randomgenerator.h
 * @author Neel Verma
 * @date 3/30/19
 */

#ifndef ARTIFICIAL_TRAINER_RANDOMGENERATOR_H
#define ARTIFICIAL_TRAINER_RANDOMGENERATOR_H

namespace artificialtrainer {
double RandomRealDistribution(const double& lower, const double& upper);
int RandomIntDistribution(const int &lower, const int &upper);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_RANDOMGENERATOR_H
