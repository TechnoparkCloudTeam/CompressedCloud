// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_message_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_message_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_message_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_message_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_message_2eproto;
namespace messageFS {
class Request;
class RequestDefaultTypeInternal;
extern RequestDefaultTypeInternal _Request_default_instance_;
}  // namespace messageFS
PROTOBUF_NAMESPACE_OPEN
template<> ::messageFS::Request* Arena::CreateMaybeMessage<::messageFS::Request>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace messageFS {

// ===================================================================

class Request PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:messageFS.Request) */ {
 public:
  inline Request() : Request(nullptr) {};
  virtual ~Request();

  Request(const Request& from);
  Request(Request&& from) noexcept
    : Request() {
    *this = ::std::move(from);
  }

  inline Request& operator=(const Request& from) {
    CopyFrom(from);
    return *this;
  }
  inline Request& operator=(Request&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Request& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Request* internal_default_instance() {
    return reinterpret_cast<const Request*>(
               &_Request_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Request& a, Request& b) {
    a.Swap(&b);
  }
  inline void Swap(Request* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Request* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Request* New() const final {
    return CreateMaybeMessage<Request>(nullptr);
  }

  Request* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Request>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Request& from);
  void MergeFrom(const Request& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Request* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "messageFS.Request";
  }
  protected:
  explicit Request(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_message_2eproto);
    return ::descriptor_table_message_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 2,
    kFileFieldNumber = 3,
    kIdFieldNumber = 1,
  };
  // string name = 2;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // string file = 3;
  void clear_file();
  const std::string& file() const;
  void set_file(const std::string& value);
  void set_file(std::string&& value);
  void set_file(const char* value);
  void set_file(const char* value, size_t size);
  std::string* mutable_file();
  std::string* release_file();
  void set_allocated_file(std::string* file);
  private:
  const std::string& _internal_file() const;
  void _internal_set_file(const std::string& value);
  std::string* _internal_mutable_file();
  public:

  // int32 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::int32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:messageFS.Request)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr file_;
  ::PROTOBUF_NAMESPACE_ID::int32 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_message_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Request

// int32 id = 1;
inline void Request::clear_id() {
  id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Request::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Request::id() const {
  // @@protoc_insertion_point(field_get:messageFS.Request.id)
  return _internal_id();
}
inline void Request::_internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  id_ = value;
}
inline void Request::set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:messageFS.Request.id)
}

// string name = 2;
inline void Request::clear_name() {
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Request::name() const {
  // @@protoc_insertion_point(field_get:messageFS.Request.name)
  return _internal_name();
}
inline void Request::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:messageFS.Request.name)
}
inline std::string* Request::mutable_name() {
  // @@protoc_insertion_point(field_mutable:messageFS.Request.name)
  return _internal_mutable_name();
}
inline const std::string& Request::_internal_name() const {
  return name_.Get();
}
inline void Request::_internal_set_name(const std::string& value) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Request::set_name(std::string&& value) {
  
  name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:messageFS.Request.name)
}
inline void Request::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:messageFS.Request.name)
}
inline void Request::set_name(const char* value,
    size_t size) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:messageFS.Request.name)
}
inline std::string* Request::_internal_mutable_name() {
  
  return name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Request::release_name() {
  // @@protoc_insertion_point(field_release:messageFS.Request.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Request::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:messageFS.Request.name)
}

// string file = 3;
inline void Request::clear_file() {
  file_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Request::file() const {
  // @@protoc_insertion_point(field_get:messageFS.Request.file)
  return _internal_file();
}
inline void Request::set_file(const std::string& value) {
  _internal_set_file(value);
  // @@protoc_insertion_point(field_set:messageFS.Request.file)
}
inline std::string* Request::mutable_file() {
  // @@protoc_insertion_point(field_mutable:messageFS.Request.file)
  return _internal_mutable_file();
}
inline const std::string& Request::_internal_file() const {
  return file_.Get();
}
inline void Request::_internal_set_file(const std::string& value) {
  
  file_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Request::set_file(std::string&& value) {
  
  file_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:messageFS.Request.file)
}
inline void Request::set_file(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  file_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:messageFS.Request.file)
}
inline void Request::set_file(const char* value,
    size_t size) {
  
  file_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:messageFS.Request.file)
}
inline std::string* Request::_internal_mutable_file() {
  
  return file_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Request::release_file() {
  // @@protoc_insertion_point(field_release:messageFS.Request.file)
  return file_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Request::set_allocated_file(std::string* file) {
  if (file != nullptr) {
    
  } else {
    
  }
  file_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), file,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:messageFS.Request.file)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace messageFS

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_message_2eproto
