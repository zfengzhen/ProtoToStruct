// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: comm_struct.proto

#ifndef PROTOBUF_comm_5fstruct_2eproto__INCLUDED
#define PROTOBUF_comm_5fstruct_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "proto_to_struct.pb.h"
// @@protoc_insertion_point(includes)

namespace ProtoComm {
namespace Player {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_comm_5fstruct_2eproto();
void protobuf_AssignDesc_comm_5fstruct_2eproto();
void protobuf_ShutdownFile_comm_5fstruct_2eproto();

class EquipInfo;
class SkillInfo;
class HeroInfo;
class RoleInfo;
class PlayerData;

// ===================================================================

class EquipInfo : public ::google::protobuf::Message {
 public:
  EquipInfo();
  virtual ~EquipInfo();

  EquipInfo(const EquipInfo& from);

  inline EquipInfo& operator=(const EquipInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EquipInfo& default_instance();

  void Swap(EquipInfo* other);

  // implements Message ----------------------------------------------

  EquipInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const EquipInfo& from);
  void MergeFrom(const EquipInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::uint32 id() const;
  inline void set_id(::google::protobuf::uint32 value);

  // optional int32 level = 2;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 2;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // optional int32 exp = 3;
  inline bool has_exp() const;
  inline void clear_exp();
  static const int kExpFieldNumber = 3;
  inline ::google::protobuf::int32 exp() const;
  inline void set_exp(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ProtoComm.Player.EquipInfo)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_exp();
  inline void clear_has_exp();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 id_;
  ::google::protobuf::int32 level_;
  ::google::protobuf::int32 exp_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_comm_5fstruct_2eproto();
  friend void protobuf_AssignDesc_comm_5fstruct_2eproto();
  friend void protobuf_ShutdownFile_comm_5fstruct_2eproto();

  void InitAsDefaultInstance();
  static EquipInfo* default_instance_;
};
// -------------------------------------------------------------------

class SkillInfo : public ::google::protobuf::Message {
 public:
  SkillInfo();
  virtual ~SkillInfo();

  SkillInfo(const SkillInfo& from);

  inline SkillInfo& operator=(const SkillInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SkillInfo& default_instance();

  void Swap(SkillInfo* other);

  // implements Message ----------------------------------------------

  SkillInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SkillInfo& from);
  void MergeFrom(const SkillInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::uint32 id() const;
  inline void set_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:ProtoComm.Player.SkillInfo)
 private:
  inline void set_has_id();
  inline void clear_has_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_comm_5fstruct_2eproto();
  friend void protobuf_AssignDesc_comm_5fstruct_2eproto();
  friend void protobuf_ShutdownFile_comm_5fstruct_2eproto();

  void InitAsDefaultInstance();
  static SkillInfo* default_instance_;
};
// -------------------------------------------------------------------

class HeroInfo : public ::google::protobuf::Message {
 public:
  HeroInfo();
  virtual ~HeroInfo();

  HeroInfo(const HeroInfo& from);

  inline HeroInfo& operator=(const HeroInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const HeroInfo& default_instance();

  void Swap(HeroInfo* other);

  // implements Message ----------------------------------------------

  HeroInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HeroInfo& from);
  void MergeFrom(const HeroInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::uint32 id() const;
  inline void set_id(::google::protobuf::uint32 value);

  // optional int32 level = 2;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 2;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // optional int32 quality = 3;
  inline bool has_quality() const;
  inline void clear_quality();
  static const int kQualityFieldNumber = 3;
  inline ::google::protobuf::int32 quality() const;
  inline void set_quality(::google::protobuf::int32 value);

  // optional int32 star = 4;
  inline bool has_star() const;
  inline void clear_star();
  static const int kStarFieldNumber = 4;
  inline ::google::protobuf::int32 star() const;
  inline void set_star(::google::protobuf::int32 value);

  // repeated .ProtoComm.Player.EquipInfo equip_info = 5;
  inline int equip_info_size() const;
  inline void clear_equip_info();
  static const int kEquipInfoFieldNumber = 5;
  inline const ::ProtoComm::Player::EquipInfo& equip_info(int index) const;
  inline ::ProtoComm::Player::EquipInfo* mutable_equip_info(int index);
  inline ::ProtoComm::Player::EquipInfo* add_equip_info();
  inline const ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::EquipInfo >&
      equip_info() const;
  inline ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::EquipInfo >*
      mutable_equip_info();

  // repeated .ProtoComm.Player.SkillInfo skill_info = 6;
  inline int skill_info_size() const;
  inline void clear_skill_info();
  static const int kSkillInfoFieldNumber = 6;
  inline const ::ProtoComm::Player::SkillInfo& skill_info(int index) const;
  inline ::ProtoComm::Player::SkillInfo* mutable_skill_info(int index);
  inline ::ProtoComm::Player::SkillInfo* add_skill_info();
  inline const ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::SkillInfo >&
      skill_info() const;
  inline ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::SkillInfo >*
      mutable_skill_info();

  // optional int32 exp = 7;
  inline bool has_exp() const;
  inline void clear_exp();
  static const int kExpFieldNumber = 7;
  inline ::google::protobuf::int32 exp() const;
  inline void set_exp(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ProtoComm.Player.HeroInfo)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_quality();
  inline void clear_has_quality();
  inline void set_has_star();
  inline void clear_has_star();
  inline void set_has_exp();
  inline void clear_has_exp();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 id_;
  ::google::protobuf::int32 level_;
  ::google::protobuf::int32 quality_;
  ::google::protobuf::int32 star_;
  ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::EquipInfo > equip_info_;
  ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::SkillInfo > skill_info_;
  ::google::protobuf::int32 exp_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_comm_5fstruct_2eproto();
  friend void protobuf_AssignDesc_comm_5fstruct_2eproto();
  friend void protobuf_ShutdownFile_comm_5fstruct_2eproto();

  void InitAsDefaultInstance();
  static HeroInfo* default_instance_;
};
// -------------------------------------------------------------------

class RoleInfo : public ::google::protobuf::Message {
 public:
  RoleInfo();
  virtual ~RoleInfo();

