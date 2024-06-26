// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/LaserScan.proto

#include "foxglove/LaserScan.pb.h"

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
PROTOBUF_CONSTEXPR LaserScan::LaserScan(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.ranges_)*/{}
  , /*decltype(_impl_.intensities_)*/{}
  , /*decltype(_impl_.frame_id_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.timestamp_)*/nullptr
  , /*decltype(_impl_.pose_)*/nullptr
  , /*decltype(_impl_.start_angle_)*/0
  , /*decltype(_impl_.end_angle_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct LaserScanDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LaserScanDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LaserScanDefaultTypeInternal() {}
  union {
    LaserScan _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LaserScanDefaultTypeInternal _LaserScan_default_instance_;
}  // namespace foxglove
static ::_pb::Metadata file_level_metadata_foxglove_2fLaserScan_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_foxglove_2fLaserScan_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_foxglove_2fLaserScan_2eproto = nullptr;

const uint32_t TableStruct_foxglove_2fLaserScan_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::foxglove::LaserScan, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::foxglove::LaserScan, _impl_.timestamp_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LaserScan, _impl_.frame_id_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LaserScan, _impl_.pose_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LaserScan, _impl_.start_angle_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LaserScan, _impl_.end_angle_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LaserScan, _impl_.ranges_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LaserScan, _impl_.intensities_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::foxglove::LaserScan)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::foxglove::_LaserScan_default_instance_._instance,
};

const char descriptor_table_protodef_foxglove_2fLaserScan_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\030foxglove/LaserScan.proto\022\010foxglove\032\023fo"
  "xglove/Pose.proto\032\037google/protobuf/times"
  "tamp.proto\"\267\001\n\tLaserScan\022-\n\ttimestamp\030\001 "
  "\001(\0132\032.google.protobuf.Timestamp\022\020\n\010frame"
  "_id\030\002 \001(\t\022\034\n\004pose\030\003 \001(\0132\016.foxglove.Pose\022"
  "\023\n\013start_angle\030\004 \001(\001\022\021\n\tend_angle\030\005 \001(\001\022"
  "\016\n\006ranges\030\006 \003(\001\022\023\n\013intensities\030\007 \003(\001b\006pr"
  "oto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_foxglove_2fLaserScan_2eproto_deps[2] = {
  &::descriptor_table_foxglove_2fPose_2eproto,
  &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::_pbi::once_flag descriptor_table_foxglove_2fLaserScan_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_foxglove_2fLaserScan_2eproto = {
    false, false, 284, descriptor_table_protodef_foxglove_2fLaserScan_2eproto,
    "foxglove/LaserScan.proto",
    &descriptor_table_foxglove_2fLaserScan_2eproto_once, descriptor_table_foxglove_2fLaserScan_2eproto_deps, 2, 1,
    schemas, file_default_instances, TableStruct_foxglove_2fLaserScan_2eproto::offsets,
    file_level_metadata_foxglove_2fLaserScan_2eproto, file_level_enum_descriptors_foxglove_2fLaserScan_2eproto,
    file_level_service_descriptors_foxglove_2fLaserScan_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_foxglove_2fLaserScan_2eproto_getter() {
  return &descriptor_table_foxglove_2fLaserScan_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_foxglove_2fLaserScan_2eproto(&descriptor_table_foxglove_2fLaserScan_2eproto);
namespace foxglove {

// ===================================================================

class LaserScan::_Internal {
 public:
  static const ::PROTOBUF_NAMESPACE_ID::Timestamp& timestamp(const LaserScan* msg);
  static const ::foxglove::Pose& pose(const LaserScan* msg);
};

const ::PROTOBUF_NAMESPACE_ID::Timestamp&
LaserScan::_Internal::timestamp(const LaserScan* msg) {
  return *msg->_impl_.timestamp_;
}
const ::foxglove::Pose&
LaserScan::_Internal::pose(const LaserScan* msg) {
  return *msg->_impl_.pose_;
}
void LaserScan::clear_timestamp() {
  if (GetArenaForAllocation() == nullptr && _impl_.timestamp_ != nullptr) {
    delete _impl_.timestamp_;
  }
  _impl_.timestamp_ = nullptr;
}
void LaserScan::clear_pose() {
  if (GetArenaForAllocation() == nullptr && _impl_.pose_ != nullptr) {
    delete _impl_.pose_;
  }
  _impl_.pose_ = nullptr;
}
LaserScan::LaserScan(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:foxglove.LaserScan)
}
LaserScan::LaserScan(const LaserScan& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  LaserScan* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.ranges_){from._impl_.ranges_}
    , decltype(_impl_.intensities_){from._impl_.intensities_}
    , decltype(_impl_.frame_id_){}
    , decltype(_impl_.timestamp_){nullptr}
    , decltype(_impl_.pose_){nullptr}
    , decltype(_impl_.start_angle_){}
    , decltype(_impl_.end_angle_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.frame_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.frame_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_frame_id().empty()) {
    _this->_impl_.frame_id_.Set(from._internal_frame_id(), 
      _this->GetArenaForAllocation());
  }
  if (from._internal_has_timestamp()) {
    _this->_impl_.timestamp_ = new ::PROTOBUF_NAMESPACE_ID::Timestamp(*from._impl_.timestamp_);
  }
  if (from._internal_has_pose()) {
    _this->_impl_.pose_ = new ::foxglove::Pose(*from._impl_.pose_);
  }
  ::memcpy(&_impl_.start_angle_, &from._impl_.start_angle_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.end_angle_) -
    reinterpret_cast<char*>(&_impl_.start_angle_)) + sizeof(_impl_.end_angle_));
  // @@protoc_insertion_point(copy_constructor:foxglove.LaserScan)
}

inline void LaserScan::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.ranges_){arena}
    , decltype(_impl_.intensities_){arena}
    , decltype(_impl_.frame_id_){}
    , decltype(_impl_.timestamp_){nullptr}
    , decltype(_impl_.pose_){nullptr}
    , decltype(_impl_.start_angle_){0}
    , decltype(_impl_.end_angle_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.frame_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.frame_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

LaserScan::~LaserScan() {
  // @@protoc_insertion_point(destructor:foxglove.LaserScan)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void LaserScan::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.ranges_.~RepeatedField();
  _impl_.intensities_.~RepeatedField();
  _impl_.frame_id_.Destroy();
  if (this != internal_default_instance()) delete _impl_.timestamp_;
  if (this != internal_default_instance()) delete _impl_.pose_;
}

void LaserScan::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void LaserScan::Clear() {
// @@protoc_insertion_point(message_clear_start:foxglove.LaserScan)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.ranges_.Clear();
  _impl_.intensities_.Clear();
  _impl_.frame_id_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && _impl_.timestamp_ != nullptr) {
    delete _impl_.timestamp_;
  }
  _impl_.timestamp_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.pose_ != nullptr) {
    delete _impl_.pose_;
  }
  _impl_.pose_ = nullptr;
  ::memset(&_impl_.start_angle_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.end_angle_) -
      reinterpret_cast<char*>(&_impl_.start_angle_)) + sizeof(_impl_.end_angle_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LaserScan::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
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
      // string frame_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_frame_id();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "foxglove.LaserScan.frame_id"));
        } else
          goto handle_unusual;
        continue;
      // .foxglove.Pose pose = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_pose(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double start_angle = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 33)) {
          _impl_.start_angle_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double end_angle = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 41)) {
          _impl_.end_angle_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // repeated double ranges = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedDoubleParser(_internal_mutable_ranges(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 49) {
          _internal_add_ranges(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // repeated double intensities = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedDoubleParser(_internal_mutable_intensities(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 57) {
          _internal_add_intensities(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
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

uint8_t* LaserScan::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:foxglove.LaserScan)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .google.protobuf.Timestamp timestamp = 1;
  if (this->_internal_has_timestamp()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::timestamp(this),
        _Internal::timestamp(this).GetCachedSize(), target, stream);
  }

  // string frame_id = 2;
  if (!this->_internal_frame_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_frame_id().data(), static_cast<int>(this->_internal_frame_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "foxglove.LaserScan.frame_id");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_frame_id(), target);
  }

  // .foxglove.Pose pose = 3;
  if (this->_internal_has_pose()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, _Internal::pose(this),
        _Internal::pose(this).GetCachedSize(), target, stream);
  }

  // double start_angle = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_start_angle = this->_internal_start_angle();
  uint64_t raw_start_angle;
  memcpy(&raw_start_angle, &tmp_start_angle, sizeof(tmp_start_angle));
  if (raw_start_angle != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(4, this->_internal_start_angle(), target);
  }

  // double end_angle = 5;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_end_angle = this->_internal_end_angle();
  uint64_t raw_end_angle;
  memcpy(&raw_end_angle, &tmp_end_angle, sizeof(tmp_end_angle));
  if (raw_end_angle != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(5, this->_internal_end_angle(), target);
  }

  // repeated double ranges = 6;
  if (this->_internal_ranges_size() > 0) {
    target = stream->WriteFixedPacked(6, _internal_ranges(), target);
  }

  // repeated double intensities = 7;
  if (this->_internal_intensities_size() > 0) {
    target = stream->WriteFixedPacked(7, _internal_intensities(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:foxglove.LaserScan)
  return target;
}

size_t LaserScan::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:foxglove.LaserScan)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated double ranges = 6;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_ranges_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  // repeated double intensities = 7;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_intensities_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  // string frame_id = 2;
  if (!this->_internal_frame_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_frame_id());
  }

  // .google.protobuf.Timestamp timestamp = 1;
  if (this->_internal_has_timestamp()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.timestamp_);
  }

  // .foxglove.Pose pose = 3;
  if (this->_internal_has_pose()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.pose_);
  }

  // double start_angle = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_start_angle = this->_internal_start_angle();
  uint64_t raw_start_angle;
  memcpy(&raw_start_angle, &tmp_start_angle, sizeof(tmp_start_angle));
  if (raw_start_angle != 0) {
    total_size += 1 + 8;
  }

  // double end_angle = 5;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_end_angle = this->_internal_end_angle();
  uint64_t raw_end_angle;
  memcpy(&raw_end_angle, &tmp_end_angle, sizeof(tmp_end_angle));
  if (raw_end_angle != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LaserScan::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    LaserScan::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LaserScan::GetClassData() const { return &_class_data_; }


void LaserScan::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<LaserScan*>(&to_msg);
  auto& from = static_cast<const LaserScan&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:foxglove.LaserScan)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.ranges_.MergeFrom(from._impl_.ranges_);
  _this->_impl_.intensities_.MergeFrom(from._impl_.intensities_);
  if (!from._internal_frame_id().empty()) {
    _this->_internal_set_frame_id(from._internal_frame_id());
  }
  if (from._internal_has_timestamp()) {
    _this->_internal_mutable_timestamp()->::PROTOBUF_NAMESPACE_ID::Timestamp::MergeFrom(
        from._internal_timestamp());
  }
  if (from._internal_has_pose()) {
    _this->_internal_mutable_pose()->::foxglove::Pose::MergeFrom(
        from._internal_pose());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_start_angle = from._internal_start_angle();
  uint64_t raw_start_angle;
  memcpy(&raw_start_angle, &tmp_start_angle, sizeof(tmp_start_angle));
  if (raw_start_angle != 0) {
    _this->_internal_set_start_angle(from._internal_start_angle());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_end_angle = from._internal_end_angle();
  uint64_t raw_end_angle;
  memcpy(&raw_end_angle, &tmp_end_angle, sizeof(tmp_end_angle));
  if (raw_end_angle != 0) {
    _this->_internal_set_end_angle(from._internal_end_angle());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LaserScan::CopyFrom(const LaserScan& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:foxglove.LaserScan)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LaserScan::IsInitialized() const {
  return true;
}

void LaserScan::InternalSwap(LaserScan* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.ranges_.InternalSwap(&other->_impl_.ranges_);
  _impl_.intensities_.InternalSwap(&other->_impl_.intensities_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.frame_id_, lhs_arena,
      &other->_impl_.frame_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LaserScan, _impl_.end_angle_)
      + sizeof(LaserScan::_impl_.end_angle_)
      - PROTOBUF_FIELD_OFFSET(LaserScan, _impl_.timestamp_)>(
          reinterpret_cast<char*>(&_impl_.timestamp_),
          reinterpret_cast<char*>(&other->_impl_.timestamp_));
}

::PROTOBUF_NAMESPACE_ID::Metadata LaserScan::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_foxglove_2fLaserScan_2eproto_getter, &descriptor_table_foxglove_2fLaserScan_2eproto_once,
      file_level_metadata_foxglove_2fLaserScan_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::foxglove::LaserScan*
Arena::CreateMaybeMessage< ::foxglove::LaserScan >(Arena* arena) {
  return Arena::CreateMessageInternal< ::foxglove::LaserScan >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
