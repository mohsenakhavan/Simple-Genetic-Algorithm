#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

// Define the chromosome as a vector of doubles
using Chromosome = std::vector<double>;

// Function to optimize (you can change this to any function)
double fitness_function(const Chromosome& chromosome) {
    // Example: f(x, y) = -(x^2 + y^2)
    return -(std::pow(chromosome[0], 2) + std::pow(chromosome[1], 2));
}

class GeneticAlgorithm {
private:
    std::vector<Chromosome> population;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
    int pop_size;
    int chromosome_length;
    double mutation_rate;
    int generations;

public:
    GeneticAlgorithm(int pop_size, int chromosome_length, double mutation_rate, int generations)
        : pop_size(pop_size), chromosome_length(chromosome_length), 
          mutation_rate(mutation_rate), generations(generations),
          gen(std::random_device{}()), dis(-10.0, 10.0) {
        // Initialize population
        for (int i = 0; i < pop_size; ++i) {
            Chromosome chromosome;
            for (int j = 0; j < chromosome_length; ++j) {
                chromosome.push_back(dis(gen));
            }
            population.push_back(chromosome);
        }
    }

    Chromosome select_parent() {
        // Tournament selection
        int a = std::uniform_int_distribution<>(0, pop_size - 1)(gen);
        int b = std::uniform_int_distribution<>(0, pop_size - 1)(gen);
        return (fitness_function(population[a]) > fitness_function(population[b])) 
               ? population[a] : population[b];
    }

    Chromosome crossover(const Chromosome& parent1, const Chromosome& parent2) {
        // Single-point crossover
        int point = std::uniform_int_distribution<>(1, chromosome_length - 1)(gen);
        Chromosome child = parent1;
        for (int i = point; i < chromosome_length; ++i) {
            child[i] = parent2[i];
        }
        return child;
    }

    void mutate(Chromosome& chromosome) {
        for (double& gene : chromosome) {
            if (std::uniform_real_distribution<>(0.0, 1.0)(gen) < mutation_rate) {
                gene = dis(gen);
            }
        }
    }

    void evolve() {
        for (int gen = 0; gen < generations; ++gen) {
            std::vector<Chromosome> new_population;

            // Elitism: keep the best individual
            auto best = std::max_element(population.begin(), population.end(),
                [](const Chromosome& a, const Chromosome& b) {
                    return fitness_function(a) < fitness_function(b);
                });
            new_population.push_back(*best);

            while (new_population.size() < pop_size) {
                Chromosome parent1 = select_parent();
                Chromosome parent2 = select_parent();
                Chromosome child = crossover(parent1, parent2);
                mutate(child);
                new_population.push_back(child);
            }

            population = new_population;

            // Print the best fitness in this generation
            std::cout << "Generation " << gen << ", Best fitness: " 
                      << fitness_function(*best) << std::endl;
        }
    }

    Chromosome get_best_solution() {
        return *std::max_element(population.begin(), population.end(),
            [](const Chromosome& a, const Chromosome& b) {
                return fitness_function(a) < fitness_function(b);
            });
    }
};

int main() {
    GeneticAlgorithm ga(100, 2, 0.01, 100);
    ga.evolve();

    Chromosome best_solution = ga.get_best_solution();
    std::cout << "Best solution found: (" << best_solution[0] << ", " << best_solution[1] << ")" << std::endl;
    std::cout << "Fitness: " << fitness_function(best_solution) << std::endl;

    return 0;
}