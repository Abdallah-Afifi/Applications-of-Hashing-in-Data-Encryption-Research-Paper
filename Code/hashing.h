#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Hashing {
public:
  Hashing() {}
  virtual ~Hashing() {}
  virtual string hash(const string &input) = 0;
};

class SHA3Hashing : public Hashing {
public:
  SHA3Hashing() {}
  virtual ~SHA3Hashing() {}
  virtual string hash(const string &input) {
    // SHA-3 hashing algorithm
    // ...
    return hashed_string;
  }

private:
  string hashed_string;
};

class MD5Hashing : public Hashing {
public:
  MD5Hashing() {}
  virtual ~MD5Hashing() {}
  virtual string hash(const string &input) {
    // MD5 hashing algorithm
    // ...
    return hashed_string;
  }

private:
  string hashed_string;
};

#endif // HASHING_H
