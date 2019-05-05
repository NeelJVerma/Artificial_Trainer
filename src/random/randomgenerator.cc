/**
 * @project Artificial Trainer
 * @brief Implementation of functions to get random int and real numbers from a
 * distribution.
 *
 * @file randomgenerator.cc
 * @author Neel Verma
 * @date 3/30/19
 */

#include <random>

namespace artificialtrainer {
namespace {

/**
  * @brief: A function that returns a random generator.
  * @return std::mt19937&: The random generator.
  */

std::mt19937& RandomGenerator() {
  static std::random_device device;
  static std::mt19937 generator(device());
  return generator;
}

} //namespace

/**
  * @brief: A function to return a random real number from a range.
  * @param const double &lower: The lower bound of the range.
  * @param const double &upper: The upper bound of the range.
  * @return double: The random real number.
  */

double RandomRealDistribution(const double& lower, const double& upper) {
  std::uniform_real_distribution<> distribution(lower, upper);
  return distribution(RandomGenerator());
}

/**
  * @brief: A function to return a random integer from a range.
  * @param const int &lower: The lower bound of the range.
  * @param const int &upper: The upper bound of the range.
  * @return int: The random integer.
  */

int RandomIntDistribution(const int &lower, const int &upper) {
  std::uniform_int_distribution<> distribution(lower, upper);
  return distribution(RandomGenerator());
}

} //namespace artificialtrainer