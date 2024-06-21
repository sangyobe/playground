// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/CylinderPrimitive.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_foxglove_2fCylinderPrimitive_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_foxglove_2fCylinderPrimitive_2eproto

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
#include "foxglove/Color.pb.h"
#include "foxglove/Pose.pb.h"
#include "foxglove/Vector3.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_foxglove_2fCylinderPrimitive_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_foxglove_2fCylinderPrimitive_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_foxglove_2fCylinderPrimitive_2eproto;
namespace foxglove {
class CylinderPrimitive;
struct CylinderPrimitiveDefaultTypeInternal;
extern CylinderPrimitiveDefaultTypeInternal _CylinderPrimitive_default_instance_;
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> ::foxglove::CylinderPrimitive* Arena::CreateMaybeMessage<::foxglove::CylinderPrimitive>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace foxglove {

// ===================================================================

class CylinderPrimitive final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:foxglove.CylinderPrimitive) */ {
 public:
  inline CylinderPrimitive() : CylinderPrimitive(nullptr) {}
  ~CylinderPrimitive() override;
  explicit PROTOBUF_CONSTEXPR CylinderPrimitive(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CylinderPrimitive(const CylinderPrimitive& from);
  CylinderPrimitive(CylinderPrimitive&& from) noexcept
    : CylinderPrimitive() {
    *this = ::std::move(from);
  }

  inline CylinderPrimitive& operator=(const CylinderPrimitive& from) {
    CopyFrom(from);
    return *this;
  }
  inline CylinderPrimitive& operator=(CylinderPrimitive&& from) noexcept {
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
  static const CylinderPrimitive& default_instance() {
    return *internal_default_instance();
  }
  static inline const CylinderPrimitive* internal_default_instance() {
    return reinterpret_cast<const CylinderPrimitive*>(
               &_CylinderPrimitive_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(CylinderPrimitive& a, CylinderPrimitive& b) {
    a.Swap(&b);
  }
  inline void Swap(CylinderPrimitive* other) {
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
  void UnsafeArenaSwap(CylinderPrimitive* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CylinderPrimitive* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<CylinderPrimitive>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const CylinderPrimitive& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const CylinderPrimitive& from) {
    CylinderPrimitive::MergeImpl(*this, from);
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
  void InternalSwap(CylinderPrimitive* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "foxglove.CylinderPrimitive";
  }
  protected:
  explicit CylinderPrimitive(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPoseFieldNumber = 1,
    kSizeFieldNumber = 2,
    kColorFieldNumber = 5,
    kBottomScaleFieldNumber = 3,
    kTopScaleFieldNumber = 4,
  };
  // .foxglove.Pose pose = 1;
  bool has_pose() const;
  private:
  bool _internal_has_pose() const;
  public:
  void clear_pose();
  const ::foxglove::Pose& pose() const;
  PROTOBUF_NODISCARD ::foxglove::Pose* release_pose();
  ::foxglove::Pose* mutable_pose();
  void set_allocated_pose(::foxglove::Pose* pose);
  private:
  const ::foxglove::Pose& _internal_pose() const;
  ::foxglove::Pose* _internal_mutable_pose();
  public:
  void unsafe_arena_set_allocated_pose(
      ::foxglove::Pose* pose);
  ::foxglove::Pose* unsafe_arena_release_pose();

  // .foxglove.Vector3 size = 2;
  bool has_size() const;
  private:
  bool _internal_has_size() const;
  public:
  void clear_size();
  const ::foxglove::Vector3& size() const;
  PROTOBUF_NODISCARD ::foxglove::Vector3* release_size();
  ::foxglove::Vector3* mutable_size();
  void set_allocated_size(::foxglove::Vector3* size);
  private:
  const ::foxglove::Vector3& _internal_size() const;
  ::foxglove::Vector3* _internal_mutable_size();
  public:
  void unsafe_arena_set_allocated_size(
      ::foxglove::Vector3* size);
  ::foxglove::Vector3* unsafe_arena_release_size();

  // .foxglove.Color color = 5;
  bool has_color() const;
  private:
  bool _internal_has_color() const;
  public:
  void clear_color();
  const ::foxglove::Color& color() const;
  PROTOBUF_NODISCARD ::foxglove::Color* release_color();
  ::foxglove::Color* mutable_color();
  void set_allocated_color(::foxglove::Color* color);
  private:
  const ::foxglove::Color& _internal_color() const;
  ::foxglove::Color* _internal_mutable_color();
  public:
  void unsafe_arena_set_allocated_color(
      ::foxglove::Color* color);
  ::foxglove::Color* unsafe_arena_release_color();

  // double bottom_scale = 3;
  void clear_bottom_scale();
  double bottom_scale() const;
  void set_bottom_scale(double value);
  private:
  double _internal_bottom_scale() const;
  void _internal_set_bottom_scale(double value);
  public:

  // double top_scale = 4;
  void clear_top_scale();
  double top_scale() const;
  void set_top_scale(double value);
  private:
  double _internal_top_scale() const;
  void _internal_set_top_scale(double value);
  public:

  // @@protoc_insertion_point(class_scope:foxglove.CylinderPrimitive)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::foxglove::Pose* pose_;
    ::foxglove::Vector3* size_;
    ::foxglove::Color* color_;
    double bottom_scale_;
    double top_scale_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_foxglove_2fCylinderPrimitive_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CylinderPrimitive

// .foxglove.Pose pose = 1;
inline bool CylinderPrimitive::_internal_has_pose() const {
  return this != internal_default_instance() && _impl_.pose_ != nullptr;
}
inline bool CylinderPrimitive::has_pose() const {
  return _internal_has_pose();
}
inline const ::foxglove::Pose& CylinderPrimitive::_internal_pose() const {
  const ::foxglove::Pose* p = _impl_.pose_;
  return p != nullptr ? *p : reinterpret_cast<const ::foxglove::Pose&>(
      ::foxglove::_Pose_default_instance_);
}
inline const ::foxglove::Pose& CylinderPrimitive::pose() const {
  // @@protoc_insertion_point(field_get:foxglove.CylinderPrimitive.pose)
  return _internal_pose();
}
inline void CylinderPrimitive::unsafe_arena_set_allocated_pose(
    ::foxglove::Pose* pose) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.pose_);
  }
  _impl_.pose_ = pose;
  if (pose) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.CylinderPrimitive.pose)
}
inline ::foxglove::Pose* CylinderPrimitive::release_pose() {
  
  ::foxglove::Pose* temp = _impl_.pose_;
  _impl_.pose_ = nullptr;
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
inline ::foxglove::Pose* CylinderPrimitive::unsafe_arena_release_pose() {
  // @@protoc_insertion_point(field_release:foxglove.CylinderPrimitive.pose)
  
  ::foxglove::Pose* temp = _impl_.pose_;
  _impl_.pose_ = nullptr;
  return temp;
}
inline ::foxglove::Pose* CylinderPrimitive::_internal_mutable_pose() {
  
  if (_impl_.pose_ == nullptr) {
    auto* p = CreateMaybeMessage<::foxglove::Pose>(GetArenaForAllocation());
    _impl_.pose_ = p;
  }
  return _impl_.pose_;
}
inline ::foxglove::Pose* CylinderPrimitive::mutable_pose() {
  ::foxglove::Pose* _msg = _internal_mutable_pose();
  // @@protoc_insertion_point(field_mutable:foxglove.CylinderPrimitive.pose)
  return _msg;
}
inline void CylinderPrimitive::set_allocated_pose(::foxglove::Pose* pose) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.pose_);
  }
  if (pose) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(pose));
    if (message_arena != submessage_arena) {
      pose = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, pose, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.pose_ = pose;
  // @@protoc_insertion_point(field_set_allocated:foxglove.CylinderPrimitive.pose)
}

// .foxglove.Vector3 size = 2;
inline bool CylinderPrimitive::_internal_has_size() const {
  return this != internal_default_instance() && _impl_.size_ != nullptr;
}
inline bool CylinderPrimitive::has_size() const {
  return _internal_has_size();
}
inline const ::foxglove::Vector3& CylinderPrimitive::_internal_size() const {
  const ::foxglove::Vector3* p = _impl_.size_;
  return p != nullptr ? *p : reinterpret_cast<const ::foxglove::Vector3&>(
      ::foxglove::_Vector3_default_instance_);
}
inline const ::foxglove::Vector3& CylinderPrimitive::size() const {
  // @@protoc_insertion_point(field_get:foxglove.CylinderPrimitive.size)
  return _internal_size();
}
inline void CylinderPrimitive::unsafe_arena_set_allocated_size(
    ::foxglove::Vector3* size) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.size_);
  }
  _impl_.size_ = size;
  if (size) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.CylinderPrimitive.size)
}
inline ::foxglove::Vector3* CylinderPrimitive::release_size() {
  
  ::foxglove::Vector3* temp = _impl_.size_;
  _impl_.size_ = nullptr;
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
inline ::foxglove::Vector3* CylinderPrimitive::unsafe_arena_release_size() {
  // @@protoc_insertion_point(field_release:foxglove.CylinderPrimitive.size)
  
  ::foxglove::Vector3* temp = _impl_.size_;
  _impl_.size_ = nullptr;
  return temp;
}
inline ::foxglove::Vector3* CylinderPrimitive::_internal_mutable_size() {
  
  if (_impl_.size_ == nullptr) {
    auto* p = CreateMaybeMessage<::foxglove::Vector3>(GetArenaForAllocation());
    _impl_.size_ = p;
  }
  return _impl_.size_;
}
inline ::foxglove::Vector3* CylinderPrimitive::mutable_size() {
  ::foxglove::Vector3* _msg = _internal_mutable_size();
  // @@protoc_insertion_point(field_mutable:foxglove.CylinderPrimitive.size)
  return _msg;
}
inline void CylinderPrimitive::set_allocated_size(::foxglove::Vector3* size) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.size_);
  }
  if (size) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(size));
    if (message_arena != submessage_arena) {
      size = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, size, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.size_ = size;
  // @@protoc_insertion_point(field_set_allocated:foxglove.CylinderPrimitive.size)
}

