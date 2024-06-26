// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foxglove/LocationFix.proto

#include "foxglove/LocationFix.pb.h"

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
PROTOBUF_CONSTEXPR LocationFix::LocationFix(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.position_covariance_)*/{}
  , /*decltype(_impl_.frame_id_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.timestamp_)*/nullptr
  , /*decltype(_impl_.latitude_)*/0
  , /*decltype(_impl_.longitude_)*/0
  , /*decltype(_impl_.altitude_)*/0
  , /*decltype(_impl_.position_covariance_type_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct LocationFixDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LocationFixDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LocationFixDefaultTypeInternal() {}
  union {
    LocationFix _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LocationFixDefaultTypeInternal _LocationFix_default_instance_;
}  // namespace foxglove
static ::_pb::Metadata file_level_metadata_foxglove_2fLocationFix_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_foxglove_2fLocationFix_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_foxglove_2fLocationFix_2eproto = nullptr;

const uint32_t TableStruct_foxglove_2fLocationFix_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::foxglove::LocationFix, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::foxglove::LocationFix, _impl_.timestamp_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LocationFix, _impl_.frame_id_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LocationFix, _impl_.latitude_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LocationFix, _impl_.longitude_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LocationFix, _impl_.altitude_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LocationFix, _impl_.position_covariance_),
  PROTOBUF_FIELD_OFFSET(::foxglove::LocationFix, _impl_.position_covariance_type_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::foxglove::LocationFix)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::foxglove::_LocationFix_default_instance_._instance,
};

const char descriptor_table_protodef_foxglove_2fLocationFix_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032foxglove/LocationFix.proto\022\010foxglove\032\037"
  "google/protobuf/timestamp.proto\"\312\002\n\013Loca"
  "tionFix\022-\n\ttimestamp\030\006 \001(\0132\032.google.prot"
  "obuf.Timestamp\022\020\n\010frame_id\030\007 \001(\t\022\020\n\010lati"
  "tude\030\001 \001(\001\022\021\n\tlongitude\030\002 \001(\001\022\020\n\010altitud"
  "e\030\003 \001(\001\022\033\n\023position_covariance\030\004 \003(\001\022N\n\030"
  "position_covariance_type\030\005 \001(\0162,.foxglov"
  "e.LocationFix.PositionCovarianceType\"V\n\026"
  "PositionCovarianceType\022\013\n\007UNKNOWN\020\000\022\020\n\014A"
  "PPROXIMATED\020\001\022\022\n\016DIAGONAL_KNOWN\020\002\022\t\n\005KNO"
  "WN\020\003b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_foxglove_2fLocationFix_2eproto_deps[1] = {
  &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::_pbi::once_flag descriptor_table_foxglove_2fLocationFix_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_foxglove_2fLocationFix_2eproto = {
    false, false, 412, descriptor_table_protodef_foxglove_2fLocationFix_2eproto,
    "foxglove/LocationFix.proto",
    &descriptor_table_foxglove_2fLocationFix_2eproto_once, descriptor_table_foxglove_2fLocationFix_2eproto_deps, 1, 1,
    schemas, file_default_instances, TableStruct_foxglove_2fLocationFix_2eproto::offsets,
    file_level_metadata_foxglove_2fLocationFix_2eproto, file_level_enum_descriptors_foxglove_2fLocationFix_2eproto,
    file_level_service_descriptors_foxglove_2fLocationFix_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_foxglove_2fLocationFix_2eproto_getter() {
  return &descriptor_table_foxglove_2fLocationFix_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_foxglove_2fLocationFix_2eproto(&descriptor_table_foxglove_2fLocationFix_2eproto);
namespace foxglove {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* LocationFix_PositionCovarianceType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_foxglove_2fLocationFix_2eproto);
  return file_level_enum_descriptors_foxglove_2fLocationFix_2eproto[0];
}
bool LocationFix_PositionCovarianceType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr LocationFix_PositionCovarianceType LocationFix::UNKNOWN;
constexpr LocationFix_PositionCovarianceType LocationFix::APPROXIMATED;
constexpr LocationFix_PositionCovarianceType LocationFix::DIAGONAL_KNOWN;
constexpr LocationFix_PositionCovarianceType LocationFix::KNOWN;
constexpr LocationFix_PositionCovarianceType LocationFix::PositionCovarianceType_MIN;
constexpr LocationFix_PositionCovarianceType LocationFix::PositionCovarianceType_MAX;
constexpr int LocationFix::PositionCovarianceType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class LocationFix::_Internal {
 public:
  static const ::PROTOBUF_NAMESPACE_ID::Timestamp& timestamp(const LocationFix* msg);
};

const ::PROTOBUF_NAMESPACE_ID::Timestamp&
LocationFix::_Internal::timestamp(const LocationFix* msg) {
  return *msg->_impl_.timestamp_;
}
void LocationFix::clear_timestamp() {
  if (GetArenaForAllocation() == nullptr && _impl_.timestamp_ != nullptr) {
    delete _impl_.timestamp_;
  }
  _impl_.timestamp_ = nullptr;
}
LocationFix::LocationFix(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:foxglove.LocationFix)
}
LocationFix::LocationFix(const LocationFix& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  LocationFix* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.position_covariance_){from._impl_.position_covariance_}
    , decltype(_impl_.frame_id_){}
    , decltype(_impl_.timestamp_){nullptr}
    , decltype(_impl_.latitude_){}
    , decltype(_impl_.longitude_){}
    , decltype(_impl_.altitude_){}
    , decltype(_impl_.position_covariance_type_){}
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
  ::memcpy(&_impl_.latitude_, &from._impl_.latitude_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.position_covariance_type_) -
    reinterpret_cast<char*>(&_impl_.latitude_)) + sizeof(_impl_.position_covariance_type_));
  // @@protoc_insertion_point(copy_constructor:foxglove.LocationFix)
}

inline void LocationFix::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.position_covariance_){arena}
    , decltype(_impl_.frame_id_){}
    , decltype(_impl_.timestamp_){nullptr}
    , decltype(_impl_.latitude_){0}
    , decltype(_impl_.longitude_){0}
    , decltype(_impl_.altitude_){0}
    , decltype(_impl_.position_covariance_type_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.frame_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.frame_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

LocationFix::~LocationFix() {
  // @@protoc_insertion_point(destructor:foxglove.LocationFix)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void LocationFix::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.position_covariance_.~RepeatedField();
  _impl_.frame_id_.Destroy();
  if (this != internal_default_instance()) delete _impl_.timestamp_;
}

void LocationFix::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void LocationFix::Clear() {
// @@protoc_insertion_point(message_clear_start:foxglove.LocationFix)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.position_covariance_.Clear();
  _impl_.frame_id_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && _impl_.timestamp_ != nullptr) {
    delete _impl_.timestamp_;
  }
  _impl_.timestamp_ = nullptr;
  ::memset(&_impl_.latitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.position_covariance_type_) -
      reinterpret_cast<char*>(&_impl_.latitude_)) + sizeof(_impl_.position_covariance_type_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LocationFix::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // double latitude = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 9)) {
          _impl_.latitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double longitude = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 17)) {
          _impl_.longitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double altitude = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 25)) {
          _impl_.altitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // repeated double position_covariance = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedDoubleParser(_internal_mutable_position_covariance(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 33) {
          _internal_add_position_covariance(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // .foxglove.LocationFix.PositionCovarianceType position_covariance_type = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_position_covariance_type(static_cast<::foxglove::LocationFix_PositionCovarianceType>(val));
        } else
          goto handle_unusual;
        continue;
      // .google.protobuf.Timestamp timestamp = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          ptr = ctx->ParseMessage(_internal_mutable_timestamp(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string frame_id = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          auto str = _internal_mutable_frame_id();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "foxglove.LocationFix.frame_id"));
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

uint8_t* LocationFix::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:foxglove.LocationFix)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // double latitude = 1;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_latitude = this->_internal_latitude();
  uint64_t raw_latitude;
  memcpy(&raw_latitude, &tmp_latitude, sizeof(tmp_latitude));
  if (raw_latitude != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(1, this->_internal_latitude(), target);
  }

  // double longitude = 2;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_longitude = this->_internal_longitude();
  uint64_t raw_longitude;
  memcpy(&raw_longitude, &tmp_longitude, sizeof(tmp_longitude));
  if (raw_longitude != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(2, this->_internal_longitude(), target);
  }

  // double altitude = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_altitude = this->_internal_altitude();
  uint64_t raw_altitude;
  memcpy(&raw_altitude, &tmp_altitude, sizeof(tmp_altitude));
  if (raw_altitude != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(3, this->_internal_altitude(), target);
  }

  // repeated double position_covariance = 4;
  if (this->_internal_position_covariance_size() > 0) {
    target = stream->WriteFixedPacked(4, _internal_position_covariance(), target);
  }

  // .foxglove.LocationFix.PositionCovarianceType position_covariance_type = 5;
  if (this->_internal_position_covariance_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      5, this->_internal_position_covariance_type(), target);
  }

  // .google.protobuf.Timestamp timestamp = 6;
  if (this->_internal_has_timestamp()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(6, _Internal::timestamp(this),
        _Internal::timestamp(this).GetCachedSize(), target, stream);
  }

  // string frame_id = 7;
  if (!this->_internal_frame_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_frame_id().data(), static_cast<int>(this->_internal_frame_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "foxglove.LocationFix.frame_id");
    target = stream->WriteStringMaybeAliased(
        7, this->_internal_frame_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:foxglove.LocationFix)
  return target;
}

size_t LocationFix::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:foxglove.LocationFix)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated double position_covariance = 4;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_position_covariance_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  // string frame_id = 7;
  if (!this->_internal_frame_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_frame_id());
  }

  // .google.protobuf.Timestamp timestamp = 6;
  if (this->_internal_has_timestamp()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.timestamp_);
  }

  // double latitude = 1;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_latitude = this->_internal_latitude();
  uint64_t raw_latitude;
  memcpy(&raw_latitude, &tmp_latitude, sizeof(tmp_latitude));
  if (raw_latitude != 0) {
    total_size += 1 + 8;
  }

  // double longitude = 2;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_longitude = this->_internal_longitude();
  uint64_t raw_longitude;
  memcpy(&raw_longitude, &tmp_longitude, sizeof(tmp_longitude));
  if (raw_longitude != 0) {
    total_size += 1 + 8;
  }

  // double altitude = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_altitude = this->_internal_altitude();
  uint64_t raw_altitude;
  memcpy(&raw_altitude, &tmp_altitude, sizeof(tmp_altitude));
  if (raw_altitude != 0) {
    total_size += 1 + 8;
  }

  // .foxglove.LocationFix.PositionCovarianceType position_covariance_type = 5;
  if (this->_internal_position_covariance_type() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_position_covariance_type());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LocationFix::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    LocationFix::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LocationFix::GetClassData() const { return &_class_data_; }


void LocationFix::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<LocationFix*>(&to_msg);
  auto& from = static_cast<const LocationFix&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:foxglove.LocationFix)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.position_covariance_.MergeFrom(from._impl_.position_covariance_);
  if (!from._internal_frame_id().empty()) {
    _this->_internal_set_frame_id(from._internal_frame_id());
  }
  if (from._internal_has_timestamp()) {
    _this->_internal_mutable_timestamp()->::PROTOBUF_NAMESPACE_ID::Timestamp::MergeFrom(
        from._internal_timestamp());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_latitude = from._internal_latitude();
  uint64_t raw_latitude;
  memcpy(&raw_latitude, &tmp_latitude, sizeof(tmp_latitude));
  if (raw_latitude != 0) {
    _this->_internal_set_latitude(from._internal_latitude());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_longitude = from._internal_longitude();
  uint64_t raw_longitude;
  memcpy(&raw_longitude, &tmp_longitude, sizeof(tmp_longitude));
  if (raw_longitude != 0) {
    _this->_internal_set_longitude(from._internal_longitude());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_altitude = from._internal_altitude();
  uint64_t raw_altitude;
  memcpy(&raw_altitude, &tmp_altitude, sizeof(tmp_altitude));
  if (raw_altitude != 0) {
    _this->_internal_set_altitude(from._internal_altitude());
  }
  if (from._internal_position_covariance_type() != 0) {
    _this->_internal_set_position_covariance_type(from._internal_position_covariance_type());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LocationFix::CopyFrom(const LocationFix& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:foxglove.LocationFix)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LocationFix::IsInitialized() const {
  return true;
}

void LocationFix::InternalSwap(LocationFix* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.position_covariance_.InternalSwap(&other->_impl_.position_covariance_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.frame_id_, lhs_arena,
      &other->_impl_.frame_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LocationFix, _impl_.position_covariance_type_)
      + sizeof(LocationFix::_impl_.position_covariance_type_)
      - PROTOBUF_FIELD_OFFSET(LocationFix, _impl_.timestamp_)>(
          reinterpret_cast<char*>(&_impl_.timestamp_),
          reinterpret_cast<char*>(&other->_impl_.timestamp_));
}

::PROTOBUF_NAMESPACE_ID::Metadata LocationFix::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_foxglove_2fLocationFix_2eproto_getter, &descriptor_table_foxglove_2fLocationFix_2eproto_once,
      file_level_metadata_foxglove_2fLocationFix_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace foxglove
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::foxglove::LocationFix*
Arena::CreateMaybeMessage< ::foxglove::LocationFix >(Arena* arena) {
  return Arena::CreateMessageInternal< ::foxglove::LocationFix >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
