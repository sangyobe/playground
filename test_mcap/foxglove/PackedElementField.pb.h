// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/PackedElementField.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_foxglove_2fPackedElementField_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_foxglove_2fPackedElementField_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_foxglove_2fPackedElementField_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_foxglove_2fPackedElementField_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_foxglove_2fPackedElementField_2eproto;
namespace foxglove {
class PackedElementField;
struct PackedElementFieldDefaultTypeInternal;
extern PackedElementFieldDefaultTypeInternal _PackedElementField_default_instance_;
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> ::foxglove::PackedElementField* Arena::CreateMaybeMessage<::foxglove::PackedElementField>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace foxglove {

enum PackedElementField_NumericType : int {
  PackedElementField_NumericType_UNKNOWN = 0,
  PackedElementField_NumericType_UINT8 = 1,
  PackedElementField_NumericType_INT8 = 2,
  PackedElementField_NumericType_UINT16 = 3,
  PackedElementField_NumericType_INT16 = 4,
  PackedElementField_NumericType_UINT32 = 5,
  PackedElementField_NumericType_INT32 = 6,
  PackedElementField_NumericType_FLOAT32 = 7,
  PackedElementField_NumericType_FLOAT64 = 8,
  PackedElementField_NumericType_PackedElementField_NumericType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PackedElementField_NumericType_PackedElementField_NumericType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PackedElementField_NumericType_IsValid(int value);
constexpr PackedElementField_NumericType PackedElementField_NumericType_NumericType_MIN = PackedElementField_NumericType_UNKNOWN;
constexpr PackedElementField_NumericType PackedElementField_NumericType_NumericType_MAX = PackedElementField_NumericType_FLOAT64;
constexpr int PackedElementField_NumericType_NumericType_ARRAYSIZE = PackedElementField_NumericType_NumericType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PackedElementField_NumericType_descriptor();
template<typename T>
inline const std::string& PackedElementField_NumericType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PackedElementField_NumericType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PackedElementField_NumericType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PackedElementField_NumericType_descriptor(), enum_t_value);
}
inline bool PackedElementField_NumericType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PackedElementField_NumericType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PackedElementField_NumericType>(
    PackedElementField_NumericType_descriptor(), name, value);
}
// ===================================================================

