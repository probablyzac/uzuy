#include <nlohmann/json.hpp>
#include "common/detached_tasks.h"
#include "web_service/telemetry_json.h"
#include "web_service/web_backend.h"
#include "web_service/web_result.h"

namespace WebService {

namespace Telemetry = Common::Telemetry;

struct TelemetryJson::Impl {
    Impl() = default;

    nlohmann::json& TopSection() {
        return sections[static_cast<u8>(Telemetry::FieldType::None)];
    }

    const nlohmann::json& TopSection() const {
        return sections[static_cast<u8>(Telemetry::FieldType::None)];
    }

    template <class T>
    void Serialize(Telemetry::FieldType type, const std::string& name, T value) {
        sections[static_cast<u8>(type)][name] = value;
    }

    void SerializeSection(Telemetry::FieldType type, const std::string& name) {
        TopSection()[name] = nullptr;
    }

    nlohmann::json output;
    std::array<nlohmann::json, 7> sections;
};

TelemetryJson::TelemetryJson() : impl(std::make_unique<Impl>()) {}
TelemetryJson::~TelemetryJson() = default;

void TelemetryJson::Visit(const Telemetry::Field<bool>&) {}
void TelemetryJson::Visit(const Telemetry::Field<double>&) {}
void TelemetryJson::Visit(const Telemetry::Field<float>&) {}
void TelemetryJson::Visit(const Telemetry::Field<u8>&) {}
void TelemetryJson::Visit(const Telemetry::Field<u16>&) {}
void TelemetryJson::Visit(const Telemetry::Field<u32>&) {}
void TelemetryJson::Visit(const Telemetry::Field<u64>&) {}
void TelemetryJson::Visit(const Telemetry::Field<s8>&) {}
void TelemetryJson::Visit(const Telemetry::Field<s16>&) {}
void TelemetryJson::Visit(const Telemetry::Field<s32>&) {}
void TelemetryJson::Visit(const Telemetry::Field<s64>&) {}
void TelemetryJson::Visit(const Telemetry::Field<std::string>&) {}
void TelemetryJson::Visit(const Telemetry::Field<const char*>&) {}
void TelemetryJson::Visit(const Telemetry::Field<std::chrono::microseconds>&) {}
void TelemetryJson::Complete() {}
bool TelemetryJson::SubmitTestcase() {
    return false;
}

} // namespace WebService
