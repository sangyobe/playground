// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/TextAnnotation.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_foxglove_2fTextAnnotation_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_foxglove_2fTextAnnotation_2eproto

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
#include "foxglove/Point2.pb.h"
#include <google/protobuf/timestamp.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_foxglove_2fTextAnnotation_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_foxglove_2fTextAnnotation_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_foxglove_2fTextAnnotation_2eproto;
namespace foxglove {
class TextAnnotation;
struct TextAnnotationDefaultTypeInternal;
extern TextAnnotationDefaultTypeInternal _TextAnnotation_default_instance_;
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> ::foxglove::TextAnnotation* Arena::CreateMaybeMessage<::foxglove::TextAnnotation>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace foxglove {

// ===================================================================

class TextAnnotation final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:foxglove.TextAnnotation) */ {
 public:
  inline TextAnnotation() : TextAnnotation(nullptr) {}
  ~TextAnnotation() override;
  explicit PROTOBUF_CONSTEXPR TextAnnotation(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TextAnnotation(const TextAnnotation& from);
  TextAnnotation(TextAnnotation&& from) noexcept
    : TextAnnotation() {
    *this = ::std::move(from);
  }

  inline TextAnnotation& operator=(const TextAnnotation& from) {
    CopyFrom(from);
    return *this;
  }
  inline TextAnnotation& operator=(TextAnnotation&& from) noexcept {
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
  static const TextAnnotation& default_instance() {
    return *internal_default_instance();
  }
  static inline const TextAnnotation* internal_default_instance() {
    return reinterpret_cast<const TextAnnotation*>(
               &_TextAnnotation_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TextAnnotation& a, TextAnnotation& b) {
    a.Swap(&b);
  }
  inline void Swap(TextAnnotation* other) {
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
  void UnsafeArenaSwap(TextAnnotation* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TextAnnotation* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TextAnnotation>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TextAnnotation& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const TextAnnotation& from) {
    TextAnnotation::MergeImpl(*this, from);
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
  void InternalSwap(TextAnnotation* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "foxglove.TextAnnotation";
  }
  protected:
  explicit TextAnnotation(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTextFieldNumber = 3,
    kTimestampFieldNumber = 1,
    kPositionFieldNumber = 2,
    kTextColorFieldNumber = 5,
    kBackgroundColorFieldNumber = 6,
    kFontSizeFieldNumber = 4,
  };
  // string text = 3;
  void clear_text();
  const std::string& text() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_text(ArgT0&& arg0, ArgT... args);
  std::string* mutable_text();
  PROTOBUF_NODISCARD std::string* release_text();
  void set_allocated_text(std::string* text);
  private:
  const std::string& _internal_text() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_text(const std::string& value);
  std::string* _internal_mutable_text();
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

  // .foxglove.Point2 position = 2;
  bool has_position() const;
  private:
  bool _internal_has_position() const;
  public:
  void clear_position();
  const ::foxglove::Point2& position() const;
  PROTOBUF_NODISCARD ::foxglove::Point2* release_position();
  ::foxglove::Point2* mutable_position();
  void set_allocated_position(::foxglove::Point2* position);
  private:
  const ::foxglove::Point2& _internal_position() const;
  ::foxglove::Point2* _internal_mutable_position();
  public:
  void unsafe_arena_set_allocated_position(
      ::foxglove::Point2* position);
  ::foxglove::Point2* unsafe_arena_release_position();

  // .foxglove.Color text_color = 5;
  bool has_text_color() const;
  private:
  bool _internal_has_text_color() const;
  public:
  void clear_text_color();
  const ::foxglove::Color& text_color() const;
  PROTOBUF_NODISCARD ::foxglove::Color* release_text_color();
  ::foxglove::Color* mutable_text_color();
  void set_allocated_text_color(::foxglove::Color* text_color);
  private:
  const ::foxglove::Color& _internal_text_color() const;
  ::foxglove::Color* _internal_mutable_text_color();
  public:
  void unsafe_arena_set_allocated_text_color(
      ::foxglove::Color* text_color);
  ::foxglove::Color* unsafe_arena_release_text_color();

  // .foxglove.Color background_color = 6;
  bool has_background_color() const;
  private:
  bool _internal_has_background_color() const;
  public:
  void clear_background_color();
  const ::foxglove::Color& background_color() const;
  PROTOBUF_NODISCARD ::foxglove::Color* release_background_color();
  ::foxglove::Color* mutable_background_color();
  void set_allocated_background_color(::foxglove::Color* background_color);
  private:
  const ::foxglove::Color& _internal_background_color() const;
  ::foxglove::Color* _internal_mutable_background_color();
  public:
  void unsafe_arena_set_allocated_background_color(
      ::foxglove::Color* background_color);
  ::foxglove::Color* unsafe_arena_release_background_color();

  // double font_size = 4;
  void clear_font_size();
  double font_size() const;
  void set_font_size(double value);
  private:
  double _internal_font_size() const;
  void _internal_set_font_size(double value);
  public:

  // @@protoc_insertion_point(class_scope:foxglove.TextAnnotation)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr text_;
    ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp_;
    ::foxglove::Point2* position_;
    ::foxglove::Color* text_color_;
    ::foxglove::Color* background_color_;
    double font_size_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_foxglove_2fTextAnnotation_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TextAnnotation

// .google.protobuf.Timestamp timestamp = 1;
inline bool TextAnnotation::_internal_has_timestamp() const {
  return this != internal_default_instance() && _impl_.timestamp_ != nullptr;
}
inline bool TextAnnotation::has_timestamp() const {
  return _internal_has_timestamp();
}
inline const ::PROTOBUF_NAMESPACE_ID::Timestamp& TextAnnotation::_internal_timestamp() const {
  const ::PROTOBUF_NAMESPACE_ID::Timestamp* p = _impl_.timestamp_;
  return p != nullptr ? *p : reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Timestamp&>(
      ::PROTOBUF_NAMESPACE_ID::_Timestamp_default_instance_);
}
inline const ::PROTOBUF_NAMESPACE_ID::Timestamp& TextAnnotation::timestamp() const {
  // @@protoc_insertion_point(field_get:foxglove.TextAnnotation.timestamp)
  return _internal_timestamp();
}
inline void TextAnnotation::unsafe_arena_set_allocated_timestamp(
    ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.timestamp_);
  }
  _impl_.timestamp_ = timestamp;
  if (timestamp) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.TextAnnotation.timestamp)
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* TextAnnotation::release_timestamp() {
  
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
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* TextAnnotation::unsafe_arena_release_timestamp() {
  // @@protoc_insertion_point(field_release:foxglove.TextAnnotation.timestamp)
  
  ::PROTOBUF_NAMESPACE_ID::Timestamp* temp = _impl_.timestamp_;
  _impl_.timestamp_ = nullptr;
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* TextAnnotation::_internal_mutable_timestamp() {
  
  if (_impl_.timestamp_ == nullptr) {
    auto* p = CreateMaybeMessage<::PROTOBUF_NAMESPACE_ID::Timestamp>(GetArenaForAllocation());
    _impl_.timestamp_ = p;
  }
  return _impl_.timestamp_;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* TextAnnotation::mutable_timestamp() {
  ::PROTOBUF_NAMESPACE_ID::Timestamp* _msg = _internal_mutable_timestamp();
  // @@protoc_insertion_point(field_mutable:foxglove.TextAnnotation.timestamp)
  return _msg;
}
inline void TextAnnotation::set_allocated_timestamp(::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
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
  // @@protoc_insertion_point(field_set_allocated:foxglove.TextAnnotation.timestamp)
}

// .foxglove.Point2 position = 2;
inline bool TextAnnotation::_internal_has_position() const {
  return this != internal_default_instance() && _impl_.position_ != nullptr;
}
inline bool TextAnnotation::has_position() const {
  return _internal_has_position();
}
inline const ::foxglove::Point2& TextAnnotation::_internal_position() const {
  const ::foxglove::Point2* p = _impl_.position_;
  return p != nullptr ? *p : reinterpret_cast<const ::foxglove::Point2&>(
      ::foxglove::_Point2_default_instance_);
}
inline const ::foxglove::Point2& TextAnnotation::position() const {
  // @@protoc_insertion_point(field_get:foxglove.TextAnnotation.position)
  return _internal_position();
}
inline void TextAnnotation::unsafe_arena_set_allocated_position(
    ::foxglove::Point2* position) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.position_);
  }
  _impl_.position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.TextAnnotation.position)
}
inline ::foxglove::Point2* TextAnnotation::release_position() {
  
  ::foxglove::Point2* temp = _impl_.position_;
  _impl_.position_ = nullptr;
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
inline ::foxglove::Point2* TextAnnotation::unsafe_arena_release_position() {
  // @@protoc_insertion_point(field_release:foxglove.TextAnnotation.position)
  
  ::foxglove::Point2* temp = _impl_.position_;
  _impl_.position_ = nullptr;
  return temp;
}
inline ::foxglove::Point2* TextAnnotation::_internal_mutable_position() {
  
  if (_impl_.position_ == nullptr) {
    auto* p = CreateMaybeMessage<::foxglove::Point2>(GetArenaForAllocation());
    _impl_.position_ = p;
  }
  return _impl_.position_;
}
inline ::foxglove::Point2* TextAnnotation::mutable_position() {
  ::foxglove::Point2* _msg = _internal_mutable_position();
  // @@protoc_insertion_point(field_mutable:foxglove.TextAnnotation.position)
  return _msg;
}
inline void TextAnnotation::set_allocated_position(::foxglove::Point2* position) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.position_);
  }
  if (position) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(position));
    if (message_arena != submessage_arena) {
      position = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.position_ = position;
  // @@protoc_insertion_point(field_set_allocated:foxglove.TextAnnotation.position)
}

// string text = 3;
inline void TextAnnotation::clear_text() {
  _impl_.text_.ClearToEmpty();
}
inline const std::string& TextAnnotation::text() const {
  // @@protoc_insertion_point(field_get:foxglove.TextAnnotation.text)
  return _internal_text();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void TextAnnotation::set_text(ArgT0&& arg0, ArgT... args) {
 
 _impl_.text_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:foxglove.TextAnnotation.text)
}
inline std::string* TextAnnotation::mutable_text() {
  std::string* _s = _internal_mutable_text();
  // @@protoc_insertion_point(field_mutable:foxglove.TextAnnotation.text)
  return _s;
}
inline const std::string& TextAnnotation::_internal_text() const {
  return _impl_.text_.Get();
}
inline void TextAnnotation::_internal_set_text(const std::string& value) {
  
  _impl_.text_.Set(value, GetArenaForAllocation());
}
inline std::string* TextAnnotation::_internal_mutable_text() {
  
  return _impl_.text_.Mutable(GetArenaForAllocation());
}
inline std::string* TextAnnotation::release_text() {
  // @@protoc_insertion_point(field_release:foxglove.TextAnnotation.text)
  return _impl_.text_.Release();
}
inline void TextAnnotation::set_allocated_text(std::string* text) {
  if (text != nullptr) {
    
  } else {
    
  }
  _impl_.text_.SetAllocated(text, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.text_.IsDefault()) {
    _impl_.text_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:foxglove.TextAnnotation.text)
}

// double font_size = 4;
inline void TextAnnotation::clear_font_size() {
  _impl_.font_size_ = 0;
}
inline double TextAnnotation::_internal_font_size() const {
  return _impl_.font_size_;
}
inline double TextAnnotation::font_size() const {
  // @@protoc_insertion_point(field_get:foxglove.TextAnnotation.font_size)
  return _internal_font_size();
}
inline void TextAnnotation::_internal_set_font_size(double value) {
  
  _impl_.font_size_ = value;
}
inline void TextAnnotation::set_font_size(double value) {
  _internal_set_font_size(value);
  // @@protoc_insertion_point(field_set:foxglove.TextAnnotation.font_size)
}

// .foxglove.Color text_color = 5;
inline bool TextAnnotation::_internal_has_text_color() const {
  return this != internal_default_instance() && _impl_.text_color_ != nullptr;
}
inline bool TextAnnotation::has_text_color() const {
  return _internal_has_text_color();
}
inline const ::foxglove::Color& TextAnnotation::_internal_text_color() const {
  const ::foxglove::Color* p = _impl_.text_color_;
  return p != nullptr ? *p : reinterpret_cast<const ::foxglove::Color&>(
      ::foxglove::_Color_default_instance_);
}
inline const ::foxglove::Color& TextAnnotation::text_color() const {
  // @@protoc_insertion_point(field_get:foxglove.TextAnnotation.text_color)
  return _internal_text_color();
}
inline void TextAnnotation::unsafe_arena_set_allocated_text_color(
    ::foxglove::Color* text_color) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.text_color_);
  }
  _impl_.text_color_ = text_color;
  if (text_color) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.TextAnnotation.text_color)
}
inline ::foxglove::Color* TextAnnotation::release_text_color() {
  
  ::foxglove::Color* temp = _impl_.text_color_;
  _impl_.text_color_ = nullptr;
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
inline ::foxglove::Color* TextAnnotation::unsafe_arena_release_text_color() {
  // @@protoc_insertion_point(field_release:foxglove.TextAnnotation.text_color)
  
  ::foxglove::Color* temp = _impl_.text_color_;
  _impl_.text_color_ = nullptr;
  return temp;
}
inline ::foxglove::Color* TextAnnotation::_internal_mutable_text_color() {
  
  if (_impl_.text_color_ == nullptr) {
    auto* p = CreateMaybeMessage<::foxglove::Color>(GetArenaForAllocation());
    _impl_.text_color_ = p;
  }
  return _impl_.text_color_;
}
inline ::foxglove::Color* TextAnnotation::mutable_text_color() {
  ::foxglove::Color* _msg = _internal_mutable_text_color();
  // @@protoc_insertion_point(field_mutable:foxglove.TextAnnotation.text_color)
  return _msg;
}
inline void TextAnnotation::set_allocated_text_color(::foxglove::Color* text_color) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.text_color_);
  }
  if (text_color) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(text_color));
    if (message_arena != submessage_arena) {
      text_color = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, text_color, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.text_color_ = text_color;
  // @@protoc_insertion_point(field_set_allocated:foxglove.TextAnnotation.text_color)
}

