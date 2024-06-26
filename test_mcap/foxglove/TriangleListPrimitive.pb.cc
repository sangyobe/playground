// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/TriangleListPrimitive.proto

#include "foxglove/TriangleListPrimitive.pb.h"

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
PROTOBUF_CONSTEXPR TriangleListPrimitive::TriangleListPrimitive(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.points_)*/{}
  , /*decltype(_impl_.colors_)*/{}
  , /*decltype(_impl_.indices_)*/{}
  , /*decltype(_impl_.pose_)*/nullptr
  , /*decltype(_impl_.color_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct TriangleListPrimitiveDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TriangleListPrimitiveDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~TriangleListPrimitiveDefaultTypeInternal() {}
  union {
    TriangleListPrimitive _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TriangleListPrimitiveDefaultTypeInternal _TriangleListPrimitive_default_instance_;
}  // namespace foxglove
static ::_pb::Metadata file_level_metadata_foxglove_2fTriangleListPrimitive_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_foxglove_2fTriangleListPrimitive_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_foxglove_2fTriangleListPrimitive_2eproto = nullptr;

const uint32_t TableStruct_foxglove_2fTriangleListPrimitive_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::foxglove::TriangleListPrimitive, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::foxglove::TriangleListPrimitive, _impl_.pose_),
  PROTOBUF_FIELD_OFFSET(::foxglove::TriangleListPrimitive, _impl_.points_),
  PROTOBUF_FIELD_OFFSET(::foxglove::TriangleListPrimitive, _impl_.color_),
  PROTOBUF_FIELD_OFFSET(::foxglove::TriangleListPrimitive, _impl_.colors_),
  PROTOBUF_FIELD_OFFSET(::foxglove::TriangleListPrimitive, _impl_.indices_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::foxglove::TriangleListPrimitive)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::foxglove::_TriangleListPrimitive_default_instance_._instance,
};

const char descriptor_table_protodef_foxglove_2fTriangleListPrimitive_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n$foxglove/TriangleListPrimitive.proto\022\010"
  "foxglove\032\024foxglove/Color.proto\032\025foxglove"
  "/Point3.proto\032\023foxglove/Pose.proto\"\251\001\n\025T"
  "riangleListPrimitive\022\034\n\004pose\030\001 \001(\0132\016.fox"
  "glove.Pose\022 \n\006points\030\002 \003(\0132\020.foxglove.Po"
  "int3\022\036\n\005color\030\003 \001(\0132\017.foxglove.Color\022\037\n\006"
  "colors\030\004 \003(\0132\017.foxglove.Color\022\017\n\007indices"
  "\030\005 \003(\007b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_foxglove_2fTriangleListPrimitive_2eproto_deps[3] = {
  &::descriptor_table_foxglove_2fColor_2eproto,
  &::descriptor_table_foxglove_2fPoint3_2eproto,
  &::descriptor_table_foxglove_2fPose_2eproto,
};
static ::_pbi::once_flag descriptor_table_foxglove_2fTriangleListPrimitive_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_foxglove_2fTriangleListPrimitive_2eproto = {
    false, false, 294, descriptor_table_protodef_foxglove_2fTriangleListPrimitive_2eproto,
    "foxglove/TriangleListPrimitive.proto",
    &descriptor_table_foxglove_2fTriangleListPrimitive_2eproto_once, descriptor_table_foxglove_2fTriangleListPrimitive_2eproto_deps, 3, 1,
    schemas, file_default_instances, TableStruct_foxglove_2fTriangleListPrimitive_2eproto::offsets,
    file_level_metadata_foxglove_2fTriangleListPrimitive_2eproto, file_level_enum_descriptors_foxglove_2fTriangleListPrimitive_2eproto,
    file_level_service_descriptors_foxglove_2fTriangleListPrimitive_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_foxglove_2fTriangleListPrimitive_2eproto_getter() {
  return &descriptor_table_foxglove_2fTriangleListPrimitive_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_foxglove_2fTriangleListPrimitive_2eproto(&descriptor_table_foxglove_2fTriangleListPrimitive_2eproto);
namespace foxglove {

// ===================================================================

class TriangleListPrimitive::_Internal {
 public:
  static const ::foxglove::Pose& pose(const TriangleListPrimitive* msg);
  static const ::foxglove::Color& color(const TriangleListPrimitive* msg);
};

const ::foxglove::Pose&
TriangleListPrimitive::_Internal::pose(const TriangleListPrimitive* msg) {
  return *msg->_impl_.pose_;
}
const ::foxglove::Color&
TriangleListPrimitive::_Internal::color(const TriangleListPrimitive* msg) {
  return *msg->_impl_.color_;
}
void TriangleListPrimitive::clear_pose() {
  if (GetArenaForAllocation() == nullptr && _impl_.pose_ != nullptr) {
    delete _impl_.pose_;
  }
  _impl_.pose_ = nullptr;
}
void TriangleListPrimitive::clear_points() {
  _impl_.points_.Clear();
}
void TriangleListPrimitive::clear_color() {
  if (GetArenaForAllocation() == nullptr && _impl_.color_ != nullptr) {
    delete _impl_.color_;
  }
  _impl_.color_ = nullptr;
}
void TriangleListPrimitive::clear_colors() {
  _impl_.colors_.Clear();
}
TriangleListPrimitive::TriangleListPrimitive(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:foxglove.TriangleListPrimitive)
}
TriangleListPrimitive::TriangleListPrimitive(const TriangleListPrimitive& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  TriangleListPrimitive* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.points_){from._impl_.points_}
    , decltype(_impl_.colors_){from._impl_.colors_}
    , decltype(_impl_.indices_){from._impl_.indices_}
    , decltype(_impl_.pose_){nullptr}
    , decltype(_impl_.color_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_pose()) {
    _this->_impl_.pose_ = new ::foxglove::Pose(*from._impl_.pose_);
  }
  if (from._internal_has_color()) {
    _this->_impl_.color_ = new ::foxglove::Color(*from._impl_.color_);
  }
  // @@protoc_insertion_point(copy_constructor:foxglove.TriangleListPrimitive)
}

inline void TriangleListPrimitive::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.points_){arena}
    , decltype(_impl_.colors_){arena}
    , decltype(_impl_.indices_){arena}
    , decltype(_impl_.pose_){nullptr}
    , decltype(_impl_.color_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

TriangleListPrimitive::~TriangleListPrimitive() {
  // @@protoc_insertion_point(destructor:foxglove.TriangleListPrimitive)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void TriangleListPrimitive::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.points_.~RepeatedPtrField();
  _impl_.colors_.~RepeatedPtrField();
  _impl_.indices_.~RepeatedField();
  if (this != internal_default_instance()) delete _impl_.pose_;
  if (this != internal_default_instance()) delete _impl_.color_;
}

void TriangleListPrimitive::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void TriangleListPrimitive::Clear() {
// @@protoc_insertion_point(message_clear_start:foxglove.TriangleListPrimitive)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.points_.Clear();
  _impl_.colors_.Clear();
  _impl_.indices_.Clear();
  if (GetArenaForAllocation() == nullptr && _impl_.pose_ != nullptr) {
    delete _impl_.pose_;
  }
  _impl_.pose_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.color_ != nullptr) {
    delete _impl_.color_;
  }
  _impl_.color_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TriangleListPrimitive::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
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
      // repeated .foxglove.Point3 points = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_points(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      // .foxglove.Color color = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_color(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .foxglove.Color colors = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_colors(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated fixed32 indices = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedFixed32Parser(_internal_mutable_indices(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 45) {
          _internal_add_indices(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<uint32_t>(ptr));
          ptr += sizeof(uint32_t);
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

uint8_t* TriangleListPrimitive::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:foxglove.TriangleListPrimitive)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .foxglove.Pose pose = 1;
  if (this->_internal_has_pose()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::pose(this),
        _Internal::pose(this).GetCachedSize(), target, stream);
  }

  // repeated .foxglove.Point3 points = 2;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_points_size()); i < n; i++) {
    const auto& repfield = this->_internal_points(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(2, repfield, repfield.GetCachedSize(), target, stream);
  }

  // .foxglove.Color color = 3;
  if (this->_internal_has_color()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, _Internal::color(this),
        _Internal::color(this).GetCachedSize(), target, stream);
  }

  // repeated .foxglove.Color colors = 4;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_colors_size()); i < n; i++) {
    const auto& repfield = this->_internal_colors(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(4, repfield, repfield.GetCachedSize(), target, stream);
  }

  // repeated fixed32 indices = 5;
  if (this->_internal_indices_size() > 0) {
    target = stream->WriteFixedPacked(5, _internal_indices(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:foxglove.TriangleListPrimitive)
  return target;
}

size_t TriangleListPrimitive::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:foxglove.TriangleListPrimitive)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .foxglove.Point3 points = 2;
  total_size += 1UL * this->_internal_points_size();
  for (const auto& msg : this->_impl_.points_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .foxglove.Color colors = 4;
  total_size += 1UL * this->_internal_colors_size();
  for (const auto& msg : this->_impl_.colors_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated fixed32 indices = 5;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_indices_size());
    size_t data_size = 4UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  // .foxglove.Pose pose = 1;
  if (this->_internal_has_pose()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.pose_);
  }

  // .foxglove.Color color = 3;
  if (this->_internal_has_color()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.color_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData TriangleListPrimitive::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    TriangleListPrimitive::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*TriangleListPrimitive::GetClassData() const { return &_class_data_; }


void TriangleListPrimitive::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<TriangleListPrimitive*>(&to_msg);
  auto& from = static_cast<const TriangleListPrimitive&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:foxglove.TriangleListPrimitive)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.points_.MergeFrom(from._impl_.points_);
  _this->_impl_.colors_.MergeFrom(from._impl_.colors_);
  _this->_impl_.indices_.MergeFrom(from._impl_.indices_);
  if (from._internal_has_pose()) {
    _this->_internal_mutable_pose()->::foxglove::Pose::MergeFrom(
        from._internal_pose());
  }
  if (from._internal_has_color()) {
    _this->_internal_mutable_color()->::foxglove::Color::MergeFrom(
        from._internal_color());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void TriangleListPrimitive::CopyFrom(const TriangleListPrimitive& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:foxglove.TriangleListPrimitive)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TriangleListPrimitive::IsInitialized() const {
  return true;
}

void TriangleListPrimitive::InternalSwap(TriangleListPrimitive* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.points_.InternalSwap(&other->_impl_.points_);
  _impl_.colors_.InternalSwap(&other->_impl_.colors_);
  _impl_.indices_.InternalSwap(&other->_impl_.indices_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(TriangleListPrimitive, _impl_.color_)
      + sizeof(TriangleListPrimitive::_impl_.color_)
      - PROTOBUF_FIELD_OFFSET(TriangleListPrimitive, _impl_.pose_)>(
          reinterpret_cast<char*>(&_impl_.pose_),
          reinterpret_cast<char*>(&other->_impl_.pose_));
}

::PROTOBUF_NAMESPACE_ID::Metadata TriangleListPrimitive::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_foxglove_2fTriangleListPrimitive_2eproto_getter, &descriptor_table_foxglove_2fTriangleListPrimitive_2eproto_once,
      file_level_metadata_foxglove_2fTriangleListPrimitive_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::foxglove::TriangleListPrimitive*
Arena::CreateMaybeMessage< ::foxglove::TriangleListPrimitive >(Arena* arena) {
  return Arena::CreateMessageInternal< ::foxglove::TriangleListPrimitive >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
