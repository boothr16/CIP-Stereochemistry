# CIP-Stereochemistry

## Introduction
This repository features a minimum-working example of an application that determines the stereochemical configuration (R, S, or achiral) of small molecules. The initial scope of this project was limited to molecules comprised of a tetrahedral carbon atom bonded to 4 monatomic substituents (see TO DO section of this README for my ideas on how I would scale up this project for larger molecules). To determine the stereochemical configuration, the Cahn-Ingold-Prelog (CIP) method is implemented using object-oriented design. Results acquired from this application are compared to Wiley's ChemWindow structure drawing software, which predicts R/S stereochemistry from 2D drawings.

The general idea:
1. Accept and validate user inputs from the command line (user enters the atomic symbols of the substituents).
2. A tetrahedral object is constructed from the user input.
3. Each substituent is assigned a priority using the Cahn-Ingold-Prelog method.
4. Based on the priorities assigned, a trigonal projection object is constructed.
5. Stereochemical configuration is determined from the trigonal projection of the tetrahedral geometry.

## Dependencies
* C++ compiler (GCC, clang, etc.)
* GNU Make

## How to compile and run application
1. `git clone` this repository.
2. `cd` into the cloned CIP-Stereochemistry directory.
3. Compile project using `make` from the command line.
4. Use `./cip <substituent atom 1> <substituent atom 2> <substituent atom 3> <substituent atom 4>` from the command line. Refer to the examples below to see how the substituents map to atom positions.
* `make clean` can be used to clean up the directory.

## Example input and output

**NOTE: All images were taken and output verified from Wiley's ChemWindow software.**

### Example 1

![test1](https://user-images.githubusercontent.com/49886228/149854526-ffb7d39d-2b00-4d1f-b7ed-c08b20652a96.png)
![cmd1](https://user-images.githubusercontent.com/49886228/149854517-450e0d0a-3e3c-4a88-9b31-a6a89f43a59e.png)

### Example 2

![test2](https://user-images.githubusercontent.com/49886228/149854528-748e36d6-17e9-48c9-b8dc-9e7cceeee741.png)
![cmd2](https://user-images.githubusercontent.com/49886228/149854519-94876df4-becf-499d-8ac0-1435d48ded23.png)

### Example 3

![test3](https://user-images.githubusercontent.com/49886228/149854529-57ee2b1e-c77d-434a-b759-681fe3ff47a4.png)
![cmd3](https://user-images.githubusercontent.com/49886228/149854520-26129ea8-0b80-49ea-8f2e-0d13d29377b9.png)

### Example 4

![test 4](https://user-images.githubusercontent.com/49886228/149854525-4dfad2bb-926c-4471-b91f-6a43153636dd.png)
![cmd4](https://user-images.githubusercontent.com/49886228/149854522-e2f757ec-43dc-45c0-9c9a-bce867aca1c1.png)

### Example 5

![test5](https://user-images.githubusercontent.com/49886228/149854530-bd063f43-8787-4cf7-8f64-d21c528637c3.png)
![cmd5](https://user-images.githubusercontent.com/49886228/149854523-d90682a3-f86d-441a-aefa-39c102ea814d.png)

### Example 6

![test6](https://user-images.githubusercontent.com/49886228/149854531-41865051-0380-4cb8-8dda-cbe888231846.png)
![cmd6](https://user-images.githubusercontent.com/49886228/149854524-c436265f-739a-4847-8bbd-b4ea49d82236.png)

## TO DO
1. Scale this application up for larger molecules containing polyatomic substituents like alkyl chains, amine groups, hydroxyl groups, etc. Here are some changes I would make to this application's design:
  1. Represent the molecule as a directed graph of AtomNode objects.
  2. Use smart pointers in place of raw pointers. Specifically, `shared_ptr`'s `use_count()` can be used to track the number of substituents bonded to a particular atom.
  3. Design a recursive method to assign priorities and determine stereochemistry for all tetrahedral geometries in the molecule. Perhaps use depth-first search to traverse the backbone of large molecules to determine priorities in the case of a tiebreaker (chiral molecules cannot have two bonding groups of equal priority, so in the case of a tie, the next atom in the chain should be compared).