// .foxglove.Color background_color = 6;
inline bool TextAnnotation::_internal_has_background_color() const {
  return this != internal_default_instance() && _impl_.background_color_ != nullptr;
}
inline bool TextAnnotation::has_background_color() const {
  return _internal_has_background_color();
}
inline const ::foxglove::Color& TextAnnotation::_internal_background_color() const {
  const ::foxglove::Color* p = _impl_.background_color_;
  return p != nullptr ? *p : reinterpret_cast<const ::foxglove::Color&>(
      ::foxglove::_Color_default_instance_);
}
inline const ::foxglove::Color& TextAnnotation::background_color() const {
  // @@protoc_insertion_point(field_get:foxglove.TextAnnotation.background_color)
  return _internal_background_color();
}
inline void TextAnnotation::unsafe_arena_set_allocated_background_color(
    ::foxglove::Color* background_color) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.background_color_);
  }
  _impl_.background_color_ = background_color;
  if (background_color) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:foxglove.TextAnnotation.background_color)
}
inline ::foxglove::Color* TextAnnotation::release_background_color() {
  
  ::foxglove::Color* temp = _impl_.background_color_;
  _impl_.background_color_ = nullptr;
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
inline ::foxglove::Color* TextAnnotation::unsafe_arena_release_background_color() {
  // @@protoc_insertion_point(field_release:foxglove.TextAnnotation.background_color)
  
  ::foxglove::Color* temp = _impl_.background_color_;
  _impl_.background_color_ = nullptr;
  return temp;
}
inline ::foxglove::Color* TextAnnotation::_internal_mutable_background_color() {
  
  if (_impl_.background_color_ == nullptr) {
    auto* p = CreateMaybeMessage<::foxglove::Color>(GetArenaForAllocation());
    _impl_.background_color_ = p;
  }
  return _impl_.background_color_;
}
inline ::foxglove::Color* TextAnnotation::mutable_background_color() {
  ::foxglove::Color* _msg = _internal_mutable_background_color();
  // @@protoc_insertion_point(field_mutable:foxglove.TextAnnotation.background_color)
  return _msg;
}
inline void TextAnnotation::set_allocated_background_color(::foxglove::Color* background_color) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.background_color_);
  }
  if (background_color) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(background_color));
    if (message_arena != submessage_arena) {
      background_color = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, background_color, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.background_color_ = background_color;
  // @@protoc_insertion_point(field_set_allocated:foxglove.TextAnnotation.background_color)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace foxglove

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_foxglove_2fTextAnnotation_2eproto
