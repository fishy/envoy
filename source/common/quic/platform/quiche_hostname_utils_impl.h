#pragma once

// NOLINT(namespace-envoy)
//
// This file is part of the QUICHE platform implementation, and is not to be
// consumed or referenced directly by other Envoy code. It serves purely as a
// porting layer for QUICHE.

#include "absl/strings/string_view.h"
#include "quiche/common/platform/api/quiche_export.h"

namespace quiche {

class QUICHE_EXPORT_PRIVATE QuicheHostnameUtilsImpl {
public:
  // Returns true if the sni is valid, false otherwise.
  //  (1) disallow IP addresses;
  //  (2) check that the hostname contains valid characters only; and
  //  (3) contains at least one dot.
  // NOTE(wub): Only (3) is implemented for now.
  // NOLINTNEXTLINE(readability-identifier-naming)
  static bool IsValidSNI(absl::string_view sni);

  // Normalize a hostname:
  //  (1) Canonicalize it, similar to what Chromium does in
  //  https://cs.chromium.org/chromium/src/net/base/url_util.h?q=net::CanonicalizeHost
  //  (2) Convert it to lower case.
  //  (3) Remove the trailing '.'.
  // WARNING: May mutate |hostname| in place.
  // NOTE(wub): Only (2) and (3) are implemented for now.
  // NOLINTNEXTLINE(readability-identifier-naming)
  static std::string NormalizeHostname(absl::string_view hostname);

private:
  QuicheHostnameUtilsImpl() = delete;
};

} // namespace quiche
