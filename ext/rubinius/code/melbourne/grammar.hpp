#ifndef MEL_GRAMMAR_HPP
#define MEL_GRAMMAR_HPP

namespace MELBOURNE {
  VALUE string_to_ast(VALUE ptp, VALUE name, VALUE source, VALUE line);
  VALUE file_to_ast(VALUE ptp, const char *f, int fd, int start);
};

#endif
