#pragma once

#include <hb/error/exception.h>

namespace hb{ namespace plugin {
    using namespace hb::error;

    class trade_api_exception : public hb_exception<trade_api_exception> {
    public:
        trade_api_exception():hb_exception<trade_api_exception>(trade_api_plugin_no, get_title(trade_api_plugin_no)) {

        }
    };
} }