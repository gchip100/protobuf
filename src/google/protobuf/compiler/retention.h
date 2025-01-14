// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef GOOGLE_PROTOBUF_COMPILER_RETENTION_H__
#define GOOGLE_PROTOBUF_COMPILER_RETENTION_H__

#include "google/protobuf/descriptor.h"
#include "google/protobuf/descriptor.pb.h"

// Must appear last
#include "google/protobuf/port_def.inc"

namespace google {
namespace protobuf {
namespace compiler {

// Returns a FileDescriptorProto for this file, with all RETENTION_SOURCE
// options stripped out. If include_source_code_info is true, this function
// will also populate the source code info but strip out the parts of it
// corresponding to source-retention options.
PROTOC_EXPORT FileDescriptorProto StripSourceRetentionOptions(
    const FileDescriptor& file, bool include_source_code_info = false);

// The following functions take a descriptor and strip all source-retention
// options from just the local entity (e.g. message, enum, field). Most code
// generators should not need these functions, but they are sometimes useful if
// you need to strip the options on a single entity rather than handling the
// entire file at once.
PROTOC_EXPORT EnumOptions
StripLocalSourceRetentionOptions(const EnumDescriptor& descriptor);
PROTOC_EXPORT EnumValueOptions
StripLocalSourceRetentionOptions(const EnumValueDescriptor& descriptor);
PROTOC_EXPORT FieldOptions
StripLocalSourceRetentionOptions(const FieldDescriptor& descriptor);
PROTOC_EXPORT FileOptions
StripLocalSourceRetentionOptions(const FileDescriptor& descriptor);
PROTOC_EXPORT MessageOptions
StripLocalSourceRetentionOptions(const Descriptor& descriptor);
PROTOC_EXPORT MethodOptions
StripLocalSourceRetentionOptions(const MethodDescriptor& descriptor);
PROTOC_EXPORT OneofOptions
StripLocalSourceRetentionOptions(const OneofDescriptor& descriptor);
PROTOC_EXPORT ServiceOptions
StripLocalSourceRetentionOptions(const ServiceDescriptor& descriptor);

}  // namespace compiler
}  // namespace protobuf
}  // namespace google

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_COMPILER_RETENTION_H__
