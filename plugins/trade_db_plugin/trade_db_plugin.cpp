//
// Created by 李卫东 on 2019-02-26.
//

#include <hb/trade_db_plugin/trade_db_plugin.h>


namespace hb{ namespace plugin{
        static appbase::abstract_plugin& _trade_db_plugin = app().register_plugin<trade_db_plugin>();
        trade_db_plugin::trade_db_plugin(){

        }
        trade_db_plugin::~trade_db_plugin(){

        }

        void trade_db_plugin::set_program_options(options_description& cli, options_description& cfg) {
            cfg.add_options()
                    ("trade_db_host", bpo::value<string>()->default_value("127.0.0.1"), "trade_db connect host")
                    ("trade_db_port", bpo::value<int>()->default_value(3306), "trade_db db port")
                    ("trade_db_name", bpo::value<string>()->default_value("eos_trad"), "trade_db db name")
                    ("trade_db_user", bpo::value<string>()->default_value("eos_trad"), "trade_db db user")
                    ("trade_db_pass", bpo::value<string>()->default_value("123456"), "trade_db db password")
                    ;
        }
        void trade_db_plugin::plugin_initialize(const variables_map& options) {
            log_info<<"trade_db_plugin::plugin_initialize";
            my = make_shared<trade_db_plugin_impl>();
            my->set_db_info(
                options.at("trade_db_host").as<string>(),
                options.at("trade_db_name").as<string>(),
                options.at("trade_db_user").as<string>(),
                options.at("trade_db_pass").as<string>(),
                options.at("trade_db_port").as<int>()
            );
        }
        void trade_db_plugin::plugin_startup() {
            log_info<<"trade_db_plugin::plugin_startup";
        }
        void trade_db_plugin::plugin_shutdown() {
            log_info<<"trade_db_plugin::plugin_shutdown";
        }
    } }