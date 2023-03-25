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

// Rust Protobuf runtime using the C++ kernel.

use std::boxed::Box;
use std::ops::Deref;
use std::ptr::NonNull;
use std::slice;

/// TODO(b/272728844): Replace this placeholder code with a real implementation.
#[repr(C)]
pub struct Arena {
    _data: [u8; 0],
}

impl Arena {
    pub unsafe fn new() -> *mut Self {
        let arena = Box::new(Arena { _data: [] });
        Box::leak(arena) as *mut _
    }

    pub unsafe fn free(arena: *mut Self) {
        let arena = Box::from_raw(arena);
        std::mem::drop(arena);
    }
}

/// Represents serialized Protobuf wire format data. It's typically produced by
/// `<Message>.serialize()`.
///
/// This stuct is ABI compatible with the equivalend struct on the C++ side.
// copybara:strip_begin
// LINT.IfChange
// copybara:strip_end
#[repr(C)]
#[derive(Debug)]
pub struct SerializedData {
    data: NonNull<u8>,
    len: usize,
}
// copybara:strip_begin
// LINT.ThenChange(//depot/google3/third_party/protobuf/rust/cpp_kernel/cpp.h)
// copybara:strip_end

impl Deref for SerializedData {
    type Target = [u8];
    fn deref(&self) -> &Self::Target {
        unsafe { slice::from_raw_parts(self.data.as_ptr() as *const _, self.len) }
    }
}