  RoleInfo(const RoleInfo& from);

  inline RoleInfo& operator=(const RoleInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RoleInfo& default_instance();

  void Swap(RoleInfo* other);

  // implements Message ----------------------------------------------

  RoleInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RoleInfo& from);
  void MergeFrom(const RoleInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 Money = 1;
  inline bool has_money() const;
  inline void clear_money();
  static const int kMoneyFieldNumber = 1;
  inline ::google::protobuf::int32 money() const;
  inline void set_money(::google::protobuf::int32 value);

  // optional int32 diamond = 2;
  inline bool has_diamond() const;
  inline void clear_diamond();
  static const int kDiamondFieldNumber = 2;
  inline ::google::protobuf::int32 diamond() const;
  inline void set_diamond(::google::protobuf::int32 value);

  // optional int32 level = 3;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 3;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // optional string name = 4;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 4;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:ProtoComm.Player.RoleInfo)
 private:
  inline void set_has_money();
  inline void clear_has_money();
  inline void set_has_diamond();
  inline void clear_has_diamond();
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_name();
  inline void clear_has_name();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 money_;
  ::google::protobuf::int32 diamond_;
  ::std::string* name_;
  ::google::protobuf::int32 level_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_comm_5fstruct_2eproto();
  friend void protobuf_AssignDesc_comm_5fstruct_2eproto();
  friend void protobuf_ShutdownFile_comm_5fstruct_2eproto();

  void InitAsDefaultInstance();
  static RoleInfo* default_instance_;
};
// -------------------------------------------------------------------

class PlayerData : public ::google::protobuf::Message {
 public:
  PlayerData();
  virtual ~PlayerData();

  PlayerData(const PlayerData& from);

