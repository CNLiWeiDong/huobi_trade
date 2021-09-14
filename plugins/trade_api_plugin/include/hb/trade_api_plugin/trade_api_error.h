#pragma once

#include <hb/error/exception.h>

namespace hb{ namespace plugin {
    using namespace hb::error;

    class trade_api_exception : public hb_exception<trade_api_exception, SN("tradeapi")> {
    public:
        trade_api_exception():hb_exception<trade_api_exception, SN("tradeapi")>() {

        }
    };
} }