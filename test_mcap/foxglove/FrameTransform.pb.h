// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/FrameTransform.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_foxglove_2fFrameTransform_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_foxglove_2fFrameTransform_2eproto

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
#include <google/protobuf/unknown_field_set.h>
#include "foxglove/Quaternion.pb.h"
#include "foxglove/Vector3.pb.h"
#include <google/protobuf/timestamp.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_foxglove_2fFrameTransform_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_foxglove_2fFrameTransform_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_foxglove_2fFrameTransform_2eproto;
namespace foxglove {
class FrameTransform;
struct FrameTransformDefaultTypeInternal;
extern FrameTransformDefaultTypeInternal _FrameTransform_default_instance_;
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> ::foxglove::FrameTransform* Arena::CreateMaybeMessage<::foxglove::FrameTransform>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace foxglove {

// ===================================================================

class FrameTransform final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:foxglove.FrameTransform) */ {
 public:
  inline FrameTransform() : FrameTransform(nullptr) {}
  ~FrameTransform() override;
  explicit PROTOBUF_CONSTEXPR FrameTransform(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FrameTransform(const FrameTransform& from);
  FrameTransform(FrameTransform&& from) noexcept
    : FrameTransform() {
    *this = ::std::move(from);
  }

  inline FrameTransform& operator=(const FrameTransform& from) {
    CopyFrom(from);
    return *this;
  }
  inline FrameTransform& operator=(FrameTransform&& from) noexcept {
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
  static const FrameTransform& default_instance() {
    return *internal_default_instance();
  }
  static inline const FrameTransform* internal_default_instance() {
    return reinterpret_cast<const FrameTransform*>(
               &_FrameTransform_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FrameTransform& a, FrameTransform& b) {
    a.Swap(&b);
  }
  inline void Swap(FrameTransform* other) {
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
  void UnsafeArenaSwap(FrameTransform* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  FrameTransform* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<FrameTransform>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const FrameTransform& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const FrameTransform& from) {
    FrameTransform::MergeImpl(*this, from);
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
  void InternalSwap(FrameTransform* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "foxglove.FrameTransform";
  }
  protected:
  explicit FrameTransform(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kParentFrameIdFieldNumber = 2,
    kChildFrameIdFieldNumber = 3,
    kTimestampFieldNumber = 1,
    kTranslationFieldNumber = 4,
    kRotationFieldNumber = 5,
  };
  // string parent_frame_id = 2;
  void clear_parent_frame_id();
  const std::string& parent_frame_id() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_parent_frame_id(ArgT0&& arg0, ArgT... args);
  std::string* mutable_parent_frame_id();
  PROTOBUF_NODISCARD std::string* release_parent_frame_id();
  void set_allocated_parent_frame_id(std::string* parent_frame_id);
  private:
  const std::string& _internal_parent_frame_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_parent_frame_id(const std::string& value);
  std::string* _internal_mutable_parent_frame_id();
  public:

  // string child_frame_id = 3;
  void clear_child_frame_id();
  const std::string& child_frame_id() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_child_frame_id(ArgT0&& arg0, ArgT... args);
  std::string* mutable_child_frame_id();
  PROTOBUF_NODISCARD std::string* release_child_frame_id();
  void set_allocated_child_frame_id(std::string* child_frame_id);
  private:
  const std::string& _internal_child_frame_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_child_frame_id(const std::string& value);
  std::string* _internal_mutable_child_frame_id();
  public:

  // .google.protobuf.Timestamp timestamp = 1;
  bool has_timestamp() const;
  private:
  bool _internal_has_timestamp() const;
  public:
  void clear_timestamp();
  const ::PROTOBUF_NAMESPACE_ID::Timestamp& timestamp() const;
  PROTOBUF_NODISCARD ::PROTOBUF_NAMESPACE_ID::Timestamp* release_timestamp();
  ::PROTOBUF_NAMESPACE_ID::Timestamp* mutable_timestamp();
  void set_allocated_timestamp(::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp);
  private:
  const ::PROTOBUF_NAMESPACE_ID::Timestamp& _internal_timestamp() const;
  ::PROTOBUF_NAMESPACE_ID::Timestamp* _internal_mutable_timestamp();
  public:
  void unsafe_arena_set_allocated_timestamp(
      ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp);
  ::PROTOBUF_NAMESPACE_ID::Timestamp* unsafe_arena_release_timestamp();

  // .foxglove.Vector3 translation = 4;
  bool has_translation() const;
  private:
  bool _internal_has_translation() const;
  public:
  void clear_translation();
  const ::foxglove::Vector3& translation() const;
  PROTOBUF_NODISCARD ::foxglove::Vector3* release_translation();
  ::foxglove::Vector3* mutable_translation();
  void set_allocated_translation(::foxglove::Vector3* translation);
  private:
  const ::foxglove::Vector3& _internal_translation() const;
  ::foxglove::Vector3* _internal_mutable_translation();
  public:
  void unsafe_arena_set_allocated_translation(
      ::foxglove::Vector3* translation);
  ::foxglove::Vector3* unsafe_arena_release_translation();

  // .foxglove.Quaternion rotation = 5;
  bool has_rotation() const;
  private:
  bool _internal_has_rotation() const;
  public:
  void clear_rotation();
  const ::foxglove::Quaternion& rotation() const;
  PROTOBUF_NODISCARD ::foxglove::Quaternion* release_rotation();
  ::foxglove::Quaternion* mutable_rotation();
  void set_allocated_rotation(::foxglove::Quaternion* rotation);
  private:
  const ::foxglove::Quaternion& _internal_rotation() const;
  ::foxglove::Quaternion* _internal_mutable_rotation();
  public:
  void unsafe_arena_set_allocated_rotation(
      ::foxglove::Quaternion* rotation);
  ::foxglove::Quaternion* unsafe_arena_release_rotation();

  // @@protoc_insertion_point(class_scope:foxglove.FrameTransform)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr parent_frame_id_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr child_frame_id_;
    ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp_;
    ::foxglove::Vector3* translation_;
    ::foxglove::Quaternion* rotation_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_foxglove_2fFrameTransform_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FrameTransform

// .google.protobuf.Timestamp timestamp = 1;
inline bool FrameTransform::_internal_has_timestamp() const {
  return this != internal_default_instance() && _impl_.timestamp_ != nullptr;
}
inline bool FrameTransform::has_timestamp() const {
  return _internal_has_timestamp();
}
inline const ::PROTOBUF_NAMESPACE_ID::Timestamp& FrameTransform::_internal_timestamp() const {
  const ::PROTOBUF_NAMESPACE_ID::Timestamp* p = _impl_.timestamp_;
  return p != nullptr ? *p : reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Timestamp&>(
      ::PROTOBUF_NAMESPACE_ID::_Timestamp_default_instance_);
}
inline const ::PROTOBUF_NAMESPACE_ID::Timestamp& FrameTransform::timestamp() const {
  // @@protoc_insertion_point(field_get:foxglove.FrameTransform.timestamp)
  return _internal_timestamp();
}
inline void FrameTransform::unsafe_arena_set_allocated_timestamp(
    ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.timestamp_);
  }
  _impl_.timestamp_ = timestamp;
  if (timestamp) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.FrameTransform.timestamp)
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* FrameTransform::release_timestamp() {
  
  ::PROTOBUF_NAMESPACE_ID::Timestamp* temp = _impl_.timestamp_;
  _impl_.timestamp_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* FrameTransform::unsafe_arena_release_timestamp() {
  // @@protoc_insertion_point(field_release:foxglove.FrameTransform.timestamp)
  
  ::PROTOBUF_NAMESPACE_ID::Timestamp* temp = _impl_.timestamp_;
  _impl_.timestamp_ = nullptr;
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* FrameTransform::_internal_mutable_timestamp() {
  
  if (_impl_.timestamp_ == nullptr) {
    auto* p = CreateMaybeMessage<::PROTOBUF_NAMESPACE_ID::Timestamp>(GetArenaForAllocation());
    _impl_.timestamp_ = p;
  }
  return _impl_.timestamp_;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* FrameTransform::mutable_timestamp() {
  ::PROTOBUF_NAMESPACE_ID::Timestamp* _msg = _internal_mutable_timestamp();
  // @@protoc_insertion_point(field_mutable:foxglove.FrameTransform.timestamp)
  return _msg;
}
inline void FrameTransform::set_allocated_timestamp(::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.timestamp_);
  }
  if (timestamp) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(timestamp));
    if (message_arena != submessage_arena) {
      timestamp = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, timestamp, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.timestamp_ = timestamp;
  // @@protoc_insertion_point(field_set_allocated:foxglove.FrameTransform.timestamp)
}

// string parent_frame_id = 2;
inline void FrameTransform::clear_parent_frame_id() {
  _impl_.parent_frame_id_.ClearToEmpty();
}
inline const std::string& FrameTransform::parent_frame_id() const {
  // @@protoc_insertion_point(field_get:foxglove.FrameTransform.parent_frame_id)
  return _internal_parent_frame_id();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FrameTransform::set_parent_frame_id(ArgT0&& arg0, ArgT... args) {
 
 _impl_.parent_frame_id_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:foxglove.FrameTransform.parent_frame_id)
}
inline std::string* FrameTransform::mutable_parent_frame_id() {
  std::string* _s = _internal_mutable_parent_frame_id();
  // @@protoc_insertion_point(field_mutable:foxglove.FrameTransform.parent_frame_id)
  return _s;
}
inline const std::string& FrameTransform::_internal_parent_frame_id() const {
  return _impl_.parent_frame_id_.Get();
}
inline void FrameTransform::_internal_set_parent_frame_id(const std::string& value) {
  
  _impl_.parent_frame_id_.Set(value, GetArenaForAllocation());
}
inline std::string* FrameTransform::_internal_mutable_parent_frame_id() {
  
  return _impl_.parent_frame_id_.Mutable(GetArenaForAllocation());
}
inline std::string* FrameTransform::release_parent_frame_id() {
  // @@protoc_insertion_point(field_release:foxglove.FrameTransform.parent_frame_id)
  return _impl_.parent_frame_id_.Release();
}
inline void FrameTransform::set_allocated_parent_frame_id(std::string* parent_frame_id) {
  if (parent_frame_id != nullptr) {
    
  } else {
    
  }
  _impl_.parent_frame_id_.SetAllocated(parent_frame_id, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.parent_frame_id_.IsDefault()) {
    _impl_.parent_frame_id_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:foxglove.FrameTransform.parent_frame_id)
}

// string child_frame_id = 3;
inline void FrameTransform::clear_child_frame_id() {
  _impl_.child_frame_id_.ClearToEmpty();
}
inline const std::string& FrameTransform::child_frame_id() const {
  // @@protoc_insertion_point(field_get:foxglove.FrameTransform.child_frame_id)
  return _internal_child_frame_id();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FrameTransform::set_child_frame_id(ArgT0&& arg0, ArgT... args) {
 
 _impl_.child_frame_id_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:foxglove.FrameTransform.child_frame_id)
}
inline std::string* FrameTransform::mutable_child_frame_id() {
  std::string* _s = _internal_mutable_child_frame_id();
  // @@protoc_insertion_point(field_mutable:foxglove.FrameTransform.child_frame_id)
  return _s;
}
inline const std::string& FrameTransform::_internal_child_frame_id() const {
  return _impl_.child_frame_id_.Get();
}
inline void FrameTransform::_internal_set_child_frame_id(const std::string& value) {
  
  _impl_.child_frame_id_.Set(value, GetArenaForAllocation());
}
inline std::string* FrameTransform::_internal_mutable_child_frame_id() {
  
  return _impl_.child_frame_id_.Mutable(GetArenaForAllocation());
}
inline std::string* FrameTransform::release_child_frame_id() {
  // @@protoc_insertion_point(field_release:foxglove.FrameTransform.child_frame_id)
  return _impl_.child_frame_id_.Release();
}
inline void FrameTransform::set_allocated_child_frame_id(std::string* child_frame_id) {
  if (child_frame_id != nullptr) {
    
  } else {
    
  }
  _impl_.child_frame_id_.SetAllocated(child_frame_id, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.child_frame_id_.IsDefault()) {
    _impl_.child_frame_id_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:foxglove.FrameTransform.child_frame_id)
}

// .foxglove.Vector3 translation = 4;
inline bool FrameTransform::_internal_has_translation() const {
  return this != internal_default_instance() && _impl_.translation_ != nullptr;
}
inline bool FrameTransform::has_translation() const {
  return _internal_has_translation();
}
inline const ::foxglove::Vector3& FrameTransform::_internal_translation() const {
  const ::foxglove::Vector3* p = _impl_.translation_;
  return p != nullptr ? *p : reinterpret_cast<const ::foxglove::Vector3&>(
      ::foxglove::_Vector3_default_instance_);
}
inline const ::foxglove::Vector3& FrameTransform::translation() const {
  // @@protoc_insertion_point(field_get:foxglove.FrameTransform.translation)
  return _internal_translation();
}
inline void FrameTransform::unsafe_arena_set_allocated_translation(
    ::foxglove::Vector3* translation) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.translation_);
  }
  _impl_.translation_ = translation;
  if (translation) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.FrameTransform.translation)
}
inline ::foxglove::Vector3* FrameTransform::release_translation() {
  
  ::foxglove::Vector3* temp = _impl_.translation_;
  _impl_.translation_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::foxglove::Vector3* FrameTransform::unsafe_arena_release_translation() {
  // @@protoc_insertion_point(field_release:foxglove.FrameTransform.translation)
  
  ::foxglove::Vector3* temp = _impl_.translation_;
  _impl_.translation_ = nullptr;
  return temp;
}
inline ::foxglove::Vector3* FrameTransform::_internal_mutable_translation() {
  
  if (_impl_.translation_ == nullptr) {
    auto* p = CreateMaybeMessage<::foxglove::Vector3>(GetArenaForAllocation());
    _impl_.translation_ = p;
  }
  return _impl_.translation_;
}
inline ::foxglove::Vector3* FrameTransform::mutable_translation() {
  ::foxglove::Vector3* _msg = _internal_mutable_translation();
  // @@protoc_insertion_point(field_mutable:foxglove.FrameTransform.translation)
  return _msg;
}
inline void FrameTransform::set_allocated_translation(::foxglove::Vector3* translation) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.translation_);
  }
  if (translation) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(translation));
    if (message_arena != submessage_arena) {
      translation = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, translation, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.translation_ = translation;
  // @@protoc_insertion_point(field_set_allocated:foxglove.FrameTransform.translation)
}