  inline PlayerData& operator=(const PlayerData& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PlayerData& default_instance();

  void Swap(PlayerData* other);

  // implements Message ----------------------------------------------

  PlayerData* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PlayerData& from);
  void MergeFrom(const PlayerData& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .ProtoComm.Player.RoleInfo role_info = 1;
  inline bool has_role_info() const;
  inline void clear_role_info();
  static const int kRoleInfoFieldNumber = 1;
  inline const ::ProtoComm::Player::RoleInfo& role_info() const;
  inline ::ProtoComm::Player::RoleInfo* mutable_role_info();
  inline ::ProtoComm::Player::RoleInfo* release_role_info();
  inline void set_allocated_role_info(::ProtoComm::Player::RoleInfo* role_info);

  // repeated .ProtoComm.Player.HeroInfo hero_info = 2;
  inline int hero_info_size() const;
  inline void clear_hero_info();
  static const int kHeroInfoFieldNumber = 2;
  inline const ::ProtoComm::Player::HeroInfo& hero_info(int index) const;
  inline ::ProtoComm::Player::HeroInfo* mutable_hero_info(int index);
  inline ::ProtoComm::Player::HeroInfo* add_hero_info();
  inline const ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::HeroInfo >&
      hero_info() const;
  inline ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::HeroInfo >*
      mutable_hero_info();

  // @@protoc_insertion_point(class_scope:ProtoComm.Player.PlayerData)
 private:
  inline void set_has_role_info();
  inline void clear_has_role_info();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::ProtoComm::Player::RoleInfo* role_info_;
  ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::HeroInfo > hero_info_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_comm_5fstruct_2eproto();
  friend void protobuf_AssignDesc_comm_5fstruct_2eproto();
  friend void protobuf_ShutdownFile_comm_5fstruct_2eproto();

  void InitAsDefaultInstance();
  static PlayerData* default_instance_;
};
// ===================================================================


// ===================================================================

// EquipInfo

// optional uint32 id = 1;
inline bool EquipInfo::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void EquipInfo::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void EquipInfo::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void EquipInfo::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 EquipInfo::id() const {
  return id_;
}
inline void EquipInfo::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
}

// optional int32 level = 2;
inline bool EquipInfo::has_level() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void EquipInfo::set_has_level() {
  _has_bits_[0] |= 0x00000002u;
}
inline void EquipInfo::clear_has_level() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void EquipInfo::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 EquipInfo::level() const {
  return level_;
}
inline void EquipInfo::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
}

// optional int32 exp = 3;
inline bool EquipInfo::has_exp() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void EquipInfo::set_has_exp() {
  _has_bits_[0] |= 0x00000004u;
}
inline void EquipInfo::clear_has_exp() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void EquipInfo::clear_exp() {
  exp_ = 0;
  clear_has_exp();
}
inline ::google::protobuf::int32 EquipInfo::exp() const {
  return exp_;
}
inline void EquipInfo::set_exp(::google::protobuf::int32 value) {
  set_has_exp();
  exp_ = value;
}

// -------------------------------------------------------------------

// SkillInfo

// optional uint32 id = 1;
inline bool SkillInfo::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SkillInfo::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SkillInfo::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SkillInfo::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 SkillInfo::id() const {
  return id_;
}
inline void SkillInfo::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
}

// -------------------------------------------------------------------

// HeroInfo

// optional uint32 id = 1;
inline bool HeroInfo::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void HeroInfo::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void HeroInfo::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void HeroInfo::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 HeroInfo::id() const {
  return id_;
}
inline void HeroInfo::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
}

// optional int32 level = 2;
inline bool HeroInfo::has_level() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void HeroInfo::set_has_level() {
  _has_bits_[0] |= 0x00000002u;
}
inline void HeroInfo::clear_has_level() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void HeroInfo::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 HeroInfo::level() const {
  return level_;
}
inline void HeroInfo::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
}

// optional int32 quality = 3;
inline bool HeroInfo::has_quality() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void HeroInfo::set_has_quality() {
  _has_bits_[0] |= 0x00000004u;
}
inline void HeroInfo::clear_has_quality() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void HeroInfo::clear_quality() {
  quality_ = 0;
  clear_has_quality();
}
inline ::google::protobuf::int32 HeroInfo::quality() const {
  return quality_;
}
inline void HeroInfo::set_quality(::google::protobuf::int32 value) {
  set_has_quality();
  quality_ = value;
}

// optional int32 star = 4;
inline bool HeroInfo::has_star() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void HeroInfo::set_has_star() {
  _has_bits_[0] |= 0x00000008u;
}
inline void HeroInfo::clear_has_star() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void HeroInfo::clear_star() {
  star_ = 0;
  clear_has_star();
}
inline ::google::protobuf::int32 HeroInfo::star() const {
  return star_;
}
inline void HeroInfo::set_star(::google::protobuf::int32 value) {
  set_has_star();
  star_ = value;
}

// repeated .ProtoComm.Player.EquipInfo equip_info = 5;
inline int HeroInfo::equip_info_size() const {
  return equip_info_.size();
}
inline void HeroInfo::clear_equip_info() {
  equip_info_.Clear();
}
inline const ::ProtoComm::Player::EquipInfo& HeroInfo::equip_info(int index) const {
  return equip_info_.Get(index);
}
inline ::ProtoComm::Player::EquipInfo* HeroInfo::mutable_equip_info(int index) {
  return equip_info_.Mutable(index);
}
inline ::ProtoComm::Player::EquipInfo* HeroInfo::add_equip_info() {
  return equip_info_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::EquipInfo >&
HeroInfo::equip_info() const {
  return equip_info_;
}
inline ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::EquipInfo >*
HeroInfo::mutable_equip_info() {
  return &equip_info_;
}

// repeated .ProtoComm.Player.SkillInfo skill_info = 6;
inline int HeroInfo::skill_info_size() const {
  return skill_info_.size();
}
inline void HeroInfo::clear_skill_info() {
  skill_info_.Clear();
}
inline const ::ProtoComm::Player::SkillInfo& HeroInfo::skill_info(int index) const {
  return skill_info_.Get(index);
}
inline ::ProtoComm::Player::SkillInfo* HeroInfo::mutable_skill_info(int index) {
  return skill_info_.Mutable(index);
}
inline ::ProtoComm::Player::SkillInfo* HeroInfo::add_skill_info() {
  return skill_info_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::SkillInfo >&
HeroInfo::skill_info() const {
  return skill_info_;
}
inline ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::SkillInfo >*
HeroInfo::mutable_skill_info() {
  return &skill_info_;
}

// optional int32 exp = 7;
inline bool HeroInfo::has_exp() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void HeroInfo::set_has_exp() {
  _has_bits_[0] |= 0x00000040u;
}
inline void HeroInfo::clear_has_exp() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void HeroInfo::clear_exp() {
  exp_ = 0;
  clear_has_exp();
}
inline ::google::protobuf::int32 HeroInfo::exp() const {
  return exp_;
}
inline void HeroInfo::set_exp(::google::protobuf::int32 value) {
  set_has_exp();
  exp_ = value;
}

// -------------------------------------------------------------------

// RoleInfo

// optional int32 Money = 1;
inline bool RoleInfo::has_money() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RoleInfo::set_has_money() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RoleInfo::clear_has_money() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RoleInfo::clear_money() {
  money_ = 0;
  clear_has_money();
}
inline ::google::protobuf::int32 RoleInfo::money() const {
  return money_;
}
inline void RoleInfo::set_money(::google::protobuf::int32 value) {
  set_has_money();
  money_ = value;
}

// optional int32 diamond = 2;
inline bool RoleInfo::has_diamond() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RoleInfo::set_has_diamond() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RoleInfo::clear_has_diamond() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RoleInfo::clear_diamond() {
  diamond_ = 0;
  clear_has_diamond();
}
inline ::google::protobuf::int32 RoleInfo::diamond() const {
  return diamond_;
}
inline void RoleInfo::set_diamond(::google::protobuf::int32 value) {
  set_has_diamond();
  diamond_ = value;
}

// optional int32 level = 3;
inline bool RoleInfo::has_level() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RoleInfo::set_has_level() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RoleInfo::clear_has_level() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RoleInfo::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 RoleInfo::level() const {
  return level_;
}
inline void RoleInfo::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
}

// optional string name = 4;
inline bool RoleInfo::has_name() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void RoleInfo::set_has_name() {
  _has_bits_[0] |= 0x00000008u;
}
inline void RoleInfo::clear_has_name() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void RoleInfo::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& RoleInfo::name() const {
  return *name_;
}
inline void RoleInfo::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void RoleInfo::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void RoleInfo::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* RoleInfo::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* RoleInfo::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void RoleInfo::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// PlayerData

// optional .ProtoComm.Player.RoleInfo role_info = 1;
inline bool PlayerData::has_role_info() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PlayerData::set_has_role_info() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PlayerData::clear_has_role_info() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PlayerData::clear_role_info() {
  if (role_info_ != NULL) role_info_->::ProtoComm::Player::RoleInfo::Clear();
  clear_has_role_info();
}
inline const ::ProtoComm::Player::RoleInfo& PlayerData::role_info() const {
  return role_info_ != NULL ? *role_info_ : *default_instance_->role_info_;
}
inline ::ProtoComm::Player::RoleInfo* PlayerData::mutable_role_info() {
  set_has_role_info();
  if (role_info_ == NULL) role_info_ = new ::ProtoComm::Player::RoleInfo;
  return role_info_;
}
inline ::ProtoComm::Player::RoleInfo* PlayerData::release_role_info() {
  clear_has_role_info();
  ::ProtoComm::Player::RoleInfo* temp = role_info_;
  role_info_ = NULL;
  return temp;
}
inline void PlayerData::set_allocated_role_info(::ProtoComm::Player::RoleInfo* role_info) {
  delete role_info_;
  role_info_ = role_info;
  if (role_info) {
    set_has_role_info();
  } else {
    clear_has_role_info();
  }
}

// repeated .ProtoComm.Player.HeroInfo hero_info = 2;
inline int PlayerData::hero_info_size() const {
  return hero_info_.size();
}
inline void PlayerData::clear_hero_info() {
  hero_info_.Clear();
}
inline const ::ProtoComm::Player::HeroInfo& PlayerData::hero_info(int index) const {
  return hero_info_.Get(index);
}
inline ::ProtoComm::Player::HeroInfo* PlayerData::mutable_hero_info(int index) {
  return hero_info_.Mutable(index);
}
inline ::ProtoComm::Player::HeroInfo* PlayerData::add_hero_info() {
  return hero_info_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::HeroInfo >&
PlayerData::hero_info() const {
  return hero_info_;
}
inline ::google::protobuf::RepeatedPtrField< ::ProtoComm::Player::HeroInfo >*
PlayerData::mutable_hero_info() {
  return &hero_info_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Player
}  // namespace ProtoComm

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_comm_5fstruct_2eproto__INCLUDED
