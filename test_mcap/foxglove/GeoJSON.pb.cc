// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/GeoJSON.proto

#include "foxglove/GeoJSON.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace foxglove {
PROTOBUF_CONSTEXPR GeoJSON::GeoJSON(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.geojson_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct GeoJSONDefaultTypeInternal {
  PROTOBUF_CONSTEXPR GeoJSONDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~GeoJSONDefaultTypeInternal() {}
  union {
    GeoJSON _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 GeoJSONDefaultTypeInternal _GeoJSON_default_instance_;
}  // namespace foxglove
static ::_pb::Metadata file_level_metadata_foxglove_2fGeoJSON_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_foxglove_2fGeoJSON_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_foxglove_2fGeoJSON_2eproto = nullptr;

const uint32_t TableStruct_foxglove_2fGeoJSON_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::foxglove::GeoJSON, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::foxglove::GeoJSON, _impl_.geojson_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::foxglove::GeoJSON)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::foxglove::_GeoJSON_default_instance_._instance,
};

const char descriptor_table_protodef_foxglove_2fGeoJSON_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026foxglove/GeoJSON.proto\022\010foxglove\"\032\n\007Ge"
  "oJSON\022\017\n\007geojson\030\001 \001(\tb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_foxglove_2fGeoJSON_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_foxglove_2fGeoJSON_2eproto = {
    false, false, 70, descriptor_table_protodef_foxglove_2fGeoJSON_2eproto,
    "foxglove/GeoJSON.proto",
    &descriptor_table_foxglove_2fGeoJSON_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_foxglove_2fGeoJSON_2eproto::offsets,
    file_level_metadata_foxglove_2fGeoJSON_2eproto, file_level_enum_descriptors_foxglove_2fGeoJSON_2eproto,
    file_level_service_descriptors_foxglove_2fGeoJSON_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_foxglove_2fGeoJSON_2eproto_getter() {
  return &descriptor_table_foxglove_2fGeoJSON_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_foxglove_2fGeoJSON_2eproto(&descriptor_table_foxglove_2fGeoJSON_2eproto);
namespace foxglove {

// ===================================================================

class GeoJSON::_Internal {
 public:
};

GeoJSON::GeoJSON(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:foxglove.GeoJSON)
}
GeoJSON::GeoJSON(const GeoJSON& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  GeoJSON* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.geojson_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.geojson_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.geojson_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_geojson().empty()) {
    _this->_impl_.geojson_.Set(from._internal_geojson(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:foxglove.GeoJSON)
}

inline void GeoJSON::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.geojson_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.geojson_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.geojson_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

GeoJSON::~GeoJSON() {
  // @@protoc_insertion_point(destructor:foxglove.GeoJSON)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void GeoJSON::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.geojson_.Destroy();
}

void GeoJSON::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void GeoJSON::Clear() {
// @@protoc_insertion_point(message_clear_start:foxglove.GeoJSON)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.geojson_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GeoJSON::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string geojson = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_geojson();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "foxglove.GeoJSON.geojson"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* GeoJSON::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:foxglove.GeoJSON)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string geojson = 1;
  if (!this->_internal_geojson().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_geojson().data(), static_cast<int>(this->_internal_geojson().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "foxglove.GeoJSON.geojson");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_geojson(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:foxglove.GeoJSON)
  return target;
}

size_t GeoJSON::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:foxglove.GeoJSON)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string geojson = 1;
  if (!this->_internal_geojson().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_geojson());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GeoJSON::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    GeoJSON::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GeoJSON::GetClassData() const { return &_class_data_; }


void GeoJSON::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<GeoJSON*>(&to_msg);
  auto& from = static_cast<const GeoJSON&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:foxglove.GeoJSON)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_geojson().empty()) {
    _this->_internal_set_geojson(from._internal_geojson());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GeoJSON::CopyFrom(const GeoJSON& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:foxglove.GeoJSON)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GeoJSON::IsInitialized() const {
  return true;
}

void GeoJSON::InternalSwap(GeoJSON* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.geojson_, lhs_arena,
      &other->_impl_.geojson_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata GeoJSON::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_foxglove_2fGeoJSON_2eproto_getter, &descriptor_table_foxglove_2fGeoJSON_2eproto_once,
      file_level_metadata_foxglove_2fGeoJSON_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::foxglove::GeoJSON*
Arena::CreateMaybeMessage< ::foxglove::GeoJSON >(Arena* arena) {
  return Arena::CreateMessageInternal< ::foxglove::GeoJSON >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
