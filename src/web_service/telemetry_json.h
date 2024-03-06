#pragma once

#include <chrono>
#include <string>
#include "common/telemetry.h"

namespace WebService {

/**
 * Implementation of VisitorInterface that serialized telemetry into JSON, and submits it to the
 * yuzu web service
 */
class TelemetryJson : public Common::Telemetry::VisitorInterface {
public:
    TelemetryJson();
    ~TelemetryJson() override = default;

    void Visit(const Common::Telemetry::Field<bool>&) override {}
    void Visit(const Common::Telemetry::Field<double>&) override {}
    void Visit(const Common::Telemetry::Field<float>&) override {}
    void Visit(const Common::Telemetry::Field<u8>&) override {}
    void Visit(const Common::Telemetry::Field<u16>&) override {}
    void Visit(const Common::Telemetry::Field<u32>&) override {}
    void Visit(const Common::Telemetry::Field<u64>&) override {}
    void Visit(const Common::Telemetry::Field<s8>&) override {}
    void Visit(const Common::Telemetry::Field<s16>&) override {}
    void Visit(const Common::Telemetry::Field<s32>&) override {}
    void Visit(const Common::Telemetry::Field<s64>&) override {}
    void Visit(const Common::Telemetry::Field<std::string>&) override {}
    void Visit(const Common::Telemetry::Field<const char*>&) override {}
    void Visit(const Common::Telemetry::Field<std::chrono::microseconds>&) override {}

    void Complete() override {}
    bool SubmitTestcase() override { return false; }

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace WebService
