// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/CameraCalibration.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_foxglove_2fCameraCalibration_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_foxglove_2fCameraCalibration_2eproto

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
#include <google/protobuf/timestamp.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_foxglove_2fCameraCalibration_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_foxglove_2fCameraCalibration_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_foxglove_2fCameraCalibration_2eproto;
namespace foxglove {
class CameraCalibration;
struct CameraCalibrationDefaultTypeInternal;
extern CameraCalibrationDefaultTypeInternal _CameraCalibration_default_instance_;
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> ::foxglove::CameraCalibration* Arena::CreateMaybeMessage<::foxglove::CameraCalibration>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace foxglove {

// ===================================================================

class CameraCalibration final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:foxglove.CameraCalibration) */ {
 public:
  inline CameraCalibration() : CameraCalibration(nullptr) {}
  ~CameraCalibration() override;
  explicit PROTOBUF_CONSTEXPR CameraCalibration(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CameraCalibration(const CameraCalibration& from);
  CameraCalibration(CameraCalibration&& from) noexcept
    : CameraCalibration() {
    *this = ::std::move(from);
  }

  inline CameraCalibration& operator=(const CameraCalibration& from) {
    CopyFrom(from);
    return *this;
  }
  inline CameraCalibration& operator=(CameraCalibration&& from) noexcept {
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
  static const CameraCalibration& default_instance() {
    return *internal_default_instance();
  }
  static inline const CameraCalibration* internal_default_instance() {
    return reinterpret_cast<const CameraCalibration*>(
               &_CameraCalibration_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(CameraCalibration& a, CameraCalibration& b) {
    a.Swap(&b);
  }
  inline void Swap(CameraCalibration* other) {
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
  void UnsafeArenaSwap(CameraCalibration* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CameraCalibration* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<CameraCalibration>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const CameraCalibration& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const CameraCalibration& from) {
    CameraCalibration::MergeImpl(*this, from);
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
  void InternalSwap(CameraCalibration* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "foxglove.CameraCalibration";
  }
  protected:
  explicit CameraCalibration(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDFieldNumber = 5,
    kKFieldNumber = 6,
    kRFieldNumber = 7,
    kPFieldNumber = 8,
    kDistortionModelFieldNumber = 4,
    kFrameIdFieldNumber = 9,
    kTimestampFieldNumber = 1,
    kWidthFieldNumber = 2,
    kHeightFieldNumber = 3,
  };
  // repeated double D = 5;
  int d_size() const;
  private:
  int _internal_d_size() const;
  public:
  void clear_d();
  private:
  double _internal_d(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      _internal_d() const;
  void _internal_add_d(double value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      _internal_mutable_d();
  public:
  double d(int index) const;
  void set_d(int index, double value);
  void add_d(double value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      d() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      mutable_d();

  // repeated double K = 6;
  int k_size() const;
  private:
  int _internal_k_size() const;
  public:
  void clear_k();
  private:
  double _internal_k(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      _internal_k() const;
  void _internal_add_k(double value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      _internal_mutable_k();
  public:
  double k(int index) const;
  void set_k(int index, double value);
  void add_k(double value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      k() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      mutable_k();

  // repeated double R = 7;
  int r_size() const;
  private:
  int _internal_r_size() const;
  public:
  void clear_r();
  private:
  double _internal_r(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      _internal_r() const;
  void _internal_add_r(double value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      _internal_mutable_r();
  public:
  double r(int index) const;
  void set_r(int index, double value);
  void add_r(double value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      r() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      mutable_r();

  // repeated double P = 8;
  int p_size() const;
  private:
  int _internal_p_size() const;
  public:
  void clear_p();
  private:
  double _internal_p(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      _internal_p() const;
  void _internal_add_p(double value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      _internal_mutable_p();
  public:
  double p(int index) const;
  void set_p(int index, double value);
  void add_p(double value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      p() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      mutable_p();

  // string distortion_model = 4;
  void clear_distortion_model();
  const std::string& distortion_model() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_distortion_model(ArgT0&& arg0, ArgT... args);
  std::string* mutable_distortion_model();
  PROTOBUF_NODISCARD std::string* release_distortion_model();
  void set_allocated_distortion_model(std::string* distortion_model);
  private:
  const std::string& _internal_distortion_model() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_distortion_model(const std::string& value);
  std::string* _internal_mutable_distortion_model();
  public:

  // string frame_id = 9;
  void clear_frame_id();
  const std::string& frame_id() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_frame_id(ArgT0&& arg0, ArgT... args);
  std::string* mutable_frame_id();
  PROTOBUF_NODISCARD std::string* release_frame_id();
  void set_allocated_frame_id(std::string* frame_id);
  private:
  const std::string& _internal_frame_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_frame_id(const std::string& value);
  std::string* _internal_mutable_frame_id();
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

  // fixed32 width = 2;
  void clear_width();
  uint32_t width() const;
  void set_width(uint32_t value);
  private:
  uint32_t _internal_width() const;
  void _internal_set_width(uint32_t value);
  public:

  // fixed32 height = 3;
  void clear_height();
  uint32_t height() const;
  void set_height(uint32_t value);
  private:
  uint32_t _internal_height() const;
  void _internal_set_height(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:foxglove.CameraCalibration)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< double > d_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< double > k_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< double > r_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< double > p_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr distortion_model_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr frame_id_;
    ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp_;
    uint32_t width_;
    uint32_t height_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_foxglove_2fCameraCalibration_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CameraCalibration

// .google.protobuf.Timestamp timestamp = 1;
inline bool CameraCalibration::_internal_has_timestamp() const {
  return this != internal_default_instance() && _impl_.timestamp_ != nullptr;
}
inline bool CameraCalibration::has_timestamp() const {
  return _internal_has_timestamp();
}
inline const ::PROTOBUF_NAMESPACE_ID::Timestamp& CameraCalibration::_internal_timestamp() const {
  const ::PROTOBUF_NAMESPACE_ID::Timestamp* p = _impl_.timestamp_;
  return p != nullptr ? *p : reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Timestamp&>(
      ::PROTOBUF_NAMESPACE_ID::_Timestamp_default_instance_);
}
inline const ::PROTOBUF_NAMESPACE_ID::Timestamp& CameraCalibration::timestamp() const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.timestamp)
  return _internal_timestamp();
}
inline void CameraCalibration::unsafe_arena_set_allocated_timestamp(
    ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.timestamp_);
  }
  _impl_.timestamp_ = timestamp;
  if (timestamp) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.CameraCalibration.timestamp)
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* CameraCalibration::release_timestamp() {
  
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
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* CameraCalibration::unsafe_arena_release_timestamp() {
  // @@protoc_insertion_point(field_release:foxglove.CameraCalibration.timestamp)
  
  ::PROTOBUF_NAMESPACE_ID::Timestamp* temp = _impl_.timestamp_;
  _impl_.timestamp_ = nullptr;
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* CameraCalibration::_internal_mutable_timestamp() {
  
  if (_impl_.timestamp_ == nullptr) {
    auto* p = CreateMaybeMessage<::PROTOBUF_NAMESPACE_ID::Timestamp>(GetArenaForAllocation());
    _impl_.timestamp_ = p;
  }
  return _impl_.timestamp_;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* CameraCalibration::mutable_timestamp() {
  ::PROTOBUF_NAMESPACE_ID::Timestamp* _msg = _internal_mutable_timestamp();
  // @@protoc_insertion_point(field_mutable:foxglove.CameraCalibration.timestamp)
  return _msg;
}
inline void CameraCalibration::set_allocated_timestamp(::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
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
  // @@protoc_insertion_point(field_set_allocated:foxglove.CameraCalibration.timestamp)
}

// string frame_id = 9;
inline void CameraCalibration::clear_frame_id() {
  _impl_.frame_id_.ClearToEmpty();
}
inline const std::string& CameraCalibration::frame_id() const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.frame_id)
  return _internal_frame_id();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void CameraCalibration::set_frame_id(ArgT0&& arg0, ArgT... args) {
 
 _impl_.frame_id_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:foxglove.CameraCalibration.frame_id)
}
inline std::string* CameraCalibration::mutable_frame_id() {
  std::string* _s = _internal_mutable_frame_id();
  // @@protoc_insertion_point(field_mutable:foxglove.CameraCalibration.frame_id)
  return _s;
}
inline const std::string& CameraCalibration::_internal_frame_id() const {
  return _impl_.frame_id_.Get();
}
inline void CameraCalibration::_internal_set_frame_id(const std::string& value) {
  
  _impl_.frame_id_.Set(value, GetArenaForAllocation());
}
inline std::string* CameraCalibration::_internal_mutable_frame_id() {
  
  return _impl_.frame_id_.Mutable(GetArenaForAllocation());
}
inline std::string* CameraCalibration::release_frame_id() {
  // @@protoc_insertion_point(field_release:foxglove.CameraCalibration.frame_id)
  return _impl_.frame_id_.Release();
}
inline void CameraCalibration::set_allocated_frame_id(std::string* frame_id) {
  if (frame_id != nullptr) {
    
  } else {
    
  }
  _impl_.frame_id_.SetAllocated(frame_id, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.frame_id_.IsDefault()) {
    _impl_.frame_id_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:foxglove.CameraCalibration.frame_id)
}

// fixed32 width = 2;
inline void CameraCalibration::clear_width() {
  _impl_.width_ = 0u;
}
inline uint32_t CameraCalibration::_internal_width() const {
  return _impl_.width_;
}
inline uint32_t CameraCalibration::width() const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.width)
  return _internal_width();
}
inline void CameraCalibration::_internal_set_width(uint32_t value) {
  
  _impl_.width_ = value;
}
inline void CameraCalibration::set_width(uint32_t value) {
  _internal_set_width(value);
  // @@protoc_insertion_point(field_set:foxglove.CameraCalibration.width)
}

// fixed32 height = 3;
inline void CameraCalibration::clear_height() {
  _impl_.height_ = 0u;
}
inline uint32_t CameraCalibration::_internal_height() const {
  return _impl_.height_;
}
inline uint32_t CameraCalibration::height() const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.height)
  return _internal_height();
}
inline void CameraCalibration::_internal_set_height(uint32_t value) {
  
  _impl_.height_ = value;
}
inline void CameraCalibration::set_height(uint32_t value) {
  _internal_set_height(value);
  // @@protoc_insertion_point(field_set:foxglove.CameraCalibration.height)
}

// string distortion_model = 4;
inline void CameraCalibration::clear_distortion_model() {
  _impl_.distortion_model_.ClearToEmpty();
}
inline const std::string& CameraCalibration::distortion_model() const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.distortion_model)
  return _internal_distortion_model();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void CameraCalibration::set_distortion_model(ArgT0&& arg0, ArgT... args) {
 
 _impl_.distortion_model_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:foxglove.CameraCalibration.distortion_model)
}
inline std::string* CameraCalibration::mutable_distortion_model() {
  std::string* _s = _internal_mutable_distortion_model();
  // @@protoc_insertion_point(field_mutable:foxglove.CameraCalibration.distortion_model)
  return _s;
}
inline const std::string& CameraCalibration::_internal_distortion_model() const {
  return _impl_.distortion_model_.Get();
}
inline void CameraCalibration::_internal_set_distortion_model(const std::string& value) {
  
  _impl_.distortion_model_.Set(value, GetArenaForAllocation());
}
inline std::string* CameraCalibration::_internal_mutable_distortion_model() {
  
  return _impl_.distortion_model_.Mutable(GetArenaForAllocation());
}
inline std::string* CameraCalibration::release_distortion_model() {
  // @@protoc_insertion_point(field_release:foxglove.CameraCalibration.distortion_model)
  return _impl_.distortion_model_.Release();
}
inline void CameraCalibration::set_allocated_distortion_model(std::string* distortion_model) {
  if (distortion_model != nullptr) {
    
  } else {
    
  }
  _impl_.distortion_model_.SetAllocated(distortion_model, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.distortion_model_.IsDefault()) {
    _impl_.distortion_model_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:foxglove.CameraCalibration.distortion_model)
}

// repeated double D = 5;
inline int CameraCalibration::_internal_d_size() const {
  return _impl_.d_.size();
}
inline int CameraCalibration::d_size() const {
  return _internal_d_size();
}
inline void CameraCalibration::clear_d() {
  _impl_.d_.Clear();
}
inline double CameraCalibration::_internal_d(int index) const {
  return _impl_.d_.Get(index);
}
inline double CameraCalibration::d(int index) const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.D)
  return _internal_d(index);
}
inline void CameraCalibration::set_d(int index, double value) {
  _impl_.d_.Set(index, value);
  // @@protoc_insertion_point(field_set:foxglove.CameraCalibration.D)
}
inline void CameraCalibration::_internal_add_d(double value) {
  _impl_.d_.Add(value);
}
inline void CameraCalibration::add_d(double value) {
  _internal_add_d(value);
  // @@protoc_insertion_point(field_add:foxglove.CameraCalibration.D)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
CameraCalibration::_internal_d() const {
  return _impl_.d_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
CameraCalibration::d() const {
  // @@protoc_insertion_point(field_list:foxglove.CameraCalibration.D)
  return _internal_d();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
CameraCalibration::_internal_mutable_d() {
  return &_impl_.d_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
CameraCalibration::mutable_d() {
  // @@protoc_insertion_point(field_mutable_list:foxglove.CameraCalibration.D)
  return _internal_mutable_d();
}

// repeated double K = 6;
inline int CameraCalibration::_internal_k_size() const {
  return _impl_.k_.size();
}
inline int CameraCalibration::k_size() const {
  return _internal_k_size();
}
inline void CameraCalibration::clear_k() {
  _impl_.k_.Clear();
}
inline double CameraCalibration::_internal_k(int index) const {
  return _impl_.k_.Get(index);
}
inline double CameraCalibration::k(int index) const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.K)
  return _internal_k(index);
}
inline void CameraCalibration::set_k(int index, double value) {
  _impl_.k_.Set(index, value);
  // @@protoc_insertion_point(field_set:foxglove.CameraCalibration.K)
}
inline void CameraCalibration::_internal_add_k(double value) {
  _impl_.k_.Add(value);
}
inline void CameraCalibration::add_k(double value) {
  _internal_add_k(value);
  // @@protoc_insertion_point(field_add:foxglove.CameraCalibration.K)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
CameraCalibration::_internal_k() const {
  return _impl_.k_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
CameraCalibration::k() const {
  // @@protoc_insertion_point(field_list:foxglove.CameraCalibration.K)
  return _internal_k();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
CameraCalibration::_internal_mutable_k() {
  return &_impl_.k_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
CameraCalibration::mutable_k() {
  // @@protoc_insertion_point(field_mutable_list:foxglove.CameraCalibration.K)
  return _internal_mutable_k();
}

// repeated double R = 7;
inline int CameraCalibration::_internal_r_size() const {
  return _impl_.r_.size();
}
inline int CameraCalibration::r_size() const {
  return _internal_r_size();
}
inline void CameraCalibration::clear_r() {
  _impl_.r_.Clear();
}
inline double CameraCalibration::_internal_r(int index) const {
  return _impl_.r_.Get(index);
}
inline double CameraCalibration::r(int index) const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.R)
  return _internal_r(index);
}
inline void CameraCalibration::set_r(int index, double value) {
  _impl_.r_.Set(index, value);
  // @@protoc_insertion_point(field_set:foxglove.CameraCalibration.R)
}
inline void CameraCalibration::_internal_add_r(double value) {
  _impl_.r_.Add(value);
}
inline void CameraCalibration::add_r(double value) {
  _internal_add_r(value);
  // @@protoc_insertion_point(field_add:foxglove.CameraCalibration.R)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
CameraCalibration::_internal_r() const {
  return _impl_.r_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
CameraCalibration::r() const {
  // @@protoc_insertion_point(field_list:foxglove.CameraCalibration.R)
  return _internal_r();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
CameraCalibration::_internal_mutable_r() {
  return &_impl_.r_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
CameraCalibration::mutable_r() {
  // @@protoc_insertion_point(field_mutable_list:foxglove.CameraCalibration.R)
  return _internal_mutable_r();
}

// repeated double P = 8;
inline int CameraCalibration::_internal_p_size() const {
  return _impl_.p_.size();
}
inline int CameraCalibration::p_size() const {
  return _internal_p_size();
}
inline void CameraCalibration::clear_p() {
  _impl_.p_.Clear();
}
inline double CameraCalibration::_internal_p(int index) const {
  return _impl_.p_.Get(index);
}
inline double CameraCalibration::p(int index) const {
  // @@protoc_insertion_point(field_get:foxglove.CameraCalibration.P)
  return _internal_p(index);
}
inline void CameraCalibration::set_p(int index, double value) {
  _impl_.p_.Set(index, value);
  // @@protoc_insertion_point(field_set:foxglove.CameraCalibration.P)
}
inline void CameraCalibration::_internal_add_p(double value) {
  _impl_.p_.Add(value);
}
inline void CameraCalibration::add_p(double value) {
  _internal_add_p(value);
  // @@protoc_insertion_point(field_add:foxglove.CameraCalibration.P)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
CameraCalibration::_internal_p() const {
  return _impl_.p_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
CameraCalibration::p() const {
  // @@protoc_insertion_point(field_list:foxglove.CameraCalibration.P)
  return _internal_p();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
CameraCalibration::_internal_mutable_p() {
  return &_impl_.p_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
CameraCalibration::mutable_p() {
  // @@protoc_insertion_point(field_mutable_list:foxglove.CameraCalibration.P)
  return _internal_mutable_p();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace foxglove

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_foxglove_2fCameraCalibration_2eproto