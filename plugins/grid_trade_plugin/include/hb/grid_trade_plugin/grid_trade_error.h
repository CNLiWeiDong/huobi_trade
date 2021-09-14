#pragma once

#include <hb/error/exception.h>

namespace hb{ namespace plugin {
    using namespace hb::error;

    class grid_trade_exception : public hb_exception<grid_trade_exception, SN("trade")> {
    public:
        grid_trade_exception():hb_exception<grid_trade_exception, SN("trade")>() {

        }
    };
} }