#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <fstream>
#include <string>
#include <crypto++/sha3.h>
#include <crypto++/md5.h>
#include <crypto++/hex.h>
#include <crypto++/filters.h>

using namespace std;
using namespace CryptoPP;

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
    SHA3_256 sha3;
    string hashed_string;
    StringSource(input, true, new HashFilter(sha3, new HexEncoder(new StringSink(hashed_string))));
    return hashed_string;
  }
};

class MD5Hashing : public Hashing {
public:
  MD5Hashing() {}
  virtual ~MD5Hashing() {}
  virtual string hash(const string &input) {
    MD5 md5;
    string hashed_string;
    StringSource(input, true, new HashFilter(md5, new HexEncoder(new StringSink(hashed_string))));
    return hashed_string;
  }
};

#endif // HASHING_H

