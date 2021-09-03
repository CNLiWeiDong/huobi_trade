//
// Created by 李卫东 on 2019-02-19.
//
#pragma once

#include <functional>
#include <string>
#include <appbase/application.hpp>
#include <hb/log_plugin/log_plugin.h>
#include <hb/trade_api_plugin/trade_api_plugin_impl.h>

using namespace std;

namespace hb{ namespace plugin {
    using namespace appbase;
    
    class trade_api_plugin_api{
    public:
        trade_api_plugin_api(shared_ptr<trade_api_plugin_impl> _impl):impl(_impl){}
        price_result_type get_price(){ return impl->get_price();}
        string get_account(){return impl->get_account();}
        const order_result_type get_order_status(const string& order_id){return impl->get_order_status(order_id);}
        const string query_order_id_by_client(const string& client_id) {return impl->query_order_id_by_client(client_id);}
        void cancell_order(const string& order_id) { return impl->cancell_order(order_id);}
        string new_buy_order(const double& num, const double& price){
            return impl->new_buy_order(num,price);
        }
        string new_sale_order(const double& num, const double& price){
            return impl->new_sale_order(num,price);
        }
    private:
        shared_ptr<trade_api_plugin_impl> impl;
    };
    class trade_api_plugin : public appbase::plugin<trade_api_plugin> {
        public:
            APPBASE_PLUGIN_REQUIRES((log_plugin))
            trade_api_plugin();
            virtual ~trade_api_plugin();
            virtual void set_program_options(options_description&, options_description&) override;
            void plugin_initialize(const variables_map&);
            void plugin_startup();
            void plugin_shutdown();
            shared_ptr<trade_api_plugin_api> get_api(){
                return make_shared<trade_api_plugin_api>(my);
            }
        private:
            shared_ptr<trade_api_plugin_impl> my;
    };
}}
