#include "errors.h"
#include <stdarg.h>
#include <stdio.h>

namespace reindexer {

Error::Error(int code, const char *fmt, ...) : code_(code) {
	char buf[1024];

	va_list args;
	va_start(args, fmt);
	vsnprintf(buf, sizeof(buf), fmt, args);
	va_end(args);
	what_ = buf;
}
Error::Error(int code) : code_(code) {}

const string &Error::what() const { return what_; }
int Error::code() const { return code_; }

}  // namespace reindexer