// Copyright (c) 2013, Kenton Varda <temporal@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef CAPNPROTO_TEST_UTIL_H_
#define CAPNPROTO_TEST_UTIL_H_

#include "test.capnp.h"
#include <iostream>
#include "blob.h"

namespace capnproto {

inline std::ostream& operator<<(std::ostream& os, const Data::Reader& value) {
  return os.write(value.data(), value.size());
}
inline std::ostream& operator<<(std::ostream& os, const Data::Builder& value) {
  return os.write(value.data(), value.size());
}
inline std::ostream& operator<<(std::ostream& os, const Text::Reader& value) {
  return os.write(value.data(), value.size());
}
inline std::ostream& operator<<(std::ostream& os, const Text::Builder& value) {
  return os.write(value.data(), value.size());
}
inline std::ostream& operator<<(std::ostream& os, Void) {
  return os << "void";
}

namespace internal {

// Explicitly import each of these to make sure they're really located in capnproto::test and not,
// say, the global namespace.
using ::capnproto::test::TestAllTypes;
using ::capnproto::test::TestDefaults;
using ::capnproto::test::TestEnum;
using ::capnproto::test::TestUnion;
using ::capnproto::test::TestUnionDefaults;
using ::capnproto::test::TestNestedTypes;
using ::capnproto::test::TestUsing;
using ::capnproto::test::TestInlineLayout;
using ::capnproto::test::TestInlineUnions;
using ::capnproto::test::TestInlineDefaults;

void initTestMessage(test::TestAllTypes::Builder builder);
void initTestMessage(test::TestDefaults::Builder builder);

void checkTestMessage(test::TestAllTypes::Builder builder);
void checkTestMessage(test::TestDefaults::Builder builder);

void checkTestMessage(test::TestAllTypes::Reader reader);
void checkTestMessage(test::TestDefaults::Reader reader);

void checkTestMessageAllZero(test::TestAllTypes::Builder builder);
void checkTestMessageAllZero(test::TestAllTypes::Reader reader);

}  // namespace internal
}  // namespace capnproto

#endif  // TEST_UTIL_H_