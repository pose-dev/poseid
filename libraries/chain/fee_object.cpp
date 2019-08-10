
#include <eosio/chain/fee_object.hpp>
#include <eosio/chain/controller.hpp>

namespace eosio{
namespace chain{
asset fee_manager::get_fee(const controller& ctl, const transaction& trx) const{
   auto fee = asset(0);

   for (const auto& act : trx.actions ) {
      fee += get_fee(ctl, act);
   }

   return fee;
};

asset fee_manager::get_fee(const controller& ctl, const action& act) const{
   return asset{10};
};

}} // namespace eosio