// double bottom_scale = 3;
inline void CylinderPrimitive::clear_bottom_scale() {
  _impl_.bottom_scale_ = 0;
}
inline double CylinderPrimitive::_internal_bottom_scale() const {
  return _impl_.bottom_scale_;
}
inline double CylinderPrimitive::bottom_scale() const {
  // @@protoc_insertion_point(field_get:foxglove.CylinderPrimitive.bottom_scale)
  return _internal_bottom_scale();
}
inline void CylinderPrimitive::_internal_set_bottom_scale(double value) {
  
  _impl_.bottom_scale_ = value;
}
inline void CylinderPrimitive::set_bottom_scale(double value) {
  _internal_set_bottom_scale(value);
  // @@protoc_insertion_point(field_set:foxglove.CylinderPrimitive.bottom_scale)
}

// double top_scale = 4;
inline void CylinderPrimitive::clear_top_scale() {
  _impl_.top_scale_ = 0;
}
inline double CylinderPrimitive::_internal_top_scale() const {
  return _impl_.top_scale_;
}
inline double CylinderPrimitive::top_scale() const {
  // @@protoc_insertion_point(field_get:foxglove.CylinderPrimitive.top_scale)
  return _internal_top_scale();
}
inline void CylinderPrimitive::_internal_set_top_scale(double value) {
  
  _impl_.top_scale_ = value;
}
inline void CylinderPrimitive::set_top_scale(double value) {
  _internal_set_top_scale(value);
  // @@protoc_insertion_point(field_set:foxglove.CylinderPrimitive.top_scale)
}

