/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <pose/eosio.hpp>

class [[eosio::contract]] payloadless : public eosio::contract {
public:
   using eosio::contract::contract;

   [[eosio::action]]
   void doit();
};
