// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/FrameTransform.proto

#include "foxglove/FrameTransform.pb.h"

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
PROTOBUF_CONSTEXPR FrameTransform::FrameTransform(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.parent_frame_id_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.child_frame_id_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.timestamp_)*/nullptr
  , /*decltype(_impl_.translation_)*/nullptr
  , /*decltype(_impl_.rotation_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct FrameTransformDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FrameTransformDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~FrameTransformDefaultTypeInternal() {}
  union {
    FrameTransform _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FrameTransformDefaultTypeInternal _FrameTransform_default_instance_;
}  // namespace foxglove
static ::_pb::Metadata file_level_metadata_foxglove_2fFrameTransform_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_foxglove_2fFrameTransform_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_foxglove_2fFrameTransform_2eproto = nullptr;

const uint32_t TableStruct_foxglove_2fFrameTransform_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::foxglove::FrameTransform, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::foxglove::FrameTransform, _impl_.timestamp_),
  PROTOBUF_FIELD_OFFSET(::foxglove::FrameTransform, _impl_.parent_frame_id_),
  PROTOBUF_FIELD_OFFSET(::foxglove::FrameTransform, _impl_.child_frame_id_),
  PROTOBUF_FIELD_OFFSET(::foxglove::FrameTransform, _impl_.translation_),
  PROTOBUF_FIELD_OFFSET(::foxglove::FrameTransform, _impl_.rotation_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::foxglove::FrameTransform)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::foxglove::_FrameTransform_default_instance_._instance,
};

const char descriptor_table_protodef_foxglove_2fFrameTransform_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\035foxglove/FrameTransform.proto\022\010foxglov"
  "e\032\031foxglove/Quaternion.proto\032\026foxglove/V"
  "ector3.proto\032\037google/protobuf/timestamp."
  "proto\"\300\001\n\016FrameTransform\022-\n\ttimestamp\030\001 "
  "\001(\0132\032.google.protobuf.Timestamp\022\027\n\017paren"
  "t_frame_id\030\002 \001(\t\022\026\n\016child_frame_id\030\003 \001(\t"
  "\022&\n\013translation\030\004 \001(\0132\021.foxglove.Vector3"
  "\022&\n\010rotation\030\005 \001(\0132\024.foxglove.Quaternion"
  "b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_foxglove_2fFrameTransform_2eproto_deps[3] = {
  &::descriptor_table_foxglove_2fQuaternion_2eproto,
  &::descriptor_table_foxglove_2fVector3_2eproto,
  &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::_pbi::once_flag descriptor_table_foxglove_2fFrameTransform_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_foxglove_2fFrameTransform_2eproto = {
    false, false, 328, descriptor_table_protodef_foxglove_2fFrameTransform_2eproto,
    "foxglove/FrameTransform.proto",
    &descriptor_table_foxglove_2fFrameTransform_2eproto_once, descriptor_table_foxglove_2fFrameTransform_2eproto_deps, 3, 1,
    schemas, file_default_instances, TableStruct_foxglove_2fFrameTransform_2eproto::offsets,
    file_level_metadata_foxglove_2fFrameTransform_2eproto, file_level_enum_descriptors_foxglove_2fFrameTransform_2eproto,
    file_level_service_descriptors_foxglove_2fFrameTransform_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_foxglove_2fFrameTransform_2eproto_getter() {
  return &descriptor_table_foxglove_2fFrameTransform_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_foxglove_2fFrameTransform_2eproto(&descriptor_table_foxglove_2fFrameTransform_2eproto);
namespace foxglove {

// ===================================================================

class FrameTransform::_Internal {
 public:
  static const ::PROTOBUF_NAMESPACE_ID::Timestamp& timestamp(const FrameTransform* msg);
  static const ::foxglove::Vector3& translation(const FrameTransform* msg);
  static const ::foxglove::Quaternion& rotation(const FrameTransform* msg);
};

const ::PROTOBUF_NAMESPACE_ID::Timestamp&
FrameTransform::_Internal::timestamp(const FrameTransform* msg) {
  return *msg->_impl_.timestamp_;
}
const ::foxglove::Vector3&
FrameTransform::_Internal::translation(const FrameTransform* msg) {
  return *msg->_impl_.translation_;
}
const ::foxglove::Quaternion&
FrameTransform::_Internal::rotation(const FrameTransform* msg) {
  return *msg->_impl_.rotation_;
}
void FrameTransform::clear_timestamp() {
  if (GetArenaForAllocation() == nullptr && _impl_.timestamp_ != nullptr) {
    delete _impl_.timestamp_;
  }
  _impl_.timestamp_ = nullptr;
}
void FrameTransform::clear_translation() {
  if (GetArenaForAllocation() == nullptr && _impl_.translation_ != nullptr) {
    delete _impl_.translation_;
  }
  _impl_.translation_ = nullptr;
}
void FrameTransform::clear_rotation() {
  if (GetArenaForAllocation() == nullptr && _impl_.rotation_ != nullptr) {
    delete _impl_.rotation_;
  }
  _impl_.rotation_ = nullptr;
}
FrameTransform::FrameTransform(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:foxglove.FrameTransform)
}
FrameTransform::FrameTransform(const FrameTransform& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  FrameTransform* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.parent_frame_id_){}
    , decltype(_impl_.child_frame_id_){}
    , decltype(_impl_.timestamp_){nullptr}
    , decltype(_impl_.translation_){nullptr}
    , decltype(_impl_.rotation_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.parent_frame_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.parent_frame_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_parent_frame_id().empty()) {
    _this->_impl_.parent_frame_id_.Set(from._internal_parent_frame_id(), 
      _this->GetArenaForAllocation());
  }
  _impl_.child_frame_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.child_frame_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_child_frame_id().empty()) {
    _this->_impl_.child_frame_id_.Set(from._internal_child_frame_id(), 
      _this->GetArenaForAllocation());
  }
  if (from._internal_has_timestamp()) {
    _this->_impl_.timestamp_ = new ::PROTOBUF_NAMESPACE_ID::Timestamp(*from._impl_.timestamp_);
  }
  if (from._internal_has_translation()) {
    _this->_impl_.translation_ = new ::foxglove::Vector3(*from._impl_.translation_);
  }
  if (from._internal_has_rotation()) {
    _this->_impl_.rotation_ = new ::foxglove::Quaternion(*from._impl_.rotation_);
  }
  // @@protoc_insertion_point(copy_constructor:foxglove.FrameTransform)
}

inline void FrameTransform::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.parent_frame_id_){}
    , decltype(_impl_.child_frame_id_){}
    , decltype(_impl_.timestamp_){nullptr}
    , decltype(_impl_.translation_){nullptr}
    , decltype(_impl_.rotation_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.parent_frame_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.parent_frame_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.child_frame_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.child_frame_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

FrameTransform::~FrameTransform() {
  // @@protoc_insertion_point(destructor:foxglove.FrameTransform)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void FrameTransform::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.parent_frame_id_.Destroy();
  _impl_.child_frame_id_.Destroy();
  if (this != internal_default_instance()) delete _impl_.timestamp_;
  if (this != internal_default_instance()) delete _impl_.translation_;
  if (this != internal_default_instance()) delete _impl_.rotation_;
}

void FrameTransform::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void FrameTransform::Clear() {
// @@protoc_insertion_point(message_clear_start:foxglove.FrameTransform)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.parent_frame_id_.ClearToEmpty();
  _impl_.child_frame_id_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && _impl_.timestamp_ != nullptr) {
    delete _impl_.timestamp_;
  }
  _impl_.timestamp_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.translation_ != nullptr) {
    delete _impl_.translation_;
  }
  _impl_.translation_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.rotation_ != nullptr) {
    delete _impl_.rotation_;
  }
  _impl_.rotation_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* FrameTransform::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .google.protobuf.Timestamp timestamp = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_timestamp(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string parent_frame_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_parent_frame_id();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "foxglove.FrameTransform.parent_frame_id"));
        } else
          goto handle_unusual;
        continue;
      // string child_frame_id = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_child_frame_id();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "foxglove.FrameTransform.child_frame_id"));
        } else
          goto handle_unusual;
        continue;
      // .foxglove.Vector3 translation = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_translation(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .foxglove.Quaternion rotation = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          ptr = ctx->ParseMessage(_internal_mutable_rotation(), ptr);
          CHK_(ptr);
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

uint8_t* FrameTransform::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:foxglove.FrameTransform)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .google.protobuf.Timestamp timestamp = 1;
  if (this->_internal_has_timestamp()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::timestamp(this),
        _Internal::timestamp(this).GetCachedSize(), target, stream);
  }

  // string parent_frame_id = 2;
  if (!this->_internal_parent_frame_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_parent_frame_id().data(), static_cast<int>(this->_internal_parent_frame_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "foxglove.FrameTransform.parent_frame_id");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_parent_frame_id(), target);
  }

  // string child_frame_id = 3;
  if (!this->_internal_child_frame_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_child_frame_id().data(), static_cast<int>(this->_internal_child_frame_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "foxglove.FrameTransform.child_frame_id");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_child_frame_id(), target);
  }

  // .foxglove.Vector3 translation = 4;
  if (this->_internal_has_translation()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, _Internal::translation(this),
        _Internal::translation(this).GetCachedSize(), target, stream);
  }

  // .foxglove.Quaternion rotation = 5;
  if (this->_internal_has_rotation()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, _Internal::rotation(this),
        _Internal::rotation(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:foxglove.FrameTransform)
  return target;
}

size_t FrameTransform::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:foxglove.FrameTransform)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string parent_frame_id = 2;
  if (!this->_internal_parent_frame_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_parent_frame_id());
  }

  // string child_frame_id = 3;
  if (!this->_internal_child_frame_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_child_frame_id());
  }

  // .google.protobuf.Timestamp timestamp = 1;
  if (this->_internal_has_timestamp()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.timestamp_);
  }

  // .foxglove.Vector3 translation = 4;
  if (this->_internal_has_translation()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.translation_);
  }

  // .foxglove.Quaternion rotation = 5;
  if (this->_internal_has_rotation()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.rotation_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData FrameTransform::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    FrameTransform::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*FrameTransform::GetClassData() const { return &_class_data_; }


void FrameTransform::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<FrameTransform*>(&to_msg);
  auto& from = static_cast<const FrameTransform&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:foxglove.FrameTransform)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_parent_frame_id().empty()) {
    _this->_internal_set_parent_frame_id(from._internal_parent_frame_id());
  }
  if (!from._internal_child_frame_id().empty()) {
    _this->_internal_set_child_frame_id(from._internal_child_frame_id());
  }
  if (from._internal_has_timestamp()) {
    _this->_internal_mutable_timestamp()->::PROTOBUF_NAMESPACE_ID::Timestamp::MergeFrom(
        from._internal_timestamp());
  }
  if (from._internal_has_translation()) {
    _this->_internal_mutable_translation()->::foxglove::Vector3::MergeFrom(
        from._internal_translation());
  }
  if (from._internal_has_rotation()) {
    _this->_internal_mutable_rotation()->::foxglove::Quaternion::MergeFrom(
        from._internal_rotation());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void FrameTransform::CopyFrom(const FrameTransform& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:foxglove.FrameTransform)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FrameTransform::IsInitialized() const {
  return true;
}

void FrameTransform::InternalSwap(FrameTransform* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.parent_frame_id_, lhs_arena,
      &other->_impl_.parent_frame_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.child_frame_id_, lhs_arena,
      &other->_impl_.child_frame_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(FrameTransform, _impl_.rotation_)
      + sizeof(FrameTransform::_impl_.rotation_)
      - PROTOBUF_FIELD_OFFSET(FrameTransform, _impl_.timestamp_)>(
          reinterpret_cast<char*>(&_impl_.timestamp_),
          reinterpret_cast<char*>(&other->_impl_.timestamp_));
}

::PROTOBUF_NAMESPACE_ID::Metadata FrameTransform::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_foxglove_2fFrameTransform_2eproto_getter, &descriptor_table_foxglove_2fFrameTransform_2eproto_once,
      file_level_metadata_foxglove_2fFrameTransform_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::foxglove::FrameTransform*
Arena::CreateMaybeMessage< ::foxglove::FrameTransform >(Arena* arena) {
  return Arena::CreateMessageInternal< ::foxglove::FrameTransform >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>