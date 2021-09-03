#pragma once

#include <hb/error/exception.h>

namespace hb{ namespace plugin {
    using namespace hb::error;

    class trade_db_exception : public hb_exception<trade_db_exception> {
    public:
        trade_db_exception():hb_exception<trade_db_exception>(trade_db_plugin_no, get_title(trade_db_plugin_no)) {

        }
    };
} }