// .foxglove.Quaternion rotation = 5;
inline bool FrameTransform::_internal_has_rotation() const {
  return this != internal_default_instance() && _impl_.rotation_ != nullptr;
}
inline bool FrameTransform::has_rotation() const {
  return _internal_has_rotation();
}
inline const ::foxglove::Quaternion& FrameTransform::_internal_rotation() const {
  const ::foxglove::Quaternion* p = _impl_.rotation_;
  return p != nullptr ? *p : reinterpret_cast<const ::foxglove::Quaternion&>(
      ::foxglove::_Quaternion_default_instance_);
}
inline const ::foxglove::Quaternion& FrameTransform::rotation() const {
  // @@protoc_insertion_point(field_get:foxglove.FrameTransform.rotation)
  return _internal_rotation();
}
inline void FrameTransform::unsafe_arena_set_allocated_rotation(
    ::foxglove::Quaternion* rotation) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.rotation_);
  }
  _impl_.rotation_ = rotation;
  if (rotation) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.FrameTransform.rotation)
}
inline ::foxglove::Quaternion* FrameTransform::release_rotation() {
  
  ::foxglove::Quaternion* temp = _impl_.rotation_;
  _impl_.rotation_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::foxglove::Quaternion* FrameTransform::unsafe_arena_release_rotation() {
  // @@protoc_insertion_point(field_release:foxglove.FrameTransform.rotation)
  
  ::foxglove::Quaternion* temp = _impl_.rotation_;
  _impl_.rotation_ = nullptr;
  return temp;
}
inline ::foxglove::Quaternion* FrameTransform::_internal_mutable_rotation() {
  
  if (_impl_.rotation_ == nullptr) {
    auto* p = CreateMaybeMessage<::foxglove::Quaternion>(GetArenaForAllocation());
    _impl_.rotation_ = p;
  }
  return _impl_.rotation_;
}
inline ::foxglove::Quaternion* FrameTransform::mutable_rotation() {
  ::foxglove::Quaternion* _msg = _internal_mutable_rotation();
  // @@protoc_insertion_point(field_mutable:foxglove.FrameTransform.rotation)
  return _msg;
}
inline void FrameTransform::set_allocated_rotation(::foxglove::Quaternion* rotation) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.rotation_);
  }
  if (rotation) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(rotation));
    if (message_arena != submessage_arena) {
      rotation = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, rotation, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.rotation_ = rotation;
  // @@protoc_insertion_point(field_set_allocated:foxglove.FrameTransform.rotation)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace foxglove

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_foxglove_2fFrameTransform_2eproto
