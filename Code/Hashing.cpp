#include <iostream>
#include <fstream>
#include <string>
#include "hashing.h"

using namespace std;

int main() {
  // Read input from text file
  ifstream input_file("input.txt");
  string input;
  getline(input_file, input);

  // Create SHA-3 and MD5 hashing objects
  SHA3Hashing sha3_hashing;
  MD5Hashing md5_hashing;

  // Hash the input using SHA-3 and MD5
  string sha3_hash = sha3_hashing.hash(input);
  string md5_hash = md5_hashing.hash(input);

  // Write the hashed output to text file
  ofstream output_file("output.txt");
  output_file << "SHA-3 hash: " << sha3_hash << endl;
  output_file << "MD5 hash: " << md5_hash << endl;

  // Compare the two algorithms based on the time it takes them to hash a sentence
  auto start = chrono::high_resolution_clock::now();
  sha3_hashing.hash(input);
  auto end = chrono::high_resolution_clock::now();
  auto sha3_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

  start = chrono::high_resolution_clock::now();
  md5_hashing.hash(input);
  end = chrono::high_resolution_clock::now();
  auto md5_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

  cout << "SHA-3 took " << sha3_time << " milliseconds to hash the sentence." << endl;
  cout << "MD5 took " << md5_time << " milliseconds to hash the sentence." << endl;

  return 0;
}
