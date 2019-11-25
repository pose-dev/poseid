/**
 *  @file
 *  @copyright defined in pose/LICENSE
 */
#pragma once

#include <pose/chain/types.hpp>
#include <pose/chain/contract_types.hpp>

namespace eosio { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_pose_newaccount(apply_context&);
   void apply_pose_updateauth(apply_context&);
   void apply_pose_deleteauth(apply_context&);
   void apply_pose_linkauth(apply_context&);
   void apply_pose_unlinkauth(apply_context&);

   /*
   void apply_eosio_postrecovery(apply_context&);
   void apply_eosio_passrecovery(apply_context&);
   void apply_eosio_vetorecovery(apply_context&);
   */

   void apply_pose_setcode(apply_context&);
   void apply_pose_setabi(apply_context&);

   void apply_pose_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace eosio::chain
