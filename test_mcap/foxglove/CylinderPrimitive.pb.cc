// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/CylinderPrimitive.proto

#include "foxglove/CylinderPrimitive.pb.h"

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
PROTOBUF_CONSTEXPR CylinderPrimitive::CylinderPrimitive(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.pose_)*/nullptr
  , /*decltype(_impl_.size_)*/nullptr
  , /*decltype(_impl_.color_)*/nullptr
  , /*decltype(_impl_.bottom_scale_)*/0
  , /*decltype(_impl_.top_scale_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct CylinderPrimitiveDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CylinderPrimitiveDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CylinderPrimitiveDefaultTypeInternal() {}
  union {
    CylinderPrimitive _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CylinderPrimitiveDefaultTypeInternal _CylinderPrimitive_default_instance_;
}  // namespace foxglove
static ::_pb::Metadata file_level_metadata_foxglove_2fCylinderPrimitive_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_foxglove_2fCylinderPrimitive_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_foxglove_2fCylinderPrimitive_2eproto = nullptr;

const uint32_t TableStruct_foxglove_2fCylinderPrimitive_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::foxglove::CylinderPrimitive, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::foxglove::CylinderPrimitive, _impl_.pose_),
  PROTOBUF_FIELD_OFFSET(::foxglove::CylinderPrimitive, _impl_.size_),
  PROTOBUF_FIELD_OFFSET(::foxglove::CylinderPrimitive, _impl_.bottom_scale_),
  PROTOBUF_FIELD_OFFSET(::foxglove::CylinderPrimitive, _impl_.top_scale_),
  PROTOBUF_FIELD_OFFSET(::foxglove::CylinderPrimitive, _impl_.color_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::foxglove::CylinderPrimitive)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::foxglove::_CylinderPrimitive_default_instance_._instance,
};

const char descriptor_table_protodef_foxglove_2fCylinderPrimitive_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n foxglove/CylinderPrimitive.proto\022\010foxg"
  "love\032\024foxglove/Color.proto\032\023foxglove/Pos"
  "e.proto\032\026foxglove/Vector3.proto\"\233\001\n\021Cyli"
  "nderPrimitive\022\034\n\004pose\030\001 \001(\0132\016.foxglove.P"
  "ose\022\037\n\004size\030\002 \001(\0132\021.foxglove.Vector3\022\024\n\014"
  "bottom_scale\030\003 \001(\001\022\021\n\ttop_scale\030\004 \001(\001\022\036\n"
  "\005color\030\005 \001(\0132\017.foxglove.Colorb\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_foxglove_2fCylinderPrimitive_2eproto_deps[3] = {
  &::descriptor_table_foxglove_2fColor_2eproto,
  &::descriptor_table_foxglove_2fPose_2eproto,
  &::descriptor_table_foxglove_2fVector3_2eproto,
};
static ::_pbi::once_flag descriptor_table_foxglove_2fCylinderPrimitive_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_foxglove_2fCylinderPrimitive_2eproto = {
    false, false, 277, descriptor_table_protodef_foxglove_2fCylinderPrimitive_2eproto,
    "foxglove/CylinderPrimitive.proto",
    &descriptor_table_foxglove_2fCylinderPrimitive_2eproto_once, descriptor_table_foxglove_2fCylinderPrimitive_2eproto_deps, 3, 1,
    schemas, file_default_instances, TableStruct_foxglove_2fCylinderPrimitive_2eproto::offsets,
    file_level_metadata_foxglove_2fCylinderPrimitive_2eproto, file_level_enum_descriptors_foxglove_2fCylinderPrimitive_2eproto,
    file_level_service_descriptors_foxglove_2fCylinderPrimitive_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_foxglove_2fCylinderPrimitive_2eproto_getter() {
  return &descriptor_table_foxglove_2fCylinderPrimitive_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_foxglove_2fCylinderPrimitive_2eproto(&descriptor_table_foxglove_2fCylinderPrimitive_2eproto);
namespace foxglove {

// ===================================================================

class CylinderPrimitive::_Internal {
 public:
  static const ::foxglove::Pose& pose(const CylinderPrimitive* msg);
  static const ::foxglove::Vector3& size(const CylinderPrimitive* msg);
  static const ::foxglove::Color& color(const CylinderPrimitive* msg);
};

const ::foxglove::Pose&
CylinderPrimitive::_Internal::pose(const CylinderPrimitive* msg) {
  return *msg->_impl_.pose_;
}
const ::foxglove::Vector3&
CylinderPrimitive::_Internal::size(const CylinderPrimitive* msg) {
  return *msg->_impl_.size_;
}
const ::foxglove::Color&
CylinderPrimitive::_Internal::color(const CylinderPrimitive* msg) {
  return *msg->_impl_.color_;
}
void CylinderPrimitive::clear_pose() {
  if (GetArenaForAllocation() == nullptr && _impl_.pose_ != nullptr) {
    delete _impl_.pose_;
  }
  _impl_.pose_ = nullptr;
}
void CylinderPrimitive::clear_size() {
  if (GetArenaForAllocation() == nullptr && _impl_.size_ != nullptr) {
    delete _impl_.size_;
  }
  _impl_.size_ = nullptr;
}
void CylinderPrimitive::clear_color() {
  if (GetArenaForAllocation() == nullptr && _impl_.color_ != nullptr) {
    delete _impl_.color_;
  }
  _impl_.color_ = nullptr;
}
CylinderPrimitive::CylinderPrimitive(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:foxglove.CylinderPrimitive)
}
CylinderPrimitive::CylinderPrimitive(const CylinderPrimitive& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  CylinderPrimitive* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.pose_){nullptr}
    , decltype(_impl_.size_){nullptr}
    , decltype(_impl_.color_){nullptr}
    , decltype(_impl_.bottom_scale_){}
    , decltype(_impl_.top_scale_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_pose()) {
    _this->_impl_.pose_ = new ::foxglove::Pose(*from._impl_.pose_);
  }
  if (from._internal_has_size()) {
    _this->_impl_.size_ = new ::foxglove::Vector3(*from._impl_.size_);
  }
  if (from._internal_has_color()) {
    _this->_impl_.color_ = new ::foxglove::Color(*from._impl_.color_);
  }
  ::memcpy(&_impl_.bottom_scale_, &from._impl_.bottom_scale_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.top_scale_) -
    reinterpret_cast<char*>(&_impl_.bottom_scale_)) + sizeof(_impl_.top_scale_));
  // @@protoc_insertion_point(copy_constructor:foxglove.CylinderPrimitive)
}

inline void CylinderPrimitive::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.pose_){nullptr}
    , decltype(_impl_.size_){nullptr}
    , decltype(_impl_.color_){nullptr}
    , decltype(_impl_.bottom_scale_){0}
    , decltype(_impl_.top_scale_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

CylinderPrimitive::~CylinderPrimitive() {
  // @@protoc_insertion_point(destructor:foxglove.CylinderPrimitive)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CylinderPrimitive::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.pose_;
  if (this != internal_default_instance()) delete _impl_.size_;
  if (this != internal_default_instance()) delete _impl_.color_;
}

void CylinderPrimitive::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CylinderPrimitive::Clear() {
// @@protoc_insertion_point(message_clear_start:foxglove.CylinderPrimitive)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && _impl_.pose_ != nullptr) {
    delete _impl_.pose_;
  }
  _impl_.pose_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.size_ != nullptr) {
    delete _impl_.size_;
  }
  _impl_.size_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.color_ != nullptr) {
    delete _impl_.color_;
  }
  _impl_.color_ = nullptr;
  ::memset(&_impl_.bottom_scale_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.top_scale_) -
      reinterpret_cast<char*>(&_impl_.bottom_scale_)) + sizeof(_impl_.top_scale_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CylinderPrimitive::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .foxglove.Pose pose = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_pose(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .foxglove.Vector3 size = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_size(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double bottom_scale = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 25)) {
          _impl_.bottom_scale_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double top_scale = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 33)) {
          _impl_.top_scale_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // .foxglove.Color color = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          ptr = ctx->ParseMessage(_internal_mutable_color(), ptr);
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

uint8_t* CylinderPrimitive::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:foxglove.CylinderPrimitive)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .foxglove.Pose pose = 1;
  if (this->_internal_has_pose()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::pose(this),
        _Internal::pose(this).GetCachedSize(), target, stream);
  }

  // .foxglove.Vector3 size = 2;
  if (this->_internal_has_size()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::size(this),
        _Internal::size(this).GetCachedSize(), target, stream);
  }

  // double bottom_scale = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_bottom_scale = this->_internal_bottom_scale();
  uint64_t raw_bottom_scale;
  memcpy(&raw_bottom_scale, &tmp_bottom_scale, sizeof(tmp_bottom_scale));
  if (raw_bottom_scale != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(3, this->_internal_bottom_scale(), target);
  }

  // double top_scale = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_top_scale = this->_internal_top_scale();
  uint64_t raw_top_scale;
  memcpy(&raw_top_scale, &tmp_top_scale, sizeof(tmp_top_scale));
  if (raw_top_scale != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(4, this->_internal_top_scale(), target);
  }

  // .foxglove.Color color = 5;
  if (this->_internal_has_color()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, _Internal::color(this),
        _Internal::color(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:foxglove.CylinderPrimitive)
  return target;
}

size_t CylinderPrimitive::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:foxglove.CylinderPrimitive)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .foxglove.Pose pose = 1;
  if (this->_internal_has_pose()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.pose_);
  }

  // .foxglove.Vector3 size = 2;
  if (this->_internal_has_size()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.size_);
  }

  // .foxglove.Color color = 5;
  if (this->_internal_has_color()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.color_);
  }

  // double bottom_scale = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_bottom_scale = this->_internal_bottom_scale();
  uint64_t raw_bottom_scale;
  memcpy(&raw_bottom_scale, &tmp_bottom_scale, sizeof(tmp_bottom_scale));
  if (raw_bottom_scale != 0) {
    total_size += 1 + 8;
  }

  // double top_scale = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_top_scale = this->_internal_top_scale();
  uint64_t raw_top_scale;
  memcpy(&raw_top_scale, &tmp_top_scale, sizeof(tmp_top_scale));
  if (raw_top_scale != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CylinderPrimitive::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CylinderPrimitive::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CylinderPrimitive::GetClassData() const { return &_class_data_; }


void CylinderPrimitive::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CylinderPrimitive*>(&to_msg);
  auto& from = static_cast<const CylinderPrimitive&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:foxglove.CylinderPrimitive)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_pose()) {
    _this->_internal_mutable_pose()->::foxglove::Pose::MergeFrom(
        from._internal_pose());
  }
  if (from._internal_has_size()) {
    _this->_internal_mutable_size()->::foxglove::Vector3::MergeFrom(
        from._internal_size());
  }
  if (from._internal_has_color()) {
    _this->_internal_mutable_color()->::foxglove::Color::MergeFrom(
        from._internal_color());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_bottom_scale = from._internal_bottom_scale();
  uint64_t raw_bottom_scale;
  memcpy(&raw_bottom_scale, &tmp_bottom_scale, sizeof(tmp_bottom_scale));
  if (raw_bottom_scale != 0) {
    _this->_internal_set_bottom_scale(from._internal_bottom_scale());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_top_scale = from._internal_top_scale();
  uint64_t raw_top_scale;
  memcpy(&raw_top_scale, &tmp_top_scale, sizeof(tmp_top_scale));
  if (raw_top_scale != 0) {
    _this->_internal_set_top_scale(from._internal_top_scale());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CylinderPrimitive::CopyFrom(const CylinderPrimitive& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:foxglove.CylinderPrimitive)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CylinderPrimitive::IsInitialized() const {
  return true;
}

void CylinderPrimitive::InternalSwap(CylinderPrimitive* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(CylinderPrimitive, _impl_.top_scale_)
      + sizeof(CylinderPrimitive::_impl_.top_scale_)
      - PROTOBUF_FIELD_OFFSET(CylinderPrimitive, _impl_.pose_)>(
          reinterpret_cast<char*>(&_impl_.pose_),
          reinterpret_cast<char*>(&other->_impl_.pose_));
}

::PROTOBUF_NAMESPACE_ID::Metadata CylinderPrimitive::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_foxglove_2fCylinderPrimitive_2eproto_getter, &descriptor_table_foxglove_2fCylinderPrimitive_2eproto_once,
      file_level_metadata_foxglove_2fCylinderPrimitive_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::foxglove::CylinderPrimitive*
Arena::CreateMaybeMessage< ::foxglove::CylinderPrimitive >(Arena* arena) {
  return Arena::CreateMessageInternal< ::foxglove::CylinderPrimitive >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
