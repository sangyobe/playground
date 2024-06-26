// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/GeoJSON.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_foxglove_2fGeoJSON_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_foxglove_2fGeoJSON_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_foxglove_2fGeoJSON_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_foxglove_2fGeoJSON_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_foxglove_2fGeoJSON_2eproto;
namespace foxglove {
class GeoJSON;
struct GeoJSONDefaultTypeInternal;
extern GeoJSONDefaultTypeInternal _GeoJSON_default_instance_;
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> ::foxglove::GeoJSON* Arena::CreateMaybeMessage<::foxglove::GeoJSON>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace foxglove {

// ===================================================================

class GeoJSON final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:foxglove.GeoJSON) */ {
 public:
  inline GeoJSON() : GeoJSON(nullptr) {}
  ~GeoJSON() override;
  explicit PROTOBUF_CONSTEXPR GeoJSON(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  GeoJSON(const GeoJSON& from);
  GeoJSON(GeoJSON&& from) noexcept
    : GeoJSON() {
    *this = ::std::move(from);
  }

  inline GeoJSON& operator=(const GeoJSON& from) {
    CopyFrom(from);
    return *this;
  }
  inline GeoJSON& operator=(GeoJSON&& from) noexcept {
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
  static const GeoJSON& default_instance() {
    return *internal_default_instance();
  }
  static inline const GeoJSON* internal_default_instance() {
    return reinterpret_cast<const GeoJSON*>(
               &_GeoJSON_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GeoJSON& a, GeoJSON& b) {
    a.Swap(&b);
  }
  inline void Swap(GeoJSON* other) {
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
  void UnsafeArenaSwap(GeoJSON* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  GeoJSON* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<GeoJSON>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const GeoJSON& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const GeoJSON& from) {
    GeoJSON::MergeImpl(*this, from);
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
  void InternalSwap(GeoJSON* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "foxglove.GeoJSON";
  }
  protected:
  explicit GeoJSON(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kGeojsonFieldNumber = 1,
  };
  // string geojson = 1;
  void clear_geojson();
  const std::string& geojson() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_geojson(ArgT0&& arg0, ArgT... args);
  std::string* mutable_geojson();
  PROTOBUF_NODISCARD std::string* release_geojson();
  void set_allocated_geojson(std::string* geojson);
  private:
  const std::string& _internal_geojson() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_geojson(const std::string& value);
  std::string* _internal_mutable_geojson();
  public:

  // @@protoc_insertion_point(class_scope:foxglove.GeoJSON)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr geojson_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_foxglove_2fGeoJSON_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GeoJSON

// string geojson = 1;
inline void GeoJSON::clear_geojson() {
  _impl_.geojson_.ClearToEmpty();
}
inline const std::string& GeoJSON::geojson() const {
  // @@protoc_insertion_point(field_get:foxglove.GeoJSON.geojson)
  return _internal_geojson();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void GeoJSON::set_geojson(ArgT0&& arg0, ArgT... args) {
 
 _impl_.geojson_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:foxglove.GeoJSON.geojson)
}
inline std::string* GeoJSON::mutable_geojson() {
  std::string* _s = _internal_mutable_geojson();
  // @@protoc_insertion_point(field_mutable:foxglove.GeoJSON.geojson)
  return _s;
}
inline const std::string& GeoJSON::_internal_geojson() const {
  return _impl_.geojson_.Get();
}
inline void GeoJSON::_internal_set_geojson(const std::string& value) {
  
  _impl_.geojson_.Set(value, GetArenaForAllocation());
}
inline std::string* GeoJSON::_internal_mutable_geojson() {
  
  return _impl_.geojson_.Mutable(GetArenaForAllocation());
}
inline std::string* GeoJSON::release_geojson() {
  // @@protoc_insertion_point(field_release:foxglove.GeoJSON.geojson)
  return _impl_.geojson_.Release();
}
inline void GeoJSON::set_allocated_geojson(std::string* geojson) {
  if (geojson != nullptr) {
    
  } else {
    
  }
  _impl_.geojson_.SetAllocated(geojson, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.geojson_.IsDefault()) {
    _impl_.geojson_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:foxglove.GeoJSON.geojson)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace foxglove

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_foxglove_2fGeoJSON_2eproto
