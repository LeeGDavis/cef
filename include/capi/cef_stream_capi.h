// Copyright (c) 2024 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
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
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=f55fa17800b9a63d128fb78201372754f9250875$
//

#ifndef CEF_INCLUDE_CAPI_CEF_STREAM_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_STREAM_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
/// Structure the client can implement to provide a custom stream reader. The
/// functions of this structure may be called on any thread.
///
typedef struct _cef_read_handler_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Read raw binary data.
  ///
  size_t(CEF_CALLBACK* read)(struct _cef_read_handler_t* self,
                             void* ptr,
                             size_t size,
                             size_t n);

  ///
  /// Seek to the specified offset position. |whence| may be any one of
  /// SEEK_CUR, SEEK_END or SEEK_SET. Return zero on success and non-zero on
  /// failure.
  ///
  int(CEF_CALLBACK* seek)(struct _cef_read_handler_t* self,
                          int64_t offset,
                          int whence);

  ///
  /// Return the current offset position.
  ///
  int64_t(CEF_CALLBACK* tell)(struct _cef_read_handler_t* self);

  ///
  /// Return non-zero if at end of file.
  ///
  int(CEF_CALLBACK* eof)(struct _cef_read_handler_t* self);

  ///
  /// Return true (1) if this handler performs work like accessing the file
  /// system which may block. Used as a hint for determining the thread to
  /// access the handler from.
  ///
  int(CEF_CALLBACK* may_block)(struct _cef_read_handler_t* self);
} cef_read_handler_t;

///
/// Structure used to read data from a stream. The functions of this structure
/// may be called on any thread.
///
typedef struct _cef_stream_reader_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Read raw binary data.
  ///
  size_t(CEF_CALLBACK* read)(struct _cef_stream_reader_t* self,
                             void* ptr,
                             size_t size,
                             size_t n);

  ///
  /// Seek to the specified offset position. |whence| may be any one of
  /// SEEK_CUR, SEEK_END or SEEK_SET. Returns zero on success and non-zero on
  /// failure.
  ///
  int(CEF_CALLBACK* seek)(struct _cef_stream_reader_t* self,
                          int64_t offset,
                          int whence);

  ///
  /// Return the current offset position.
  ///
  int64_t(CEF_CALLBACK* tell)(struct _cef_stream_reader_t* self);

  ///
  /// Return non-zero if at end of file.
  ///
  int(CEF_CALLBACK* eof)(struct _cef_stream_reader_t* self);

  ///
  /// Returns true (1) if this reader performs work like accessing the file
  /// system which may block. Used as a hint for determining the thread to
  /// access the reader from.
  ///
  int(CEF_CALLBACK* may_block)(struct _cef_stream_reader_t* self);
} cef_stream_reader_t;

///
/// Create a new cef_stream_reader_t object from a file.
///
CEF_EXPORT cef_stream_reader_t* cef_stream_reader_create_for_file(
    const cef_string_t* fileName);

///
/// Create a new cef_stream_reader_t object from data.
///
CEF_EXPORT cef_stream_reader_t* cef_stream_reader_create_for_data(void* data,
                                                                  size_t size);

///
/// Create a new cef_stream_reader_t object from a custom handler.
///
CEF_EXPORT cef_stream_reader_t* cef_stream_reader_create_for_handler(
    cef_read_handler_t* handler);

///
/// Structure the client can implement to provide a custom stream writer. The
/// functions of this structure may be called on any thread.
///
typedef struct _cef_write_handler_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Write raw binary data.
  ///
  size_t(CEF_CALLBACK* write)(struct _cef_write_handler_t* self,
                              const void* ptr,
                              size_t size,
                              size_t n);

  ///
  /// Seek to the specified offset position. |whence| may be any one of
  /// SEEK_CUR, SEEK_END or SEEK_SET. Return zero on success and non-zero on
  /// failure.
  ///
  int(CEF_CALLBACK* seek)(struct _cef_write_handler_t* self,
                          int64_t offset,
                          int whence);

  ///
  /// Return the current offset position.
  ///
  int64_t(CEF_CALLBACK* tell)(struct _cef_write_handler_t* self);

  ///
  /// Flush the stream.
  ///
  int(CEF_CALLBACK* flush)(struct _cef_write_handler_t* self);

  ///
  /// Return true (1) if this handler performs work like accessing the file
  /// system which may block. Used as a hint for determining the thread to
  /// access the handler from.
  ///
  int(CEF_CALLBACK* may_block)(struct _cef_write_handler_t* self);
} cef_write_handler_t;

///
/// Structure used to write data to a stream. The functions of this structure
/// may be called on any thread.
///
typedef struct _cef_stream_writer_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Write raw binary data.
  ///
  size_t(CEF_CALLBACK* write)(struct _cef_stream_writer_t* self,
                              const void* ptr,
                              size_t size,
                              size_t n);

  ///
  /// Seek to the specified offset position. |whence| may be any one of
  /// SEEK_CUR, SEEK_END or SEEK_SET. Returns zero on success and non-zero on
  /// failure.
  ///
  int(CEF_CALLBACK* seek)(struct _cef_stream_writer_t* self,
                          int64_t offset,
                          int whence);

  ///
  /// Return the current offset position.
  ///
  int64_t(CEF_CALLBACK* tell)(struct _cef_stream_writer_t* self);

  ///
  /// Flush the stream.
  ///
  int(CEF_CALLBACK* flush)(struct _cef_stream_writer_t* self);

  ///
  /// Returns true (1) if this writer performs work like accessing the file
  /// system which may block. Used as a hint for determining the thread to
  /// access the writer from.
  ///
  int(CEF_CALLBACK* may_block)(struct _cef_stream_writer_t* self);
} cef_stream_writer_t;

///
/// Create a new cef_stream_writer_t object for a file.
///
CEF_EXPORT cef_stream_writer_t* cef_stream_writer_create_for_file(
    const cef_string_t* fileName);

///
/// Create a new cef_stream_writer_t object for a custom handler.
///
CEF_EXPORT cef_stream_writer_t* cef_stream_writer_create_for_handler(
    cef_write_handler_t* handler);

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_STREAM_CAPI_H_
