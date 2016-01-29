#ifndef MEL_VISITOR_HPP
#define MEL_VISITOR_HPP

namespace MELBOURNE {
  rb_parser_state *parser_alloc_state();
  void *pt_allocate(rb_parser_state *st, int size);
  void pt_free(rb_parser_state *st);

  void create_error(rb_parser_state *parser_state, char *msg);
};

#endif

