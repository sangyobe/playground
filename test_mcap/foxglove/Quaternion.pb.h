// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/Quaternion.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_foxglove_2fQuaternion_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_foxglove_2fQuaternion_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_foxglove_2fQuaternion_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_foxglove_2fQuaternion_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_foxglove_2fQuaternion_2eproto;
namespace foxglove {
class Quaternion;
struct QuaternionDefaultTypeInternal;
extern QuaternionDefaultTypeInternal _Quaternion_default_instance_;
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> ::foxglove::Quaternion* Arena::CreateMaybeMessage<::foxglove::Quaternion>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace foxglove {

// ===================================================================

class Quaternion final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:foxglove.Quaternion) */ {
 public:
  inline Quaternion() : Quaternion(nullptr) {}
  ~Quaternion() override;
  explicit PROTOBUF_CONSTEXPR Quaternion(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Quaternion(const Quaternion& from);
  Quaternion(Quaternion&& from) noexcept
    : Quaternion() {
    *this = ::std::move(from);
  }

  inline Quaternion& operator=(const Quaternion& from) {
    CopyFrom(from);
    return *this;
  }
  inline Quaternion& operator=(Quaternion&& from) noexcept {
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
  static const Quaternion& default_instance() {
    return *internal_default_instance();
  }
  static inline const Quaternion* internal_default_instance() {
    return reinterpret_cast<const Quaternion*>(
               &_Quaternion_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Quaternion& a, Quaternion& b) {
    a.Swap(&b);
  }
  inline void Swap(Quaternion* other) {
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
  void UnsafeArenaSwap(Quaternion* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Quaternion* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Quaternion>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Quaternion& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Quaternion& from) {
    Quaternion::MergeImpl(*this, from);
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
  void InternalSwap(Quaternion* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "foxglove.Quaternion";
  }
  protected:
  explicit Quaternion(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kZFieldNumber = 3,
    kWFieldNumber = 4,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // double z = 3;
  void clear_z();
  double z() const;
  void set_z(double value);
  private:
  double _internal_z() const;
  void _internal_set_z(double value);
  public:

  // double w = 4;
  void clear_w();
  double w() const;
  void set_w(double value);
  private:
  double _internal_w() const;
  void _internal_set_w(double value);
  public:

  // @@protoc_insertion_point(class_scope:foxglove.Quaternion)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    double x_;
    double y_;
    double z_;
    double w_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_foxglove_2fQuaternion_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Quaternion

// double x = 1;
inline void Quaternion::clear_x() {
  _impl_.x_ = 0;
}
inline double Quaternion::_internal_x() const {
  return _impl_.x_;
}
inline double Quaternion::x() const {
  // @@protoc_insertion_point(field_get:foxglove.Quaternion.x)
  return _internal_x();
}
inline void Quaternion::_internal_set_x(double value) {
  
  _impl_.x_ = value;
}
inline void Quaternion::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:foxglove.Quaternion.x)
}

// double y = 2;
inline void Quaternion::clear_y() {
  _impl_.y_ = 0;
}
inline double Quaternion::_internal_y() const {
  return _impl_.y_;
}
inline double Quaternion::y() const {
  // @@protoc_insertion_point(field_get:foxglove.Quaternion.y)
  return _internal_y();
}
inline void Quaternion::_internal_set_y(double value) {
  
  _impl_.y_ = value;
}
inline void Quaternion::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:foxglove.Quaternion.y)
}

// double z = 3;
inline void Quaternion::clear_z() {
  _impl_.z_ = 0;
}
inline double Quaternion::_internal_z() const {
  return _impl_.z_;
}
inline double Quaternion::z() const {
  // @@protoc_insertion_point(field_get:foxglove.Quaternion.z)
  return _internal_z();
}
inline void Quaternion::_internal_set_z(double value) {
  
  _impl_.z_ = value;
}
inline void Quaternion::set_z(double value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:foxglove.Quaternion.z)
}

// double w = 4;
inline void Quaternion::clear_w() {
  _impl_.w_ = 0;
}
inline double Quaternion::_internal_w() const {
  return _impl_.w_;
}
inline double Quaternion::w() const {
  // @@protoc_insertion_point(field_get:foxglove.Quaternion.w)
  return _internal_w();
}
inline void Quaternion::_internal_set_w(double value) {
  
  _impl_.w_ = value;
}
inline void Quaternion::set_w(double value) {
  _internal_set_w(value);
  // @@protoc_insertion_point(field_set:foxglove.Quaternion.w)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace foxglove

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_foxglove_2fQuaternion_2eproto