// .foxglove.Color color = 5;
inline bool CylinderPrimitive::_internal_has_color() const {
  return this != internal_default_instance() && _impl_.color_ != nullptr;
}
inline bool CylinderPrimitive::has_color() const {
  return _internal_has_color();
}
inline const ::foxglove::Color& CylinderPrimitive::_internal_color() const {
  const ::foxglove::Color* p = _impl_.color_;
  return p != nullptr ? *p : reinterpret_cast<const ::foxglove::Color&>(
      ::foxglove::_Color_default_instance_);
}
inline const ::foxglove::Color& CylinderPrimitive::color() const {
  // @@protoc_insertion_point(field_get:foxglove.CylinderPrimitive.color)
  return _internal_color();
}
inline void CylinderPrimitive::unsafe_arena_set_allocated_color(
    ::foxglove::Color* color) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.color_);
  }
  _impl_.color_ = color;
  if (color) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.CylinderPrimitive.color)
}
inline ::foxglove::Color* CylinderPrimitive::release_color() {
  
  ::foxglove::Color* temp = _impl_.color_;
  _impl_.color_ = nullptr;
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
inline ::foxglove::Color* CylinderPrimitive::unsafe_arena_release_color() {
  // @@protoc_insertion_point(field_release:foxglove.CylinderPrimitive.color)
  
  ::foxglove::Color* temp = _impl_.color_;
  _impl_.color_ = nullptr;
  return temp;
}
inline ::foxglove::Color* CylinderPrimitive::_internal_mutable_color() {
  
  if (_impl_.color_ == nullptr) {
    auto* p = CreateMaybeMessage<::foxglove::Color>(GetArenaForAllocation());
    _impl_.color_ = p;
  }
  return _impl_.color_;
}
inline ::foxglove::Color* CylinderPrimitive::mutable_color() {
  ::foxglove::Color* _msg = _internal_mutable_color();
  // @@protoc_insertion_point(field_mutable:foxglove.CylinderPrimitive.color)
  return _msg;
}
inline void CylinderPrimitive::set_allocated_color(::foxglove::Color* color) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.color_);
  }
  if (color) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(color));
    if (message_arena != submessage_arena) {
      color = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, color, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.color_ = color;
  // @@protoc_insertion_point(field_set_allocated:foxglove.CylinderPrimitive.color)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace foxglove

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_foxglove_2fCylinderPrimitive_2eproto