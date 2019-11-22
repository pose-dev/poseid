
#pragma once

#include <pose/chain/types.hpp>
#include <pose/chain/asset.hpp>
#include <pose/chain/multi_index_includes.hpp>

namespace eosio {
namespace chain {

class controller;
struct transaction;
struct action;

class fee_manager{

public:
   explicit fee_manager(){
         ilog("fee manager initialization----------------------------------------------");
   };
   asset get_fee(const controller& ctl, const transaction& trx) const;
   asset get_fee(const controller& ctl, const action& act) const;

private:
   asset fee_;

};


class fee_paramter {
  public:
    account_name name;
    asset fee;
    account_name producer;
    fee_paramter(account_name name, asset fee, account_name producer) : name(name), fee(fee), producer(producer) {};
};

class fee_object : public chainbase::object<fee_object_type, fee_object> {
   OBJECT_CTOR(fee_object);
   id_type      id;
   asset        fee;
};

using fee_object_index = chainbase::shared_multi_index_container<
     fee_object,
     indexed_by<
           ordered_unique<tag<by_id>,
                 BOOST_MULTI_INDEX_MEMBER(fee_object, fee_object::id_type, id)
           >
     >
>;

}} // namespace

FC_REFLECT(eosio::chain::fee_paramter, (name)(fee)(producer))
FC_REFLECT(eosio::chain::fee_object, (id)(fee))

CHAINBASE_SET_INDEX_TYPE(eosio::chain::fee_object, eosio::chain::fee_object_index)