class PackedElementField final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:foxglove.PackedElementField) */ {
 public:
  inline PackedElementField() : PackedElementField(nullptr) {}
  ~PackedElementField() override;
  explicit PROTOBUF_CONSTEXPR PackedElementField(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PackedElementField(const PackedElementField& from);
  PackedElementField(PackedElementField&& from) noexcept
    : PackedElementField() {
    *this = ::std::move(from);
  }

  inline PackedElementField& operator=(const PackedElementField& from) {
    CopyFrom(from);
    return *this;
  }
  inline PackedElementField& operator=(PackedElementField&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PackedElementField& default_instance() {
    return *internal_default_instance();
  }
  static inline const PackedElementField* internal_default_instance() {
    return reinterpret_cast<const PackedElementField*>(
               &_PackedElementField_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PackedElementField& a, PackedElementField& b) {
    a.Swap(&b);
  }
  inline void Swap(PackedElementField* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PackedElementField* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PackedElementField* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PackedElementField>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PackedElementField& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const PackedElementField& from) {
    PackedElementField::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PackedElementField* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "foxglove.PackedElementField";
  }
  protected:
  explicit PackedElementField(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef PackedElementField_NumericType NumericType;
  static constexpr NumericType UNKNOWN =
    PackedElementField_NumericType_UNKNOWN;
  static constexpr NumericType UINT8 =
    PackedElementField_NumericType_UINT8;
  static constexpr NumericType INT8 =
    PackedElementField_NumericType_INT8;
  static constexpr NumericType UINT16 =
    PackedElementField_NumericType_UINT16;
  static constexpr NumericType INT16 =
    PackedElementField_NumericType_INT16;
  static constexpr NumericType UINT32 =
    PackedElementField_NumericType_UINT32;
  static constexpr NumericType INT32 =
    PackedElementField_NumericType_INT32;
  static constexpr NumericType FLOAT32 =
    PackedElementField_NumericType_FLOAT32;
  static constexpr NumericType FLOAT64 =
    PackedElementField_NumericType_FLOAT64;
  static inline bool NumericType_IsValid(int value) {
    return PackedElementField_NumericType_IsValid(value);
  }
  static constexpr NumericType NumericType_MIN =
    PackedElementField_NumericType_NumericType_MIN;
  static constexpr NumericType NumericType_MAX =
    PackedElementField_NumericType_NumericType_MAX;
  static constexpr int NumericType_ARRAYSIZE =
    PackedElementField_NumericType_NumericType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  NumericType_descriptor() {
    return PackedElementField_NumericType_descriptor();
  }
  template<typename T>
  static inline const std::string& NumericType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, NumericType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function NumericType_Name.");
    return PackedElementField_NumericType_Name(enum_t_value);
  }
  static inline bool NumericType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      NumericType* value) {
    return PackedElementField_NumericType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kOffsetFieldNumber = 2,
    kTypeFieldNumber = 3,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // fixed32 offset = 2;
  void clear_offset();
  uint32_t offset() const;
  void set_offset(uint32_t value);
  private:
  uint32_t _internal_offset() const;
  void _internal_set_offset(uint32_t value);
  public:

  // .foxglove.PackedElementField.NumericType type = 3;
  void clear_type();
  ::foxglove::PackedElementField_NumericType type() const;
  void set_type(::foxglove::PackedElementField_NumericType value);
  private:
  ::foxglove::PackedElementField_NumericType _internal_type() const;
  void _internal_set_type(::foxglove::PackedElementField_NumericType value);
  public:

  // @@protoc_insertion_point(class_scope:foxglove.PackedElementField)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    uint32_t offset_;
    int type_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_foxglove_2fPackedElementField_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PackedElementField

// string name = 1;
inline void PackedElementField::clear_name() {
  _impl_.name_.ClearToEmpty();
}
inline const std::string& PackedElementField::name() const {
  // @@protoc_insertion_point(field_get:foxglove.PackedElementField.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PackedElementField::set_name(ArgT0&& arg0, ArgT... args) {
 
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:foxglove.PackedElementField.name)
}
inline std::string* PackedElementField::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:foxglove.PackedElementField.name)
  return _s;
}
inline const std::string& PackedElementField::_internal_name() const {
  return _impl_.name_.Get();
}
inline void PackedElementField::_internal_set_name(const std::string& value) {
  
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* PackedElementField::_internal_mutable_name() {
  
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* PackedElementField::release_name() {
  // @@protoc_insertion_point(field_release:foxglove.PackedElementField.name)
  return _impl_.name_.Release();
}
inline void PackedElementField::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:foxglove.PackedElementField.name)
}

// fixed32 offset = 2;
inline void PackedElementField::clear_offset() {
  _impl_.offset_ = 0u;
}
inline uint32_t PackedElementField::_internal_offset() const {
  return _impl_.offset_;
}
inline uint32_t PackedElementField::offset() const {
  // @@protoc_insertion_point(field_get:foxglove.PackedElementField.offset)
  return _internal_offset();
}
inline void PackedElementField::_internal_set_offset(uint32_t value) {
  
  _impl_.offset_ = value;
}
inline void PackedElementField::set_offset(uint32_t value) {
  _internal_set_offset(value);
  // @@protoc_insertion_point(field_set:foxglove.PackedElementField.offset)
}

// .foxglove.PackedElementField.NumericType type = 3;
inline void PackedElementField::clear_type() {
  _impl_.type_ = 0;
}
inline ::foxglove::PackedElementField_NumericType PackedElementField::_internal_type() const {
  return static_cast< ::foxglove::PackedElementField_NumericType >(_impl_.type_);
}
inline ::foxglove::PackedElementField_NumericType PackedElementField::type() const {
  // @@protoc_insertion_point(field_get:foxglove.PackedElementField.type)
  return _internal_type();
}
inline void PackedElementField::_internal_set_type(::foxglove::PackedElementField_NumericType value) {
  
  _impl_.type_ = value;
}
inline void PackedElementField::set_type(::foxglove::PackedElementField_NumericType value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:foxglove.PackedElementField.type)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace foxglove

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::foxglove::PackedElementField_NumericType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::foxglove::PackedElementField_NumericType>() {
  return ::foxglove::PackedElementField_NumericType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_foxglove_2fPackedElementField_2eproto
